#include "calculator.h"

int main(int argc, char **argv) {
  int sum;

  //Comentarioooooooooooooooooo!
  
  sum = add_numbers(PEPE, 11);
  printf("I know how to add! 31 + 11 is %d\n", sum);
  return 0;
}

int add_numbers(int a, int b){
  return a + b;
}
