//
// Created by reiche on 10/27/21.
//

#include "Particle.h"

#ifndef GENESIS_5_TEST_PARTICLETRACKING_H
#define GENESIS_5_TEST_PARTICLETRACKING_H


template<typename T>
void TrackDrift(Particle<T> &par, auto dz){
    auto tmp = dz/ par.gamma;
    par.x += par.px*tmp;
    par.y += par.py*tmp;
}




#endif //GENESIS_5_TEST_PARTICLETRACKING_H
