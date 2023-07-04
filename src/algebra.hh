#pragma once

#include <pybind11/pybind11.h>

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

std::tuple<int, int, int> extended_gcd(int a, int b) {
    int x = 1;
    int y = 0;

    int x1 = 0, y1 = 1, a1 = a, b1 = b;

    while (b1) {
        int q = a1 / b1;
        std::tie(x, x1) = std::make_tuple(x1, x - q * x1);
        std::tie(y, y1) = std::make_tuple(y1, y - q * y1);
        std::tie(a1, b1) = std::make_tuple(b1, a1 - q * b1);
    }

    return std::tie(a1, x, y);
}

std::tuple<bool, int, int> linear_diophantine_equation(int a, int b, int c) {
    std::tuple<int, int, int> result = extended_gcd(a, b);
    int gcd = std::get<0>(result);

    if (c % gcd) {
        return std::tuple<bool, int, int>(false, 0, 0);
    }

    int x0 = std::get<1>(result);
    int y0 = std::get<2>(result);

    x0 *= c/gcd;
    y0 *= c/gcd;

    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;

    return std::tuple<bool, int, int>(true, x0, y0);
}