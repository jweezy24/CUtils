#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
    int arr[n];
    for(int i = 0; i < n; i++){
      arr[i] = n;
    }
    for(int i = 0; i < n; i++){
      arr[i] = arr[i]-i;
      for(int j = 0; j < n; j++){
        if(j <= i)
          printf("%d ", arr[j]);
        else
          printf("%d ",arr[i]);
      }
      for(int j = n-2; j >= 0 ; j--){
        if(j <= i)
          printf("%d ", arr[j]);
        else
          printf("%d ",arr[i]);
      }
      printf("\n");
    }

    for(int i = n-1; i > 0; i--){
      arr[i] = arr[i]+1;
      for(int j = 0; j < n; j++){
        if(j <= i)
          printf("%d ", arr[j]);
        else
          printf("%d ",arr[i]);
      }
      for(int j = n-2; j >= 0 ; j--){
        if(j <= i)
          printf("%d ", arr[j]);
        else
          printf("%d ",arr[i]);
      }
      printf("\n");
    }

    return 0;
}
