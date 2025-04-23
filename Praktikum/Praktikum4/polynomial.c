#include "polynomial.h"

void CreatePolynomial(Polynomial *P, int degree)
{
    P->degree = degree;
    for (int i = 0; i <= degree; i++)
    {
        P->coef[i] = 0;
    }
}

void ReadPolynomial(Polynomial *P)
{
    int degree;
    scanf("%d", &degree);
    CreatePolynomial(P, degree);
    for (int i = 0; i <= degree; i++)
    {
        scanf("%d", &P->coef[i]);
    }
}

void WritePolynomial(Polynomial P)
{
    int firstTerm = 1;

    if (P.degree == 0 && P.coef[0] == 0)
    {
        printf("0\n");
        return;
    }
    else if (P.degree == 0 && P.coef[0] != 0)
    {
        printf("%d\n", P.coef[0]);
        return;
    }

    for (int i = P.degree; i >= 0; i--)
    {
        int coefficient = P.coef[i];
        int absCoefficient = abs(coefficient);

        if (coefficient == 0)
        {
            continue;
        }

        if (firstTerm && coefficient < 0)
        {
            printf("-");
        }
        else if (i < P.degree && coefficient > 0)
        {
            printf(" + ");
        }
        else if (i < P.degree && coefficient < 0)
        {
            printf(" - ");
        }

        if (i == 0)
        {
            printf("%d", absCoefficient);
        }
        else if (i == 1)
        {
            if (absCoefficient == 1)
            {
                printf("x");
            }
            else
            {
                printf("%dx", absCoefficient);
            }
        }
        else
        {
            if (absCoefficient == 1)
            {
                printf("x^%d", i);
            }
            else
            {
                printf("%dx^%d", absCoefficient, i);
            }
        }

        firstTerm = 0;
    }
    printf("\n");
}

Polynomial AddPolynomial(Polynomial P1, Polynomial P2)
{
    Polynomial result;
    int maxDegree = (P1.degree > P2.degree) ? P1.degree : P2.degree;
    CreatePolynomial(&result, maxDegree);

    for (int i = 0; i <= maxDegree; i++)
    {
        int coef1 = (i <= P1.degree) ? P1.coef[i] : 0;
        int coef2 = (i <= P2.degree) ? P2.coef[i] : 0;
        result.coef[i] = coef1 + coef2;
    }

    return result;
}

Polynomial MultiplyPolynomial(Polynomial P1, Polynomial P2)
{
    Polynomial result;
    CreatePolynomial(&result, P1.degree + P2.degree);

    for (int i = 0; i <= P1.degree; i++)
    {
        for (int j = 0; j <= P2.degree; j++)
        {
            result.coef[i + j] += P1.coef[i] * P2.coef[j];
        }
    }

    return result;
}

int EvaluatePolynomial(Polynomial P, int x)
{
    int result = 0;
    int power = 1;
    for (int i = 0; i <= P.degree; i++)
    {
        result += P.coef[i] * power;
        power *= x;
    }
    return result;
}

Polynomial DerivativePolynomial(Polynomial P)
{
    Polynomial result;
    if (P.degree == 0)
    {
        CreatePolynomial(&result, 0);
        result.coef[0] = 0;
        return result;
    }

    CreatePolynomial(&result, P.degree - 1);
    for (int i = 1; i <= P.degree; i++)
    {
        result.coef[i - 1] = i * P.coef[i];
    }

    return result;
}