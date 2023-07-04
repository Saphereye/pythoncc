#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <vector>

// vector<bool> is faster than vector<char> and bitset but takes more memory
std::vector<bool> sieve_of_eratosthenes(uint n) {
    uint sieve_size = n/2 - 1;
    std::vector<bool> output(sieve_size, true);

    for (uint i = 0; i < sieve_size; i++) {
        if (output[i]) {
            uint representative_number = (i + 1) * 2 + 1;
            uint representative_number_squared_index = (((representative_number * representative_number) - 1) / 2 - 1);
            for (uint j = representative_number_squared_index; j < sieve_size; j += representative_number) {
                output[j] = false;
            }
        }
    }

    return output;
}