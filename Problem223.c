#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void inputGet(int size, int* trials);
void acuteTris(int max);
int equationCheck(int a, int b, int c);

int main(){
  int size =0;
  int* trials;
  scanf("%d", &size);
  trials = malloc(sizeof(int)*size);
  inputGet(size,trials);
  for(int i = 0; i < size; i++){
    acuteTris(trials[i]);
  }
  free(trials);
    return 0;
}

void inputGet(int size, int* trials){
    for(int i = 0; i < size; i++){
      int temp = 0;
      scanf("%d", &temp);
      trials[i] = temp;
    }
}

void acuteTris(int max){
  int total = 0;
  for(int i =1; i <= (max); i++){
    for(int j = i; j <= (max); j++){
        if(equationCheck(i,j,max) == 1){
          total+=1;
        }
      }
    }
  printf("%d\n", total);
}

int equationCheck(int a, int b, int per){
  int c = sqrt( (double)(a*a + b*b + 1) );
  int l = a + b + c;
  int l1 = a*a + b*b;
  int r = c*c + 1;

  if(l <= per && l1 == r){
    printf("%d %d %d\n", a,b,c);
    //printf("%d\n", c);
    return 1;
  }else{
    return 0;
  }
}
