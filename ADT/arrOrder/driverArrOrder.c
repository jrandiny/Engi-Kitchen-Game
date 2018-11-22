/* Kelompok  : UAS
   Nama file : DriverArrOrder.c
   Deskripsi : Driver ADT untuk tipe Array order */

#include "arrOrder.h"
#include "order.h"
#include "../mesinkata/mesinkata.h"
#include <stdlib.h>
#include <stdio.h>

void AO_TulisIsi (ArrOrder T);
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/*      Jika T kosong : Hanya menulis "Tabel kosong" */
/* Contoh: Jika isi Tabel: [1, 20, 30, 50]
   Maka tercetak di layar:
   [1]1
   [2]20
   [3]30
   [4]50
*/

int main(){
  /* KAMUS */
  ArrOrder T1;
  int input;
  int temp1,temp2;
  Order tempOrder;
  char tempStr[50];

  AO_IdxType idx;


  /* ALGORITMA */
  AO_CreateEmpty(&T1);

  do {
    printf("\nArrOrder:\n");
    AO_TulisIsi(T1);

    printf("\n");

    printf("Menu\n");
    printf("0 = Exit\n");
    printf("1 = I/O\n");
    printf("2 = Indeks\n");
    printf("3 = Status\n");
    printf("4 = Search\n");
    printf("Choice = ");
    scanf("%d",&input);

    switch(input){
      case 1:
        printf("1 = AddEli\n");
        printf("2 = AddAsLastEl\n");
        printf("3 = DelEli\n");
        printf("4 = DelLasEl\n");
        printf("Choice = ");
        scanf("%d",&input);

        if(input==1 || input==2){
          printf("Insert id = ");
          scanf("%d",&temp1);

          printf("Insert nama = ");
          scanf("%s",tempStr);

          printf("Insert nomeja = ");
          scanf("%d",&temp2);
          tempOrder = O_CreateOrder(temp1, K_MakeKata(tempStr),temp2);
        }

        switch(input){
          case 1:
            printf("I = ");
            scanf("%d",&temp2);

            AO_AddEli(&T1,tempOrder, temp2);
            break;
          case 2:
            AO_AddAsLastEl(&T1,tempOrder);
            break;
          case 3:
            printf("I = ");
            scanf("%d",&temp2);
            AO_DelEli(&T1, temp2,&tempOrder);
            printf("Deleted id = %d",O_IDMakanan(tempOrder));
            break;
          case 4:
            AO_DelLastEl(&T1, &tempOrder);
            printf("Deleted id = %d",O_IDMakanan(tempOrder));
            break;
        }
        break;

      case 2:
        printf("FirstIdx = %d\n",AO_GetFirstIdx(T1));
        printf("LastIdx = %d\n",AO_GetLastIdx(T1));

        printf("Test index = ");
        scanf("%d",&temp1);

        printf("Valid ? %d\n",AO_IsIdxValid(T1,temp1));
        printf("Eff ? %d\n",AO_IsIdxEff(T1,temp1));
        break;
      case 3:
        printf("Full ? %d\n",AO_IsFull(T1));
        printf("Empty ? %d\n",AO_IsEmpty(T1));
        break;
      case 4:
        printf("Search id = ");
        scanf("%d",&temp1);

        idx = AO_Search(T1,temp1);

        if(idx != IdxUndeff){
          printf("Found\n");
        }else{
          printf("Not found\n");
        }
    }

  } while(input!=0);

  return 0;
}

void AO_TulisIsi (ArrOrder T)
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : Ditulis ke bawah [nomor meja] id - nama makanan */
/*      Jika T kosong : Hanya menulis "Tabel kosong" */

{
  /* KAMUS LOKAL */
  AO_IdxType i;
  AO_ElType tempOrder;
  char *tempStr;

  /* ALGORITMA */
  if(AO_IsEmpty(T)){
    printf("Tabel kosong\n");
  }else{
    for(i=AO_GetFirstIdx(T);i<=AO_GetLastIdx(T);i++){
      tempOrder = AO_Elmt(T, i);
      tempStr = K_KataToChar(O_NamaMakanan(tempOrder));
      printf("[%d] %d - %s\n",O_NoMeja(tempOrder),O_IDMakanan(tempOrder),tempStr);
      free(tempStr);
    }
  }

}
