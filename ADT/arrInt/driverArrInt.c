/* Kelompok  : UAS
   Nama file : driverArrInt.c
   Deskripsi : Driver ADT untuk tipe Array integer statik eksplisit */

#include "arrInt.h"

int main (){

  /* KAMUS */
  ArrInt T;
  int input;
  int temp;

  /* ALGORITMA */
  AI_CreateEmpty(&T);

  do {
    /* Menu */
    printf("Menu\n");
    printf("0. Exit\n");
    printf("1. Info elemen\n");
    printf("2. Info indeks\n");
    printf("3. AddAsLastEl\n");
    printf("4. DelLastEl\n");
    printf("5. Cek Tabel\n");
    printf("6. Cek Indeks\n");
    printf("\n");

    printf("Choice = ");
    scanf("%d", &input);

    /* Info element */
    if(input==1){
      printf("NbElmt : %d \n", AI_NbElmt(T));
      printf("MaxNbElmt : %d\n", AI_MaxNbEl(T));
    }

    /* Info indeks */
    else if(input==2){
      printf("FirstIdx = %d\n", AI_GetFirstIdx(T));
      printf("LastIdx = %d\n", AI_GetLastIdx(T));
    }
    /* AddAsLastEl */
    else if(input==3){
      printf("Elemen yang akan dimasukkan = ");
      scanf("%d", &temp);
      if(!AI_IsFull(T))
        AI_AddAsLastEl(&T,temp);
      else
        printf("Tabel full");
    }
    /* DelLastEl */
    else if(input==4){
      if(!AI_IsEmpty(T))
        AI_DelLastEl(&T,&temp);
      else
        printf("Tabel kosong\n");
    }
    /* Cek tabel */
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
    /*Cek Indeks */
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

    /* Cetak array */
    if(input!=0){
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

  } while (input != 0);
  /* input == 0 (exit)*/

  return 0;
}
