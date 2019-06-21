#include <stdio.h>

int n;
int k;
int A[100000];


int p(int capacity) {
    int i;
    int needed_bag_num = 0;
    for(i=0; i<n; i++) {
	needed_bag_num += (A[i] + capacity - 1)/capacity;
    }
    return needed_bag_num <= k;
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
      int capacity = (ub + lb)/2;
      if(p(capacity)) {
	  ub = capacity;
      }
      else {
	  lb = capacity;
      }
  }

  printf("%d\n", ub);

  return 0;
}
