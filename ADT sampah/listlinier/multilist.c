
#include "multilist.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean ML_IsEmpty (ML_List L)
/* Mengirim true jika ML_List kosong */
{
	
}
/****************** PEMBUATAN LIST KOSONG ******************/
void ML_CreateEmpty (ML_List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk ML_List kosong */
{
	FirstML_List(*L) = Nil;
}
/****************** Manajemen Memori ******************/
ML_address ML_Alokasi (List X)
/* Mengirimkan ML_address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka ML_address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{

}
void ML_Dealokasi (ML_address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian ML_address P */
{

}
/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
ML_address ML_Search (ML_List L, List X)
/* Mencari apakah ada elemen ML_List dengan Info(P)= X */
/* Jika ada, mengirimkan ML_address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{

}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void ML_InsVFirst (ML_List *L, List X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{

}
void ML_InsVLast (ML_List *L, List X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen ML_List di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{

}

/*** PENGHAPUSAN ELEMEN ***/
void ML_DelVFirst (ML_List *L, List *X)
/* I.S. ML_List L tidak kosong  */
/* F.S. Elemen pertama ML_List dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{

}
void ML_DelVLast (ML_List *L, List *X)
/* I.S. ML_List tidak kosong */
/* F.S. Elemen terakhir ML_List dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{

}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void ML_InsertFirst (ML_List *L, ML_address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-ML_address P sebagai elemen pertama */
{

}
void ML_InsertAfter (ML_List *L, ML_address P, ML_address Prec)
/* I.S. Prec pastilah elemen ML_List dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{

}
void ML_InsertLast (ML_List *L, ML_address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{

}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void ML_DelFirst (ML_List *L, ML_address *P)
/* I.S. ML_List tidak kosong */
/* F.S. P adalah alamat elemen pertama ML_List sebelum penghapusan */
/*      Elemen ML_List berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{

}
void ML_DelP (ML_List *L, List X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen ML_List beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari ML_List dan di-dealokasi */
/* Jika tidak ada elemen ML_List dengan Info(P)=X, maka ML_List tetap */
/* ML_List mungkin menjadi kosong karena penghapusan */
{

}
void ML_DelLast (ML_List *L, ML_address *P)
/* I.S. ML_List tidak kosong */
/* F.S. P adalah alamat elemen terakhir ML_List sebelum penghapusan  */
/*      Elemen ML_List berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{

}
void ML_DelAfter (ML_List *L, ML_address *Pdel, ML_address Prec)
/* I.S. ML_List tidak kosong. Prec adalah anggota ML_List  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen ML_List yang dihapus  */
{

}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void ML_PrintInfo (ML_List L)
/* I.S. ML_List mungkin kosong */
/* F.S. Jika ML_List tidak kosong, iai ML_List dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika ML_List kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{

}
int ML_NbElmt (ML_List L)
/* Mengirimkan banyaknya elemen ML_List mengirimkan 0 jika ML_List kosong */
{

}
