/* Kelompok  : UAS
   Nama file : driverArrInt.c
   Deskripsi : Driver ADT untuk tipe Array integer statik eksplisit */

#include "arrInt.h"

int main (){

  //Kamus
  ArrInt T;
  int input;
  int temp;

  //ALGORITMA
  AI_CreateEmpty(&T);

  do {
    printf("1. Info elemen\n");
    printf("2. Info indeks\n");
    printf("3. AddAsLastEl\n");
    printf("4. DelLastEl\n");
    printf("5. Cek Tabel\n");
    printf("6. Cek Indeks\n");
    printf("7. Exit\n");
    printf("\n");

    printf("Input = ");
    scanf("%d", &input);

    if(input==1){
      printf("NbElmt : %d \n", AI_NbElmt(T));
      printf("MaxNbElmt : %d\n", AI_MaxNbEl(T));
    }

    else if(input==2){
      printf("FirstIdx = %d\n", AI_GetFirstIdx(T));
      printf("LastIdx = %d\n", AI_GetLastIdx(T));
    }

    else if(input==3){
      printf("Elemen yang akan dimasukkan = ");
      scanf("%d", &temp);
      if(!AI_IsFull(T))
        AI_AddAsLastEl(&T,temp);
      else
        printf("Tabel full");
    }

    else if(input==4){
      if(!AI_IsEmpty(T))
        AI_DelLastEl(&T,&temp);
      else
        printf("Tabel kosong\n");
    }

    else if(input==5){
      if(AI_IsEmpty(T))
        printf("IsEmpty = true\n");
      else
        printf("IsEmpty = false\n");

      if(AI_IsFull(T))
        printf("IsFUll = true\n");
      else
        printf("IsFull = false\n");
    }

    else if(input==6){
      printf("indeks yang akan dimasukkan = ");
      scanf("%d", &temp);

      if(AI_IsIdxValid(T,temp))
        printf("IsIdxValid = true\n");
      else
        printf("IsIdxvalid = false\n");

      if(AI_IsIdxEff(T,temp))
        printf("IsIdxEff = true\n");
      else
        printf("IsIdxEff = false\n");

    }

    printf("\n");

    if(input!=7){
      if(AI_IsEmpty(T))
        printf("Array = []\n");
      else{
        printf("[");

        for(int i=AI_GetFirstIdx(T);i< AI_GetLastIdx(T);i++){
          printf("%d,", AI_Elmt(T,i));
        }

        printf("%d]\n", AI_Elmt(T,AI_GetLastIdx(T)));
      }
      printf("\n");
    }

  } while (input != 7);

  return 0;
}
