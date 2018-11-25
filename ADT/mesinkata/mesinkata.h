/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */
/* Kelompok  : UAS
   Nama file : mesinkata.h
   Deskripsi : ADT mesin kata*/

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "mesinkar.h"
#include "../point/point.h"
#include "../jam/jam.h"

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

void K_STARTKATA(char* nama,int *status);
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata
          status 1 jika file ada, 0 jika tidak ada*/

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

boolean K_IsKataSama(Kata kata1,Kata kata2);
/*true jika kata1 sama kata2, dan sebaliknya*/

int K_KataToInt(Kata input);
/*mengubah input menjadi tipe integer*/

Kata K_CopySubKata(Kata input,int idxmulai,int idxakhir);
/*mengcopy sebagian dari input sesuai parameter*/

void K_PrintKata(Kata S);
/* I.S. S valid
   F.S. S terprint di layar dengan tanpa enter di akhir
*/

char* K_KataToChar(Kata S);
/*mengubah tipe kata menjadi string*/

Point K_KataToPoint(Kata S);
/*mengubah tipe kata menjadi point*/

void K_KonkatKata(Kata *kata1, Kata kata2);
/* I.S. kata1, kata2 terdefenisi
   F.S. kata1 berisi hasil konkat kata 1 dan kata 2
*/

void K_ReplaceSpace(Kata* kata);
/* I.S. kata terdefinisi
   F.S. semua _ yang terdapat di kata diubah menjadi ' '*/

void K_RemoveSpace(Kata* kata);
/* I.S. kata terdefinisi
   F.S. semua ' ' yang terdapat di kata diubah menjadi _*/

Kata K_JamToKata(Jam jam);
/* mengembalikan tipe kata dari jam*/

#endif
