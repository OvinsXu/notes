#include <stdlib.h>
#include <stdio.h>
typedef struct LinkNode{
	ElemType data;
	struct LinkNode * next;
} LinkStNode;

//1.初始化
void InitStack(LinkStNode **S)
{
	(*S) = (LinkStNode *)malloc(sizeof(LinkStNode));
	(*S)->next = NULL;
}

//2.销毁顺序表
void DestroyStack(LinkStNode **S)
{
    LinkStNode * pre = *S, * p = (*S)->next;
    while(p != NULL){
        free(pre);
        pre = (*S);
        p = pre->next;
    }
	free(pre);
}

//3.push
void Push(LinkStNode **S, ElemType e)
{
    LinkStNode * p = (LinkStNode *)malloc(sizeof(LinkStNode));
    p->data = e;
    p->next = (*S)->next;
    (*S)->next = p;
}

//4.pop
int Pop(LinkStNode ** S, ElemType *e)
{
	LinkStNode * p = (*S)->next;
	if ((*S)->next == NULL)
	{
		printf("栈为空");
		return 0;
	}
	*e = p->data;
	(*S)->next = p->next;
	free(p);
	return 1;
}

//5.GetTop
int GetTop(LinkStNode ** S,ElemType * e){
	if ((*S)->next == NULL)
	{
		printf("栈为空");
		return 0;
	}
	*e = (*S)->next->data;
	return 1;
}