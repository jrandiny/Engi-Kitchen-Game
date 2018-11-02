/* File : custprioqueue.h */
/* Definisi ADT Customer Priority Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut mengecil berdasarkan elemen prio */

#ifndef prioqueuecustomer_H
#define prioqueuecustomer_H

#include "../../std.h"

/* Definisi elemen dan PQ_address */
typedef struct { int prio;  /* [0..1], prioritas dengan nilai 0..1 (1 adalah prioritas tertinggi) */
                 int jumlah;  /* [2 atau 4] nilai elemen */
                 int waktu; /* waktu datang */
                 int idmakanan; /* id bahan di tree makanan */
               } customer;
typedef int C_address;   /* indeks tabel */
/* Contoh deklarasi variabel bertype Queue : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct { customer * T;   /* tabel penyimpan elemen */
                 C_address HEAD;  /* alamat penghapusan */
                 C_address TAIL;  /* alamat penambahan */
                 int MaxEl;     /* Max elemen queue */
               } PrioQueueCustomer;
/* Definisi Queue kosong: HEAD=Nil; TAIL=Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah customer dan Q adalah Queue, maka akses elemen : */
#define C_Prio(e)     (e).prio
#define C_Jumlah(e)   (e).jumlah
#define C_Waktu(e)    (e).waktu
#define C_Head(Q)     (Q).HEAD
#define C_Tail(Q)     (Q).TAIL
#define C_InfoHead(Q) (Q).T[(Q).HEAD]
#define C_InfoTail(Q) (Q).T[(Q).TAIL]
#define C_MaxEl(Q)    (Q).MaxEl
#define C_Elmt(Q,i)   (Q).T[(i)]

/* ********* Prototype ********* */
boolean C_IsEmpty (PrioQueueCustomer Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean C_IsFull (PrioQueueCustomer Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int C_NBElmt (PrioQueueCustomer Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void C_CreateEmpty (PrioQueueCustomer * Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void C_DeAlokasi (PrioQueueCustomer * Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void C_Add (PrioQueueCustomer * Q, customer X);
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer;
        elemen baru disisipkan pada posisi yang tepat sesuai dengan prioritas */
void C_Del (PrioQueueCustomer * Q, customer * X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void C_PrintQueue (PrioQueueCustomer Q);
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/

#endif
