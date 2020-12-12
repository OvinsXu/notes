#define ElemType int
#define MaxSize 50
#include"SqStack.h"

int main(){
	int i;
	SqStack * S;
	ElemType e;
	ElemType a[10] = {10,9,8,7,6,5,4,3,2,1};
	
	InitList(&S);// 这里一定要有初始化
	for (i = 0; i < 10; i++)
	{
		Push(&S,a[i]);
		
	}
	for (i = 0; i < 10; i++)
	{
		Pop(&S,&e);
		printf("%d\t",e);
	}
	printf("\n");
	

	return 0;
}
