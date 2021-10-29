//
// Created by reiche on 10/27/21.
//

#ifndef GENESIS_5_TEST_HAMMERSLEY_H
#define GENESIS_5_TEST_HAMMERSLEY_H

#include <vector>

const std::vector<unsigned int> hammersley_bases= {2,3,5,7,11,13,17,19,23,29,
                    31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};

class Hammersley{
public:
    Hammersley() {
        ibase = hammersley_bases[0];
        base = static_cast<double>(ibase);
        idx = 0;
    };
    void set(unsigned int,  unsigned int);
    double getElement();
private:
    double base;
    unsigned int ibase, idx;
};

inline void Hammersley::set(unsigned int ibase_in,  unsigned int idx_in) {
    ibase = hammersley_bases[ibase_in];
    base = static_cast<double>(ibase);
    idx = idx_in;
};

#endif //GENESIS_5_TEST_HAMMERSLEY_H
