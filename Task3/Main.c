#include <stdio.h>

// Declare the function prototype
long double poissonProbability(int k, long double lambda);

int main() {
    struct {
        long double lambda;
        int k;
    } test_cases[] = {
        {2.0, 1},
        {2.0, 10},
        {2.0, 2},
        {3.0, 3},
        {100.0, 3}
    };

    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < num_cases; i++) {
        long double lambda = test_cases[i].lambda;
        int k = test_cases[i].k;
        long double result = poissonProbability(k, lambda);

        printf("P(X = %d, lambda = %.1Lf) = %.17Lf\n", k, lambda, result);
    }

    return 0;
}
