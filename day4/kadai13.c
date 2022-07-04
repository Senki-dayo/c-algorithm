#include <stdio.h>
#include <math.h>

/* f(x)の出力 */
void function()
{
  printf("f(x) = pow(x,2) - 2\n");
}

/* f(x) */
double f(double x)
{
  return x*x-2;
}

/* f(x)の導関数 */
double g(double x)
{
  return 2*x;
}

int main()
{
  double x,new_x,eps;
  int number, i;

  function(); /* f(x)を表示 */
  printf("初期値 : ");
  scanf("%lf",&x);
  printf("計算精度 : ");
  scanf("%lf",&eps);
  printf("繰り返し上限回数 : ");
  scanf("%d",&number);
  printf("繰り返し\tnew_x\t\tf(x)\t\tg(x)\n");
  for(i=0;i<number;i++ ) {
    //float a = f(x);
    //float b = g(x);
    new_x = x-((float)f(x)/(float)g(x));    
    if( fabs((new_x-x)/new_x) <= eps ) {
      printf("x = %f\n", new_x);
      break;
    }
    printf("%2d\t\t%f\t%f\t%f\n", i, new_x, f(x), g(x));
    if(fabs((new_x-x)/new_x)==eps && g(x)<=0.0001) {
      printf("x = %f(重解)\n", new_x);
      break;
    }
    x = new_x;
  }
  if(i == number) printf("繰り返し上限\n");
}

// 日本語表示が上手くいかない場合
// gcc kadai13.c -lm --exec-charset=cp932