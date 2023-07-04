#pragma once

#include <pybind11/pybind11.h>

#include <iostream>
#include <numeric>

unsigned long long binary_exponentiation(unsigned long long x, unsigned long long y) {
    unsigned long long res = 1;
    while (y > 0) {
        if (y & 1)
            res = res * x;
        x = x * x;
        y >>= 1;
    }
    return res;
};

long long gcd(long long x, long long y) {
    while (y) {
        x %= y;
        std::swap(x, y);
    }

    return x;
}

long long binary_gcd(long long x, long long y) {
    if (!x || !y)
        return x | y;
    unsigned shift = __builtin_ctz(x | y);
    x >>= __builtin_ctz(x);
    do {
        y >>= __builtin_ctz(y);
        if (x > y)
            std::swap(x, y);
        y -= x;
    } while (y);
    return x << shift;
}