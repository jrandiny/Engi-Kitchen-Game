/* Kelompok  : UAS
   Nama file : arraykata.c
   Topik     : Engi's Kitchen Game
   Tanggal   : 31 Oktober 2018
   Deskripsi : ADT untuk tipe array kata*/

#include "../mesinkata/mesinkata.h"
#include "../../header/std.h"
#include "arraykata.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void AK_CreateEmpty (ArrKata * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
  AK_Neff(*T) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int AK_NbElmt (ArrKata T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
{
  return AK_Neff(T);
}

int AK_MaxNbEl (ArrKata T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
{
  return AK_IdxMax;
}

AK_IdxType AK_GetFirstIdx (ArrKata T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
  return AK_IdxMin;
}
AK_IdxType AK_GetLastIdx (ArrKata T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
  return (AK_IdxMin + AK_Neff(T) -1);
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean AK_IsEmpty (ArrKata T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
  return (AK_Neff(T) == 0);
}

/* ********** Test Indeks yang valid ********** */
boolean AK_IsIdxValid (ArrKata T, AK_IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
  return ((i >= AK_IdxMin)&&(i <= AK_IdxMax));
}

boolean AK_IsIdxEff (ArrKata T, AK_IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
  return ((i >= AK_GetFirstIdx(T))&&(i <= AK_GetLastIdx(T)));
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AK_AddAsLastEl (ArrKata * T, AK_ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  AK_Elmt(*T,AK_GetLastIdx(*T)+1) = X;
  AK_Neff(*T)++;
}
