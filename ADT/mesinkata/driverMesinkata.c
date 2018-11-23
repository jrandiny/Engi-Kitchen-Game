/* File: drivermesinkata.c */
/* Implementasi Mesin Karakter */
/* Kelompok  : UAS
   Nama file : drivermesinkata.c
   Deskripsi : Driver ADT untuk mesin kata*/

#include "mesinkata.h"
#include "mesinkar.h"

boolean EndKata;
Kata CKata;

void K_TulisPita();

int main ()
{
  /* KAMUS */
  int i,input,count,status;

  /* ALGORITMA */
  do{
  printf("Menu\n");
  printf("0. Exit\n");
  printf("1. membaca pita karakter.\n");
  printf("2. menulis pita karakter.\n");
  printf("\n");
  printf("Input : ");
  scanf("%d", &input);

  if(input==1)
  {
    K_STARTKATA("pitakar.txt",&status);
    count = 0;
    while(!EndKata)
    {
      for(i=1;i<=CKata.Length;i++)
      {
        printf("%c", CKata.TabKata[i]);
      }
      printf(" ");
      count++;
      K_ADVKATA();
    }

    printf("\n");
    printf("Jumlah kata adalah : %d\n", count);
    printf("\n");

  }
  else if(input==2)
  {
    K_TulisPita();
  }

} while(input != 0);

  return 0;
}

void K_TulisPita()
{
  /* KAMUS LOKAL */
  char kalimat[NMax];

  /* ALGORITMA */
  printf("Tuliskan kalimat dibawah untuk ditulis pada pita karakter (maksimal 50 karakter).\n");
  scanf("%s", kalimat);

  FILE *out = fopen("pitakar.txt","w");
	fprintf(out,"%s.\n", kalimat);
	fclose(out);
}
