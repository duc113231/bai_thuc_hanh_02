#include<stdio.h>
#include<stdlib.h>
typedef struct{
    char hoten[30];
    int masv;
    float d1,d2,d3; 
}Data;
typedef struct tagNode{
    Data infor;
    struct tagNode *next, *prev; 
}Node;
typedef struct{
    Node *pHead;
    Node *pTail;
    int spt; 
}LList;
void initList(LList *L){
    L ->pHead = NULL;
    L ->pTail = NULL;
    L ->spt = 0; 
} 
int emptyList(LList L){
    return (L.spt == 0); 
} 
void insert_Head(LList *L, Data x){
    Node *pp;
    pp = (Node*)malloc(sizeof(Node));
    pp -> infor = x;
    pp -> next = NULL;
    pp -> prev = NULL; 
    if(emptyList(*L)){
        L -> pHead = pp;
        L -> pTail = pp; 
    }else{
        L->pHead->prev=pp;
		pp->next = L->pHead; 
        L -> pHead = pp; 
    } 
    L -> spt++; 
} 
void insert_Tail(LList *L, Data x){
    Node *pp;
    pp = (Node*)malloc(sizeof(Node));
    if(pp == NULL)return; 
    pp -> infor = x;
    pp -> next = NULL;
	pp -> prev = NULL; 
    if(emptyList(*L)){
        L -> pHead = pp;
        L -> pTail = pp; 
    }else{
        L -> pTail -> next = pp;
        pp -> prev = L->pTail; 
        L -> pTail = pp; 
    }
    L -> spt++; 
} 
void insert_After(LList *L, Node *q,Data x){
    Node *pp;
    if(NULL == q) return;
    else{
        pp = (Node*)malloc(sizeof(Node));
        pp -> infor = x;
        pp -> next = q-> next;
		q->next -> prev = pp;
		q->next = pp;
		pp -> prev = q;
        if(q == L->pTail) L->pTail = pp;
        L -> spt++; 
    } 
} 
void del_Head(LList *L){
    Node *pp;
    if(emptyList(*L)) return;
    else{
        pp = L->pHead;
        L ->pHead = pp->next;
        if(L->pHead != NULL) L->pHead->prev = NULL; 
        free(pp);
        L -> spt--;
        if(L -> pHead == NULL) L -> pTail = NULL; 
    } 
} 
void del_After(LList *L, Node *q){
    Node *pp;
    if(NULL == q) return;
    else{
        pp =  q -> next;
        q->next  = pp->next;
        if(pp->next != NULL) pp->next->prev = q; 
        free(pp);
        L ->spt--; 
        if(NULL == L->pTail || pp==L->pTail){
        	L->pTail = q; 
		} 
    } 
}
void del_K(LList *L,int id){
    Node *pp =  L ->pHead, *q;
    while(pp!=NULL && (pp->infor.masv != id)){
        pp = pp->next; 
    }
    if(NULL == pp) return;
    else
        if(pp == L->pHead) del_Head(L);
        else {
        	q=pp->prev;
			del_After(L,q); 
		} 
}
void tach(LList L, LList *L1, LList *L2){
    initList(L1);
    initList(L2);
    Node *pp = L.pHead;
    while(pp != NULL){
        float dtb = (pp->infor.d1 + pp->infor.d2 + pp->infor.d3) / 3;
        if(dtb < 4){
            insert_Head(L1, pp->infor);
        }else{
            insert_Head(L2, pp->infor);
        }

        pp = pp->next;
    }
}
void ghep(LList L1, LList L2, LList *L){
    initList(L);

    Node *p1 = L1.pHead;
    Node *p2 = L2.pHead;

    while(p1 != NULL && p2 != NULL){
        insert_Tail(L, p1->infor);
        insert_Tail(L, p2->infor);

        p1 = p1->next;
        p2 = p2->next;
    }

    while(p1 != NULL){
        insert_Tail(L, p1->infor);
        p1 = p1->next;
    }

    while(p2 != NULL){
        insert_Tail(L, p2->infor);
        p2 = p2->next;
    }
}
void nhap(Data *x){
    printf("Nhap ma sv: ");
    scanf("%d", &(x ->masv));
    if(x -> masv > 0){
        printf("Nhap ten sv: "); 
        scanf("%s", (x -> hoten));
        printf("Nhap diem 1: "); 
        scanf("%f", &(x -> d1));
        printf("Nhap diem 2: "); 
        scanf("%f", &(x -> d2));
        printf("Nhap diem 3: "); 
        scanf("%f", &(x -> d3));
    } 
} 
void in(Data x){
    printf("Ten: %s, Ma: %d, diem 1: %.2f, diem 2: %.2f, diem 3: %.2f\n", x.hoten, x.masv, x.d1, x.d2, x.d3);
} 
void processList(LList L){
    Node *pp = L.pHead;
    while(pp != NULL){
        in(pp->infor);
        pp = pp->next; 
    }
} 
void duyetds(LList L){
    Node *p = L.pHead;
    while(p != NULL){
        printf("%d - %s\n", p->infor.masv, p->infor.hoten);
        p = p->next;
    }
}
int main(){
    LList L,L1,L2;
    int kt = 0;
    Data x;
    initList(&L);
    initList(&L1);
    initList(&L2);
    do{
        printf("\n Chuong trinh lam viec voi DSLK don SV\n");
        printf("\n 1: Them nut vao dau danh sach");
        printf("\n 2: Them nut vao cuoi danh sach");
        printf("\n 3: Them nut vao sau mot nut khac trong danh sach");
        printf("\n 4: Xoa nut dau danh sach");
        printf("\n 5: Xoa 1 sau mot nut khac trong danh sach");
        printf("\n 6: Xóa theo id");
        printf("\n 7: Tách ds");
        printf("\n 8: Ghép ds");
        printf("\n 9: duyet ds");
        printf("\n 0: thoat");
        printf("\n Moi ban chon: ");
        int chon;
        scanf("%d", &chon);
        switch(chon){
            case 1:
                printf("Nhap so thong tin sv can them vao dau danh sach\n");
                nhap(&x);
                if(x.masv>0){
                    insert_Head(&L,x); 
                }
                break; 
            case 2:
                printf("Nhap so thong tin sv can them vao cuoi danh sach\n");
                nhap(&x);
                if(x.masv>0){
                    insert_Tail(&L,x); 
                }
                break; 
            case 3: {
            	printf("Nhap so thong tin sv can them");
                int id;
                scanf("%d", &id);
                Node *q = L.pHead;
                while(q != NULL && q->infor.masv != id)
                    q = q->next;
                if(q != NULL){
                    nhap(&x);
                    if(x.masv > 0)
                        insert_After(&L, q, x);
                }
                break;
            } 
            case 4:
                del_Head(&L); 
                break;
            case 5: {
                int id;
                printf("Nhap ma sinh vien muon xoa nut dang sau: ");
                scanf("%d", &id);

                Node *q = L.pHead;

                while(q != NULL && q->infor.masv != id){
                    q = q->next;
                }

                if(q != NULL){
                    del_After(&L, q);
                }else{
                    printf("Khong tim thay nut\n");
                }
                break;
            }
            case 6:{
                printf("Nhap nut ban muon xoa");
                int id;
                scanf("%d", &id);
                del_K(&L, id); 
                break; 
            }
            case 7:
                tach(L, &L1, &L2);
                printf("Danh sach L1:\n");
                processList(L1);
                printf("Danh sach L2:\n");
                processList(L2);
                break;
            case 8:
                ghep(L1, L2, &L);
                printf("Danh sach sau khi ghep:\n");
                processList(L);
                break; 
            case 9:
                processList(L);
                break; 
            case 0:
                printf("Ket thuc");
                kt = 1; 
                break; 
        }  
    }while(kt == 0); 
    return 0; 
} 
