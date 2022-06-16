#include <stdio.h>

float convC2F(float c){
  return (float)(9*c)/(float)5+32;;
}

void main(){
  float celsius;
  float fahrenheit;
  printf("摂氏を入力する\n");
  scanf("%f",&celsius);
  fahrenheit = convC2F(celsius);
  printf("華氏は、%3.1fである\n",fahrenheit);
  return;
}

// 日本語表示が上手くいかない場合
// gcc kadai4.c --exec-charset=cp932