#include <stdio.h>

int main() {
  double salario = 9050.17;
  double *ponteiroSalario = &salario;
  
  printf("%.2lf\n", salario);
  printf("%p\n", &salario);
  printf("%p\n", ponteiroSalario);
  
  return 0;
}