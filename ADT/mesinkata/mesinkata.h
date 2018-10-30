/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */
/* Kelompok  : UAS
   Nama file : mesinkata.h
   Topik     : Tugas Besar Alstrukdat
   Tanggal   : 25 Oktober 2018
   Deskripsi : Implementasi mesin kata*/

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../../header/std.h"
#include "mesinkar.h"

#define NMax 50
#define BLANK ' '

typedef struct {
	char TabKata[NMax+1]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
    int Length;
} Kata;

/* State Mesin Kata */
extern boolean EndKata;
extern Kata CKata;

void K_IgnoreBlank();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void K_STARTKATA(char* nama);
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void K_ADVKATA();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void K_SalinKata();
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

Kata K_MakeKata(char* S);
/* Membuat kata dari string */

void K_LowercaseKata(Kata *input);
/* I.S. input tidak kosong
   F.S. input menjadi K_LowercaseKata
*/

boolean K_IsKataSama(Kata kata1,Kata kata2);
/*true jika kata1 sama kata2, dan sebaliknya*/

void K_CopyKata(Kata sumber,Kata* hasil);
/*I.S. sumber terdefinisi
  F.S. hasil terisi sumber
*/

int K_KataToInt(Kata input);
/*mengubah input menjadi tipe integer*/

#endif
