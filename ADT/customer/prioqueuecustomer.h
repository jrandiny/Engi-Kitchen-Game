/* File : custprioqueue.h */
/* Definisi ADT Customer Priority Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut mengecil berdasarkan elemen prio */

#ifndef prioqueuecustomer_H
#define prioqueuecustomer_H

#include "../../std.h"

#define PQC_MaxEl 12
/* Definisi elemen dan PQ_address */
typedef struct { int prio;  /* [0..1], prioritas dengan nilai 0..1 (1 adalah prioritas tertinggi) */
                 int jumlah;  /* [2 atau 4] nilai elemen */
                 int waktu; /* waktu keluar */
               } Customer;
typedef int PQC_address;   /* indeks tabel */
/* Contoh deklarasi variabel bertype Queue : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct { Customer T[PQC_MaxEl+1];   /* tabel penyimpan elemen */
                 PQC_address HEAD;  /* alamat penghapusan */
                 PQC_address TAIL;  /* alamat penambahan */
               } PrioQueueCustomer;
/* Definisi Queue kosong: HEAD=Nil; TAIL=Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah Customer dan Q adalah Queue, maka akses elemen : */
#define PQC_Prio(e)       (e).prio
#define PQC_Jumlah(e)     (e).jumlah
#define PQC_Waktu(e)      (e).waktu
#define PQC_Head(Q)       (Q).HEAD
#define PQC_Tail(Q)       (Q).TAIL
#define PQC_InfoHead(Q)   (Q).T[(Q).HEAD]
#define PQC_InfoTail(Q)   (Q).T[(Q).TAIL]
#define PQC_Elmt(Q,i)     (Q).T[(i)]

/* ********* Prototype ********* */
boolean PQC_IsEmpty (PrioQueueCustomer Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean PQC_IsFull (PrioQueueCustomer Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int PQC_NBElmt (PrioQueueCustomer Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void PQC_CreateEmpty (PrioQueueCustomer * Q);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Primitif Add/Delete *** */
void PQC_Add (PrioQueueCustomer * Q, Customer X);
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer;
        elemen baru disisipkan pada posisi yang tepat sesuai dengan prioritas */
void PQC_Del (PrioQueueCustomer * Q, Customer * X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void PQC_PrintQueue (PrioQueueCustomer Q);
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/

#endif
