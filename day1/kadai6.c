#include <stdio.h>
#include <math.h>
 
void main(){
  float a,b,c,D;
  float r,i,x1,x2;
  printf("2次方程式の係数を入力\n");
  scanf("%f %f %f",&a,&b,&c);
  D=b*b- 4*a*c;
  if(D>0){
    x1=((-1)*b + sqrt(D))/(2*a);
    x2=((-1)*b - sqrt(D))/(2*a);
    printf("x= %3.2f , %3.2f\n",x1,x2);
  }else if(D==0){
    x1=x2=((-1)*b) / (2*a);
    printf("x= %3.2f (重解)\n",x1);
  }else if(D<0){
    r=((-1)*b) / (2*a);
    i=sqrt((-1)*D) / (2*a);
    printf("x= %3.2f+%3.2fi , %3.2f-%3.2fi \n",r,i,r,i);
  }
  return;
}

// 入力例
// 1 -5 6 -> 2.00 , 3.00
// 1 4 4 -> -2.00
// 1 -2 2 -> 1.00+1.00i ,1.00-1.00i

// sqrt関数を使う場合は-lmオプションを指定する
// 日本語表示が上手くいかない場合
// gcc kadai6.c -lm --exec-charset=cp932