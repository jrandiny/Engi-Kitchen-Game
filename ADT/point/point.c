/* Kelompok  : UAS
   Nama file : point.c
   Deskripsi : Implementasi ADT untuk tipe Point*/
/* *** Definisi ABSTRACT DATA TYPE Point *** */

#include "point.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk Point *** */
void P_CreatePoint (Point *P)
/* Membentuk sebuah Point dari komponen-komponennya */
{
  /* ALGORITMA */
  P_Baris(*P) = 0;
  P_Kolom(*P) = 0;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void P_BacaPoint (Point * P)
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   Point P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk Point <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
{
  /* KAMUS */
  int X,Y;

  /* ALGORITMA */
  scanf("%d %d",&X,&Y);
  P_SetXY(P,X,Y);
}

void P_TulisPoint (Point P)
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
{
  /* KAMUS */

  /* ALGORITMA */
  printf("(%d,%d)",P_Baris(P),P_Kolom(P));
}

/* *** Kelompok operasi relasional terhadap Point *** */
boolean P_EQ (Point P1, Point P2)
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
{
  return ((P_Baris(P1)==P_Baris(P2)) && (P_Kolom(P1)==P_Kolom(P2)));
}
boolean P_NEQ (Point P1, Point P2)
/* Mengirimkan true jika P1 tidak sama dengan P2 */
{
  return ((P_Baris(P1)!=P_Baris(P2)) && (P_Kolom(P1)!=P_Kolom(P2)));
}


/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
Point P_PlusDelta (Point P, int deltaX, int deltaY)
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
{
  /* KAMUS */
  int newX, newY;
  Point p;
  /* ALGORITMA */
  newX = P_Baris(P) + deltaX;
  newY = P_Kolom(P) + deltaY;
  P_SetXY(&p,newX,newY);
  return p;
}
void P_GetXY(Point P, int *x, int *y)
/*
	I.S. P terdefinisi
	F.S. x dan y terisi absis dan ordinat dari P
*/
{
  *x = P_Baris(P);
  *y = P_Kolom(P);
}
void P_SetXY(Point *P, int x,int y)
/*
	I.S. P, x, dan y terdefinisi
	F.S. absis(p) = x && ordinat(p) = y
*/
{
  P_Baris(*P) = x;
  P_Kolom(*P) = y;
}
void P_Geser (Point *P, int deltaX, int deltaY)
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
{
  /* ALGORITMA */
  *P = P_PlusDelta(*P, deltaX, deltaY);
}
