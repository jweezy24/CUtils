#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
int calcVol(triangle tr){
  int p = (tr.a + tr.b + tr.c)/2;
  int area = sqrt(p * (p-tr.a) * (p-tr.b) * (p-tr.c));
  if(area <= 0){
    area = 1;
  }
  return area;
}
void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
  triangle* sortedTris = malloc(sizeof(triangle)*n);
  for(int i =0; i < n; i++){
    sortedTris[i].a = 0;
    sortedTris[i].b = 0;
    sortedTris[i].c = 0;
  }
  int tempArea = 0;
  int lastTri = 0;
  for(int i=0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(tempArea < calcVol(tr[j]) && tr[j].a != 0){
        tempArea = calcVol(tr[j]);
        lastTri = j;
      }
    }
    printf("Checking Shit %d %d %d %d\n", calcVol(tr[1]), tr[1].a, tr[1].b, tr[1].c );
    sortedTris[i].a = tr[lastTri].a;
    sortedTris[i].b = tr[lastTri].b;
    sortedTris[i].c = tr[lastTri].c;
    tr[lastTri].a = 0;
    tr[lastTri].b = 0;
    tr[lastTri].c = 0;
    tempArea = 0;
  }
  int counter = 0;
  for(int i = n-1; i >= 0; i--){
    tr[counter].a = sortedTris[i].a;
    tr[counter].b = sortedTris[i].b;
    tr[counter].c = sortedTris[i].c;
    counter++;
  }
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
