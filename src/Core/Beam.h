//
// Created by reiche on 10/28/21.
//

#include <vector>

#ifndef GENESIS_5_TEST_BEAM_H
#define GENESIS_5_TEST_BEAM_H

#include "Particle.h"

class Beam {
    public:
        bool allocate(const std::vector<unsigned int> nsize);
        void release();

        std::vector<Particle<double>> beam; // holding the beam distribution
        std::vector<double> current;        // current profile
        std::vector<unsigned int> sliceidx;   // indexing of the slice pointing to the first start element in beam
    private:
        unsigned long nslice;
};



#endif //GENESIS_5_TEST_BEAM_H
