#include <stdio.h>

int main() {
    const float PI = 3.1415;
    float r, luas;

    scanf("%f" , &r);

    luas = PI * r * r;

    printf("%f\n" , luas);
    
    return 0;
}