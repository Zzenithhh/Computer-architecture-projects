#include <stdio.h>
#include <math.h>

float fact(int n) {
    float fact = 1;
    int flag;

    for (flag = 1; flag <= n; flag++){
        fact *= flag;
    }

    return fact;
}

float my_cos(float radians, float epsilon) {
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
    printf("%f", my_cos(M_PI/6, 0.000000001) );
    return 0;
}