/* File: point.h */
/* Tanggal: 26 Oktober 2018 */

/* *** Definisi ABSTRACT DATA TYPE POINT *** */

#ifndef POINT_H
#define POINT_H

#include "../../header/std.h"

typedef struct {
	int X; /* absis   */
	int Y; /* ordinat */
} POINT;

/* *** Notasi Akses: Selektor POINT *** */
#define P_Absis(P) (P).X
#define P_Ordinat(P) (P).Y

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT P_MakePOINT (int X, int Y);
/* Membentuk sebuah POINT dari komponen-komponennya */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void P_BacaPOINT (POINT * P);
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
void P_TulisPOINT (POINT P);
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean P_EQ (POINT P1, POINT P2);
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
boolean P_NEQ (POINT P1, POINT P2);
/* Mengirimkan true jika P1 tidak sama dengan P2 */

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT P_NextX (POINT P);
/* Mengirim salinan P dengan absis ditambah satu */
POINT P_NextY (POINT P);
/* Mengirim salinan P dengan ordinat ditambah satu */
POINT P_PlusDelta (POINT P, int deltaX, int deltaY);
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */

void P_Geser (POINT *P, int deltaX, int deltaY);
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */

#endif
