//
// Created by reiche on 10/28/21.
//
#include <map>
#include <iostream>
#include <string>
#include <any>

#ifndef GENESIS_5_TEST_PROFILEBEAM_H
#define GENESIS_5_TEST_PROFILEBEAM_H

#include "../Core/Beam.h"

void loadBeam(Beam& beam){

    std::map<std::string, std::any> my_map;


//    auto lambda = [s0=60e-6,c=30e-6](auto s) { return (s-s0)*(s-s0)/c/c; };
//    std::map<std::string, std::any> my_map;
    my_map["gamma"] =  std::function<double(double)>([s0=60e-6,c=30e-6](double s) { return (s-s0)*(s-s0)/c/c; });
//    my_map["gamma"] =  std::function<double(double)>([](double s) { return 2.*s; });

    std::cout << std::any_cast<std::function<double(double)>>(my_map["gamma"])(31e-6) << std::endl;
//    std::cout << std::any_cast<doub>(my_map["gamma"])(60e-6) << std::endl;
//    std::cout << std::any_cast<double>(my_map["gamma"])(120e-6) << std::endl;
}




#endif //GENESIS_5_TEST_PROFILEBEAM_H
