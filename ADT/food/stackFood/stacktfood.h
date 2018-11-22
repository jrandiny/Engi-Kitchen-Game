/* File : stackt.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef stacktfood_H
#define stacktfood_H

#include "../../../std.h"
#include "../food.h"

#define SF_MaxEl 50
/* Nil adalah stack dengan elemen kosong . */
/* Karena indeks dalam bhs C dimulai 0 maka tabel dg indeks 0 tidak dipakai */

typedef Food SF_infotype;
typedef int SF_address;   /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct {
	SF_infotype T[SF_MaxEl+1]; /* tabel penyimpan elemen */
	SF_address TOP;  /* alamat TOP: elemen puncak */
	int Max;
} StackFood;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai StackFood T[1]..T[SF_MaxEl] */
/* Jika S adalah StackFood maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define SF_Top(S) (S).TOP
#define SF_InfoTop(S) (S).T[(S).TOP]
#define SF_Max(S) (S).Max

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void SF_CreateEmpty (StackFood *S, int max);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas SF_MaxEl */
/* jadi indeksnya antara 1.. SF_MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean SF_IsEmpty (StackFood S);
/* Mengirim true jika StackFood kosong: lihat definisi di atas */
boolean SF_IsFull (StackFood S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke StackFood ************ */
void SF_Push (StackFood * S, SF_infotype X);
/* Menambahkan X sebagai elemen StackFood S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen StackFood ************ */
void SF_Pop (StackFood * S, SF_infotype* X);
/* Menghapus X dari StackFood S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

// fungsi lain
StackFood SF_ReversStack(StackFood S);
/*
	fungsi mengembalikan S yang di balikkan,
	misalnya inputnya 1 2 3 menjadi 3 2 1
*/

#endif
