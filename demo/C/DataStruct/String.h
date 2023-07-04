#include<stdio.h>

#define MaxSize 100 //字符串最大长度
typedef struct{
	char ch[MaxSize];
	int length;
}SqString;

/**********************************************/

//生成串
void StrAssign(SqString & s,char cstr[]);

//销毁串
void DestroyStr(SqString & s);

//串的复制
void StrCopy(SqString & s,SqString t);

//判断串相等
bool StrEqual(SqString & s,SqString t);

//求串长
int StrLength(SqString & s);

//串的连接
SqString Concat(SqString s,SqString t);

//求子串
SqString SubStr(SqString s,int i,int j);

//子串的插入
SqString SubStr(SqString s1,int i,SqString s2);

//子串的删除
SqString DelStr(SqString s,int i,int j);

//子串的替换
SqString ReqStr(SqString s,int i,int j,SqString t);

//输出串
void DispStr(SqString s);


/**********************************************/

//生成串
void StrAssign(SqString & s,char cstr[]){
	int i = 0;
	while(cstr[i] != '\0'){
		s.ch[i] = cstr[i];
		i++;
	}
	s.length = i;
}

//销毁串
void DestroyStr(SqString & s){
	
}

//串的复制
void StrCopy(SqString & s,SqString t){
	int i;
	for(i = 0;i < t.length;i++){
		s.ch[i] = t.ch[i];
	}
	s.length = t.length;
}

//判断串相等
int StrEqual(SqString & s,SqString t){
	int IsSame = 1;
	int i;

	if(s.length != t.length){
		IsSame = 0;
	}else{
		for (i = 0; i < s.length; i++)
		{
			if(s.ch[i] != t.ch[i]){
				IsSame = 0;
				break;
			}
		}
		
	}

	return IsSame;
}

//求串长
int StrLength(SqString & s){
	return s.length;
}

//串的连接
SqString Concat(SqString s,SqString t){
	SqString str;
	int i;

	str.length = s.length + t.length;
	for (i = 0; i < s.length; i++)
	{
		str.ch[i] = s.ch[i];
	}
	for (i = 0; i < t.length; i++)
	{
		str.ch[s.length + i] = t.ch[i];
	}
	
	return str;
}

//求子串
SqString SubStr(SqString s,int i,int j){
	int k;
	SqString str;
	str.length = 0;
	
	if(i<=0 || i>s.length || j<0 || i+j-1 > s.length){
		return str;
	}
	for (k = i-1; i < i+j-1; k++){
		str.ch[k-i+1] = s.ch[k];
	}
	str.length = j;

	return str;
}

//子串的插入
SqString SubStr(SqString s1,int i,SqString s2){
	int j;
	SqString str;
	str.length = 0;
	if(i<=0 || i>s1.length + 1){
		return str;
	}
	for (j = 0; j < i-1; j++){
		str.ch[j] = s1.ch[j];
	}
	for (j = 0; j < s2.length; j++)
	{
		str.ch[i+j-1] = s2.ch[j];
	}
	for(j = i-1;j < s1.length;j++){
		str.ch[j + s2.length] = s2.ch[j];
	}
	str.length = s1.length + s2.length;
	
	return str;
}

//子串的删除
SqString DelStr(SqString s,int i,int j){
	int k;
	SqString str;
	str.length = 0;
	
	if(i<=0 || i>s.length || j<0 || i+j-1 > s.length){
		return str;
	}
	for(k = 0;k < i-1; k++){
		str.ch[k] = s.ch[k];
	}
	for(k = i + j - 1;k < s.length; k++){
		str.ch[k - j] = s.ch[k];
	}

	return str;
}

//子串的替换
SqString ReqStr(SqString s,int i,int j,SqString t){
	int k;
	SqString str;
	str.length = 0;
	
	if(i<=0 || i>s.length || j<0 || i+j-1 > s.length){
		return str;
	}
	for(k = 0;k < i-1; k++){
		str.ch[k] = s.ch[k];
	}
	for(k = 0;k < t.length; k++){
		str.ch[i + k - 1] = s.ch[k];
	}
	for(k = i + j - 1;k < s.length; k++){
		str.ch[t.length + k - j] = s.ch[k];
	}
	str.length = s.length - j + t.length;

	return str;
}

//输出串
void DispStr(SqString s){
	int i;
	if(s.length > 0){
		for(i = 0;i<s.length;i++){
			printf("%c\t",s.ch[0]);
		}
		printf("\n");
	}
}