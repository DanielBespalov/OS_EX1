#include <stdio.h>
#include <stdlib.h>
#include <math.h>


unsigned long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}


double poissonProbability(int k, double lambda) {
    return exp(-lambda) * pow(lambda, k) / factorial(k);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Error\n");
        return 1;
    }

    double lambda = atof(argv[1]);
    int k = atoi(argv[2]);

    double px = poissonProbability(k, lambda);

    printf("%.17lf\n", px);

    return 0;
}
