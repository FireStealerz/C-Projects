/* @JUDGE_ID:  	1614287   100  C  "3n+1 Problem"  */

/* Solution to the 3n+1 problem  /onlinejudge.org/
* by: Ivan Herran 
* 2023-08-06 12:30*/

/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <stdlib.h>

/*Prototypes*/
int process(int min, int max);

int main(void)
{
  int min, max, cycles, remeberMin, rememberMax;

  while (scanf("%d  %d", &min, &max) != EOF) {
    remeberMin = min;
    rememberMax = max;
    if (min > max) {
      int temp;
      temp = max;
      max = min;
      min = temp;
    }
    cycles = process(min, max);
    printf("%d %d %d\n", remeberMin, rememberMax, cycles);
  }

  return EXIT_SUCCESS;
}

int process(int min, int max){
  int steps = 1, rememberMax = max,cycles = 0;
  while (rememberMax >= min) {
    max = rememberMax;  
    steps = 1;
   while (max != 1) {
    if (max % 2 == 1) {
      max = 3*max+1;
    }else if (max % 2 == 0) {
      max = max / 2;
    }
    steps++;
  }
    if (steps > cycles) {
      cycles = steps;  
    }
    steps = 1;  
    rememberMax--;
  }
  return cycles;
}

/* @END_OF_SOURCE_CODE */
