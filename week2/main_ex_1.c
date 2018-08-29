#include <stdio.h>
#include <float.h>
#include <limits.h>

int main() {
    int a = INT_MAX;
    float b = FLT_MAX;
    double c = DBL_MAX;

    printf("INT\nSize: %zu\nValue: %d\n\n", sizeof(a), a);
    printf("FLOAT\nSize: %zu\nValue: %f\n\n", sizeof(b), b);
    printf("DOUBLE\nSize: %zu\nValue: %lf", sizeof(c), c);

    return 0

}