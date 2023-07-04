#include <pybind11/pybind11.h>

#include "algebra.hh"
#include "prime.hh"

namespace py = pybind11;

PYBIND11_MODULE(pythoncc, handle) {
    handle.doc() = "This is the doc";
    handle.def(
        "binary_exponentiation",
        &binary_exponentiation,
        "Caclculates the power of number using recursive formula",
        py::arg("number"),
        py::arg("power"));

    handle.def(
        "gcd",
        &gcd,
        "Caclculates the gcd of two number using modulo method");

    handle.def(
        "binary_gcd",
        &binary_gcd,
        "Caclculates the gcd of two number using binary method");

    handle.def(
        "extended_gcd",
        &extended_gcd,
        "Caclculates the gcd of two numbers(a, b) and return the gcd, x, and y where ax+by=gcd(a, b)");

    handle.def(
        "linear_diophantine_equation",
        &linear_diophantine_equation,
        "Gives one solution of the equation ax+by=c as (true, x, y) or gives (false, 0, 0) with input (a, b, c)");

    handle.def(
        "sieve_of_eratosthenes",
        &sieve_of_eratosthenes,
        "Returns the sieve for range [0, n) but only the odd numbers for input n, e.g for 10, we get the is prime values for [3, 5, 7, 9] as a list [true, true, true, false]");
}
