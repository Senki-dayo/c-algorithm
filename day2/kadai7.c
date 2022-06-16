#include<stdio.h>

void main(){
  float t, x, g = 9.8;
  for (t=0; t<=50; t++) {
    x = (g*(t/10)*(t/10))/2;
    printf("%2.1f  %6.3f\n",(t/10),x);
  }
  return;
}
      
