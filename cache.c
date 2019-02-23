#include "stdio.h" 
#include "stdlib.h" 
#include "math.h"
#define MAX_DIGITS 256

int countDigits(int n);
void printCache(int * values, int cachesize);
int maxCompare(int a, int b);
void printTopBottom(int * end_spaces, int cachesize);
void printValues(int * current_nums, int cachesize);

int main(int argc, char** argv) {
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <int>\n", argv[0]);
        return EXIT_FAILURE;
    }
    int cachesize = atoi(argv[1]);
    int * values;
    if(!(values = (int*) malloc(cachesize * sizeof(int)))) {
        perror("Malloc Failed.");
        exit(EXIT_FAILURE);
    }
    int i;
    for (i = 0; i < cachesize; i++) {
        values[i] = 0;
    }
    int num = 0;
    char * input_buffer;
    while (1) {
        printf(">");
        if(!(input_buffer = (char*)malloc(MAX_DIGITS * sizeof(char)))) {
            perror("Malloc Failed.");
            exit(EXIT_FAILURE);
        }
        fgets(input_buffer, MAX_DIGITS, stdin);
        num = atoi(input_buffer);
        if (num <= 0) {
			free(input_buffer);
            break;
        }
        int num_index = num % cachesize;
        int i;
        if (values[num_index] == num) {
            printf("Cache Hit!\n");
        } else {
            printf("Cache Miss. Inserting %d.\n", num);
            values[num_index] = num;
        }
        printCache(values, cachesize);
        free(input_buffer);
    }
    printf("Exiting.");
	free(values);
    return EXIT_SUCCESS;
}
void printCache(int * values, int cachesize) {
    int * end_spaces;
    if(!(end_spaces = (int*) malloc(cachesize * sizeof(int)))) {
        perror("Malloc Failed");
        exit(EXIT_FAILURE);
    }
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
        for (j = 0; j < end_spaces[i]; j++) {
            printf("-");
        }
    }
    printf("+\n");
}
int countDigits(int n) {
    return n == 0 ? 1 : (int) floor(log10(abs(n))) + 1;
}
