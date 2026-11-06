#include <stdio.h>
struct Data {
    int masv;
    char ten[50];
    float d1, d2, d3;
};

struct Node {
    Data infor;
    Node *link;
};

struct LList {
    Node *pHead;
};

void initL(LList *L) {
    L->pHead = NULL;
}

void insertHead(LList *L, Data x) {
    Node *p = new Node;
    p->infor = x;
    p->link = L->pHead;
    L->pHead = p;
}
void nhapdl(Data *x){
	printf("Nhap ma: ");
	scanf("%d", &(x->masv));
	if(x->masv>0){
		printf("Nhap ten: \n");
		scanf("%s", &(x->ten));
		printf("Nhap diem m1: \n");
		scanf("%f", &(x->d1));
		printf("Nhap diem m2: \n");
		scanf("%f", &(x->d2));
		printf("Nhap diem m3: \n");
		scanf("%f", &(x->d3));
	}
}
void tao_ds(LList *L){
	initL(L);
	Data x;
	do{
		nhapdl(&x);
		if(x.masv>0) insertHead(L,x);
	}while(x.masv>0);
}
void indl(Data x){
	printf("%s, %d, %.2f, %.2f, %.2f\n", x.ten, x.masv, x.d1, x.d2, x.d3);
}
void duyet_ds(LList L){
	Node *pp = L.pHead;
	while(pp != NULL){
		indl(pp -> infor);
		pp = pp -> link;
	}
}
int main(){
	LList ds1;
	initL(&ds1);
	tao_ds(&ds1);
	duyet_ds(ds1);
}
