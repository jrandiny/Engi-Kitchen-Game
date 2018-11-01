/* File : multilist.h */
/* contoh ADT multi list berkait dengan representasi fisik pointer  */
/* Representasi ML_address dengan pointer */

#ifndef multilist_H
#define multilist_H

#include "../../header/std.h"
#include "../point/point.h"
#include "listlinier.h"

typedef struct tML_Elmt *ML_address;
typedef struct tML_Elmt {
	List SimpulList;
	ML_address ML_next;
} ML_Elmt;
typedef struct {
	ML_address ML_First;
} ML_List;

/* Definisi Mlist : */
/* List kosong : ML_First(L) = Nil */
/* Setiap elemen dengan ML_address P dapat diacu FirstSimpul(P), ML_next(P) */
/* Elemen terakhir list : jika addressnya Last, maka ML_next(Last)=Nil */

#define FirstSimpul(P) (P)->SimpulList
#define ML_next(P) (P)->ML_next
#define FirstML_List(L) (L).ML_First

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean ML_IsEmpty (ML_List L);
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void ML_CreateEmpty (ML_List *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
ML_address ML_Alokasi (List X);
/* Mengirimkan ML_address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka ML_address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void ML_Dealokasi (ML_address *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian ML_address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
ML_address ML_Search (ML_List L, List X);
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan ML_address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void ML_InsVFirst (ML_List *L, List X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void ML_InsVLast (ML_List *L, List X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void ML_DelVFirst (ML_List *L, List *X);
/* I.S. ML_List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void ML_DelVLast (ML_List *L, List *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void ML_InsertFirst (ML_List *L, ML_address P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-ML_address P sebagai elemen pertama */
void ML_InsertAfter (ML_List *L, ML_address P, ML_address Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void ML_InsertLast (ML_List *L, ML_address P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void ML_DelFirst (ML_List *L, ML_address *P);
/* I.S. ML_List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void ML_DelP (ML_List *L, List X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list berML_address P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* ML_List mungkin menjadi kosong karena penghapusan */
void ML_DelLast (ML_List *L, ML_address *P);
/* I.S. ML_List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
void ML_DelAfter (ML_List *L, ML_address *Pdel, ML_address Prec);
/* I.S. ML_List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void ML_PrintInfo (ML_List L);
/* I.S. ML_List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int ML_NbElmt (ML_List L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

#endif
