/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */
/* Kelompok  : UAS
   Nama file : mesinkata.c
   Topik     : Tugas Besar Alstrukdat
   Tanggal   : 25 Oktober 2018
   Deskripsi : Implementasi mesin kata*/

#include "mesinkar.h"
#include "mesinkata.h"

/* State Mesin Kata */
boolean EndKata;
Kata CKata;

void K_IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  while((CC==BLANK)&&(CC!=MARK)){
    K_ADV();
  }
  /* CC == BLANK atau CC == MARK */
}

void K_STARTKATA()
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  K_START();
  K_IgnoreBlank();
  if(CC == MARK){
    EndKata = true;
  }else{
    EndKata = false;
    K_SalinKata();
  }
}

void K_ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure K_SalinKata */
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  K_IgnoreBlank();
  if(CC == MARK){
    EndKata = true;
  }else{
    K_SalinKata();
    K_IgnoreBlank();
  }

}

void K_SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
  /* KAMUS LOKAL */
  int i;

  /* ALGORITMA */
  i = 1;
  while( (!((CC == MARK)||(CC == BLANK))) ){
    CKata.TabKata[i] = CC;
    K_ADV();

    if(i==NMax){
      break;
    }

    if(!((CC==MARK)||(CC==BLANK))){
      i = i+1;
    }
  }
  CKata.Length = i;
}
