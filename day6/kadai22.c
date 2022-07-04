#include<stdio.h>
#define M 100001

void bubble(int a[], int left, int right){
  int i,j,tmp;
  for(i=left; i<=right-1; i++){
    for(j=i+1; j<=right; j++){
      if(a[j]<a[i]){
        tmp=a[i];
        a[i]=a[j];
        a[j]=tmp;
      }
    }
  }
}

void mergesort(int a[],int left,int right){
  int mid,i,j,k,tmp[M];
  if(left >= right){
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

void quicksort(int a[], int left, int right){
    int l, r, k, pivot, tmp;
    if(left>=right) return;

    //pivotを選ぶ
    pivot = a[left];
    
    l = left;
    r = right;
    while(l < r){
        while(!(a[l]>pivot)) {
            l++;
            if(l==right) break;
        }
        while(!(a[r]<pivot)) {
            r--;
            if(r==left) break;
        }
        if(l < r){
            tmp = a[l];
            a[l] = a[r];
            a[r] = tmp;
        }
    }
    k = r;

    tmp = a[left];
    a[left] = a[k];
    a[k] = tmp;

    quicksort(a,left,k-1);
    quicksort(a,k+1,right);
}

void sorting(int a[], int left, int right){
  int mode;
  printf("1.bubblesort\n");
  printf("2.mergesort\n");
  printf("3.quicksort\n");
  scanf("%d",&mode);
  if (mode == 1) bubble(a,left,right);
  else if (mode == 2) mergesort(a,left,right);
  else if (mode == 3) quicksort(a,left,right);
  return;
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
  sorting(a,0,n-1);

  //並び替えた配列を表示
  for(int i=0;i<n;i++){
    printf("%3d: %5d\n",i,a[i]);
  }
}
