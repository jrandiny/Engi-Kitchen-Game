/* MODUL TABEL INTEGER */
/* Kelompok  : UAS
   Nama file : arrInt.h
   Deskripsi : ADT untuk tipe Array integer statik eksplisit */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi I : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori tabel statik */

#ifndef ARRAY_H
#define ARRAY_H

#include "../../std.h"

/*  Kamus Umum */
#define IdxMax 100
/* Indeks maksimum array, sekaligus ukuran maksimum array dalam C */
#define IdxMin 1
/* Indeks minimum array */

/* Definisi elemen dan koleksi objek */
typedef struct {
	int TI[IdxMax+1]; /* memori tempat penyimpan elemen (container) */
	int Neff; /* >=0, banyaknya elemen efektif */
} ArrInt;
/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Jika T adalah ArrInt, cara deklarasi dan akses: */
/* Deklarasi : T : ArrInt */
/* Maka cara akses:
   T.Neff  untuk mengetahui banyaknya elemen
   T.TI    untuk mengakses seluruh nilai elemen tabel
   T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
  Tabel kosong: T.Neff = 0
  Definisi elemen pertama : T.TI[i] dengan i=1
  Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */

/* ********** SELEKTOR ********** */
#define AI_Neff(T)   (T).Neff
#define AI_TI(T)     (T).TI
#define AI_Elmt(T,i) (T).TI[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void AI_CreateEmpty (ArrInt * T);
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int AI_NbElmt (ArrInt T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int AI_MaxNbEl (ArrInt T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
int AI_GetFirstIdx (ArrInt T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
int AI_GetLastIdx (ArrInt T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** Test Indeks yang valid ********** */
boolean AI_IsIdxValid (ArrInt T, int i);
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean AI_IsIdxEff (ArrInt T, int i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean AI_IsEmpty (ArrInt T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean AI_IsFull (ArrInt T);
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AI_AddAsLastEl (ArrInt * T, int X);
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */

/* ********** MENGHAPUS ELEMEN ********** */
void AI_DelLastEl (ArrInt * T, int * X);
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */


#endif
