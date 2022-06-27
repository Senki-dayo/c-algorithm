#include <stdio.h>

int main(){
    int i = 5 , j = 3;
    float k1,k2,k3;

    k1 = i / j;
    k2 = (float)(i/j);
    k3 = (float)i / (float)j;
    
    printf("%f\n",k1); // 1.000000
    printf("%f\n",k2); // 1.000000
    printf("%f\n",k3); // 1.666667
}