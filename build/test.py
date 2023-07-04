import pythoncc as cc
import unittest
from random import *
from math import *

class AlebraTest(unittest.TestCase):
    def test_binary_exponentiation(self):
        for i in range(100):
            i = randint(1, 10)
            j = randint(1, 10)
            self.assertEqual(cc.binary_exponentiation(i, j), i**j)
    
    def test_gcd(self):
        for i in range(100):
            i = randint(1, 500)
            j = randint(1, 500)
            self.assertEqual(cc.gcd(i, j), gcd(i, j))
    
    def test_binary_gcd(self):
        for i in range(100):
            i = randint(1, 500)
            j = randint(1, 500)
            self.assertEqual(cc.binary_gcd(i, j), gcd(i, j))

if __name__ == '__main__':
    unittest.main()