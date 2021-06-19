#include <stdio.h>
#include <stdlib.h>

void printIntVector(int vector[], int len) {
  printf("{ ");

  if (len > 0) {
    printf("%d", vector[0]);

    for (int i = 1; i < len; i ++) {
      printf(", %d", vector[i]);
    }
  }

  printf(" }\n");
}

int DIVIDE(int A[], int p, int r) {
  int *pivo = &A[r];
  int i = p - 1;
  printf("pivo: %d, i: %d\n", *pivo, i);
  int aux = 0;

  // printf("for\n");
  for (int j = p; j <= r - 1; j++) {
    printf("i: %d, j: %d\n", i, j);

    if (A[j] <= *pivo) {
      i++;

      aux = A[i];
      A[i] = A[j];
      A[j] = aux;

      printf(">> parte 1: incrementou i (%d) e mudou A[%d] (%d) de posição com A[%d] (%d)!\n", i, i, A[i], j, *pivo);
    }
  }
  // printf("endfor\n");

  i++;

  aux = A[i];
  A[i] = *pivo;
  *pivo = aux;

  printf(">> parte 2: incrementou i (%d) e mudou A[%d] (%d) de posição com o pivô (%d)!\n", i, i, A[i], *pivo);

  return i;
}

void QUICKSORT(int A[], int p, int r, int lenOfA) {
  int q = 0;

  if (p <= r) {
    q = DIVIDE(A, p, r);
    printf(">> Após DIVIDE: \n");
    printIntVector(A, lenOfA);

    QUICKSORT(A, p, q - 1, lenOfA);
    QUICKSORT(A, q + 1, r, lenOfA);
  }
}


int main() {
  // int A[] = {1, 3, 6, 2, 8, 5, 7, 4};
  // int A[] = {1, 3, 6, 2, 8, 5, 7};
  // int A[] = {1, 3, 6, 2, 8, 5};
  // int A[] = {1, 3, 6, 2, 8};
  // int A[] = {1, 3, 6, 2};
  // int A[] = {1, 3, 6};
  // int A[] = {1, 3};
  // int A[] = {1};
  // int A[] = {};
  // int A[] = {3, 9, 2, 1, 5, 4};
  // int A[] = {1, 2, 3, 4};
  // int A[] = {4, 3, 2, 1};
  int A[] = {33, 44, 55, 77, 95, 99, 22, 25, 41, 66, 88, 89};
  int lenOfA = sizeof (A) / sizeof (int);
  int p = 0;
  int r = lenOfA - 1;

  printf("lenOfA: %d\n", lenOfA);
  printIntVector(A, lenOfA);

  QUICKSORT(A, p, r, lenOfA);
  printIntVector(A, lenOfA);

  return 0;
}
