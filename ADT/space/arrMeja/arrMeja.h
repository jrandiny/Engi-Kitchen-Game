/* MODUL TABEL meja */
/* Berisi definisi dan semua primitif pemrosesan tabel meja */
/* Idx awal tidak di idxmin */
/* Versi I : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori tabel statik */

#ifndef ARRAYMEJA_H
#define ARRAYMEJA_H

#include "../../../std.h"
#include "../../point/point.h"
#include "../meja.h"

/*  Kamus Umum */
#define AM_IdxMax 30
/* Indeks maksimum array, sekaligus ukuran maksimum array dalam C */
#define AM_IdxMin 1
/* Indeks minimum array */

/* Definisi elemen dan koleksi objek */
typedef int IdxType;  /* type indeks */
typedef struct {
	Meja TI[AM_IdxMax+1]; /* memori tempat penyimpan elemen (container) */
	int Neff; /* >=0, banyaknya elemen efektif */
} ArrMeja;
/* Indeks yang digunakan [AM_IdxMin..AM_IdxMax] */
/* Jika T adalah ArrMeja, cara deklarasi dan akses: */
/* Deklarasi : T : ArrMeja */
/* Maka cara akses:
   T.Neff  untuk mengetahui banyaknya elemen
   T.TI    untuk mengakses seluruh nilai elemen tabel
   T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
  Tabel kosong: T.Neff = 0
  Definisi elemen pertama : T.TI[i] dengan i=1
  Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */

/* ********** SELEKTOR ********** */
#define AM_Neff(T)   (T).Neff
#define AM_TI(T)     (T).TI
#define AM_Elmt(T,i) (T).TI[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void AM_CreateEmpty (ArrMeja * T);
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas AM_IdxMax-AM_IdxMin+1 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int AM_NbElmt (ArrMeja T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int AM_MaxNbEl (ArrMeja T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType AM_GetFirstIdx (ArrMeja T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxType AM_GetLastIdx (ArrMeja T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** Test Indeks yang valid ********** */
boolean AM_IsIdxValid (ArrMeja T, IdxType i);
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean AM_IsIdxEff (ArrMeja T, IdxType i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean AM_IsEmpty (ArrMeja T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void AM_BacaIsi (ArrMeja * T);
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
void AM_TulisIsi (ArrMeja T);
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/*      Jika T kosong : Hanya menulis "Tabel kosong" */
/* Contoh: Jika isi Tabel: [1, 20, 30, 50]
   Maka tercetak di layar:
   [1]1
   [2]20
   [3]30
   [4]50
*/

/* ********** OPERASI LAIN ********** */
void AM_CopyTab (ArrMeja Tin, ArrMeja * Tout);
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
Meja AM_CreateMeja(int bangku,Point pos,int status);
/*
	fungsi menhasilkan meja yang sudah di set berdasarkan input
*/

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AM_AddAsLastEl (ArrMeja * T, Meja X);
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
void AM_AddEli (ArrMeja * T, Meja X, IdxType i);
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas
   terhadap elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses : Geser elemen ke-i+1 s.d. terakhir */
/*          Isi elemen ke-i dengan X */

/* ********** MENGHAPUS ELEMEN ********** */
void AM_DelLastEl (ArrMeja * T, Meja * X);
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
void AM_DelEli (ArrMeja * T, IdxType i, Meja * X);
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */

#endif
