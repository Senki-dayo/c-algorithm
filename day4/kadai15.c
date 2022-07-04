#include <stdio.h>
#include <math.h>

double f(double x)
{
    return x*x-2;
}

// 2分法
int main()
{
  printf("x*x-2 の解を二分法で求める\n初期値はxl=1,xh=5と設定している\n");
  double x,xl=1,xh=5;
  int i=0;
  while(1){
    i++;
    x=(xl+xh)/2;
    if(f(x)==0){
      printf("%lf が%d 回の反復で導かれた\n",x,i);
      break;};
    if(f(x)>0) xh=x;
    if(f(x)<0) xl=x;
    if((fabs(xh-xl)/fabs(xl))<0.00001){
      printf("%lf が%d 回の反復で導かれた\n",x,i);
      break;};
  };
};

// 日本語表示が上手くいかない場合
// gcc kadai15.c -lm --exec-charset=cp932