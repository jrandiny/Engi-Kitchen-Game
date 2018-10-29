/* Kelompok  : UAS
   Nama file : point.c
   Topik     : Engi's Kitchen Game
   Tanggal   : 26-10-2018
   Deskripsi : ADT untuk tipe Point*/
/* *** Definisi ABSTRACT DATA TYPE Point *** */

#include "point.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk Point *** */
Point P_MakePoint (int X, int Y)
/* Membentuk sebuah Point dari komponen-komponennya */
{
  /* KAMUS */
  Point P;

  /* ALGORITMA */
  P_Absis(P) = X;
  P_Ordinat(P) = Y;

  return P;
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
  scanf("%f %f",&X,&Y);
  *P = P_MakePoint(X,Y);
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
  printf("(%d,%d)",P_Absis(P),P_Ordinat(P));
}

/* *** Kelompok operasi relasional terhadap Point *** */
boolean P_EQ (Point P1, Point P2)
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
{
  return ((P_Absis(P1)==P_Absis(P2)) && (P_Ordinat(P1)==P_Ordinat(P2)));
}
boolean P_NEQ (Point P1, Point P2)
/* Mengirimkan true jika P1 tidak sama dengan P2 */
{
  return ((P_Absis(P1)!=P_Absis(P2)) && (P_Ordinat(P1)!=P_Ordinat(P2)));
}


/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
Point P_NextX (Point P)
/* Mengirim salinan P dengan absis ditambah satu */
{
  return P_MakePoint((P_Absis(P)+1), P_Ordinat(P));
}
Point P_NextY (Point P)
/* Mengirim salinan P dengan ordinat ditambah satu */
{
  return P_MakePoint(P_Absis(P), (P_Ordinat(P)+1));
}
Point P_PlusDelta (Point P, int deltaX, int deltaY)
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
{
  /* KAMUS */
  int newX, newY;

  /* ALGORITMA */
  newX = P_Absis(P) + deltaX;
  newY = P_Ordinat(P) + deltaY;

  return P_MakePoint(newX,newY);
}

void P_Geser (Point *P, int deltaX, int deltaY)
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
{
  /* KAMUS */

  /* ALGORITMA */
  *P = P_PlusDelta(*P, deltaX, deltaY);
}
