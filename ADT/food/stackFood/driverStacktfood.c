/* Kelompok  : UAS
   Nama file : driverStacktFood.c
   Deskripsi : Driver ADT untuk stack food */
#include "stacktfood.h"

int main() {
  /* KAMUS */
  int menu,idmkn;
  SF_infotype X;
  StackFood F;

  /* ALGORITMA */
  SF_CreateEmpty(&F,10);
  printf("Menu\n");
  printf("0. Exit\n");
  printf("1. IsEmpty\n");
  printf("2. IsFull\n");
  printf("3. Push\n");
  printf("4. Pop\n");

  printf("Choice = ");
  scanf("%d", &menu);

  while (menu!=0)
  {
      switch (menu) {
          case 1 :
          {
              if (SF_IsEmpty(F))
              {
                  printf("kosong\n");
              } else {
                  printf("isi\n");
              }
          }
          break;
          case 2 :
          {
              if (SF_IsFull(F))
              {
                  printf("penuh\n");
              } else{
                  printf("tidak penuh\n");
              }
          }
          break;
          case 3 :
          {
              printf("id makanan : ");
              scanf("%d", &idmkn);
              F_IDMakanan(X) = idmkn;
              SF_Push(&F,X);
          }
          break;
          case 4 :
          {
              SF_Pop(&F,&X);
              printf("Pop : %d\n", F_IDMakanan(X));
          }
          break;
      }
      printf("Masukkan pilihan menu : ");
      scanf("%d", &menu);
  }
  return 0;
}
