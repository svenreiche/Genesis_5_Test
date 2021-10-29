//
// Created by reiche on 10/28/21.
//

#include <cmath>
#include "Time.h"
#include <iostream>

bool Time::init(double s0_in, double slen_in, double ds_in, int mpi_size, int mpi_rank){
    // check if the time window has been initialized before
    if (nslice > 0) {
        if (mpi_rank==0){ std::cout << "*** Error: Reinitialization of time window not allowed.\n";}
        return false;
    }

    s0 = s0_in;
    slen = slen_in;
    ds = ds_in;

    // adjusting length to have samek block size for all ranks
    nslice=static_cast<int> (round(slen/ds));
    if (nslice < mpi_size) { nslice = mpi_size ; }

    nblock=nslice/mpi_size;
    if ((nslice % mpi_size)!=0) {nblock++;}
    nslice=nblock*mpi_size;
    n0 = nblock*mpi_rank;

    // needs to adjust the time window
    slen=ds*nslice;

    if (mpi_rank==0){std::cout << "Setting up time window of " << slen*1e6 << " microns with " << nslice <<" sample points...\n";}

    return true;

}

