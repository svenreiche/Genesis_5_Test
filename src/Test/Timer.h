//
// Created by reiche on 10/27/21.
//

#ifndef GENESIS_5_TEST_TIMER_H
#define GENESIS_5_TEST_TIMER_H

#include <iostream>
#include <chrono>
#include <thread>
#include <assert.h>

using namespace std::chrono_literals;

template <class TimeT = std::chrono::milliseconds,
        class ClockT = std::chrono::steady_clock>
class Timer
{
    using timep_t = decltype(ClockT::now());

    timep_t _start = ClockT::now();
    timep_t _end = {};

public:
    void tick() {
        _end = timep_t{};
        _start = ClockT::now();
    }

    void tock() {
        _end = ClockT::now();
    }

    template <class TT = TimeT>
    TT duration() const {
        // Use gsl_Expects if your project supports it.
        assert(_end != timep_t{} && "Timer must toc before reading the time");
        return std::chrono::duration_cast<TT>(_end - _start);
    }
};
#endif //GENESIS_5_TEST_TIMER_H
