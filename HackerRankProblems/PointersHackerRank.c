#include <stdio.h>
#include <stdlib.h>

void update(int *a,int *b) {
    // Complete this function
    int tempA = *a;
    int tempB = *b;
    int tempSum = tempA+tempB;
    int tempDiff = abs(tempA-tempB);
    *a = tempSum;
    *b = tempDiff;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
