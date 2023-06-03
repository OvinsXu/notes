#include<stdlib.h>
#include<stdio.h>
typedef struct{
	ElemType data[MaxSize];
	int length;
}SqList;


//0.整体创建
void CreateList(SqList ** L,ElemType a[],int n){
	int i = 0;
	(*L) = (SqList *)malloc(sizeof(SqList));
	while(i<n){
		(*L)->data[i] = a[i];
		i++;
	}
	(*L)->length = i;
}

//1.初始化顺序表
void InitList(SqList ** L){
	(*L) = (SqList *)malloc(sizeof(SqList));
	(*L)->length = 0;
}

//2.销毁顺序表
void DestroyList(SqList ** L){
	free(*L);
}
//3.判断顺序表是否为空
int ListEmpty(SqList * L){
	return (L->length == 0);
}
//4.返回顺序表长度
int ListLength(SqList * L){
	return (L->length);
}

//5.输出顺序表
void DisplayList(SqList * L){
	int i = 0;
	for(;i < L->length;i++){
		printf("%d\t",L->data[i]);//顺序表的元素类型不一定为int，故此处语句用 %d 并不合适，还需做处理，此处仅当演示作用,后面的判断对比处，也不要计较，理解思路即可
	}
    printf("\n");
}

//6.求顺序表中的某个元素
int GetElem(SqList * L,int i,ElemType * e){
	if(i<1||i>L->length){
		return 0;
	}
	*e = L->data[i-1];
	return 1;
}
//7.找元素返回序号
int LocateElem(SqList * L,ElemType e){
	int i = 0;
	for(;i < L->length-1;i++){
		if(L->data[i] == e){
			return i+1;
		}
	}
	return 0;
}
//8.插入元素
int ListInsert(SqList ** L,int i,ElemType e){
	int j;
	if(i<1||i>(*L)->length+1){
		return 0;
	}
	i--;
	for(j = (*L)->length;j>i;j--){
		(*L)->data[j] = (*L)->data[j-1];
	}
	(*L)->data[i] = e;
	(*L)->length++;
	return 1;
}
//9.删除元素
int ListDelete(SqList ** L,int i,ElemType *e){
	int j;
	if(i<1||i>(*L)->length+1){
		return 0;
	}
	i--;
	*e = (*L)->data[i];
	for(j = i;j<(*L)->length-1;j++){
		(*L)->data[j] = (*L)->data[j+1];
	}
	(*L)->length--;
	return 1;
}
