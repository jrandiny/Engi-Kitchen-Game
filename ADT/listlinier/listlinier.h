/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi L_address dengan pointer */
/* infotype adalah integer */

#ifndef listlinier_H
#define listlinier_H

#include "../../header/std.h"

typedef struct{
	int simpul;
	Point warp;
} infotype;
typedef struct tElmtlist *L_address;
typedef struct tElmtlist {
	infotype info;
	L_address next;
} ElmtList;
typedef struct {
	L_address First;
} List;

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan L_address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */

#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) (L).First

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean LL_IsEmpty (List L);
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void LL_CreateEmpty (List *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
L_address LL_Alokasi (infotype X);
/* Mengirimkan L_address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka L_address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void LL_Dealokasi (L_address *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian L_address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
L_address LL_Search (List L, infotype X);
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan L_address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void LL_InsVFirst (List *L, infotype X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void LL_InsVLast (List *L, infotype X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void LL_DelVFirst (List *L, infotype *X);
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void LL_DelVLast (List *L, infotype *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void LL_InsertFirst (List *L, L_address P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-L_address P sebagai elemen pertama */
void LL_InsertAfter (List *L, L_address P, L_address Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void LL_InsertLast (List *L, L_address P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void LL_DelFirst (List *L, L_address *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void LL_DelP (List *L, infotype X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void LL_DelLast (List *L, L_address *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
void LL_DelAfter (List *L, L_address *Pdel, L_address Prec);
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void LL_PrintInfo (List L);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int LL_NbElmt (List L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype LL_Max (List L);
/* Mengirimkan nilai Info(P) yang maksimum */

/****************** PROSES TERHADAP LIST ******************/
void LL_Konkat1 (List *L1, List *L2, List *L3);
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */

#endif
