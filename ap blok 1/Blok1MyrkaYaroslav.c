#include <stdio.h>
#include <float.h>
#include <math.h>

void uloha1(int a) {
    int bin[32];
    int i = 0;

    while (a != 0) {
        bin[i] = a % 2;
        a = a / 2;
        ++i;
    }

    --i;

    for (i; i >= 0; --i) {
        printf("%d",bin[i]);
    }
    printf("\n");
}

void uloha3(int a) {
    int i = 0;
    int c = 0;

    while (a != 0) {
        if (a % 2 == 1){
            ++c;
        }
        a = a / 2;
        ++i;
    }

    --i;
    printf("%d\n", c);
}

void uloha4float() {
    float epsilonf = 1.0;
    float sumf = 2.0;

    while (sumf > 1.0) {
        epsilonf /= 2.0;
        sumf = 1.0 + epsilonf / 2.0;

    }
    printf("Calculated float epsilon: %e\n", epsilonf);
    printf("FLT_EPSILON from float.h: %e\n", FLT_EPSILON);

    double epsilond = 1.0;
    double sumd = 2.0;

    while (sumd > 1.0) {
        epsilond /= 2.0;
        sumd = 1.0 + epsilond / 2.0;
    }
    printf("Calculated double epsilon: %e\n", epsilond);
    printf("DBL_EPSILON from float.h:  %e\n", DBL_EPSILON);
}

float fact(int n) {
    float fact = 1;
    int flag;

    for (flag = 1; flag <= n; flag++){
        fact *= flag;
    }

    return fact;
}

float uloha5_cos(float radians, float epsilon) {
    float res = 1.0f;
    float term = 1.0f;

    int n = 1;

    while (term > epsilon) {
        term = pow(radians, 2*n) / (fact(2 * n));


        if (n % 2 == 0) {
            res += term;
        } else {
            res -= term;
        }
        n++;
    }

    return res;
}

int main() {
    int cislo = 209;
    char znak = 'X';

    printf("%d\n", cislo);
    uloha1(cislo);
    printf("%X\n", cislo);

    printf("%c\n", znak);
    printf("%d\n", znak);
    printf("%X\n", znak);

    return 0;
}