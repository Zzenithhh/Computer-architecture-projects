#include <stdio.h>
#include <float.h>

void calculate_float_epsilon() {
    float epsilon = 1.0;
    float sum = 2.0;

    while (sum > 1.0) {
        epsilon /= 2.0;
        sum = 1.0 + epsilon / 2.0;

    }
    printf("Calculated float epsilon: %e\n", epsilon);
    printf("FLT_EPSILON from float.h: %e\n", FLT_EPSILON);
}

void calculate_double_epsilon() {
    double epsilon = 1.0;
    double sum = 2.0;

    while (sum > 1.0) {
        epsilon /= 2.0;
        sum = 1.0 + epsilon / 2.0;
    }
    printf("Calculated double epsilon: %e\n", epsilon);
    printf("DBL_EPSILON from float.h:  %e\n", DBL_EPSILON);
}


int main() {
    calculate_float_epsilon();
    calculate_double_epsilon();
    return 0;
}
