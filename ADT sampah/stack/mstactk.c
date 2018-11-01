#include "stackt.h"

void printStack(Stack S){
	int X;
	if(S_IsFull(S)){
		printf("full=true\n");
	}else{
		printf("full=false\n");
	}
	if(S_IsEmpty(S)){
		printf("empty=true\n");
	}else{
		printf("empty=false\n");
	}
	printf("[");
	if(!S_IsEmpty(S)){
		while(!S_IsEmpty(S)){
			S_Pop(&S,&X);
			printf("%d",X);
			if(!S_IsEmpty(S)){
				printf(",");
			}
		}
	}
	printf("]");

}

int main(){
	Stack S;
	int X,input;
	S_CreateEmpty(&S);
	do{
		printf("1. push\n2. pop\n3. exit\n");
		scanf("%d",&input);
		switch(input){
			case 1:
				if(!S_IsFull(S)){
					printf("insert value : ");scanf("%d",&X);
					S_Push(&S,X);
				}else{
					printf("stack full\n");
				}
				break;
			case 2:
				if(!S_IsEmpty(S)){
					S_Pop(&S,&X);
					printf("popped value : %d\n",X);
				}else{
					printf("can't pop empty stack\n");
				}
				break;
		}
		printStack(S);printf("\n\n");
	}while(input!=3);
	return 0;
}
