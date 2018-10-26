/* File : prioqueue.h */
/* Definisi ADT Priority Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut mengecil berdasarkan elemen prio */

#ifndef prioqueue_H
#define prioqueue_H

#include "../../std.h"

#define Nil 0
/* Konstanta untuk mendefinisikan address tak terdefinisi */

/* Definisi elemen dan address */
typedef struct { int prio;  /* [1..3], prioritas dengan nilai 1..3 (3 adalah prioritas tertinggi) */
                 int info;  /* nilai elemen */
               } infotype;
typedef int address;   /* indeks tabel */
/* Contoh deklarasi variabel bertype Queue : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct { infotype * T;   /* tabel penyimpan elemen */
                 address HEAD;  /* alamat penghapusan */
                 address TAIL;  /* alamat penambahan */
                 int MaxEl;     /* Max elemen queue */
               } PrioQueue;
/* Definisi Queue kosong: HEAD=Nil; TAIL=Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah infotype dan Q adalah Queue, maka akses elemen : */
#define Prio(e)     (e).prio
#define InfoPQ(e)     (e).info
#define HeadPQ(Q)     (Q).HEAD
#define TailPQ(Q)     (Q).TAIL
#define InfoHeadPQ(Q) (Q).T[(Q).HEAD]
#define InfoTailPQ(Q) (Q).T[(Q).TAIL]
#define MaxElPQ(Q)    (Q).MaxEl
#define ElmtPQ(Q,i)   (Q).T[(i)]

/* ********* Prototype ********* */
boolean IsEmpty_PrioQueue (PrioQueue Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull_PrioQueue (PrioQueue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmt_PrioQueue (PrioQueue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void CreateEmpty_PrioQueue (PrioQueue * Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi_PrioQueue (PrioQueue * Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Add_PrioQueue (PrioQueue * Q, infotype X);
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer;
        elemen baru disisipkan pada posisi yang tepat sesuai dengan prioritas */
void Del_PrioQueue (PrioQueue * Q, infotype * X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void PrintPrioQueue (PrioQueue Q);
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/

#endif
