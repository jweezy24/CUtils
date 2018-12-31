#include <stdio.h>

//euclidean
int GCD(int a, int b){
  int temp = 0;
  if(a == 0 || b == 0){
    //saves a couple lines of code. if one of them is zero adding them together
    //wont matter
    return a+b;
  }
  if(a < b){
    temp = b%a;
    GCD(temp, a);
  }else{
    temp = a%b;
    GCD(temp, b);
  }
}

void main(){
  int a = 0;
  int b = 0;

  scanf("%d", &a);
  scanf("%d", &b);
  printf("GCD is %d", GCD(a,b));
}
