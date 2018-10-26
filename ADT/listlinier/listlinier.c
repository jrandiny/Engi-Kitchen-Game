/* NIM/Nama  : 13517063/Joshua Christo Randiny
   Nama file : listlinier.c
   Topik     : List linear
   Tanggal   : 22-10-2018
   Deskripsi : ADT list linear*/
/* File : listlinier.c */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah integer */


#include "listlinier.h"
#include <stdlib.h>
#include <stdio.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{
  return First(L)==Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
  First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
  /* KAMUS LOKAL */
  address P;

  /* ALGORITMA */
  P = (ElmtList*)malloc(sizeof(ElmtList));

  if(P!=Nil){
    Next(P) = Nil;
    Info(P) = X;
  }

  return P;
}
void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
  Next(*P) = Nil;
  free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
  /* KAMUS LOKAL */
  address pt;

  /* ALGORITMA */

  if(IsEmpty(L)){
    return Nil;
  }else{
    pt = First(L);

    while((X != Info(pt))&&(Next(pt)!=Nil)){
      pt = Next(pt);
    }

    if(X == Info(pt)){
      return pt;
    }else{
      return Nil;
    }
  }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
  /* KAMUS LOKAL */
  address P;

  /* ALGORITMA */
  P = Alokasi(X);
  if(P!=Nil){
    InsertFirst(L,P);
  }
}
void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
  /* KAMUS LOKAL */
  address P;

  /* ALGORITMA */
  P = Alokasi(X);
  if(P!=Nil){
    InsertLast(L,P);
  }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
  /* KAMUS LOKAL */
  address pdel;

  /* ALGORITMA */
  DelFirst(L, &pdel);
  *X = Info(pdel);
  Dealokasi(&pdel);
}
void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
  /* KAMUS LOKAL */
  address pdel;

  /* ALGORITMA */
  DelLast(L, &pdel);
  *X = Info(pdel);
  Dealokasi(&pdel);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  Next(P) = First(*L);
  First(*L) = P;
}

void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  Next(P) = Next(Prec);
  Next(Prec) = P;
}

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
  /* KAMUS LOKAL */
  address pt;

  /* ALGORITMA */
  if(IsEmpty(*L)){
    InsertFirst(L, P);
  }else{
    pt = First(*L);
    while(Next(pt)!=Nil){
      pt = Next(pt);
    }

    InsertAfter(L, P, pt);
  }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  *P = First(*L);
  First(*L) = Next(*P);
  Next(*P)=Nil;
}
void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
  /* KAMUS LOKAL */
  address pt;
  address prev;
  address pdel;

  /* ALGORITMA */
  prev = Nil;
  pt = First(*L);

  while((X != Info(pt))&&(Next(pt)!=Nil)){
    prev = pt;
    pt = Next(pt);
  }

  if(X==Info(pt)){
    if(prev==Nil){
      DelFirst(L, &pdel);
    }else{
      DelAfter(L, &pdel, prev);
    }

    Dealokasi(&pdel);
  }
}

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
  /* KAMUS LOKAL */
  address pt;
  address prev;
  address pdel;

  /* ALGORITMA */
  pt = First(*L);
  prev = Nil;
  while(Next(pt)!=Nil){
    prev = pt;
    pt = Next(pt);
  }

  if(prev == Nil){
    DelFirst(L, &pdel);
  }else{
    DelAfter(L, &pdel, prev);
  }

  *P = pdel;
}
void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  *Pdel = Next(Prec);
  Next(Prec) = Next(Next(Prec));
  Next(*Pdel) = Nil;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
  /* KAMUS LOKAL */
  address pt;

  /* ALGORITMA */
  printf("[");

  pt = First(L);

  while(pt!=Nil){
    printf("%d",Info(pt));
    pt = Next(pt);
    if(pt!=Nil){
      printf(",");
    }
  }
  /* pt = Nil*/

  printf("]");

}
int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
  /* KAMUS LOKAL */
  int count;
  address pt;

  /* ALGORITMA */
  pt = First(L);
  count = 0;
  while(pt!=Nil){
    pt = Next(pt);
    count++;
  }
  /* pt = Nil */

  return count;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L)
/* Mengirimkan nilai Info(P) yang maksimum */
{
  /* KAMUS LOKAL */
  infotype infoMax;
  address pt;

  /* ALGORITMA */
  pt = First(L);
  infoMax = Info(pt);

  pt = Next(pt);

  while(pt != Nil){
    if(Info(pt)>infoMax){
      infoMax = Info(pt);
    }
    pt = Next(pt);
  }
  /* pt = Nil */

  return infoMax;
}

/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
  /* KAMUS LOKAL */
  address pt3;

  /* ALGORITMA */
  pt3 = Nil;

  CreateEmpty(L3);

  if(IsEmpty(*L1)){
    First(*L3) = First(*L2);
  }else{
    First(*L3) = First(*L1);
    pt3 = First(*L1);

    while(Next(pt3)!=Nil){
      pt3 = Next(pt3);
    }
    /* Next(pt3) = Nil*/

    Next(pt3) = First(*L2);
  }

  First(*L1) = Nil;
  First(*L2) = Nil;

}
