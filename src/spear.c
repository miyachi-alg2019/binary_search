#include <stdio.h>

int n;
int k;
int A[100000];


int can_make(int length) {
    int i;
    int total = 0;
    for(i=0; i<n; i++) {
	total += A[i]/length;
    }
    return total >= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = 1000000000;
  while(ub-lb > 1) {
      int length = (ub + lb)/2;
      if(can_make(length)) lb = length;
      else ub = length;
  }

  printf("%d\n", lb);

  return 0;
}
