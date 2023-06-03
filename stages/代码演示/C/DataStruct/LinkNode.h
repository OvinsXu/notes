#include<stdlib.h>
#include<stdio.h>
typedef struct LNode{
        ElemType data;
        struct LNode * next;
}LinkNode;


//0.整体创建 头插法
void CreateListF(LinkNode ** L,ElemType a[],int n){
        LinkNode * s;
        int i = 0;
        (*L) = (LinkNode *)malloc(sizeof(LinkNode));
        (*L)->next = NULL;

        while(i<n){
            s = (LinkNode *)malloc(sizeof(LinkNode));
            s->data = a[i];
            s->next = (*L)->next;
            (*L)->next = s;
            i++;
        }

}
//0.整体创建 尾插法
void CreateListR(LinkNode ** L,ElemType a[],int n){
        LinkNode * s,* r;
        int i = 0;
        (*L) = (LinkNode *)malloc(sizeof(LinkNode));
        r = (*L);

        while(i<n){
            s = (LinkNode *)malloc(sizeof(LinkNode));
            s->data = a[i];
            r->next = s;
            r = s;
            i++;
        }
        r->next = NULL;
}

//1.初始化顺序表
void InitList(LinkNode ** L){
        (*L) = (LinkNode *)malloc(sizeof(LinkNode));
        (*L)->next = NULL;
}

//2.销毁顺序表
void DestroyList(LinkNode ** L){
        LinkNode * pre = *L,*p = (*L)->next;
        while(p != NULL){
            free(pre);
            pre = p;
            p = pre->next;
        }
        free(pre);
}
//3.判断顺序表是否为空
int ListEmpty(LinkNode * L){
        return (L->next == NULL);
}
//4.返回顺序表长度
int ListLength(LinkNode * L){
        int i = 0;
        LinkNode * p = L;
        while(p->next != NULL){
            i++;
            p = p->next;
        }
        return i;
}

//5.输出顺序表
void DisplayList(LinkNode * L){
        LinkNode * p = L->next;
        while(p != NULL){
            printf("%d\t",p->data);//顺序表的元素类型不一定为int，故此处语句用 %d 并不合适，还需做处理，此处仅当演示作用,后面的判断对比处，也不要计较，理解思路即可
            p = p->next;
        }
        printf("\n");

}

//6.求顺序表中的某个元素
int GetElem(LinkNode * L,int i,ElemType * e){
        int j = 0;
        LinkNode * p = L;
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
int LocateElem(LinkNode * L,ElemType e){
        int i = 0;
        LinkNode * p = L;

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
int ListInsert(LinkNode ** L,int i,ElemType e){
        int j = 0;
        LinkNode * p = (*L),*s;

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
            s = (LinkNode *)malloc(sizeof(LinkNode));
            s->data = e;
            s->next = p->next;
            p->next = s;
            return 1;
        }
}
//9.删除元素
int ListDelete(LinkNode ** L,int i,ElemType *e){
        int j = 0;
        LinkNode * p = *L, * s;

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
