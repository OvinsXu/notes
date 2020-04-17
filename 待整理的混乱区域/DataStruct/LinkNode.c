#define ElemType int
#include"LinkNode.h"

int main(){
	int i;
	ElemType a[] = {1,2,3,4,5,6,7,8};
	LinkNode * L;
	ElemType e;
	
	CreateListF(&L,a,8);

	printf("打印顺序表:\n");
	DisplayList(L);
	
	printf("顺序表是否(1/0)为空:%d\n",ListEmpty(L));
	printf("顺序表长度:%d\n",ListLength(L));
	
	if(GetElem(L,4,&e)){
		printf("打印第4个元素:%d\n",e);
	}else{
		printf("输入序号不正确!\n");
	}
	
	if(LocateElem(L,7)){
		printf("第%d个元素为7\n",LocateElem(L,7));
	}else
	{
		printf("没有该元素!\n");
	}
	
	i = ListInsert(&L,4,0);
	if(i){
		printf("插入成功!\n");
	}else
	{
		printf("插入失败!\n");
	}
	
	printf("打印顺序表:\n");
	DisplayList(L);

	i = ListDelete(&L,4,&e);
	if(i){
		printf("删除成功!\n");
	}else
	{
		printf("删除失败!\n");
	}

	printf("打印顺序表:\n");
	DisplayList(L);

	return 0;
}