//
// Created by reiche on 10/28/21.
//

#ifndef GENESIS_5_TEST_TIME_H
#define GENESIS_5_TEST_TIME_H

#include <vector>
#include <ranges>


class Time {
public:
    bool init(double, double, double, int, int);
public:
    double s0,slen,ds;        // starting point, window length, sample length
    unsigned int n0, nblock;
    unsigned int nslice = 0;   // total slices - for valid simulation it must be at least 1
};


#endif //GENESIS_5_TEST_TIME_H
