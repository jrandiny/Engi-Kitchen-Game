/* Kelompok  : UAS
   Nama file : driverArrMeja.h
   Deskripsi : Driver ADT untuk tipe array Meja*/
#include "arrMeja.h"

int main(){
  /* KAMUS */
  ArrMeja T;
  int input;
  int temp;
  Meja meja;
  int bangku,status;
  Point pos;

  /* ALGORITMA */
  AM_CreateEmpty(&T);

  input = 99;
  while(input!=4){
    printf("T\n");
    AM_TulisIsi(T);

    printf("\n0. Exit\n1. I/O\n2. Indeks\n3. Status\n");
    printf("Choice = ");
    scanf("%d",&input);

    switch(input){
      case 1:
      printf("\n1. Baca T\n2. Tulis T\n3. AddAsLastEl(T)\n");
      printf("4. AddEli(T)\n5. DelLastEl(T)\n6. DelEli(T)\nChoice = ");

        scanf("%d",&temp);

        switch (temp) {
          case 1:
            printf("Input (dengan menginput N terlebih dahulu)\n");
            AM_BacaIsi(&T);
            printf("\n");
            break;
          case 2:
            printf("TulisIsi(T)\n");
            AM_TulisIsi(T);
            break;
          case 3:
            printf("Data = \n");
            printf("JumlahBangku: "); scanf("%d",&bangku);
            printf("Posisi: "); scanf("%d %d",&P_Baris(pos),&P_Kolom(pos));
            printf("Status: "); scanf("%d",&status);
            meja = AM_CreateMeja(bangku,pos,status);
            AM_AddAsLastEl(&T,meja);
            break;
          case 4:
            printf("Data = \n");
            printf("JumlahBangku: "); scanf("%d",&bangku);
            printf("Posisi: "); scanf("%d %d",&P_Baris(pos),&P_Kolom(pos));
            printf("Status: "); scanf("%d",&status);
            meja = AM_CreateMeja(bangku,pos,status);
            printf("Indeks = ");
            scanf("%d",&temp);
            AM_AddEli(&T,meja,temp);
            break;
          case 5:
            AM_DelLastEl(&T,&meja);
            printf("Deleted = \n");
            printf("JumlahBangku: %d\n",Bangku(meja));
            printf("Posisi: (%d,%d)\n",P_Baris(Meja_Posisi(meja)),P_Kolom(Meja_Posisi(meja)));
            printf("Status: %d\n",Status(meja));
            break;
          case 6:
            printf("Indeks = ");
            scanf("%d",&temp);
            AM_DelEli(&T,temp,&meja);
            printf("Deleted = \n");
            printf("JumlahBangku: %d\n",Bangku(meja));
            printf("Posisi: (%d,%d)\n",P_Baris(Meja_Posisi(meja)),P_Kolom(Meja_Posisi(meja)));
            printf("Status: %d\n",Status(meja));
            break;
        }
        break;
      case 2:
        printf("\nIndeks yang ingin diuji = ");
        scanf("%d",&temp);
        printf("IsIdxValid(T,%d) = %d\n",temp,AM_IsIdxValid(T,temp));
        printf("IsIdxEff(T,%d) = %d\n",temp,AM_IsIdxEff(T,temp));
        break;
      case 3:
        printf("\nIsEmpty(T) = %d\n",AM_IsEmpty(T));
        //printf("IsFull(T) = %d\n",AM_IsFull(T));
        printf("NbElmt(T) = %d\n",AM_NbElmt(T));
        printf("MaxNbEl(T) = %d\n",AM_MaxNbEl(T));
        printf("GetFirstIdx(T) = %d\n",AM_GetFirstIdx(T));
        printf("GetLastIdx(T) = %d\n",AM_GetLastIdx(T));
    }
  }

  return 0;
}
