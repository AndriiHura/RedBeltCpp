cmake_minimum_required(VERSION 3.17)
project(PrinciplesOfCodeOptimization)
project(PrinciplesOfCodeOptimization1)
project(PrinciplesOfCodeOptimization2)


set(CMAKE_CXX_STANDARD 17)

add_executable(PrinciplesOfCodeOptimization 1_2ndRuleOfCodeOptimiation.cpp profile.h)
add_executable(PrinciplesOfCodeOptimization1  2_ImplementingOwnProfiler.cpp profile.h)
add_executable(PrinciplesOfCodeOptimization2  3_ImprovingProfiler.cpp profile.h)
