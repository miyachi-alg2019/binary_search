#include <stdio.h>

int n;
int k;
int A[100000];


int can_work(int max_time) {
    int i = 0;
    int people_num = k, sum_time = 0;
    while(i < n && people_num > 0) {
	int t = sum_time + A[i];
	if(t > max_time) {
	    sum_time = 0;
	    people_num -= 1;
	}
	else {
	    sum_time = t;
	    i += 1;
	}
    }
    return i == n;
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
      int max_time = (ub+lb)/2;
      if(can_work(max_time)) ub = max_time;
      else lb = max_time;
  }

  printf("%d\n", ub);
      
  return 0;
}
