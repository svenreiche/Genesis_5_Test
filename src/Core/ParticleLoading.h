//
// Created by reiche on 10/27/21.
//
#include<vector>
#include<ranges>

#ifndef GENESIS_5_TEST_PARTICLELOADING_H
#define GENESIS_5_TEST_PARTICLELOADING_H

#include "Particle.h"
#include "ParticleDiagnostics.h"
#include "../Util/Hammersley.h"
#include "../Util/Inverfc.h"





template<typename T>
void QuietLoading(std::vector<Particle<T>> &beam, const std::vector<int> base, const unsigned int seed)
{
    if (beam.size() == 0) {
        return;
    }

    // Hammersley sequence for quiet loading -> select base and seed (= starting point of sequence)
    std::vector<Hammersley> seq(6);
    for (int i = 0; i < 6; i++){
        seq[i].set(base[i],seed);
    }

    double xpx,ypy;
    T norm = 1./static_cast<T>(beam.size());

    // fill particle distribution and calculate correlation
    auto quietloading = [&seq,&xpx,&ypy](Particle<T> &par){
        par.gamma = inverfc(2*seq[0].getElement());
        par.theta = seq[1].getElement();
        par.x  = inverfc(2*seq[2].getElement());
        par.y  = inverfc(2*seq[3].getElement());
        par.px = inverfc(2*seq[4].getElement());
        par.py = inverfc(2*seq[5].getElement());
        xpx += par.x * par.px;   // calculate the correlation
        ypy += par.y * par.py;
    };
    std::ranges::for_each(beam, quietloading);

    // get moments of distribution and calculate the residual slope between x,px and y,py
    auto [mom1,mom2] = BeamMoments(beam);
    std::cout << "Moments: " << mom2.x << " " << mom2.px << " " << xpx << "\n";
    if (mom2.x > 0) {
        xpx=(xpx*norm-mom1.x*mom1.px)/(mom2.x*mom2.x);
    } else {
        xpx = 0;
    }
    if (mom2.y > 0) {
        ypy=(ypy*norm-mom1.y*mom1.py)/(mom2.y*mom2.y);
    } else {
        ypy = 0;
    }

    // normalize distribution
    mom1.theta=0;      // do not change theta distribution which is filled between 0 and 1
    mom2.theta=1;      // and do not scale it
    mom2.inv();

    auto normalize = [mom1,mom2,xpx,ypy](Particle<T> &par){
        par -=mom1;
        par.px -= xpx * par.x;
        par.py -= ypy * par.y;
        par *=mom2;
    };
    std::ranges::for_each(beam, normalize);

    return;
}

template<typename T>
void TransformBeam(std::vector<Particle<T>> &beam, const Particle<T> size, const Particle<T> center, const T slopex, const T slopey)
{
    if (beam.size()==0){
        return;
    }

    auto scale = [size, center, slopex, slopey](Particle<T> &par) {
        par *= size;
        par.px += slopex * par.x;
        par.py += slopey * par.y;
        par += center;
    };

    std::ranges::for_each(beam, scale);
}



#endif //GENESIS_5_TEST_PARTICLELOADING_H
