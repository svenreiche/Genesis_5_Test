//
// Created by reiche on 10/28/21.
//

#include <numeric>
#include <iostream>
#include "Beam.h"

bool Beam::allocate(std::vector<unsigned int> nsize) {

    nslice = nsize.size();
    current.resize(nslice);
    sliceidx.resize(nslice+1);      // one more element for pointing to the end of the record
    unsigned int totalsize = 0;
    for (int i = 0; i < nslice; i++){
        sliceidx[i] = totalsize;
        totalsize+= nsize[i];
    }
    sliceidx[nslice]=totalsize;
    beam.resize(totalsize);
    return true;
}

void Beam::release() {
    beam.clear();
    current.clear();
    sliceidx.clear();
    nslice = 0;
}