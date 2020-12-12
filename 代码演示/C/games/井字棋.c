#include<stdio.h>
#include<string.h>
#include<windows.h> 
	//����ġ�\���Ǻ���������� ������̫����Ҫ����ʱʹ�� 
#define CHECK(j1, i1, j2, i2, j3, i3) \
    if (s->board[j1][i1] != -1 && s->board[j1][i1] == s->board[j2][i2] && s->board[j1][i1] == s->board[j3][i3]) \
        return s->board[j1][i1] == 0 ? 1 : -1;


//����һ��3*3������ 
typedef struct{
	int board[3][3];
	int turn;
}state;

int evaluate(const state* s) {
    int i;
    for (i = 0; i < 3; i++) {
        CHECK(i, 0, i, 1, i, 2);    // �ж�ˮƽ���� 
        CHECK(0, i, 1, i, 2, i);    // �ж���ֱ���� 
    }
    CHECK(0, 0, 1, 1, 2, 2);        // �ж϶�б���� 
    CHECK(0, 2, 1, 1, 2, 0);        
    return 0;
}	

void init(state* s){
	int i,j;
	//�����и��Ӷ�����Ϊ�� 
	for(j=0;j<3;j++){
		for(i=0;i<3;i++){
			s->board[j][i] = -1;
		}
	}
	
	s->turn = 0;
}



void display(const state* s){
	int i,j;
	
	HANDLE hdl=GetStdHandle(STD_OUTPUT_HANDLE);  //��ȡ����̨���
	
	for(j = 0;j<3;j++){

		for(i =0;i<3;i++){
			switch(s->board[j][i]){
				case -1:printf(" %d ",j*3+i+1);
				break;
				case 0:
					SetConsoleTextAttribute(hdl,FOREGROUND_GREEN);  
					printf(" O ");
					SetConsoleTextAttribute(hdl,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
					 
				break;
				case 1:
					SetConsoleTextAttribute(hdl,FOREGROUND_RED);  
					printf(" X ");			
					SetConsoleTextAttribute(hdl,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
					
				break;
			}
			
			if(i<2)
				printf("|");
			else
				printf("\n");
				
	}
			if(j<2)
				printf("---+---+---\n");
			else
				printf("\n");
							
		
		

	}
}

/*
//��ӡ������ 
void display(const state* s){
	int i,j;
	for(j = 0;j<3;printf(++j<3?"---+---+---\n":"\n"))
		for(i =0;i<3;putchar("||\n"[i++]))
		
			//��ABCD...��[x],��ʾ��ABCD...���е� x+1 �� Ԫ�� 
			printf(" %c ",s->board[j][i]==-1?'1'+j*3+i:"OX"[s->board[j][i]]);
}
*/

int move(state* s,int i,int j) {
	if(s->board[j][i]!=-1)
		return 0;
	//turn������������ 
	s->board[j][i]=s->turn++%2;
	return 1;
}

void human(state* s) {
    char c;
    do {
        printf("%c: ", "OX"[s->turn % 2]);
        c = getchar();
        while (getchar() != '\n');
        printf("\n");
    } while (c < '1' || c > '9' || !move(s, (c - '1') % 3, (c - '1') / 3));
}


int main(void){


	state s;
	init(&s);
	
	display(&s);
	while(s.turn<9){
		human(&s);
		system("cls");
		display(&s);
		switch (evaluate(&s)) {
            case  1: printf("O win\n"); return 0;
            case -1: printf("X win\n"); return 0;
        }
	} 
} 
