#include <stdio.h>

void main(){
  int i;
  double ip = 0.0;
  double u[3], v[3];
  printf("三次元ベクトルu,vの内積を求めます\n");
  printf("u[x,y,z]=");
  scanf("%lf %lf %lf",&u[0],&u[1],&u[2]);
  printf("v[x,y,z]=");
  scanf("%lf %lf %lf",&v[0],&v[1],&v[2]);
  for (i=0; i<3; i++) {
    ip = ip + u[i]*v[i];
  }
  printf("内積=%f\n", ip);
  return;
}

