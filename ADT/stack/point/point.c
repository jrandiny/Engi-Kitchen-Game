/* NIM/Nama  : 13517063/Joshua Christo Randiny
   Nama file : point.h
   Topik     : Modul Prapraktikum 01
   Tanggal   : 29-08-2018
   Deskripsi : ADT untuk tipe POINT*/
/* *** Definisi ABSTRACT DATA TYPE POINT *** */

#include "point.h"
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y)
/* Membentuk sebuah POINT dari komponen-komponennya */
{
  /* KAMUS */
  POINT P;

  /* ALGORITMA */
  Absis(P) = X;
  Ordinat(P) = Y;

  return P;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT (POINT * P)
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
{
  /* KAMUS */
  float X,Y;

  /* ALGORITMA */
  scanf("%f %f",&X,&Y);
  *P = MakePOINT(X,Y);
}

void TulisPOINT (POINT P)
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
  printf("(%f,%f)",Absis(P),Ordinat(P));
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
{
  return ((Absis(P1)==Absis(P2)) && (Ordinat(P1)==Ordinat(P2)));
}
boolean NEQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 tidak sama dengan P2 */
{
  return ((Absis(P1)!=Absis(P2)) && (Ordinat(P1)!=Ordinat(P2)));
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P)
/* Menghasilkan true jika P adalah titik origin */
{
  return ((Absis(P)==0) && (Ordinat(P)==0));
}
boolean IsOnSbX (POINT P)
/* Menghasilkan true jika P terletak Pada sumbu X */
{
  return (Ordinat(P)==0);
}
boolean IsOnSbY (POINT P)
/* Menghasilkan true jika P terletak pada sumbu Y */
{
  return (Absis(P)==0);
}

int Kuadran (POINT P)
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
{
  /* KAMUS */

  /* ALGORITMA */
  if(Absis(P)>0){
    if(Ordinat(P)>0){
      return 1;
    }else{
      return 4;
    }
  }else{
    if(Ordinat(P)>0){
      return 2;
    }else{
      return 3;
    }
  }
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT NextX (POINT P)
/* Mengirim salinan P dengan absis ditambah satu */
{
  return MakePOINT((Absis(P)+1), Ordinat(P));
}
POINT NextY (POINT P)
/* Mengirim salinan P dengan ordinat ditambah satu */
{
  return MakePOINT(Absis(P), (Ordinat(P)+1));
}
POINT PlusDelta (POINT P, float deltaX, float deltaY)
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
{
  /* KAMUS */
  float newX, newY;

  /* ALGORITMA */
  newX = Absis(P) + deltaX;
  newY = Ordinat(P) + deltaY;

  return MakePOINT(newX,newY);
}
POINT MirrorOf (POINT P, boolean SbX)
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
{
  /* KAMUS */
  float newX,newY;

  /* ALGORITMA */
  if(SbX){
    newX = Absis(P);
    newY = -Ordinat(P);
  }else{
    newX = -Absis(P);
    newY = Ordinat(P);
  }

  return MakePOINT(newX, newY);
}
float Jarak0 (POINT P)
/* Menghitung jarak P ke (0,0) */
{
  return sqrt( pow(Absis(P),2) + pow(Ordinat(P),2) );
}
float Panjang (POINT P1, POINT P2)
/* Menghitung jarak antara point P1 dan P2 */
{
  /* KAMUS */
  float jarakX, jarakY;

  /* ALGORITMA */
  jarakX = Absis(P1) - Absis(P2);
  jarakY = Ordinat(P1) - Ordinat(P2);

  return sqrt( pow(jarakX,2) + pow(jarakY,2) );

}
void Geser (POINT *P, float deltaX, float deltaY)
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
{
  /* KAMUS */

  /* ALGORITMA */
  *P = PlusDelta(*P, deltaX, deltaY);
}
void GeserKeSbX (POINT *P)
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
{
  /* KAMUS */

  /* ALGORITMA */
  *P = MakePOINT(Absis(*P),0);
}
void GeserKeSbY (POINT *P)
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
{
  /* KAMUS */

  /* ALGORITMA */
  *P = MakePOINT(0,Ordinat(*P));
}
void Mirror (POINT *P, boolean SbX)
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
{
  /* KAMUS */

  /* ALGORITMA */
  *P = MirrorOf(*P, SbX);
}
void Putar (POINT *P, float Sudut)
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */
{
  /* KAMUS */
  float newX,newY;
  const float degRad = PI/180.0;

  /* ALGORITMA */
  /* X = x*cos() + y*sin()*/
  newX = cos(Sudut*degRad)*Absis(*P) + sin(Sudut*degRad)*Ordinat(*P);
  /* Y = -x*sin() + y*cos()*/
  newY =  - sin(Sudut*degRad)*Absis(*P) + cos(Sudut*degRad)*Ordinat(*P);

  *P = MakePOINT(newX,newY);

}
