/* File: point.h */
/* Tanggal: 26 Oktober 2018 */

/* *** Definisi ABSTRACT DATA TYPE Point *** */

#ifndef POINT_H
#define POINT_H

#include "../../std.h"

typedef struct {
	int X; /* absis   */
	int Y; /* ordinat */
} Point;

/* *** Notasi Akses: Selektor Point *** */
#define P_Absis(P) (P).X
#define P_Ordinat(P) (P).Y

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk Point *** */
void P_CreatePoint (Point *P);
/* Membentuk sebuah Point dari komponen-komponennya */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void P_BacaPoint (Point * P);
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   Point P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk Point <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
void P_TulisPoint (Point P);
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */

/* *** Kelompok operasi relasional terhadap Point *** */
boolean P_EQ (Point P1, Point P2);
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
boolean P_NEQ (Point P1, Point P2);
/* Mengirimkan true jika P1 tidak sama dengan P2 */

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
Point P_PlusDelta (Point P, int deltaX, int deltaY);
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
void P_GetXY(Point P, int *x, int *y);
/*
	I.S. P terdefinisi
	F.S. x dan y terisi absis dan ordinat dari P
*/
void P_SetXY(Point *P, int x,int y);
/*
	I.S. P, x, dan y terdefinisi
	F.S. absis(p) = x && ordinat(p) = y
*/
void P_Geser (Point *P, int deltaX, int deltaY);
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */

#endif
