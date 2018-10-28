
#include "listsirkuler.h"

int main(){
	List L;
	infotype x,y;
	address pt,pt2;
	int input;
	LS_CreateEmpty(&L);

	do{
		printf("1. insertfirst\n2. insertlast\n3. delfirst\n4. dellast\n5. delp\n6. search\n7. insertafter\n8. deleteafter\n9. exit\n");
		scanf("%d",&input);
		switch(input){
			case 1:
				scanf("%d",&x);
				LS_InsVFirst(&L,x);
				break;
			case 2:
				scanf("%d",&x);
				LS_InsVLast(&L,x);
				break;
			case 3:
				LS_DelVFirst(&L,&x);
				printf("deleted:%d\n",x);
				break;
			case 4:
				LS_DelVLast(&L,&x);
				printf("deleted:%d\n",x);
				break;
			case 5:
				scanf("%d",&x);
				LS_DelP(&L,x);
				break;
			case 6:
				scanf("%d",&x);
				pt=LS_Search(L,x);
				if(pt==Nil){
					printf("not found\n");
				}else{
					printf("found in %d with value %d\n",pt,Info(pt));
				}
				break;
			case 7:
				printf("insert after element: ");scanf("%d",&x);
				printf("value to be inserted : ");scanf("%d",&y);
				pt2=LS_Alokasi(y);
				pt=LS_Search(L,x);
				LS_InsertAfter(&L,pt2,pt);
				break;
			case 8:
				printf("delete after element: ");scanf("%d",&x);
				pt=LS_Search(L,x);
				LS_DelAfter(&L,&pt2,pt);
				printf("deleted: %d\n",Info(pt2));
				break;

		}
		LS_PrintInfo(L);
		printf("\n\n");
	}while(input!=9);
	return 0;
}
