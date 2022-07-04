#include <stdio.h>
#include <math.h>

double f(double x) {
  return log(x)*sin(x)*sin(x);
}

void main() {
  int bool = 1;
  printf("被積分関数 : log(x)*sin^2(x)\n");
  
  while(!(bool==2)){
    int a,b,n;
    printf("\n積分区間(a～b) : ");
    scanf("%d %d",&a,&b);
    printf("分割数 : ");
    scanf("%d",&n);

    double h = (double)(b-a)/(double)(2*n);
    double S = 0.0;
    S += f(a) + f(b);
    for(int i=0; i<n; i++) {
      S += 4*f(a+(2*i + 1)*h);
    };
    for(int i=1; i<n; i++) {
      S += 2*f(a+2*i*h);
    };
    S = S * (h / 3.0);

    printf("%f\n",S);
    printf("他のパラメータで試しますか？(1.yes/2.no): ");
    scanf("%d",&bool);
    return;
  };
};

// 日本語表示が上手くいかない場合
// gcc kadai17.c -lm --exec-charset=cp932
