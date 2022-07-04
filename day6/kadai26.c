#include <stdio.h>
#include <stdlib.h>
#define M 100001

void quicksort(int a[], int left, int right){
    int l, r, k, pivot, tmp;
    if(left>=right) return;

    int r1, r2, r3, min, med, max;
    r1 = rand() % (right - left + 1) + left;
    r2 = rand() % (right - left + 1) + left;
    r3 = rand() % (right - left + 1) + left;
    min = med = max = r1;
    if(r2 < min) min = r2;
    if(r3 < min) min = r3;
    if(max < r2) max = r2;
    if(max < r3) max = r3;
    if(r1 != min && r1 != max) med = r1;
    if(r2 != min && r2 != max) med = r2;
    if(r3 != min && r3 != max) med = r3;

    //pivotを選ぶ
    pivot = a[med];
    
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
    
    if(l < med){
        k = l;
        tmp = a[med];
        a[med] = a[k];
        a[k] = tmp;
    }else if(med < r){
        k = r;
        tmp = a[med];
        a[med] = a[k];
        a[k] = tmp;
    } else if(r < med < l) {
        k = med;
    }

    quicksort(a,left,k-1);
    quicksort(a,k+1,right);
}

int main(){
  int n=0, ret;
  int a[M];
  FILE *fp;

  //ファイルから数値列を読み込み
  fp=fopen("data.txt", "r");
  for(int i=0; i<M; i++){
    ret = fscanf(fp,"%d",&a[i]);
    if (ret == EOF) break;
    n = i+1;
  }
  fclose(fp);

  //ソーテイング
  quicksort(a,0,n-1);

  //並び替えた配列を表示
  for(int i=0;i<n;i++){
    printf("%3d: %5d\n",i,a[i]);
  }
}
