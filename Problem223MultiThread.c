#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

typedef struct memory_th{
  int total;
  int b;
  int max;
}memory_th;
void inputGet(int size, int* trials);
void acuteTris(int max);
int equationCheck(int a, int b, int c);
void* bVals(void* b);
int getTotals(memory_th* tots, int max);

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
  pthread_t* threads = malloc(sizeof(pthread_t)*(max/3));
  memory_th* mems = malloc(sizeof(memory_th)*(max/3));
  pthread_attr_t pthread_custom_attr;
  pthread_attr_init(&pthread_custom_attr);
  for(int i =0; i < (max/3); i++){
    mems[i].b = i+1;
    mems[i].total = 0;
    mems[i].max = max;
    pthread_create(&threads[i],NULL, bVals, (void*)&mems[i]);
    }
    for(int j =0; j < max/3; j++){
      pthread_join(threads[j], NULL);
    }

    int total;
    total = getTotals(mems, max/3);
  printf("%d\n", total);
}

int getTotals(memory_th* tots, int max){
  int total = 0;
  for(int i =0; i < max; i++ ){
    //printf("%d\n", tots[i].total);
    total += tots[i].total;
  }
  return total;
}


void* bVals(void* b){
  memory_th temp;
  temp.b = ((memory_th*)b)->b;
  temp.max = ((memory_th*)b)->max;
  temp.total = 0;
  for(int j = temp.b; j <= (temp.max/3-temp.b); j++){
      if(equationCheck(temp.b,j,temp.max) == 1){
        temp.total += 1;
      }
    }
    ((memory_th*)b)->b = temp.b;
    ((memory_th*)b)->total = temp.total;
    return NULL;
}

int equationCheck(int a, int b, int per){
  int c = sqrt( (double)(a*a + b*b - 1) );
  int l = a + b + c;
  int l1 = a*a + b*b;
  int r = c*c + 1;

  if(l <= per && l1 == r){
    //printf("%d %d %d\n", a,b,c);
    //printf("%d\n", c);
    return 1;
  }else{
    return 0;
  }
}
