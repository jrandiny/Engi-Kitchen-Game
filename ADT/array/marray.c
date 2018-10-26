#include "array.h"
#include <stdio.h>

void MenuTerurut(TabInt Tin);
/*I.S. : Bebas */
/*F.S. : Dilakukan ke array terurut sesuai perintah */


int main(){
  /* KAMUS */
  TabInt T1,T2,T3;
  int input;
  int temp;
  int temp2;

  /* ALGORITMA */
  A_CreateEmpty(&T1);
  A_CreateEmpty(&T2);
  A_CreateEmpty(&T3);

  input = 99;
  while(input!=8){
    printf("T1\n");
    A_TulisIsi(T1);

    printf("T2\n");
    A_TulisIsi(T2);

    printf("\n");

    printf("1 = I/O\n2 = Indeks\n3 = Status\n4 = Operasi\n");
    printf("5 = Search\n6 = Nilai ekstrem\n7 = Sorting\n8 = Exit\nChoice = ");
    scanf("%d",&input);

    switch(input){
      case 1:
        printf("1 = Baca T1 dan T2\n2 = Tulis T1 dan T2\n3 = AddAsLastEl(T1)\n");
        printf("4 = AddEli(T1)\n5 = DelLastEl(T1)\n6 = DelEli(T1)\n7 = AddElUnik(T1)\nChoice = ");

        scanf("%d",&temp);

        switch (temp) {
          case 1:
            printf("Input 1 (dengan menginput N terlebih dahulu)\n");
            A_BacaIsi(&T1);

            printf("Input 2 (dengan menunggu sampai input -9999)\n");
            A_BacaIsiTab(&T2);

            printf("\n");

            break;
          case 2:
            printf("TulisIsi(T1)\n");
            A_TulisIsi(T1);

            printf("TulisIsiTab(T2)\n");
            A_TulisIsiTab(T2);

            break;
          case 3:
            printf("Data = ");
            scanf("%d",&temp2);
            A_AddAsLastEl(&T1,temp2);
            break;
          case 4:
            printf("Data = ");
            scanf("%d",&temp2);
            printf("Indeks = ");
            scanf("%d",&temp);
            A_AddEli(&T1,temp2,temp);
            break;
          case 5:
            A_DelLastEl(&T1,&temp2);
            printf("Deleted = %d\n",temp2);
            break;
          case 6:
            printf("Indeks = ");
            scanf("%d",&temp);
            A_DelEli(&T1,temp,&temp2);
            printf("Deleted = %d\n",temp2);
            break;
          case 7:
            printf("Data = ");
            scanf("%d",&temp2);
            A_AddElUnik(&T1,temp2);
            break;
        }
        break;
      case 2:
        printf("Indeks yang ingin diuji = ");
        scanf("%d",&temp);
        printf("IsIdxValid(T1,i) = %d\n",A_IsIdxValid(T1,temp));
        printf("IsIdxEff(T1,i) = %d\n",A_IsIdxEff(T1,temp));
        break;
      case 3:
        printf("IsEmpty(T1) = %d\n",A_IsEmpty(T1));
        printf("IsFull(T1) = %d\n",A_IsFull(T1));
        printf("NbElmt(T1) = %d\n",A_NbElmt(T1));
        printf("MaxNbEl(T1) = %d\n",A_MaxNbEl(T1));
        printf("GetFirstIdx(T1) = %d\n",A_GetFirstIdx(T1));
        printf("GetLastIdx(T1) = %d\n",A_GetLastIdx(T1));

        printf("IsSimetris(T1) = %d\n",A_IsSimetris(T1));

        printf("IsEQ(T1,T2) = %d\n",A_IsEQ(T1,T2));
        printf("IsLess(T1,T2) = %d\n",A_IsLess(T1,T2));
        break;
      case 4:
        printf("1 = Plus\n2 = Minus\n3 = Kali\n4 = Kali kons\n5 = Inverse\n6 = Copy\nChoice = ");
        scanf("%d",&temp);
        if(temp == 1){
          T3 = A_PlusTab(T1,T2);
        }else if(temp==2){
          T3 = A_MinusTab(T1,T2);
        }else if(temp==3){
          T3 = A_KaliTab(T1,T2);
        }else if(temp ==4){
          printf("Konstanta = ");
          scanf("%d",&temp2);
          T3 = A_KaliKons(T1,3);
        }else if(temp ==5){
          T3 = A_InverseTab(T1);
        }else if(temp == 6){
          A_CopyTab(T1,&T3);
        }

        printf("[T1] \n");
        A_TulisIsi(T1);
        printf("\n");

        printf("[T2] \n");
        A_TulisIsi(T2);
        printf("\n");

        printf("Hasil\n");
        A_TulisIsi(T3);
        printf("\n");

        break;
      case 5:
        printf("Searching di T1\n");

        printf("Query = ");
        scanf("%d",&temp2);

        printf("Search1\n");
        temp = A_Search1(T1,temp2);
        printf("Hasil = %d\n",temp);

        printf("Search2\n");
        temp = A_Search2(T1,temp2);
        printf("Hasil = %d\n",temp);

        printf("SearchB\n");
        printf("Hasil = %d\n",A_SearchB(T1,temp2));

        printf("SearchSentinel\n");
        printf("Hasil = %d\n",A_SearchSentinel(T1,temp2));
        break;
      case 6:
        printf("ValMax(T1) = %d\n",A_ValMax(T1));
        printf("Valmin(T1) = %d\n",A_ValMin(T1));

        printf("IdxMaxTab(T1) = %d\n",A_IdxMaxTab(T1));
        printf("IdxMinTab(T1) = %d\n",A_IdxMinTab(T1));
        break;
      case 7:
        MenuTerurut(T1);
        break;

    }
  }

  return 0;
}

void MenuTerurut(TabInt Tin)
/*I.S. : Bebas */
/*F.S. : Dilakukan ke array terurut sesuai perintah */
{
  /* KAMUS LOKAL */
  int input;
  int temp;
  int temp2;

  /* ALGORITMA */
  printf("Array awal \n");
  A_TulisIsi(Tin);
  printf("\nSORTING MaxSortDesc\n");

  A_MaxSortDesc(&Tin);
  printf("Hasil \n");
  A_TulisIsi(Tin);

  printf("\nSORTING InsSortAsc\n");

  A_InsSortAsc(&Tin);
  printf("Hasil \n");
  A_TulisIsi(Tin);

  input = -99;

  while(input!=6){
    printf("Tin\n");
    A_TulisIsi(Tin);
    printf("\n");

    printf("1 = Search\n2 = Max\n3 = Min\n4 = Add\n");
    printf("5 = Del\n6 = Return to main\nChoice = ");

    scanf("%d",&input);

    switch(input){
      case 1:
        printf("Query = ");
        scanf("%d",&temp);
        printf("Indeks temu = %d\n",A_SearchUrut(Tin,temp));
        break;
      case 2:
        printf("Max = %d\n",A_MaxUrut(Tin));
        break;
      case 3:
        printf("Min = %d\n",A_MinUrut(Tin));
        break;
      case 4:
        printf("Data = ");
        scanf("%d",&temp2);
        A_Add1Urut(&Tin, temp2);
        break;
      case 5:
        printf("Data = ");
        scanf("%d",&temp2);
        A_Del1Urut(&Tin,temp2);
        break;
    }
  }

}
