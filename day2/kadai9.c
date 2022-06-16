#include <stdio.h>
#include <math.h>

void main(){
  int input;
  do{
    printf("1000以下の整数を入力\n");
    scanf("%d",&input);
  }while (input > 1000);

  int numberbox[input];
  for (int i=2; i<input; i++){
    numberbox[i] = i;
  }

  for (int i=2; i<sqrt(input); i++){
    if(numberbox[i] != 0){
      for (int j=i+1; j<input; j++){
        if(numberbox[j]%i==0){
          numberbox[j] = 0;
        }
      }
    }
  }

  printf("prime number is ...\n");
  for (int i=2; i<input; i++){
    if (numberbox[i] != 0){
      printf("%d,",numberbox[i]);
    }
  }
  return;
}

// 日本語表示が上手くいかない場合
// gcc kadai9.c -lm --exec-charset=cp932