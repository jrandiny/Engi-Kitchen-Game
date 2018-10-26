#include <stdio.h>
#include "listlinier.h"

int main(){
	List L,L1,L2;
	infotype x;
	address pt;
	int input,n,i;
	LL_CreateEmpty(&L);

	do{
		printf("1. insertfirst\n2. insertlast\n3. delfirst\n4. dellast\n5. delp\n6. search\n7. nbelmt\n8. max\n9. concat\n10. exit\n");
		scanf("%d",&input);
		switch(input){
			case 1:
				scanf("%d",&x);
				LL_InsVFirst(&L,x);
				break;
			case 2:
				scanf("%d",&x);
				LL_InsVLast(&L,x);
				break;
			case 3:
				LL_DelVFirst(&L,&x);
				printf("deleted:%d\n",x);
				break;
			case 4:
				LL_DelVLast(&L,&x);
				printf("deleted:%d\n",x);
				break;
			case 5:
				scanf("%d",&x);
				LL_DelP(&L,x);
				break;
			case 6:
				scanf("%d",&x);
				pt=LL_Search(L,x);
				if(pt==Nil){
					printf("not found\n");
				}else{
					printf("found in %d with value %d\n",pt,Info(pt));
				}
				break;
			case 7:
				printf("number of element:%d\n",LL_NbElmt(L));
				break;
			case 8:
				printf("max:%d\n",LL_Max(L));
				break;
			case 9:
				LL_CreateEmpty(&L1);
				LL_CreateEmpty(&L2);
				printf("make the 1st list\ninsert noe:");scanf("%d",&n);
				i=0;
				while(i<n){
					scanf("%d",&x);
					LL_InsVFirst(&L1,x);
					i++;
				}
				LL_PrintInfo(L1);printf("\n");
				
				printf("make the 2nd list\ninsert noe:");scanf("%d",&n);
				i=0;
				while(i<n){
					scanf("%d",&x);
					LL_InsVFirst(&L2,x);
					i++;
				}
				LL_PrintInfo(L2);printf("\n");

				LL_Konkat1(&L1,&L2,&L);
				printf("result:\n");
				printf("1st list:");LL_PrintInfo(L1);printf("\n");
				printf("2nd list:");LL_PrintInfo(L2);printf("\n");
				printf("concatenated:");
				break;

		}
		LL_PrintInfo(L);
		printf("\n\n");
	}while(input!=10);
	return 0;
}