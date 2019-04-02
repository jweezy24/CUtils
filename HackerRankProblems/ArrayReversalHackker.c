#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }


    /* Write the logic to reverse the array. */
    int *arr2;
    arr2 = malloc(num * sizeof(int));
    int counter = num-1;
    for(int i = 0; i < num; i++){
      arr2[i] = arr[counter];
      counter--;
    }

    for(i = 0; i < num; i++)
        printf("%d ", *(arr2 + i));
    return 0;
}
