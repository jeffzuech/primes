/**************************************************************************
 * primes.c 
 *
 * AUTHOR: Jeff Zuech
 * DATE:   8/20/15
 * DESCRIPTION:
 * 
 * Given N, this program calculates the Nth prime number.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>

void usage()
{
    printf("Usage: \n");
    printf("primes n (where n is the Nth prime number between 1 and %ld)\n",
            LONG_MAX);
}

/**************************************************************************
 *  calculate_prime
 *
 *  Inputs:
 *  n - the prime number to calculate
 *
 *  Returns;
 *  the Nth prime number
 *
 */
unsigned long calculate_prime(long n)
{
    /* A dynamic array to store calculated primes, */
    unsigned long *primes;
    unsigned long pp = 2, nth_prime;
    long i, count = 0;
    int prime_flag;
    double sqrtpp;

    primes = (unsigned long *) malloc(sizeof(unsigned long) * n);
    
    if (!primes) {
        printf("calculate_prime: malloc failed!\n");
        return 0;
    }

    primes[count++] = pp++; /* add 2 to the prime array */

    while (count < n) {
        prime_flag = 1;

        /* To be efficient we only need to test a number for prime */
        /* by seeing if it can be factored by an primes less than */
        /* the square root of a number. */
        sqrtpp = sqrt((double) pp);
        for (i = 0; prime_flag && primes[i] <= sqrtpp; i++) {
            if (pp % primes[i] == 0)
                prime_flag = 0;
        }

        if (prime_flag)
            primes[count++] = pp;

        /* Since prime numbers after 2 are odd, we only */
        /* need to test odd numbers as potental primes. */
        pp += 2; 
    }

#define DEBUG
#ifdef DEBUG
    for (i = 0; i < n; i++)
        printf("%ld:  %ld\n", i, primes[i]);
#endif
    
    nth_prime = primes[count - 1];
    free(primes);
    
    return nth_prime;
}


int main(int argc, char *argv[])
{
    long n;

    /* make sure command line argument is entered */
    if (argc != 2) {
        usage();
        return 1;
    }

    n = atol(argv[1]);

    /* range check on the command line input */
    if (n < 1 || n >= LONG_MAX) {
        usage();
        return 1;
    }

    printf("Prime number %ld is %ld\n", n,  calculate_prime(n));

    return 0;
}
