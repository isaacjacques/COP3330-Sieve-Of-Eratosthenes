#include "sieve.h"


// *****************************************************************
// * Function Name: Sieve
// * Description: Default Constructor
// * sets the last number to DEFAULTMAXPRIME and generates primes
// * Parameter Description: 
// * Date: 10-04-24
// * Author: Isaac Jacques
// * References: GeneratePrimes 
// ***************************************************************** 
Sieve::Sieve() {
    lastnumber = DEFAULTMAXPRIME;
    bvect = new bool[lastnumber + 1];
    GeneratePrimes();
}

// *****************************************************************
// * Function Name: Sieve
// * Description: Destructor
// * cleans up allocated memory
// * Parameter Description: 
// * Date: 10-04-24
// * Author: Isaac Jacques
// * References:  
// ***************************************************************** 
Sieve::~Sieve() {
    delete[] bvect;
}

// *****************************************************************
// * Function Name: Sieve [overload]
// * Description: One parameter Constructor
// * generates primes up to last number provided
// * Parameter Description: int s=lastnumber for prime generation
// * Date: 10-04-24
// * Author: Isaac Jacques
// * References: GeneratePrimes 
// ***************************************************************** 
Sieve::Sieve(const int s) {
    if (s < 2) {
        lastnumber = DEFAULTMAXPRIME;
    } else {
        lastnumber = s;
    }
    bvect = new bool[lastnumber + 1];
    GeneratePrimes();
}

// *****************************************************************
// * Function Name: ReSet
// * Description: Reset prime number list to maximum of s
// * Parameter Description: int s=lastnumber for prime generation
// * Date: 10-04-24
// * Author: Isaac Jacques
// * References:  GeneratePrimes
// ***************************************************************** 
void Sieve::ReSet(const int s) {
    delete[] bvect;
    if (s < 2) {
        lastnumber = DEFAULTMAXPRIME;
    } else {
        lastnumber = s;
    }
    bvect = new bool[lastnumber + 1];  
    GeneratePrimes();
}

// *****************************************************************
// * Function Name: IsPrime
// * Description: Returns true if s is a prime number
// * Parameter Description: int s= value to check if prime
// * Date: 10-04-24
// * Author: Isaac Jacques
// * References:  
// ***************************************************************** 
bool Sieve::IsPrime(const int s) {
    if (s < 2 || s > lastnumber) {
        return false;
    }
    return bvect[s];
}

// *****************************************************************
// * Function Name: GeneratePrimes
// * Description: Impliments the Sieve of Eratosthenes to find prime numbers
// * Parameter Description:
// * Date: 10-04-24
// * Author: Isaac Jacques
// * References: https://www.geeksforgeeks.org/sieve-of-eratosthenes/
// ***************************************************************** 
void Sieve::GeneratePrimes() {
    // Initialize all numbers as potential primes
    for (int i = 0; i <= lastnumber; i++) {
        bvect[i] = true;
    }
    // 0 and 1 are not prime
    bvect[0] = false;
    bvect[1] = false;

    // Apply the Sieve of Eratosthenes
    int sqrtLimit = (int)std::sqrt(lastnumber);
    for (int i = 2; i <= sqrtLimit; i++) {
        if (bvect[i]) {
            for (int j = i * i; j <= lastnumber; j += i) {
                bvect[j] = false;  
            }
        }
    }
}

// *****************************************************************
// * Function Name: Print
// * Description: Print all prime numbers up to the lastnumber
// * Parameter Description: 
// *    os= output stream object reference
// * Date: 10-04-24
// * Author: Isaac Jacques
// * References:  
// ***************************************************************** 
void Sieve::Print(ostream & os) {
    os << "Last number in Print is " << lastnumber;
    for (int i = 2; i <= lastnumber; i++) {
        if (bvect[i]) {
            os << endl << "    " << i << " Is Prime";
        }
    }
}

// *****************************************************************
// * Function Name: operator << [overload]
// * Description: Calls the Print function to output primes
// * Parameter Description: 
// *    os= output stream object reference
// *    s= Sieve object references
// * Date: 10-04-24
// * Author: Isaac Jacques
// * References:  
// ***************************************************************** 
ostream & operator <<(ostream & os, Sieve & s) {
    s.Print(os);
    return os;
}
