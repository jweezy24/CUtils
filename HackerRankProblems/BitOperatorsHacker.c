#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
  //Write your code here.
  int maxAnd =0;
  int maxOR =0;
  int maxXOR =0;
  for (int i = 1; i <= n; i++){
    for(int j = i; j <= n; j++){
      if(i == j){
        continue;
      }
      if( (i&j) > maxAnd && (i&j) < k){
        maxAnd = i&j;
      }
      if( (i|j) > maxOR && (i|j) < k){
        maxOR = i|j;
      }
      if( (i^j) > maxXOR && (i^j) < k){
        maxXOR = i^j;
      }
      //printf("Here %d\n", maxAnd);
    }
  }
  printf("%d\n", maxAnd);
  printf("%d\n", maxOR);
  printf("%d\n", maxXOR);
}

int main() {
    int n, k;

    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);

    return 0;
}
