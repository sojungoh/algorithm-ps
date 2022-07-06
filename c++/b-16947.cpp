#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, s1, s2;
	scanf("%d", &n);

	int *hasEdge = (int*)malloc(sizeof(int)*n);

	for(int i = 0; i < n; i++){
		scanf("%d %d", &s1, &s2);
		if(s1 < s2)
			hasEdge[s1][s2] = 1;
		else
			hasEdge[s2][s1] = 1;
	}




	return 0;
}
