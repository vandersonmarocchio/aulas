#include <stdio.h>
#include <math.h>
#include <math.h>
#include <math.h>
#define PI 3.14159265358979323846

int fatorial(int x){
  int fat = 1;
  while (x > 0) {
    fat = fat *  x;
    x--;
  }
  return fat;
}

int main(){
  double grau, radiano, taylor, real;

  printf("Digite o grau: ");
  scanf(" %lf", &grau);
  radiano = (grau*PI)/180;
  printf("Radiano : %lf\n", radiano);

  /*for (int i = 0; i<6; i++){
    taylor = (pow(-1, i+1) * pow(radiano, 2*i-1)) / fatorial(2*i-1);
  }*/

  return 0;
}
