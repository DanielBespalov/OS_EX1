#include <stdio.h>
#include <stdlib.h>

// Function to generate random numbers
void generateRandomNumbers(int seed, int size, int array[]) {
    srand(seed);
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100 - seed; 
    } 
}

// Solution 1: O(n) Kadane's Algorithm
int maxSubArraySum1(int array[], int size) {
    int max_so_far = array[0];
    int max_ending_here = array[0];

    for (int i = 1; i < size; i++) {
        max_ending_here = (array[i] > max_ending_here + array[i]) ? array[i] : max_ending_here + array[i];
        max_so_far = (max_so_far > max_ending_here) ? max_so_far : max_ending_here;
    }

    return max_so_far;
}

// Solution 2: O(n^2) Brute Force
int maxSubArraySum2(int array[], int size) {
    int max_sum = array[0];
    for (int i = 0; i < size; i++) {
        int current_sum = 0;
        for (int j = i; j < size; j++) {
            current_sum += array[j];
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
        }
    }
    return max_sum;
}

// Solution 3: O(n^3) Brute Force
int maxSubArraySum3(int array[], int size) {
    int max_sum = array[0];
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            int current_sum = 0;
            for (int k = i; k <= j; k++) {
                current_sum += array[k];
            }
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
        }
    }
    return max_sum;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <seed> <size>\n", argv[0]);
        return 1;
    }

    int seed = atoi(argv[1]);
    int size = atoi(argv[2]);

    int *array = malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return 0;
    }

    generateRandomNumbers(seed, size, array);
    
    // Solution 1
    int max1 = maxSubArraySum1(array, size);
    // Solution 2
    int max2 = maxSubArraySum2(array, size);
    // Solution 3
    int max3 = maxSubArraySum3(array, size);
    free(array);

    return 0;
}
