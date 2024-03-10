#include <stdio.h>
#include <stdlib.h>

void bolha(int n, int *v) {
	int i, j, temp;
	
	for(i = n - 1; i > 0; i--) {
		for(j = 0; j < i; j++) {
			if(v[j] > v[j +1]) {
				temp = v[j];
				v[j]  = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}
}

int main() {
	int v[5] = {10, 6 ,4, 3, 0}, i;
	
	printf("Unsorted vector: \n");
	for(i = 0; i < 5; i++) 
		printf("%d ", v[i]);
	
	bolha(5, v);
	
	printf("\nApplied bubble sort: \n");
	
	for(i = 0; i < 5; i++)
		printf("%d ", v[i]);
	return 0;
}
