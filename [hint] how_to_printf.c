#include <stdio.h>

void main(){

    // 文字
    char a = 'a';
    printf("%c\n",a);

    // 文字列
    char b[10] = "hello";
    printf("%s\n",b);

    // 符号付き10進整数
    int c = 10;
    int d = -4;
    printf("%d\n",c);
    printf("%d\n",d);

    // 符号なし10進整数
    int e = 10;
    int f = -4;
    printf("%u\n",e);
    printf("%u\n",f); //4294967292 ←補数表現により...

    // 符号なし8進整数 (8進数は古代の遺物)
    int g = 022;
    printf("%o\n",g);

    // 符号なし16進整数
    int h = 0x3d;
    printf("%x\n",h);

    // 浮動小数点数
    float i = 3.141592;
    printf("%f",i);









}