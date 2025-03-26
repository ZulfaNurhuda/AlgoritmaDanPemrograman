#include <stdio.h>

float Max2(float a, float b) {
    return (a >= b) ? a : b;
}

float Max3(float a, float b, float c) {
    return Max2(a, Max2(b, c));
}

int main() {
    printf("Max2(1, 2) = %.2f\n", Max2(1, 2));
    printf("Max3(1, 2, 3) = %.2f\n", Max3(1, 2, 3));
    return 0;
}