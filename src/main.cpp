#include <pybind11/pybind11.h>

#include "algebra.hh"

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
        "Caclculates the gcd of two number using modulo method",
        py::arg("x"),
        py::arg("y"));

    handle.def(
        "binary_gcd",
        &binary_gcd,
        "Caclculates the gcd of two number using binary method",
        py::arg("x"),
        py::arg("y"));
}
