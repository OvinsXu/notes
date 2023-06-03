#include <stdlib.h>
#include <stdio.h>
typedef struct
{
	ElemType data[MaxSize];
	int top;
} SqStack;

//1.初始化
void InitList(SqStack **S)
{
	(*S) = (SqStack *)malloc(sizeof(SqStack));
	(*S)->top = -1;
}

//2.销毁顺序表
void DestroyList(SqStack **S)
{
	free(*S);
}

//3.push
int Push(SqStack **S, ElemType e)
{
	if ((*S)->top == MaxSize - 1)
	{
		return 0;
	}
	(*S)->top++;
	(*S)->data[(*S)->top] = e;
	return 1;
}

//4.pop
int Pop(SqStack ** S, ElemType *e)
{
	if ((*S)->top == -1)
	{
		return 0;
	}
	*e = (*S)->data[(*S)->top];
	(*S)->top--;
	return 1;
}

//5.GetTop
int GetTop(SqStack ** S,ElemType * e){
	if ((*S)->top == -1)
	{
		return 0;
	}
	*e = (*S)->data[(*S)->top];
	return 1;
}