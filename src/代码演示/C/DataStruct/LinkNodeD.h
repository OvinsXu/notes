#include<stdlib.h>
#include<stdio.h>
typedef struct LNode{
        ElemType data;
        struct LNode * prior;
        struct LNode * next;
}LinkNodeD;


//0.整体创建 头插法
void CreateListF(LinkNodeD ** L,ElemType a[],int n){
        LinkNodeD * s;
        int i = 0;
        (*L) = (LinkNodeD *)malloc(sizeof(LinkNodeD));
        (*L)->prior = NULL;
        (*L)->next = NULL;

        while(i<n){
            s = (LinkNodeD *)malloc(sizeof(LinkNodeD));
            s->data = a[i];
            if((*L)->next != NULL){
                (*L)->next->prior = s;//针对如果L表上本来就有节点的情况
            }
            s->prior = (*L);
            s->next = (*L)->next;
            (*L)->next = s;
            i++;
        }

}
//0.整体创建 尾插法
void CreateListR(LinkNodeD ** L,ElemType a[],int n){
        LinkNodeD * s,* r;
        int i = 0;
        (*L) = (LinkNodeD *)malloc(sizeof(LinkNodeD));
        (*L)->prior = NULL;
        r = (*L);

        while(i<n){
            s = (LinkNodeD *)malloc(sizeof(LinkNodeD));
            s->data = a[i];
    
            r->next = s;
            s->prior = r;
            r = s;
            i++;
        }
        r->next = NULL;
}

//1.初始化顺序表
void InitList(LinkNodeD ** L){
        (*L) = (LinkNodeD *)malloc(sizeof(LinkNodeD));
        (*L)->prior = NULL;
        (*L)->next = NULL;
}

//2.销毁顺序表
void DestroyList(LinkNodeD ** L){
        LinkNodeD * pre = *L,*p = (*L)->next;
        while(p != NULL){
            free(pre);
            pre = p;
            p = pre->next;
        }
        free(pre);
}
//3.判断顺序表是否为空
int ListEmpty(LinkNodeD * L){
        return (L->next == NULL);
}
//4.返回顺序表长度
int ListLength(LinkNodeD * L){
        int i = 0;
        LinkNodeD * p = L;
        while(p->next != NULL){
            i++;
            p = p->next;
        }
        return i;
}

//5.输出顺序表
void DisplayList(LinkNodeD * L){
        LinkNodeD * p = L->next;
        while(p != NULL){
            printf("%d\t",p->data);//顺序表的元素类型不一定为int，故此处语句用 %d 并不合适，还需做处理，此处仅当演示作用,后面的判断对比处，也不要计较，理解思路即可
            p = p->next;
        }
        printf("\n");

}

//6.求顺序表中的某个元素
int GetElem(LinkNodeD * L,int i,ElemType * e){
        int j = 0;
        LinkNodeD * p = L;
        if(i<1){
            return 0;
        }
        while(j<i && p->next != NULL){
            p = p->next;
            j++;
        }
        if(p == NULL){
            return 0;
        }else{
            *e = p->data;
            return 1;
        }
}
//7.找元素返回序号
int LocateElem(LinkNodeD * L,ElemType e){
        int i = 0;
        LinkNodeD * p = L;

        while(p->next != NULL && p->data != e){
            p = p->next;
            i++;
        }

        if(p->next == NULL){
            return 0;
        }else{
            return i;
        }

}
//8.插入元素
int ListInsert(LinkNodeD ** L,int i,ElemType e){
        int j = 0;
        LinkNodeD * p = (*L),*s;

        if(i<0){
            return 0;
        }

        while(j<i-1 && p->next != NULL){
            j++;
            p = p->next;
        }
        if(p->next == NULL){
            return 0;
        }else{
            s = (LinkNodeD *)malloc(sizeof(LinkNodeD));
            s->data = e;
            s->next = p->next;
            p->next = s;
            return 1;
        }
}
//9.删除元素
int ListDelete(LinkNodeD ** L,int i,ElemType *e){
        int j = 0;
        LinkNodeD * p = *L, * s;

        if(i<1){
            return 0;
	}

        while(j < i-1 && p->next != NULL){
            j++;
            p = p->next;
        }
        if(p == NULL){
            return 0;
        }else{
            s = p->next;
            if(s == NULL){
                return 0;
            }
            *e = s->data;
            p->next =s->next;
            free(s);
            return 1;
        }

}
//10节点逆置
void reverse(LinkNodeD ** L){
    LinkNodeD * p = (*L)->next,* q;
    p->prior = NULL;
    while(p->next != NULL){
        q = p->next;
        p->next = p->prior;
        p->prior = q;
        p = q;
    }
    q->next = q->prior;
    q->prior = (*L);
    (*L)->next = q;
    
}