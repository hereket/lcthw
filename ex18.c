#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/* Our old friend from ex17. */
void die(const char *msg)
{
  if(errno) {
    perror(msg);
  } else {
    printf("ERROR: %s\n", msg);
  }
}

// a typedef creates a fake type
// in this case for function pointer
typedef int (*compare_cb)(int a, int b);

/**
 * A classic bubble sort function that uses the
 * compare_cb to do the sorting
 */

int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
  int i = 0;
  int j = 0;
  int tmp = 0;
  int *target = malloc(count * sizeof(int));

  if(!target) die("Memory error.");

  memcpy(target, numbers, count * sizeof(int));

  for(i = 0; i < count; i++) {
    for(j = 0; j < count - 1; j++) {
      if(cmp(target[j],target[j+1]) > 0) {
        tmp = target[j+1];
        target[j+1] = target[j];
        target[j] = tmp;
      }
    }
  }
  return target;
}



int sorted_order(int a, int b)
{
  return a - b;
}

int reverse_order(int a, int b)
{
  return b - a;
}

int strange_order(int a, int b)
{
  if(a == 0 || b == 0) {
    return 0;
  } else {
    return a % b;
  }
}

/* Test if we are doing sorting correctly
 * by sorting and printing them out
 */
void test_sorting(int *numbers, int count, compare_cb cmp)
{
  int i = 0;
  int *sorted = bubble_sort(numbers, count, cmp);

  if(!sorted) die("Failed to sort as requeted");

  for(i = 0; i < count; i++) {
    printf("%d ", sorted[i]);
  }
  printf("\n");

  unsigned char *data = (unsigned char *)cmp;

  for(i = 0; i < 25; i++) {
    printf("%02x:", data[i]);
  }

  free(sorted);
}

int main(int argc, char *argv[])
{
  if(argc < 2) die("USAGE: ex18 2 7 23 1 4");    

  int count = argc - 1;
  int i = 0;
  char **inputs = argv + 1;

  int *numbers = malloc(count * sizeof(int));
  if(!numbers) die("Memmory erro");

  for(i = 0; i < count; i++) {
    numbers[i] = atoi(inputs[i]);
  }

  test_sorting(numbers, count, sorted_order);
  test_sorting(numbers, count, reverse_order);
  test_sorting(numbers, count, strange_order);

  free(numbers);

  return 0;
}


