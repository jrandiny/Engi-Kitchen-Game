/* Kelompok  : UAS
   Nama file : arrMeja.c
   Topik     : Engi's Kitchen Game
   Tanggal   : 1 November 2018
   Deskripsi : ADT untuk tipe array Meja*/
/* Berisi definisi dan semua primitif pemrosesan tabel meja */
/* Idx awal tidak di idxmin */
/* Versi I : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori tabel statik */

#include "arrMeja.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void AM_CreateEmpty (ArrMeja * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas AM_AM_IdxMax-AM_AM_IdxMin+1 */
{
  AM_Neff(*T) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int AM_NbElmt (ArrMeja T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
  return AM_Neff(T);
}
/* *** Daya tampung container *** */
int AM_MaxNbEl (ArrMeja T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
  return AM_AM_IdxMax;
}
/* *** Selektor INDEKS *** */
IdxType AM_GetFirstIdx (ArrMeja T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
  return AM_AM_IdxMin;
}
IdxType AM_GetLastIdx (ArrMeja T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
  return (AM_AM_IdxMin + AM_Neff(T) -1);
}

/* ********** Test Indeks yang valid ********** */
boolean AM_IsIdxValid (ArrMeja T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
  return ((i >= AM_AM_IdxMin)&&(i <= AM_AM_IdxMax));
}
boolean AM_IsIdxEff (ArrMeja T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
  return ((i >= AM_GetFirstIdx(T))&&(i <= AM_GetLastIdx(T)));
}

/* ********** OPERASI LAIN ********** */
void AM_CopyTab (ArrMeja Tin, ArrMeja * Tout)
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
{
  /* KAMUS LOKAL */
  IdxType i;

  /* ALGORTIMA */
  AM_CreateEmpty(Tout);

  for(i=AM_GetFirstIdx(Tin);i<=AM_GetLastIdx(Tin);i++){
    AM_Elmt(*Tout,i) = AM_Elmt(Tin,i);
  }

  AM_Neff(*Tout) = AM_Neff(Tin);
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AM_AddAsLastEl (ArrMeja * T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  AM_Elmt(*T,AM_GetLastIdx(*T)+1) = X;
  AM_Neff(*T)++;
}

/* ********** MENGHAPUS ELEMEN ********** */
void AM_DelLastEl (ArrMeja * T, ElType * X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  *X = AM_Elmt(*T,AM_GetLastIdx(*T));
  AM_Neff(*T)--;
}
