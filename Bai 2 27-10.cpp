#include<stdio.h>
#include<stdlib.h>
void nhap(float *a, int n, int m){
	for(int i = 0;i < n; i++){
		for(int j = 0;j<m;j++){
			scanf("%f", a+i*m+j);
		}
	}
}
void in(float *a, int n, int m){
	for(int i = 0;i < n; i++){
		for(int j = 0;j<m;j++){
			printf("%.2f ", *(a+i*m+j));
		}
	printf("\n");
	}
}
int main(){
	int n,m;
	float *a;
	printf("Nhap so phan tu trong mang 2 chieu: ");
	scanf("%d %d", &n, &m);
	
	a = (float*)malloc(n* m* sizeof(int));
	nhap(a,n,m);
	in(a,n,m);
	free(a);
	a = NULL;
	return 0;
}
