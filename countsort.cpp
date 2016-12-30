#include <stdio.h>
#include <stdlib.h>

void countSort(int *a, int n, int k)
{
  int i;
  int *count = (int*)malloc(sizeof(int)*(k+1));
  int *b = (int*)malloc(sizeof(int)*(n+1));
  for(i = 0; i <= k; i++)
    *(count+i) = 0;
  for(i = 1; i <= n; i++)
    (*(count+a[i]))++;
  for(int i = 1; i <= k; i++)
    *(count + i) += *(count + i - 1);
  for(i = n; i >= 1; i--)
  {
    *(b + *(count+a[i])) = a[i];  
    (*(count+a[i]))--;
  }
  for(i = 1; i <= n; i++)
  {
    a[i] = *(b+i);
  }
  free(count);
  free(b);
}

int main(){
  int i;
  int a[7] = {0,3,5,8,9,1,1};
  countSort(a, 6, 9);
  for(i = 0; i <= 6; i++){
    printf("%-4d", a[i]);
  }
  printf("\n");
  return 0;
}
