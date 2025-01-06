// ********************************************************
// * Sieve Class                                          *
// * Description: Manages a class called Sieve that       *
// *    produces a list of prime numbers up to a maximum  *
// *    value.  Created for the COP330 course as an       *
// *    assignment.  Publishing any solution of this      *
// *    problem violates copyright laws.                  *
// * Date: December 24th, 2023                            *
// * Author: Dr. David A. Gaitros                         *
// ********************************************************
//

#ifndef SIEVE_SIEVE_H
#define SIEVE_SIEVE_H
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const int DEFAULTMAXPRIME=1103;

class Sieve {
public:
    Sieve();                    // Default Constructor
    ~Sieve();                   // Destructor
    Sieve(const int s);         // One parameter Constructor
    void ReSet(const int s);    // Reset prime number list to maximum of s
    bool IsPrime(const int s);  // Returns true if s is a prime number
    void Print(ostream & os);   // Print all prime numbers up to the lastnumber;
private:
    void GeneratePrimes();      // Private function that generates the prime
                                //    numbers up to the lastnumber value.
    bool * bvect;               // Boolean array.  Each index is set to true if that
                                //    index value is a prime number.. 2,3,5, 7 would be
                                //    turned on as true;
    int lastnumber;             // The highest value checked to be a prime number.
                                //    May or may not be a prime.

};
ostream & operator <<(ostream & os, Sieve & s);
#endif