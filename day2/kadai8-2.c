#include <stdio.h>

void main(){
  double u[3][3], v[3][3];
  printf("3×3行列u,vの積を計算します\n");
  printf("u[x][x,y,z]=");
  scanf("%lf %lf %lf",&u[0][0],&u[0][1],&u[0][2]);
  printf("u[y][x,y,z]=");
  scanf("%lf %lf %lf",&u[1][0],&u[1][1],&u[1][2]);
  printf("u[z][x,y,z]=");
  scanf("%lf %lf %lf",&u[2][0],&u[2][1],&u[2][2]);
  printf("v[x][x,y,z]=");
  scanf("%lf %lf %lf",&v[0][0],&v[0][1],&v[0][2]);
  printf("v[y][x,y,z]=");
  scanf("%lf %lf %lf",&v[1][0],&v[1][1],&v[1][2]);
  printf("v[z][x,y,z]=");
  scanf("%lf %lf %lf",&v[2][0],&v[2][1],&v[2][2]);

  for (int i=0; i<3; i++){
    for (int j=0; j<3; j++){
      int t = 0;
      for (int k=0; k<3; k++){
        t+= u[i][k]*v[k][j];
      }
	    printf("%d, ", t);
    }
    printf("\n");
  }
  return;
}
