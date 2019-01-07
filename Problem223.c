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

void main(){
  int size =0;
  int* trials;
  scanf("%d", &size);
  trials = malloc(sizeof(int)*size);
  inputGet(size,trials);
  for(int i = 0; i < size; i++){
    acuteTris(trials[i]);
  }
  free(trials);
}

void inputGet(int size, int* trials){
    for(int i = 0; i < size; i++){
      int temp = 0;
      scanf("%d", &temp);
      trials[i] = temp;
    }
}

void acuteTris(int max){
  pthread_t* threads = malloc(sizeof(pthread_t)*(max));
  memory_th* mems = malloc(sizeof(memory_th)*(max));
  pthread_attr_t pthread_custom_attr;
  pthread_attr_init(&pthread_custom_attr);
  for(int i =1; i <= (max); i++){
    mems[i-1].b = i;
    mems[i-1].total = 0;
    mems[i-1].max = max;
    pthread_create(&threads[i-1],NULL, bVals, (void*)&mems[i-1]);
    }
    for(int i =0; i < (max); i++){
      pthread_join(threads[i], NULL);
    }

    int total;
    total = getTotals(mems, max);
  printf("%d\n", total);
}

int getTotals(memory_th* tots, int max){
  int total = 0;
  for(int i =0; i < max; i++ ){
    total += tots[i].total;
  }
  return total;
}


void* bVals(void* b){
  memory_th temp;
  temp.b = ((memory_th*)b)->b;
  temp.max = ((memory_th*)b)->max;
  temp.total = ((memory_th*)b)->total;
  for(int j = temp.b; j <= (temp.max-temp.b); j++){
      if(equationCheck(temp.b,j,temp.max) == 1){
        temp.total += 1;
      }
    }
    ((memory_th*)b)->b = temp.b;
    ((memory_th*)b)->total = temp.total;
    return NULL;
}

int equationCheck(int a, int b, int per){
  int c = sqrt( (double)(a*a + b*b + 1) );
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
