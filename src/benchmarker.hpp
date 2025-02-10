#ifndef BENCHMARKER_HPP
#define BENCHMARKER_HPP

#include <cstddef>
#include <cstdlib>
#include <chrono>
#include <iostream>
#include <fstream>
#include <cmath>
#include <map>
#include <memory>

#include "skiplists.hpp"

namespace skiplists {
    
class BenchMarker {

    public:

    constexpr static const char * const fileOutName = "benchmarks_search_map_results.csv";

    std::ofstream outFile;

    BenchMarker():  outFile{fileOutName} {
        outFile << "operation,duration (ns),n,average (ns/n)" << "\n";
    }

    constexpr void writeRunTimeDurations(const char * const operationName, const double duration, const std::size_t n) {
        outFile << operationName << "," << duration << ","<< n << "," << static_cast<double>(duration / n)  << "\n";
    }

    constexpr void runInsertAndTime(const std::size_t numIterations){
        skiplists::SkipList skiplists{};
        const auto timeStart = std::chrono::high_resolution_clock::now();
        for (std::size_t i = 0; i < numIterations; i++){
            const int key = rand();
            skiplists.insert(key);
        }
        const auto timeEnd = std::chrono::high_resolution_clock::now();
        const auto durations = std::chrono::duration_cast<std::chrono::nanoseconds>(timeEnd - timeStart).count();
        writeRunTimeDurations("insertion", durations, numIterations);
    }

    constexpr void runInsertMapAndTime(const std::size_t numIterations){
        std::map<int,int> map{};
        const auto timeStart = std::chrono::high_resolution_clock::now();
        for (std::size_t i = 0; i < numIterations; i++){
            const int key = rand();
            map.insert({key,key});
        }
        const auto timeEnd = std::chrono::high_resolution_clock::now();
        const auto durations = std::chrono::duration_cast<std::chrono::nanoseconds>(timeEnd - timeStart).count();
        writeRunTimeDurations("insertion", durations, numIterations);
    }

    constexpr void runInsertBenchmarks(void){
        constexpr std::size_t numTests = 7;
        std::size_t currentItersNum = 10;
        for (std::size_t i = 0; i < numTests; i++){
            std::cerr << "running with n = " << currentItersNum << std::endl;
            runInsertAndTime(currentItersNum);
            currentItersNum *= 10;
        }
    }

    constexpr void runInsertMapBenchmarks(void){
        constexpr std::size_t numTests = 7;
        std::size_t currentItersNum = 10;
        for (std::size_t i = 0; i < numTests; i++){
            std::cerr << "running with n = " << currentItersNum << std::endl;
            runInsertMapAndTime(currentItersNum);
            currentItersNum *= 10;
        }
    }

    constexpr std::unique_ptr<std::vector<int>> getRandomKeys(const std::size_t num) const {
        std::unique_ptr<std::vector<int>> vec = std::make_unique<std::vector<int>>();
        for (std::size_t i = 0; i < num; i++){
            (*vec).push_back(rand());
        }
        return vec;
    }

    constexpr void runRemoveAndTime(const std::size_t numIterations){
        skiplists::SkipList skiplists{};
        const auto vec = getRandomKeys(numIterations);
        for (const auto & key : (*vec)){
            skiplists.insert(key);
        }
        const auto timeStart = std::chrono::high_resolution_clock::now();
        for (const auto & key : (*vec)){
            // const int key = rand();
            skiplists.remove(key);
        }
        const auto timeEnd = std::chrono::high_resolution_clock::now();
        const auto durations = std::chrono::duration_cast<std::chrono::nanoseconds>(timeEnd - timeStart).count();
        writeRunTimeDurations("remove", durations, numIterations);
    }

    constexpr void runRemoveMapAndTime(const std::size_t numIterations){
        std::map<int,int> skiplists{};
        const auto vec = getRandomKeys(numIterations);
        for (const auto & key : (*vec)){
            skiplists.insert({key,key});
        }
        const auto timeStart = std::chrono::high_resolution_clock::now();
        for (const auto & key : (*vec)){
            // const int key = rand();
            skiplists.erase(key);
        }
        const auto timeEnd = std::chrono::high_resolution_clock::now();
        const auto durations = std::chrono::duration_cast<std::chrono::nanoseconds>(timeEnd - timeStart).count();
        writeRunTimeDurations("remove", durations, numIterations);
    }

    constexpr void runRemoveBenchmarks(void){
        constexpr std::size_t numTests = 7;
        std::size_t currentItersNum = 10;
        for (std::size_t i = 0; i < numTests; i++){
            std::cerr << "running with n = " << currentItersNum << std::endl;
            runRemoveAndTime(currentItersNum);
            currentItersNum *= 10;
        }
    }

    constexpr void runRemoveMapBenchmarks(void){
        constexpr std::size_t numTests = 7;
        std::size_t currentItersNum = 10;
        for (std::size_t i = 0; i < numTests; i++){
            std::cerr << "running with n = " << currentItersNum << std::endl;
            runRemoveMapAndTime(currentItersNum);
            currentItersNum *= 10;
        }
    }

    constexpr void runSearchAndTime(const std::size_t numIterations){
        skiplists::SkipList skiplists{};
        const auto vec = getRandomKeys(numIterations);
        for (const auto & key : (*vec)){
            skiplists.insert(key);
        }
        const auto timeStart = std::chrono::high_resolution_clock::now();
        for (const auto & key : (*vec)){
            // const int key = rand();
            skiplists.search(key);
        }
        const auto timeEnd = std::chrono::high_resolution_clock::now();
        const auto durations = std::chrono::duration_cast<std::chrono::nanoseconds>(timeEnd - timeStart).count();
        writeRunTimeDurations("search", durations, numIterations);
    }

    constexpr void runSearchMapAndTime(const std::size_t numIterations){
        std::map<int,int> skiplists{};
        const auto vec = getRandomKeys(numIterations);
        for (const auto & key : (*vec)){
            skiplists.insert({key,key});
        }
        const auto timeStart = std::chrono::high_resolution_clock::now();
        for (const auto & key : (*vec)){
            // const int key = rand();
            skiplists.contains(key);
        }
        const auto timeEnd = std::chrono::high_resolution_clock::now();
        const auto durations = std::chrono::duration_cast<std::chrono::nanoseconds>(timeEnd - timeStart).count();
        writeRunTimeDurations("search", durations, numIterations);
    }

    constexpr void runSearchBenchmarks(void){
        constexpr std::size_t numTests = 7;
        std::size_t currentItersNum = 10;
        for (std::size_t i = 0; i < numTests; i++){
            std::cerr << "running with n = " << currentItersNum << std::endl;
            runSearchAndTime(currentItersNum);
            currentItersNum *= 10;
        }
    }

    constexpr void runSearchMapBenchmarks(void){
        constexpr std::size_t numTests = 7;
        std::size_t currentItersNum = 10;
        for (std::size_t i = 0; i < numTests; i++){
            std::cerr << "running with n = " << currentItersNum << std::endl;
            runSearchMapAndTime(currentItersNum);
            currentItersNum *= 10;
        }
    }

    constexpr void runBenchMarks(void){
        // runInsertBenchmarks();
        // runInsertMapBenchmarks();
        // runRemoveBenchmarks();
        // runRemoveMapBenchmarks();
        // runSearchBenchmarks();
        runSearchMapBenchmarks();
    }

};


} // namespace skiplists


#endif // BENCHMARKER_HPP
