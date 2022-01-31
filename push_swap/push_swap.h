#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stacks {
	int *stack;
	int size;
} stack;

typedef struct LIS {
	int *arr;
	int size;
} lis;

typedef struct moves {
	int to_b;
	int to_a;
	int index;
} moves;
void swap_stack(stack *a, stack *b, char *instruction);
void swap(stack *stack);
void push_stack(stack *a, stack *b, char *instruction);
void shift(stack *stack);
void append(stack *stack, int n);
void rotate_stack(stack *a, stack *b, char *instruction);
void sort_stack(stack *a, stack *b);
int find_max(int *arr, int size, int max);
void print_stack(stack *a, char stack);
#endif

