/* MODUL TABEL INTEGER */
/* Kelompok  : UAS
   Nama file : arrInt.c
   Deskripsi : ADT untuk tipe Array integer statik eksplisit */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi I : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori tabel statik */

#include "arrInt.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void AI_CreateEmpty (ArrInt * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
  AI_Neff(*T) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int AI_NbElmt (ArrInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
  return AI_Neff(T);
}
/* *** Daya tampung container *** */
int AI_MaxNbEl (ArrInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
  return IdxMax;
}
/* *** Selektor INDEKS *** */
int AI_GetFirstIdx (ArrInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
  return IdxMin;
}
int AI_GetLastIdx (ArrInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
  return (IdxMin + AI_Neff(T) -1);
}

/* ********** Test Indeks yang valid ********** */
boolean AI_IsIdxValid (ArrInt T, int i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
  return ((i >= IdxMin)&&(i <= IdxMax));
}
boolean AI_IsIdxEff (ArrInt T, int i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
  return ((i >= AI_GetFirstIdx(T))&&(i <= AI_GetLastIdx(T)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean AI_IsEmpty (ArrInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
  return (AI_Neff(T) == 0);
}
/* *** Test tabel penuh *** */
boolean AI_IsFull (ArrInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
  return (AI_Neff(T) >= IdxMax);
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AI_AddAsLastEl (ArrInt * T, int X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  AI_Elmt(*T,AI_GetLastIdx(*T)+1) = X;
  AI_Neff(*T)++;
}

/* ********** MENGHAPUS ELEMEN ********** */
void AI_DelLastEl (ArrInt * T, int * X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  *X = AI_Elmt(*T,AI_GetLastIdx(*T));
  AI_Neff(*T)--;
}
