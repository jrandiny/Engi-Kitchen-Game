/* Kelompok  : UAS
   Nama file : marraykata.h
   Topik     : Engi's Kitchen Game
   Tanggal   : 31 Oktober 2018
   Deskripsi : driver untuk ADT untuk tipe array kata*/

#include "arrKata.h"
#include <stdio.h>

Kata K_MakeKata(char* S);
/* Membuat kata dari string */

void PrintArrKata(ArrKata ak);
/* I.S. : ak terdefinisi */
/* F.S. : Tercetak arr kata dalam 1 baris, jika kosong tercetak "Kosong" */


int main(){
  /* KAMUS */
  ArrKata ak;
  Kata input;
  int pil;
  char temp[50];

  /* ALGORITMA */
  AK_CreateEmpty(&ak);
  do {
    printf("Array kata:\n");
    PrintArrKata(ak);
    printf("\nMenu\n0. Exit\n1. Add kata\n2. Length\nChoice = ");
    scanf("%d",&pil);
    if(pil==1){
      scanf("%s",temp);
      AK_AddAsLastEl(&ak, K_MakeKata(temp));
    }else if(pil==2){
      printf("Length = %d\n",AK_NbElmt(ak));
    }
  } while(pil!=0);

  return 0;
}

/* Realisasi fungsi prosedur */
Kata K_MakeKata(char* S)
/* Membuat kata dari string */
{
  Kata hasil;
  int i=0;
  while(S[i]!='\0'){
    hasil.TabKata[i+1]=S[i];
    i++;
  }
  hasil.Length=i;
  return hasil;
}

void PrintArrKata(ArrKata ak)
/* I.S. : ak terdefinisi */
/* F.S. : Tercetak arr kata dalam 1 baris, jika kosong tercetak "Kosong" */
{
  /* KAMUS LOKAL */
  int i,j;

  /* ALGORITMA */
  if(AK_IsEmpty(ak)){
    printf("Kosong");
  }else{
    for(i=1;i<=AK_Neff(ak);i++){
      for(j=1;j<=AK_Elmt(ak,i).Length;j++){
        printf("%c",AK_Elmt(ak, i).TabKata[j]);
      }
      printf(" ");
    }
  }

  printf("\n");

}
