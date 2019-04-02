#include <stdio.h>
#include <stdlib.h>
#include <math.h>


long long tribSeq(int k, long long a, long long b, long long c);

int main(){
  int k =0;
  long long t1, t2, t3 =0;
  int j = 5;

  scanf("%lld %lld %lld %d", &t1,&t2,&t3,&k);
  //printf("%d\n", tribSeq(5, t1,t2,t3));
  while((tribSeq(j,t1,t2,t3)%27) != 0 ){
    j++;
    printf("%lld\n", tribSeq(j,t1,t2,t3) );
  }
  //printf("done after %d iters , the value is %d\n", j, tribSeq(j,t1,t2,t3) );
  return 0;
}


long long tribSeq(int k, long long a, long long b, long long c){
  if(k > 3){
    tribSeq(k-1, b, c, (a+b+c));
  }else{
    return c;
  }
}
