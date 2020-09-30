#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("Enter the size of an array\n");
    int N;

    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Illegal N\n");
        return 1;
    }

    int *arr = malloc(N*sizeof(int));
    if (arr == NULL) {
        printf("Not enough memory!\n");
        return 2;
    }

    for (int i = 0; i<N; i++) 
        arr[i] = i;

    for (int i = 0; i<N; i++) 
        printf("%d ", arr[i]);

    printf("\n");
    free(arr);
    return 0;
}
