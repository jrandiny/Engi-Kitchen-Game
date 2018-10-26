#include "listlinier.h"

/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah integer */

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean LL_IsEmpty (List L)
/* Mengirim true jika list kosong */
{
  return First(L)==Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void LL_CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
  First(*L)=Nil;
}

/****************** Manajemen Memori ******************/
address LL_Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
  address pt;
  pt=(address)malloc(sizeof(ElmtList));
  if(pt!=Nil){
    Info(pt)=X;
    Next(pt)=Nil;
  }
  return pt;
}
void LL_Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
  free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address LL_Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
  if (LL_IsEmpty(L)){
    return Nil;
  }else{
    address P=First(L);
    while((Info(P)!=X)&&(Next(P)!=Nil)){
      P=Next(P);
    }
    if(Info(P)==X){
      return P;
    }else{
      return Nil;
    }
  }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void LL_InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
  address P=LL_Alokasi(X);
  if(P!=Nil){
    LL_InsertFirst(L,P);
  }
}
void LL_InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
  address P=LL_Alokasi(X);
  if(P!=Nil){
    LL_InsertLast(L,P);
  }
}

/*** PENGHAPUSAN ELEMEN ***/
void LL_DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
  address P;
  LL_DelFirst(L,&P);
  *X=Info(P);
  LL_Dealokasi(&P);
}
void LL_DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
  address last;
  LL_DelLast(L,&last);
  *X=Info(last);
  LL_Dealokasi(&last);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void LL_InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
  Next(P)=First(*L);
  First(*L)=P;
}
void LL_InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
  Next(P)=Next(Prec);
  Next(Prec)=P;
}
void LL_InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
  if(LL_IsEmpty(*L)){
    LL_InsertFirst(L,P);
  }else{
    address pt=First(*L);
    while(Next(pt)!=Nil){
      pt=Next(pt);
    }
    Next(pt)=P;
    Next(P)=Nil;  
  }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void LL_DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
  *P=First(*L);
  First(*L)=Next(*P);
  Next(*P)=Nil;
}
void LL_DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
  address P,Prec;
  P=First(*L);
  Prec=Nil;
  while((Info(P)!=X)&&(Next(P)!=Nil)){
    Prec=P;
    P=Next(P);
  }
  if(Info(P)==X){
    if(Prec==Nil){
      LL_DelFirst(L,&P);
    }else{
      Next(Prec)=Next(P);
      Next(P)=Nil;
    }
    LL_Dealokasi(&P);
  }
}
void LL_DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
  address last,prec;
  last=First(*L);
  prec=Nil;
  while(Next(last)!=Nil){
    prec=last;
    last=Next(last);
  }
  if(prec==Nil){
    LL_DelFirst(L,P);
  }else{
    *P=last;
    Next(prec)=Nil;
  }
}
void LL_DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
  *Pdel=Next(Prec);
  Next(Prec)=Next(*Pdel);
  Next(*Pdel)=Nil;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void LL_PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
  address P=First(L);
  printf("[");
  while(P!=Nil){
    printf("%d",Info(P));
    if(Next(P)!=Nil){
      printf(",");
    }
    P=Next(P);
  }
  printf("]");
}
int LL_NbElmt (List L)
/* Mengirimkan banyaknya elemen list mengirimkan 0 jika list kosong */
{
  int count=0;
  address P=First(L);
  while(P!=Nil){
    count++;
    P=Next(P);
  }
  return count;
}
/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype LL_Max (List L)
/* Mengirimkan nilai Info(P) yang maksimum */
{
  address P=First(L);
  infotype max=Info(P);
  P=Next(P);
  while(P!=Nil){
    if(Info(P)>max){
      max=Info(P);
    }
    P=Next(P);
  }
  return max;
}

/****************** PROSES TERHADAP LIST ******************/
void LL_Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
  LL_CreateEmpty(L3);
  address P,temp;
  if(!LL_IsEmpty(*L1)){
    P=First(*L1);
    while(P!=Nil){
      LL_DelFirst(L1,&temp);
      LL_InsertLast(L3,temp);
      P=First(*L1);
    }
  }
  if(!LL_IsEmpty(*L2)){
    P=First(*L2);
    while(P!=Nil){
      LL_DelFirst(L2,&temp);
      LL_InsertLast(L3,temp);
      P=First(*L2);
    }
  }
}