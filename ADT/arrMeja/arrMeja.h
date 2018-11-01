/* MODUL TABEL meja */
/* Berisi definisi dan semua primitif pemrosesan tabel meja */
/* Penempatan elemen selalu rapat kiri */
/* Versi I : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori tabel statik */

#ifndef ARRAYMEJA_H
#define ARRAYMEJA_H

#include "../../header/std.h"
#include "../point/point.h"

/*  Kamus Umum */
#define AM_IdxMax 50
/* Indeks maksimum array, sekaligus ukuran maksimum array dalam C */
#define AM_IdxMin 1
/* Indeks minimum array */

/* Definisi elemen dan koleksi objek */
typedef int IdxType;  /* type indeks */
typedef struct {
  int bangku;
  Point posisi;
  int status; //[0,1,2]
  /*
    0 : kosong
    1 : ada pelanggan belum order
    2 : ada pelanggan sudah order
  */
} Meja; /* type elemen tabel */
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
#define AM_Bangku(E) (E).room
#define AM_Posisi(E) (E).posisi
#define AM_Status(E) (E).status

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

/* ********** OPERASI LAIN ********** */
void AM_CopyTab (ArrMeja Tin, ArrMeja * Tout);
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AM_AddAsLastEl (ArrMeja * T, Meja X);
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */

/* ********** MENGHAPUS ELEMEN ********** */
void AM_DelLastEl (ArrMeja * T, Meja * X);
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */

#endif
