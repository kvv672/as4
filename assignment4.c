#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "assignment4.h"

/* Question 1 */

int my_string_compare(const void* str_ptr1, const void* str_ptr2) {
      const char* str1 = *(const char**)str_ptr1;
      const char* str2 = *(const char**)str_ptr2;

      int len1 = strlen((const char*)str1);
      int len2 = strlen((const char*)str2);
    
    int sum1 = 0, sum2 = 0;
    for (int i=0; i<len1; ++i){
        int a = str1[i] - '0';
        if (0 <= a && a <= 9){
            sum1 = sum1 + a;
        }
    }
    for (int i=0; i<len2; ++i){
        int a = str2[i] - '0';
        if (0 <= a && a <= 9){
            sum2 = sum2 + a;
        }
    }
    return sum1 - sum2;
}
void sort_strings(const char* A[], int n) {
  qsort(A, n, sizeof(A[0]), my_string_compare);
}  


void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

/* Question 2 */

int* selection_sort(int* A, int n) {
  // implement me
  int i, j, min_idx, index;
    int* idx_arr = malloc(n*sizeof(int));
    index = 0;
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (A[j] < A[min_idx])
        {
            min_idx = j;
        }
        // Swap the found minimum element with the first element
        if(min_idx != i)
        {
            idx_arr[index] = min_idx;
            swap(&A[min_idx], &A[i]);
        }
        else
        {
            idx_arr[index] = index;
        }
        index++;
    }
    return idx_arr;
}


/* Question 3 */

void swap3(int* arr, int i, int j) {
  int tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

void gen_insertion_sort(void* array, int n, size_t size, int (*compare)(const void*, const void*)) {
  // implement me
    int* trace = malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
    int count_swaps = 0;
    int j=i;
    while (j>0 && array[j]<array[j-1]) {
      swap(array, j, j-1);
      j--;
      count_swaps++;
    }
    trace[i] = count_swaps;
  }
  
  return trace;
}



/* Question 4 */

int stack_size(stack_int_t* s) {
  // implement me
  return s-> capacity;
}


int stack_count(stack_int_t* s, bool(*pred)(int)) {
  // implement me
  int count = 0;
  for(int i = 0; i < s->capacity;i++) {
    if(pred(s->ar[i])) {
      count++;
    }
  }
  return -1;
}


void stack_reverse(stack_int_t* s) {
  // implement me
}

