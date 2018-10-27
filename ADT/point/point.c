/* Kelompok  : UAS
   Nama file : point.c
   Topik     : Engi's Kitchen Game
   Tanggal   : 26-10-2018
   Deskripsi : ADT untuk tipe POINT*/
/* *** Definisi ABSTRACT DATA TYPE POINT *** */

#include "point.h"

#define PI 3.14159265358979323846

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT P_MakePOINT (float X, float Y)
/* Membentuk sebuah POINT dari komponen-komponennya */
{
  /* KAMUS */
  POINT P;

  /* ALGORITMA */
  P_Absis(P) = X;
  P_Ordinat(P) = Y;

  return P;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void P_BacaPOINT (POINT * P)
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
  *P = P_MakePOINT(X,Y);
}

void P_TulisPOINT (POINT P)
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
  printf("(%f,%f)",P_Absis(P),P_Ordinat(P));
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean P_EQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
{
  return ((P_Absis(P1)==P_Absis(P2)) && (P_Ordinat(P1)==P_Ordinat(P2)));
}
boolean P_NEQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 tidak sama dengan P2 */
{
  return ((P_Absis(P1)!=P_Absis(P2)) && (P_Ordinat(P1)!=P_Ordinat(P2)));
}

/* *** Kelompok menentukan di mana P berada *** */
boolean P_IsOrigin (POINT P)
/* Menghasilkan true jika P adalah titik origin */
{
  return ((P_Absis(P)==0) && (P_Ordinat(P)==0));
}
boolean P_IsOnSbX (POINT P)
/* Menghasilkan true jika P terletak Pada sumbu X */
{
  return (P_Ordinat(P)==0);
}
boolean P_IsOnSbY (POINT P)
/* Menghasilkan true jika P terletak pada sumbu Y */
{
  return (P_Absis(P)==0);
}

int P_Kuadran (POINT P)
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
{
  /* KAMUS */

  /* ALGORITMA */
  if(P_Absis(P)>0){
    if(P_Ordinat(P)>0){
      return 1;
    }else{
      return 4;
    }
  }else{
    if(P_Ordinat(P)>0){
      return 2;
    }else{
      return 3;
    }
  }
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT P_NextX (POINT P)
/* Mengirim salinan P dengan absis ditambah satu */
{
  return P_MakePOINT((P_Absis(P)+1), P_Ordinat(P));
}
POINT P_NextY (POINT P)
/* Mengirim salinan P dengan ordinat ditambah satu */
{
  return P_MakePOINT(P_Absis(P), (P_Ordinat(P)+1));
}
POINT P_PlusDelta (POINT P, float deltaX, float deltaY)
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
{
  /* KAMUS */
  float newX, newY;

  /* ALGORITMA */
  newX = P_Absis(P) + deltaX;
  newY = P_Ordinat(P) + deltaY;

  return P_MakePOINT(newX,newY);
}
POINT P_MirrorOf (POINT P, boolean SbX)
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
{
  /* KAMUS */
  float newX,newY;

  /* ALGORITMA */
  if(SbX){
    newX = P_Absis(P);
    newY = -P_Ordinat(P);
  }else{
    newX = -P_Absis(P);
    newY = P_Ordinat(P);
  }

  return P_MakePOINT(newX, newY);
}
float P_Jarak0 (POINT P)
/* Menghitung jarak P ke (0,0) */
{
  return sqrt( pow(P_Absis(P),2) + pow(P_Ordinat(P),2) );
}
float P_Panjang (POINT P1, POINT P2)
/* Menghitung jarak antara point P1 dan P2 */
{
  /* KAMUS */
  float jarakX, jarakY;

  /* ALGORITMA */
  jarakX = P_Absis(P1) - P_Absis(P2);
  jarakY = P_Ordinat(P1) - P_Ordinat(P2);

  return sqrt( pow(jarakX,2) + pow(jarakY,2) );

}
void P_Geser (POINT *P, float deltaX, float deltaY)
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
{
  /* KAMUS */

  /* ALGORITMA */
  *P = P_PlusDelta(*P, deltaX, deltaY);
}
void P_GeserKeSbX (POINT *P)
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
{
  /* KAMUS */

  /* ALGORITMA */
  *P = P_MakePOINT(P_Absis(*P),0);
}
void P_GeserKeSbY (POINT *P)
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
{
  /* KAMUS */

  /* ALGORITMA */
  *P = P_MakePOINT(0,P_Ordinat(*P));
}
void P_Mirror (POINT *P, boolean SbX)
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
{
  /* KAMUS */

  /* ALGORITMA */
  *P = P_MirrorOf(*P, SbX);
}
void P_Putar (POINT *P, float Sudut)
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */
{
  /* KAMUS */
  float newX,newY;
  const float degRad = PI/180.0;

  /* ALGORITMA */
  newX = cos(Sudut*degRad)*P_Absis(*P) + sin(Sudut*degRad)*P_Ordinat(*P);
  newY =  - sin(Sudut*degRad)*P_Absis(*P) + cos(Sudut*degRad)*P_Ordinat(*P);

  *P = P_MakePOINT(newX,newY);

}
