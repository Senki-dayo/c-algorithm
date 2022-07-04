#include <stdio.h>
#include <math.h>

double f(double x) {
  return exp((-1)*x*x);
}

void main() {
  int bool=1;
  printf("被積分関数 : f(x) = exp(-x^2)\n");
  
  while(!(bool==2)){
    int a,b,n;
    printf("\n積分区間(a～b) : ");
    scanf("%d %d",&a,&b);
    printf("分割数 : ");
    scanf("%d",&n);

    double h = (double)(b-a)/(double)n;
    double S = 0.0;
    for(int i=0; i<n; i++) {
      double x = a + i * h;
      S += ( f(x) + f(x+h) ) * h / 2.0;
    };
    printf("面積 = %f\n",S);
    printf("他のパラメータで試しますか？(1.yes/2.no): ");
    scanf("%d",&bool);
  };
  return;
};

// 日本語表示が上手くいかない場合
// gcc kadai16.c -lm --exec-charset=cp932