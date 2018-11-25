/* File: drivermesinkata.c */
/* Implementasi Mesin Karakter */
/* Kelompok  : UAS
   Nama file : drivermesinkata.c
   Deskripsi : Driver ADT untuk mesin kata*/

#include "mesinkata.h"
#include "mesinkar.h"
#include "../jam/jam.h"

boolean EndKata;
Kata CKata;

void K_TulisPita();

int main ()
{
  /* KAMUS */
  int i,input,count,status,idxawal,idxakhir;
  char stringinput[100];
  Kata kata1,kata2;


  /* ALGORITMA */
  do{
  printf("Menu\n");
  printf("0. Exit\n");
  printf("1. membaca pita karakter.\n");
  printf("2. menulis pita karakter.\n");
  printf("3. katatoint\n");
  printf("4. copysubkata.\n");
  printf("5. konkatkata.\n");
  printf("6. replacespace then removespace.\n");
  printf("7. katatochar.\n");
  printf("8. jamtokata.\n");
  printf("\n");
  printf("Input : ");
  scanf("%d", &input);

  if(input==1)
  {
    K_STARTKATA("pitakar.txt",&status);
    count = 0;
    if(status==1){
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
    }else{
      printf("pita kosong atau file tidak ditemukan.\n");
    }
    printf("\n");
    printf("Jumlah kata adalah : %d\n", count);
    printf("\n");

  }
  else if(input==2)
  {
    K_TulisPita();
  }
  else if(input==3)
  {
    printf("masukkan kata : ");scanf("%s",stringinput);
    kata1=K_MakeKata(stringinput);
    printf("hasil int : %d\n",K_KataToInt(kata1));
  }
  else if(input==4)
  {
    printf("masukkan kata : ");scanf("%s",stringinput);
    printf("masukkan idx awal : ");scanf("%d",&idxawal);
    printf("masukkan idx akhir : ");scanf("%d",&idxakhir);
    kata1=K_MakeKata(stringinput);
    kata1=K_CopySubKata(kata1,idxawal,idxakhir);
    printf("hasil : ");K_PrintKata(kata1);printf("\n");
  }
  else if(input==5)
  {
    printf("masukkan kata1 : ");scanf("%s",stringinput);
    kata1=K_MakeKata(stringinput);
    printf("masukkan kata2 : ");scanf("%s",stringinput);
    kata2=K_MakeKata(stringinput);
    K_KonkatKata(&kata1,kata2);
    printf("hasil : ");K_PrintKata(kata1);printf("\n");
  }
  else if(input==6)
  {
    printf("masukkan kata (dipisah dengan _ ) : ");scanf("%s",stringinput);
    kata1=K_MakeKata(stringinput);
    K_ReplaceSpace(&kata1);
    printf("hasil replace _ dengan spasi : ");K_PrintKata(kata1);printf("\n");
    K_RemoveSpace(&kata1);
    printf("hasil remove spasi : ");K_PrintKata(kata1);printf("\n");
  }
  else if(input==7)
  {
    printf("masukkan kata : ");scanf("%s",stringinput);
    kata1=K_MakeKata(stringinput);
    printf("hasil : %s\n",K_KataToChar(kata1));
  }
  else if(input==8)
  {
    Jam j;
    J_BacaJam(&j);
    kata1=K_JamToKata(j);
    K_PrintKata(kata1);printf("\n");
  }  
  printf("\n");
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
