#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void quadForm(int a, int b, int c, int* answers){
  answers = malloc(sizeof(int)*2);
  int a1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
  printf("%d\n", a1 );
  int a2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
  printf("%d\n", a2 );
  answers[0] = a1;
  answers[1] = a2;
}

void main(){
  int a,b,c = 0;
  scanf("%d %d %d", &a,&b,&c);
  int* ans;
  quadForm(a,b,c, ans);
  for(int i = 0; i < 2; i++){
    printf("%d\n", ans[i]);
  }
}
