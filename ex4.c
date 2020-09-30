#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void* my_realloc(void *ptr, int init_size, int new_size) {
  if (ptr == NULL) {
    return malloc(new_size);
  }
  if (new_size == 0) {
    free(ptr);
    return NULL;
  }
  void* new_ptr;
  int s2 = (init_size>=new_size)? new_size : init_size;
  new_ptr = malloc(new_size);
  memcpy(new_ptr, ptr, s2);
  free(ptr);
  return new_ptr;
}
int main(void) {
  printf("Enter the size of an array\n");
  int N,M;
  scanf("%d", &N);
  int *arr = malloc(N*sizeof(int));
  for (int i = 0; i<N; i++) {
    arr[i] = i;
    printf("%d ", arr[i]);
  }
  printf("\nEnter new size of an array\n");
  scanf("%d", &M);
  arr = my_realloc(arr, N*sizeof(int), M*sizeof(int));
  for (int i = 0; i<M; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}
