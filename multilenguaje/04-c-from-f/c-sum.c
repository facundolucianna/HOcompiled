#include <stdlib.h>
#include "c-sum.h"

void sum_abs_(int *in, int *num, int *out) {
   int i,sum;

   for (i=0,sum=0; i < *num; ++i) {
       sum += abs(in[i]);
   }
   *out = sum;
}
