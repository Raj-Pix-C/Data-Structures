#include<stdio.h>

/* selection sort */

int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i = 0; i < n; i++)scanf("%d",&a[i]);
	
	for(int i = 0; i < n; i++){
		int curr_min = a[i];
		int curr_min_loc = i;
		for(int j = i+1; j < n; j++){
			if(curr_min > a[j]){
				curr_min = a[j];
				curr_min_loc = j;
			}
		}
		int temp = a[i];
		a[i] = curr_min;
		a[curr_min_loc] = temp;
	}

	for(int i = 0; i < n; i++)printf("%d ",a[i]);

}