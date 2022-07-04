#include <stdio.h>

void swap(int *x, int *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void main(){
    int x = 2;
    int y = 3;
    printf("x:%d, y:%d\n", x, y);   
    swap(&x, &y);
    printf("x:%d, y:%d\n\n", x, y);
    return;
}