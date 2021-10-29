//
// Created by reiche on 10/27/21.
//

#include<vector>
#include<ranges>
#include<tuple>
#include<cmath>

#ifndef GENESIS_5_TEST_PARTICLEDIAGNOSTICS_H
#define GENESIS_5_TEST_PARTICLEDIAGNOSTICS_H

#include "Particle.h"


template<typename T>
std::tuple<Particle<T>,Particle<T>> BeamMoments(std::vector<Particle<T>> &beam)
{
    Particle<T> par1,par2;
    double xpx,ypy;
    auto moments = [&par1,&par2](const Particle<T> &par){
        par1 +=par;
        par2 +=par*par;
    };
    std::ranges::for_each(beam, moments);
    T norm = 1.;
    if (beam.size() > 0) {norm = 1./static_cast<T>(beam.size());}
    par1 *= norm;
    par2 *= norm;
    par2.var2std(par1);

    return {par1,par2};
}


#endif //GENESIS_5_TEST_PARTICLEDIAGNOSTICS_H
