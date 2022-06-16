#include <stdio.h>

void main(){
    int i, j, k;
    float f0, f1;
    i = 5;
    j = 3;

    k = i + j;
    f0 = (float)(i / j);
    f1 = (float)i / (float) j;

    printf("%5d + %5d = %5d\n", i, j, k);
    printf("%5d - %5d = %5d\n", i, j, i - j);
    printf("%5d x %5d = %5d\n", i, j, i * j);
    printf("%5d / %5d = %5d\n", i, j, i / j);
    printf("(float)(%d / %d) = %5.3f\n", i, j, f0);
    printf("(float)%d / (float)%d = %5.3f\n", i, j, f1);
    return;
}
