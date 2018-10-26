/* File: drivermesinkata.c */
/* Implementasi Mesin Karakter */
/* Kelompok  : UAS
   Nama file : drivermesinkata.c
   Topik     : Tugas Besar Alstrukdat
   Tanggal   : 25 Oktober 2018
   Deskripsi : Driver mesin kata*/

#include <stdio.h>
#include "boolean.h"
#include "mesinkata.h"
#include "mesinkar.h"

boolean EndKata;
Kata CKata;

void K_TulisPita();

int main ()
{
  //KAMUS
  int i,input,count;

  //ALGORITMA
  printf("DRIVER MESIN KATA\n");
  printf("\n");

  do {

  printf("Tekan 1 untuk membaca pita karakter.\n");
  printf("Tekan 2 untuk menulis pita karakter.\n");
  printf("Tekan 3 untuk keluar.\n");
  printf("\n");
  printf("Input : ");
  scanf("%d", &input);

  if(input==1)
  {
    K_STARTKATA();
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

} while(input != 3);

  return 0;
}

void K_TulisPita()
{
  //Kamus LOKAL
  char kalimat[NMax];

  //Algoritma
  printf("Tuliskan kalimat dibawah untuk ditulis pada pita karakter (maksimal 50 karakter).\n");
  scanf("\n", &kalimat);
  scanf("%[^\n]", &kalimat);

  FILE *out = fopen("pitakar.txt","w");
	fprintf(out,"%s.\n", kalimat);
	fclose(out);
}
