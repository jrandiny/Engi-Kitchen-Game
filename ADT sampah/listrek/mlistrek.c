#include <stdio.h>
#include "listrek.h"

int main(){
	List L,Lcpy,Lresult;
	infotype x;
	address pt;
	int input,n,i;
	L=Nil;
	while(1){
		Lcpy=Lresult=Nil;
		printf("1. isempty\n2. isoneelmt\n3. firstelement\n4. tail\n5. konso\n6. konsdot\n7. copy\n8. mcopy\n9. concat\n10. mconcat\n11. nbelmt\n12. search\n");
		printf("your input : ");scanf("%d",&input);
		switch(input){
			case 1:
				if(IsEmpty(L)){
					printf("list is empty\n");
				}else{
					printf("list is not empty\n");
				}
				break;
			case 2:
				if(IsOneElmt(L)){
					printf("list contains one element\n");
				}else{
					printf("list doesn't contain one element\n");
				}
				break;
			case 3:
				printf("%d\n",FirstElmt(L));
				break;
			case 4:
				PrintList(Tail(L));
				break;
			case 5:
				printf("enter first element : ");scanf("%d",&x);
				L=Konso(x,L);
				break;
			case 6:
				printf("enter last element : ");scanf("%d",&x);
				L=KonsB(L,x);
				break;
			case 7:
				Lcpy=Copy(L);
				printf("copy result :\n");PrintList(Lcpy);
				break;
			case 8:
				MCopy(L,&Lcpy);
				printf("copy result :\n");PrintList(Lcpy);
				break;
			case 9:
				printf("enter noe of new list :");scanf("%d",&n);
				printf("enter the element :\n");
				for(i=1;i<=n;i++){
					scanf("%d",&x);
					Lresult=KonsB(Lresult,x);
				}
				printf("new list :\n");PrintList(Lresult);
				L=Concat(L,Lresult);
				break;
			case 10:
				printf("enter noe of new list :");scanf("%d",&n);
				printf("enter the element :\n");
				for(i=1;i<=n;i++){
					scanf("%d",&x);
					Lresult=KonsB(Lresult,x);
				}
				printf("new list :\n");PrintList(Lresult);
				MConcat(L,Lresult,&L);
				break;
			case 11:
				printf("nbelmt : %d\n",NbElmtList(L));
				break;
			case 12:
				printf("enter element : ");scanf("%d",&x);
				if(Search(L,x)){
					printf("element found\n");
				}else{
					printf("element not found\n");
				}
		}
		printf("current list : \n");PrintList(L);
		printf("\n\n");
	}
	return 0;
}