/* Kelompok  : UAS
   Nama file : driverPrioQueueCustomer.c
   Deskripsi : Driver ADT untuk prio queue customer */

#include "prioQueueCustomer.h"

int main () {
	int menu;
	PrioQueueCustomer C;
	Customer X;
	char tipecustomer;

	printf("MENU PRIO QUEUE CUSTOMER\n");
	printf("1. IsEmpty\n");
	printf("2. IsFull\n");
	printf("3. NBElmt\n");
	printf("4. Add\n");
	printf("5. Del\n");
	printf("6. PrintQueue\n");
	printf("Masukkan pilihan menu : \n");
	PQC_CreateEmpty(&C);

	scanf("%d", &menu);
	while ((menu>0) && (menu<=6))
	{
		switch (menu) {
			case 1 :
			{
				if (PQC_IsEmpty(C))
				{
					printf("kosong\n");
				}
				else
				{
					printf("isi\n");
				}
			}
			break;
			case 2 :
			{
				if (PQC_IsFull(C))
				{
					printf("penuh\n");
				}
				else
				{
					printf("tidak penuh\n");
				}
			}
			break;
			case 3 :
			{
				printf("banyaknya antrian costumer : %d\n", PQC_NBElmt(C));
			}
			break;
			case 4 :
			{
				printf("masukkan jumlah costumer : ");
				scanf("%d", &PQC_Jumlah(X));
                printf("masukkan prioritas costumer : ");
				scanf("%d", &PQC_Prio(X));
				printf("masukkan durasi kesabaran : ");
				scanf("%d", &PQC_Waktu(X));
				PQC_Add(&C,X);
			}
			break;
			case 5 :
			{
				PQC_Del(&C,&X);
				printf("%d %d %d\n", PQC_Prio(X), PQC_Jumlah(X), PQC_Waktu(X));
            }
			break;
			case 6 :
			{
				PQC_PrintQueue(C);
			}
			break;
		}
		printf("Masukkan pilihan menu : \n");
		scanf("%d", &menu);
	}
	return 0;
}
