#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char s[6];
    scanf("%s", s);
    //Complete the code to calculate the sum of the five digits on n.
    int total = 0;
    for(int i = 0; i < strlen(s); i++){
      int x = s[i] - '0';
      total+=x;
    }
    printf("%d\n", total);
    return 0;
}
