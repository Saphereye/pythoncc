import pythoncc as cc
import unittest
from random import *
from math import *

class AlebraTest(unittest.TestCase):
    def test_binary_exponentiation(self):
        for _ in range(100):
            i = randint(1, 10)
            j = randint(1, 10)
            self.assertEqual(cc.binary_exponentiation(i, j), i**j)
    
    def test_gcd(self):
        for _ in range(100):
            i = randint(1, 500)
            j = randint(1, 500)
            self.assertEqual(cc.gcd(i, j), gcd(i, j))
    
    def test_binary_gcd(self):
        for _ in range(100):
            i = randint(1, 500)
            j = randint(1, 500)
            self.assertEqual(cc.binary_gcd(i, j), gcd(i, j))
    
    def test_extended_gcd(self):
        self.assertEqual(cc.extended_gcd(10, 5), (5, 0, 1))
    
    def test_linear_diophantine_equation(self):
        for _ in range(100):
            a = randint(1, 500)
            b = randint(1, 500)
            c = randint(1, 500)
            soln = cc.linear_diophantine_equation(a, b, c)
            if soln[0]:
                self.assertEqual(soln[1]*a + soln[2]*b, c)

if __name__ == '__main__':
    unittest.main()