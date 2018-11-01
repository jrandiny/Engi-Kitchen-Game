/* MODUL TABEL RUANGAN */
/* Berisi definisi dan semua primitif pemrosesan tabel ruangan */
/* Penempatan elemen selalu rapat kiri */
/* Versi I : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori tabel statik */

#ifndef ARRAYRUANGAN_H
#define ARRAYRUANGAN_H

#include "../../header/std.h"
#include "../arrMeja/arrMeja.h"
#include "../matRoom/matRoom.h"

/*  Kamus Umum */
#define AR_IdxMax 4
/* Indeks maksimum array, sekaligus ukuran maksimum array dalam C */
#define AR_IdxMin 1
/* Indeks minimum array */

/* Definisi elemen dan koleksi objek */
typedef int IdxType;  /* type indeks */
typedef struct {
  MatRoom room;
  ArrMeja meja;
} Ruangan; /* type elemen tabel */
typedef struct {
	Ruangan TI[AR_IdxMax+1]; /* memori tempat penyimpan elemen (container) */
	int Neff; /* >=0, banyaknya elemen efektif */
} ArrRuangan;
/* Indeks yang digunakan [AR_IdxMin..AR_IdxMax] */
/* Jika T adalah ArrRuangan, cara deklarasi dan akses: */
/* Deklarasi : T : ArrRuangan */
/* Maka cara akses:
   T.Neff  untuk mengetahui banyaknya elemen
   T.TI    untuk mengakses seluruh nilai elemen tabel
   T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
  Tabel kosong: T.Neff = 0
  Definisi elemen pertama : T.TI[i] dengan i=1
  Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */

/* ********** SELEKTOR ********** */
#define AR_Neff(T)   (T).Neff
#define AR_TI(T)     (T).TI
#define AR_Elmt(T,i) (T).TI[(i)]
#define AR_Room(E) (E).room
#define AR_Meja(E) (E).meja

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void AR_CreateEmpty (ArrRuangan * T);
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas AR_IdxMax-AR_IdxMin+1 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int AR_NbElmt (ArrRuangan T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int AR_MaxNbEl (ArrRuangan T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType AR_GetFirstIdx (ArrRuangan T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxType AR_GetLastIdx (ArrRuangan T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** Test Indeks yang valid ********** */
boolean AR_IsIdxValid (ArrRuangan T, IdxType i);
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean AR_IsIdxEff (ArrRuangan T, IdxType i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** OPERASI LAIN ********** */
void AR_CopyTab (ArrRuangan Tin, ArrRuangan * Tout);
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AR_AddAsLastEl (ArrRuangan * T, Ruangan X);
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */

/* ********** MENGHAPUS ELEMEN ********** */
void AR_DelLastEl (ArrRuangan * T, Ruangan * X);
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */

#endif
