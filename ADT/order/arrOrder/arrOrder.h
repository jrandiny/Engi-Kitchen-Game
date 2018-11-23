/* MODUL TABEL ORDER */
/* Kelompok  : UAS
   Nama file : arrOrder.h
   Deskripsi : ADT untuk tipe Array order */
/* Berisi definisi dan semua primitif pemrosesan tabel order */
/* Penempatan elemen selalu rapat kiri */
/* Versi I : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori tabel statik */

#ifndef ARRORDER_H
#define ARRORDER_H

#include "../../../std.h"
#include "../order.h"

/*  Kamus Umum */
#define AO_IdxMax 100
/* Indeks maksimum array, sekaligus ukuran maksimum array dalam C */
#define AO_IdxMin 1
/* Indeks minimum array */

/* Definisi elemen dan koleksi objek */
typedef int AO_IdxType;  /* type indeks */
typedef Order AO_ElType;   /* type elemen tabel */
typedef struct {
	AO_ElType TI[AO_IdxMax+1]; /* memori tempat penyimpan elemen (container) */
	int Neff; /* >=0, banyaknya elemen efektif */
} ArrOrder;
/* Indeks yang digunakan [AO_IdxMin..AO_IdxMax] */
/* Jika T adalah ArrOrder, cara deklarasi dan akses: */
/* Deklarasi : T : ArrOrder */
/* Maka cara akses:
   T.Neff  untuk mengetahui banyaknya elemen
   T.TI    untuk mengakses seluruh nilai elemen tabel
   T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
  Tabel kosong: T.Neff = 0
  Definisi elemen pertama : T.TI[i] dengan i=1
  Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */

/* ********** SELEKTOR ********** */
#define AO_Neff(T)   (T).Neff
#define AO_TI(T)     (T).TI
#define AO_Elmt(T,i) (T).TI[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void AO_CreateEmpty (ArrOrder * T);
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas AO_IdxMax-AO_IdxMin+1 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int AO_NbElmt (ArrOrder T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */

int AO_MaxNbEl (ArrOrder T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */

AO_IdxType AO_GetFirstIdx (ArrOrder T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */

AO_IdxType AO_GetLastIdx (ArrOrder T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** Test Indeks yang valid ********** */
boolean AO_IsIdxValid (ArrOrder T, AO_IdxType i);
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/

boolean AO_IsIdxEff (ArrOrder T, AO_IdxType i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean AO_IsEmpty (ArrOrder T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */

boolean AO_IsFull (ArrOrder T);
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
AO_IdxType AO_Search (ArrOrder T, int X);
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AO_AddAsLastEl (ArrOrder * T, AO_ElType X);
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */

void AO_AddEli (ArrOrder * T, AO_ElType X, AO_IdxType i);
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas
   terhadap elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses : Geser elemen ke-i+1 s.d. terakhir */
/*          Isi elemen ke-i dengan X */

/* ********** MENGHAPUS ELEMEN ********** */
void AO_DelLastEl (ArrOrder * T, AO_ElType * X);
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */

void AO_DelEli (ArrOrder * T, AO_IdxType i, AO_ElType * X);
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */

#endif
