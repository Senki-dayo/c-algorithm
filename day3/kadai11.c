#include <stdio.h>
#include<math.h>

/*算術平均*/
double average(int n, double s){
  return (n==0) ? 0 : (float)s/(float)n;
}

/*分散*/
double dispersion(int n, double s, double list[n]){
  double sum_dis=0;
  if(n==0){
    return 0;
  }else{
    double a = average(n,s);
    for(int i=0; i<n; i++){
      sum_dis += pow(list[i]-a,2.0);
    }
    return (float)sum_dis/(float)n;
  }
}

void main(){  
  printf("算術平均と分散を求める。\n1000個までの0を除く実数を入力可能。\n0を入力すると終了。\n");

  double numlist[1000];
  int count=0;
  double input,sum=0;

  for(int i=0; i<1000; i++){
    scanf("%lf",&input);
    if(input==0){
      break;
    }else{
      numlist[i] = input;
      count++;
      sum += input;
    }
  }
  
  printf("算術平均:%lf\n",average(count,sum));
  printf("分散:%lf\n",dispersion(count,sum,numlist));
  return;
}

// 日本語表示が上手くいかない場合
// gcc kadai11.c --exec-charset=cp932