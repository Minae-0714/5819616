#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {
    int sum = 0;
    int prime;

    for (int num = 2; num <= 100; num++) {
        prime = 1;

        for (int j = 2; j <= num / 2; j++) {
            if (num % j == 0) {
                prime = 0;
                break;
            }
        }

        if (prime == 1) {
            sum += num;
        }
    }

    printf("Sum : %d\n", sum);
}