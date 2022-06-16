#include <stdio.h>
int counter = 0;

int func1(){
  int counter = 10;
  static int static_counter = 100;

  printf("counters in func1 = %d, %d\n",
	 counter, static_counter);
  counter++;
  static_counter++;
  return counter;
}

void main(){
  int i;
  i=func1();

  printf("return value of func1 = %d\n", i);
  printf("counter in main = %d\n", counter);
  i = func1();
  printf("return value of func1 = %d\n", i);
  printf("counter in main = %d\n", counter);
  return;
}

// counters in func1 = 10, 100 
// -> 関数func1内の変数
// return value of func1 = 11
// -> 関数func1からの返り値
// counter in main = 0
// -> 外部変数 counter
// counters in func1 = 10, 101
// -> static変数はプログラム終了時まで保持されるため
// return value of func1 = 11
// -> 関数func1からの返り値
// -> counterはstatic変数ではないので
// -> 値は保持されていない。
// counter in main = 0
// -> 外部変数 counter