#include<stdio.h>
#include<stdlib.h>
int main(){
	int n;
	float *a;
	
	printf("Nhap so phan tu: ");
	scanf("%d", &n);
	
	a = (float*)malloc(n* sizeof(int));
	if(a == NULL){
		printf("Khong du bo nho");
		return 1;
	}else{
		printf("Nhap cac phan tu: ");
		for(int i = 0; i < n; i++){
			scanf("%f", &a[i]);
		}
		printf("Mang vua nhap: ");
		for(int i = 0; i < n; i++){
			printf("%.2f ", a[i]);
		}
	}
	free(a);
}
