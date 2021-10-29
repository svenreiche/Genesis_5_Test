//
// Created by reiche on 10/27/21.
//
#include <cmath>
#ifndef GENESIS_5_TEST_PARTICLE_H
#define GENESIS_5_TEST_PARTICLE_H

template<typename T>   // template to optimize memory consumption (either float or double)
struct Particle{
    T gamma = 0.;        // energy in units of mc^2
    T theta = 0.;        // longitudinal position in units in units of 2 pi /lambda_ref
    T x = 0.;            // transverse position in x in units of m
    T y = 0.;            // transverse position in y in units of m
    T px = 0.;           // transverse momentum in x in units of mc
    T py = 0.;            // transverse momentum in y in units of mc

    void var2std(const Particle<T> mean){
        gamma = sqrt(fabs(gamma-mean.gamma*mean.gamma));
        theta = sqrt(fabs(theta-mean.theta*mean.theta));
        x = sqrt(fabs(x-mean.x*mean.x));
        y = sqrt(fabs(y-mean.y*mean.y));
        px = sqrt(fabs(px-mean.px*mean.px));
        py = sqrt(fabs(py-mean.py*mean.py));
    }

    void inv(){
        if (gamma == 0) { gamma = 0;} else { gamma = 1./gamma;}
        if (theta == 0) { theta = 0;} else { theta = 1./theta;}
        if (x == 0) { x = 0;} else { x = 1./x;}
        if (y == 0) { y = 0;} else { y = 1./y;}
        if (px == 0) { px = 0;} else { px = 1./px;}
        if (py == 0) { py = 0;} else { py = 1./py;}
    }

    // overloading functions

    friend Particle<T> operator*(const Particle<T>& par1, const Particle<T>& par2){
        Particle<T> par = { par1.gamma*par2.gamma,
                            par1.theta*par2.theta,
                            par1.x*par2.x,
                            par1.y*par2.y,
                            par1.px*par2.px,
                            par1.px*par2.py};
        return par;
    };

    Particle<T> operator*=(const Particle<T>& par){
        this->gamma *= par.gamma;
        this->theta *= par.theta;
        this->x *= par.x;
        this->y *= par.y;
        this->px *= par.px;
        this->py *= par.py;
        return std::move(*this);
    };

    Particle<T> operator*=(const T par){
        this->gamma *= par;
        this->theta *= par;
        this->x *= par;
        this->y *= par;
        this->px *= par;
        this->py *= par;
        return std::move(*this);
    };

    Particle<T> operator+=(const Particle<T>& par){
        this->gamma += par.gamma;
        this->theta += par.theta;
        this->x += par.x;
        this->y += par.y;
        this->px += par.px;
        this->py += par.py;
        return std::move(*this);
    };

    Particle<T> operator-=(const Particle<T>& par){
        this->gamma -= par.gamma;
        this->theta -= par.theta;
        this->x -= par.x;
        this->y -= par.y;
        this->px -= par.px;
        this->py -= par.py;
        return std::move(*this);
    };

};


#endif //GENESIS_5_TEST_PARTICLE_H
