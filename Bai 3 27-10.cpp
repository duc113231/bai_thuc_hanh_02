#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char hoten[50];
	int masv;
	float d1,d2,d3;
}SV;
void nhap(SV *ds, int n){
	for(int i = 0;i<n;i++){
		printf("Nhap sv thu %d: \n", i+1);
		printf("Nhap ho ten: ");
		scanf(" %[^\n]", ds[i].hoten);
		printf("Nhap ma sv: ");
		scanf("%d", &ds[i].masv);
		printf("Nhap diem: ");
		scanf("%f %f %f", &ds[i].d1, &ds[i].d2, &ds[i].d3);
	}
}
void in(SV *ds, int n){
	for(int i = 0;i<n;i++){
		printf("sv thu %d: \n", i+1);
		printf("Ho ten: %s\n", ds[i].hoten);
		printf("Ma sv: %d\n", ds[i].masv);
		printf("diem:  %.2f %.2f %.2f\n", ds[i].d1, ds[i].d2, ds[i].d3);
	}
}
int main(){
	int n;
	SV *ds;
	printf("Nhap so luong sv: ");
	scanf("%d", &n);
	ds = (SV*)malloc(n*sizeof(SV));
	if(ds == NULL){
		printf("Khong du bo nho");
		return 1;
	}
	nhap(ds,n);
	in(ds,n);
	free(ds);
	ds = NULL;
	return 0;
}
