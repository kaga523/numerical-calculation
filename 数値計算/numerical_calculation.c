#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10000
double fnctv(double x);
double RND(void);
int main(void){
    int i,n = 100;
    double dh, Simp_solution,Monte_solution, xk, xa = -1.0, xb = 1.0;
    dh = (xb - xa)/(double) n;
    Simp_solution = fnctv(xa);
    Monte_solution = fnctv(xa);
    //以下　シンプソン法の計算
    for (i=1; i<n; i++){
        xk = xa + dh*(double)i;
        if(i%2!=0) {Simp_solution = Simp_solution + 4.0*fnctv(xk);}
        else       {Simp_solution = Simp_solution + 2.0*fnctv(xk);}
    }
    Simp_solution = Simp_solution + fnctv(xb);
    Simp_solution = dh*Simp_solution/3.0;
    //以下モンテカルロ法の計算
    for (i=1; i<n; i++){
        xk = xa + (xb - xa)*RND();
        if(i%2!=0) {Monte_solution = Monte_solution + 4.0*fnctv(xk);}
        else       {Monte_solution = Monte_solution + 2.0*fnctv(xk);}
    }
    Monte_solution = Monte_solution + fnctv(xb);
    Monte_solution = dh*Monte_solution/3.0;
    printf("シンプソン公式を用いた解は%fです。\n",Simp_solution);
    printf("モンテカルロ法を用いた解は%fです。\n",Monte_solution);
    return 0;
}
//以下　-1~1の範囲で2/(x^2+1)を微分
//x2 =　xの2乗
double fnctv(double x){
    double x2;
    x2 = x*x;
    return 2.0/(x2 + 1.0);
}
//以下　乱数を生成
double RND(void){
    int nr;
    double dr;
    nr = rand();
    dr = (double) nr/(double) RAND_MAX;
    return dr;
}