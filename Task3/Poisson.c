#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long long factorial(int n) __attribute__((visibility("default")));
unsigned long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

long double poissonProbability(int k, long double lambda) __attribute__((visibility("default")));
long double poissonProbability(int k, long double lambda) {
    return expl(-lambda) * powl(lambda, k) / factorial(k);
}
