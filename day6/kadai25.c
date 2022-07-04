#include<stdio.h>
#define M 100001

void bubble(int a[], int left, int right){
  int i,j,tmp,min_point;
  for(i=left; i<=right-1; i++){
    min_point = i;
    for(j=i+1; j<=right; j++){
      if(a[min_point] > a[j]) min_point = j;
    }
    if(min_point == i) continue;
    tmp = a[i];
    a[i] = a[min_point];
    a[min_point] = tmp;
  }
}

void mergesort(int a[],int left,int right){
  int mid,i,j,k,tmp[M];
  if(right-left<32){
    bubble(a,left,right);
    return;
  }
  //要素が1個になるまで分割
  mid = (left + right)/2;
  mergesort(a, left, mid);
  mergesort(a, mid+1, right);

  // a[left] ~ a[mid] を tmp にコピー
  for(i=left; i<=mid; i++){
    tmp[i] = a[i];
  }
  // a[mid+1] ~ a[right] を逆順に tmp にコピー
  j = right;
  for(i=mid+1; i<=right; i++){
    tmp[j] = a[i];
    j--;
  }
  // 小さい方から配列に戻す
  i=left;
  j=right;
  for(k=left; k<=right; k++){
    if(tmp[i] < tmp[j]){
      a[k] = tmp[i];
      i++;
    }else{
      a[k] = tmp[j];
      j--;
    }
  }
}

int main(){
  int n=0, ret;
  int a[M];
  FILE *fp;

  //ファイルから数値列を読み込み
  fp=fopen("data.txt", "r");
  for(int i=0; i<M; i++){
    ret = fscanf(fp,"%d",&a[i]);
    if (ret == EOF) { break; }
    n = i+1;
  }
  fclose(fp);

  //ソーテイング
  mergesort(a,0,n-1);

  //並び替えた配列を表示
  for(int i=0;i<n;i++){
    printf("%3d: %5d\n",i,a[i]);
  }
}
