#include "serial.h"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int eratostenes(int lastNumber){

  char* isPrime = malloc(lastNumber+1 * sizeof(int));
  for (int i = 0; i <= lastNumber; i++){
    isPrime[i] = 1;
  }

  for (int i = 2; i*i <= lastNumber; i++){
    if (isPrime[i]){
      for (int j = i*i; j <= lastNumber; j += i){
        isPrime[j] = 0;
      }
    }
  }

  int found = 0;
  for (int i = 2; i <= lastNumber; i++){
      found += isPrime[i];
  }

  free(isPrime);
  return found;
}
