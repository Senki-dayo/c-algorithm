#include <stdio.h>
#include <math.h>

double f(double x) {
  return sqrt(4-x*x);
}

double daikei(int a, int b, int n){
  double S = 0.0;
  double h = (double)(b-a)/(double)n;
  for(int i=0; i<n; i++) {
      double x = a + i * h;
      S += ( f(x) + f(x+h) ) * h / 2.0;
    };
  return S;
}

double simpson(int a, int b, int n){
  double S = 0.0;
  double h = (double)(b-a)/(double)(2*n);
  S += f(a) + f(b);
    for(int i=0; i<n; i++) {
      S += 4*f(a+(2*i + 1)*h);
    };
    for(int i=1; i<n; i++) {
      S += 2*f(a+2*i*h);
    };
    return S * (h / 3.0);
}

void main(){
  int bool = 1;
  while( !(bool == 2) ){
    double a=0.0, b=2.0;
    int mode, n;
    printf("\n利用する関数を選択\n1.台形則/2.シンプソン則\t");
    scanf("%d",&mode);
    printf("分割数 : ");
    scanf("%d",&n);

    if(mode==1) printf("%lf\n",daikei(a,b,n));
    if(mode==2) printf("%lf\n",simpson(a,b,n));
    
    printf("他のパラメータで試しますか？(1.yes/2.no):");
    scanf("%d",&bool);
  };
  return;
}
  
// 日本語表示が上手くいかない場合
// gcc kadai17.c -lm --exec-charset=cp932