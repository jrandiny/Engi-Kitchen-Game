/* Kelompok  : UAS
   Nama file : arrRuangan.c
   Topik     : Engi's Kitchen Game
   Tanggal   : 1 November 2018
   Deskripsi : ADT untuk tipe array Ruangan*/
/* Berisi definisi dan semua primitif pemrosesan tabel ruangan */
/* Penempatan elemen selalu rapat kiri */
/* Versi I : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori tabel statik */

#include "arrRuangan.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void AR_CreateEmpty (ArrRuangan * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas AR_IdxMax-AR_IdxMin+1 */
{
  AR_Neff(*T) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int AR_NbElmt (ArrRuangan T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
  return AR_Neff(T);
}
/* *** Daya tampung container *** */
int AR_MaxNbEl (ArrRuangan T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
  return AR_IdxMax;
}
/* *** Selektor INDEKS *** */
IdxType AR_GetFirstIdx (ArrRuangan T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
  return AR_IdxMin;
}
IdxType AR_GetLastIdx (ArrRuangan T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
  return (AR_IdxMin + AR_Neff(T) -1);
}

/* ********** Test Indeks yang valid ********** */
boolean AR_IsIdxValid (ArrRuangan T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
  return ((i >= AR_IdxMin)&&(i <= AR_IdxMax));
}
boolean AR_IsIdxEff (ArrRuangan T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
  return ((i >= AR_GetFirstIdx(T))&&(i <= AR_GetLastIdx(T)));
}

/* ********** OPERASI LAIN ********** */
void AR_CopyTab (ArrRuangan Tin, ArrRuangan * Tout)
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
{
  /* KAMUS LOKAL */
  IdxType i;

  /* ALGORTIMA */
  AR_CreateEmpty(Tout);

  for(i=AR_GetFirstIdx(Tin);i<=AR_GetLastIdx(Tin);i++){
    AR_Elmt(*Tout,i) = AR_Elmt(Tin,i);
  }

  AR_Neff(*Tout) = AR_Neff(Tin);
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AR_AddAsLastEl (ArrRuangan * T, Ruangan X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  AR_Elmt(*T,AR_GetLastIdx(*T)+1) = X;
  AR_Neff(*T)++;
}

/* ********** MENGHAPUS ELEMEN ********** */
void AR_DelLastEl (ArrRuangan * T, Ruangan * X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  *X = AR_Elmt(*T,AR_GetLastIdx(*T));
  AR_Neff(*T)--;
}
