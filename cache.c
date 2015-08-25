#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int countDigits(int n);
void printCache(int * values, int cachesize);
int maxCompare(int a, int b);
void printTopBottom(int * end_spaces, int cachesize);
void printValues(int * current_nums, int cachesize);
int main(int argc, char ** argv) {
  if(argc != 2) {
    fprintf(stderr, "Usage: %s <int>", argv[0]);
    return EXIT_FAILURE;
  }
  int cachesize = atoi(argv[1]);
  int * values = (int*)malloc(cachesize * sizeof(int));
  int i;
  for(i = 0; i < cachesize; i++) {
    values[i] = 0;
  }
  int num = 0;
  while(1) {
    printf(">");
    scanf("%d", &num);
    if(num <= 0) {
      break;
    }
    int num_index = num % cachesize;
    int i;
    if(values[num_index] == num) {
      printf("Cache Hit!\n");
    }
    else {
      printf("Cache Miss. Inserting %d.\n", num);
      values[num_index] = num;	
    }
    printCache(values, cachesize);
  }
  printf("Exiting.");
  return EXIT_SUCCESS;
}
void printCache(int * values, int cachesize) {
  int * end_spaces = (int*)malloc(cachesize*sizeof(int));
  int i;
  for(i = 0; i < cachesize; i++) {
    end_spaces[i] = 0;
  }
  for(i = 0; i < cachesize; i++) {
    end_spaces[i] = countDigits(values[i]) + 2;
  }
  printTopBottom(end_spaces, cachesize);
  printValues(values, cachesize);
  printTopBottom(end_spaces, cachesize);
  free(end_spaces);
}
void printValues(int * current_nums, int cachesize) {
  int i;
  for(i = 0; i < cachesize; i++) {
    int j;
    printf("|");
    printf(" %d ", current_nums[i]);
  }
  printf("|\n");
}
void printTopBottom(int * end_spaces, int cachesize) {
  int i;
  for(i = 0; i < cachesize; i++) {
    int j;
    printf("+");
    for(j = 0; j < end_spaces[i]; j++) {
      printf("-");	
    }
  }
  printf("+\n");
}
int countDigits(int n) {
  return n == 0 ? 1 : (int)floor(log10(abs(n))) + 1;
}
