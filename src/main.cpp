#include<iostream>
#include<stdlib.h>

#include <cstddef>

#include "skiplists.hpp"
#include "benchmarker.hpp"

int main(){
    
    skiplists::BenchMarker benchMarker{};
    constexpr std::size_t numIterations = static_cast<std::size_t>(1e+7);
    benchMarker.runBenchMarks();

    return 0;
}
