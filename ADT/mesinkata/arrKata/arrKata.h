/* Kelompok  : UAS
   Nama file : arrKata.h
   Deskripsi : ADT untuk tipe array kata*/

#ifndef ARRAYKATAK_H
#define ARRAYKATAK_H

#include "../mesinkata.h"
#include "../../../boolean.h"

#define AK_IdxMax 100
#define AK_IdxMin 1

/* Definisi struktur */
typedef Kata AK_ElType;
typedef int AK_IdxType;
typedef struct{
  AK_ElType TabKata[AK_IdxMax+1];
  int Neff;
} ArrKata;

/* ********** SELEKTOR ********** */
#define AK_Neff(T)   (T).Neff
#define AK_TI(T)     (T).TabKata
#define AK_Elmt(T,i) (T).TabKata[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void AK_CreateEmpty (ArrKata * T);
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean AK_IsEmpty (ArrKata T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int AK_NbElmt (ArrKata T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int AK_MaxNbEl (ArrKata T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
AK_IdxType AK_GetFirstIdx (ArrKata T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
AK_IdxType AK_GetLastIdx (ArrKata T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** Test Indeks yang valid ********** */
boolean AK_IsIdxValid (ArrKata T, AK_IdxType i);
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean AK_IsIdxEff (ArrKata T, AK_IdxType i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AK_AddAsLastEl (ArrKata * T, AK_ElType X);
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */


#endif
