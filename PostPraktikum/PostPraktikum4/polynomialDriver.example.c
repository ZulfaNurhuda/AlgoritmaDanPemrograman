#include "polynomial.h"

int main() {
    Polynomial P1, P2;

    printf("Input P1:\n");
    printf("degree = ");
    ReadPolynomial(&P1);

    printf("Input P2:\n");
    printf("degree = ");
    ReadPolynomial(&P2);

    printf("P1: ");
    WritePolynomial(P1);

    printf("P2: ");
    WritePolynomial(P2);

    Polynomial sum = AddPolynomial(P1, P2);
    printf("P1 + P2: ");
    WritePolynomial(sum);

    Polynomial product = MultiplyPolynomial(P1, P2);
    printf("P1 * P2: ");
    WritePolynomial(product);

    Polynomial derivative = DerivativePolynomial(P1);
    printf("(d/dx) P1: ");
    WritePolynomial(derivative);

    Polynomial derivative2 = DerivativePolynomial(P2);
    printf("(d/dx) P2: ");
    WritePolynomial(derivative2);

    printf("P1(2) = %d\n", EvaluatePolynomial(P1, 2));
    printf("P2(2) = %d\n", EvaluatePolynomial(P2, 2));
}