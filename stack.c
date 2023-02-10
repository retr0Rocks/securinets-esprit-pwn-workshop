#include <stdio.h>
#include <stdlib.h>

int foo2(){
  printf("CALLED FOO2\n");
  return;
}

int foo1() {
  printf("CALLED FOO1\n");
  printf("CALLING FOO2\n");
  foo2();
  return;
}

int main() {
  printf("CALLING FOO1\n");
  foo1();
  return 0;
}
