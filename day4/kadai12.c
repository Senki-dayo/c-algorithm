#include <stdio.h>
#include <math.h>
#define g 9.8

void main() {
  double t, x, y;
  double vel,deg,time,delta,rad; 
  FILE* fp;
  printf("初期速度 v0 = ");
  scanf("%lf",&vel);
  printf("投射角 Θ = ");
  scanf("%lf",&deg);
  rad = deg*(M_PI/180);
  printf("t秒後までの位置を求める t = ");
  scanf("%lf",&time);
  printf("Δt秒間隔で計算する Δt = ");
  scanf("%lf",&delta);
  
  fp = fopen("kadai12.txt","w");
  
  for(int i = 0; i<=(time/delta); i++) {
    t = i * delta;
    x = vel*cos(rad)*t;
    y = vel*sin(rad)*t-(g*t*t)/2;
    printf("t = %5.1f\tx = %8.3f\ty = %8.3f\n",t,x,y);
    fprintf(fp,"t =\t%5.1f\tx =\t%8.3f\ty =\t%8.3f\n",t,x,y);
  }

  fprintf(stdout,"File kadai12.txt was created\n");
  fclose( fp );
  return;
} 

// 日本語表示が上手くいかない場合
// gcc kadai12.c -lm --exec-charset=cp932