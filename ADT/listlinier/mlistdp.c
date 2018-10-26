#include <stdio.h>
#include "listdp.h"

int main(){
	List L;
	infotype x,y;
	address pt,pt2;
	int input;
	LD_CreateEmpty(&L);

	do{
		printf("1. insertfirst\n2. insertlast\n3. delfirst\n4. dellast\n5. delp\n6. search\n7. insertafter\n8. insertbefore\n9. deleteafter\n10. deletebefore\n11. exit\n");
		scanf("%d",&input);
		switch(input){
			case 1:
				scanf("%d",&x);
				LD_InsVFirst(&L,x);
				break;
			case 2:
				scanf("%d",&x);
				LD_InsVLast(&L,x);
				break;
			case 3:
				LD_DelVFirst(&L,&x);
				printf("deleted:%d\n",x);
				break;
			case 4:
				LD_DelVLast(&L,&x);
				printf("deleted:%d\n",x);
				break;
			case 5:
				scanf("%d",&x);
				LD_DelP(&L,x);
				break;
			case 6:
				scanf("%d",&x);
				pt=LD_Search(L,x);
				if(pt==Nil){
					printf("not found\n");
				}else{
					printf("found in %d with value %d\n",pt,Info(pt));
				}
				break;
			case 7:
				printf("insert after element: ");scanf("%d",&x);
				printf("value to be inserted : ");scanf("%d",&y);
				pt2=LD_Alokasi(y);
				pt=LD_Search(L,x);
				LD_InsertAfter(&L,pt2,pt);
				break;
			case 8:
				printf("insert before element: ");scanf("%d",&x);
				printf("value to be inserted : ");scanf("%d",&y);
				pt2=LD_Alokasi(y);
				pt=LD_Search(L,x);
				LD_InsertBefore(&L,pt2,pt);
				break;
			case 9:
				printf("delete after element: ");scanf("%d",&x);
				pt=LD_Search(L,x);
				LD_DelAfter(&L,&pt2,pt);
				printf("deleted: %d\n",Info(pt2));
				break;
			case 10:
				printf("delete before element: ");scanf("%d",&x);
				pt=LD_Search(L,x);
				LD_DelBefore(&L,&pt2,pt);
				printf("deleted: %d\n",Info(pt2));
				break;

		}
		LD_PrintForward(L);printf("\n");
		LD_PrintBackward(L);
		printf("\n\n");
	}while(input!=11);
	return 0;
}