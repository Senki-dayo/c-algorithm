#include <stdio.h>
#include <math.h>
#define M 4

void output(double a[M][M], double b[M]){
    for(int i=0; i<M; i++){
        for(int j=0;j<M;j++){
            printf("%10.5lf ",a[i][j]);
        }
        printf("%10.5lf\n", b[i]);
    }
    printf("\n");
}

void pivot(int i, double a[M][M], double b[M]){
    double tmp[M] = {0,0,0,0};
    double max = 0.0;
    int j = i;
    for(int k=i; k<M; k++){
        if(fabs(max) < fabs(a[k][i])){
            max = a[k][i];
            j = k;
        }
    }
    if(i != j){
        for(int k=0; k<M; k++){
            tmp[k] = a[i][k];
            a[i][k] = a[j][k];
            a[j][k] = tmp[k];
        }
        tmp[0] = b[i];
        b[i] = b[j];
        b[j] = tmp[0];
    }
    return;
}

void zensin(int i, double a[M][M], double b[M]){
    double divisor = a[i][i];
    for(int k=0; k<M; k++){
        a[i][k] /= divisor;
    }
    b[i] /= divisor;

    for(int k=i+1; k<M; k++){
        double multi = a[k][i];
        if(a[k][i]==0) continue;
        for(int l=0; l<M; l++){
            a[k][l] -= a[i][l] * multi;
        }
        b[k] -= b[i] * multi;
    }
    return;
}

void koutai(int i, double a[M][M], double b[M]){
    for(int k=i+1; k<M; k++){
        b[i] = b[i] - a[i][k] * b[k];
        a[i][k] = 0;
    }
    return;
}

void main(){

    double a[M][M];
    double b[M];
    FILE *fp;

    //データの読み込み
    fp = fopen("kadai19(1).txt","r");
    for(int i=0; i<M; i++){
        for(int j=0;j<M;j++){
            fscanf(fp,"%lf",&a[i][j]);
        }
        fscanf(fp,"%lf",&b[i]);
    }
    fclose(fp);

    //入力行列
    printf("\n\t\t\t入力行列\n");
    output(a,b);

    //前進消去
    printf("\t\t\t前進消去\n");
    for(int i=0; i<M; i++){
        pivot(i,a,b);
        zensin(i,a,b);
    }
    output(a,b);

    //後退代入
    printf("\t\t\t後退代入\n");
    for(int i=M-2; i>=0; i--){
        koutai(i,a,b);
    }
    output(a,b);

    printf("\tx0 = %10.5lf\n",b[0]);
    printf("\tx1 = %10.5lf\n",b[1]);
    printf("\tx2 = %10.5lf\n",b[2]);
    printf("\tx3 = %10.5lf\n",b[3]);
    return;
}

// 日本語表示が上手くいかない場合
// gcc kadai19.c -lm --exec-charset=cp932