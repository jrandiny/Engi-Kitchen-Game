/* File : custprioqueue */
/* Implementasi ADT Customer Priority Queue */

#include "prioqueuecustomer.h"

/* ********* Prototype ********* */
boolean C_IsEmpty (PrioQueueCustomer Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
	//algoritma
  return (C_Head(Q)==Nol && C_Tail(Q)==Nol);
}
boolean C_IsFull (PrioQueueCustomer Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak C_MaxEl */
{
  //algoritma
	return (C_NBElmt(Q)==C_MaxEl(Q));
}
int C_NBElmt (PrioQueueCustomer Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
	//kamus
  C_address count;
  //algoritma
  if (C_IsEmpty(Q)) return 0;
  else {
    count = C_Tail(Q);
    if (C_Tail(Q)<C_Head(Q)) count += C_MaxEl(Q);
    return(count-C_Head(Q)+1);
  }
}

/* *** Kreator *** */
void C_CreateEmpty (PrioQueueCustomer * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg C_MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
	//algoritma
  (*Q).T = (customer*) malloc ((Max+1)* sizeof(customer));
  if ((*Q).T != NULL) {
    C_MaxEl(*Q) = Max;
    C_Head(*Q) = C_Tail(*Q) = Nol;
  } else C_MaxEl(*Q) = Nol;
}

/* *** Destruktor *** */
void C_DeAlokasi (PrioQueueCustomer * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, C_MaxEl(Q) diset 0 */
{
	//algoritma
  free((*Q).T);
  C_MaxEl(*Q) = Nol;
}

/* *** Primitif Add/Delete *** */
void C_Add (PrioQueueCustomer * Q, customer X)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer;
        elemen baru disisipkan pada posisi yang tepat sesuai dengan prioritas */
{
  //kamus
  int i,j;
  int indeks;
	//algoritma
  if (C_IsEmpty(*Q)) {
		C_Head(*Q) = 1;
		C_Tail(*Q) = 1;
		C_InfoTail(*Q) = X;
	}
  else {
    i=C_Head(*Q);
    j=C_Tail(*Q);
		while (C_Prio(C_Elmt(*Q,j))<C_Prio(X) && j!=i) {
      indeks = j+1;
      if (indeks > C_MaxEl(*Q)) indeks%=C_MaxEl(*Q);
			C_Elmt(*Q,indeks) = C_Elmt(*Q,j);
			j--;
      if (j==0) j=C_MaxEl(*Q);
		}
    indeks = j+1;
    if (indeks > C_MaxEl(*Q)) indeks%=C_MaxEl(*Q);
    if (C_Prio(C_Elmt(*Q,j))<C_Prio(X)) {
      C_Elmt(*Q,indeks) = C_Elmt(*Q,j);
      C_Elmt(*Q,j) = X;
    } else {
      C_Elmt(*Q,indeks) = X;
    }
		if (C_Tail(*Q)==C_MaxEl(*Q)) C_Tail(*Q) = 1;
    else C_Tail(*Q)++;
  }
}
void C_Del (PrioQueueCustomer * Q, customer * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
	//algoritma
  *X = C_InfoHead(*Q);
  if (C_Head(*Q)==C_Tail(*Q)) {
    C_Head(*Q) = Nol;
    C_Tail(*Q) = Nol;
  } else if (C_Head(*Q)==C_MaxEl(*Q)) C_Head(*Q) = 1;
  else C_Head(*Q)++;
}
/* Operasi Tambahan */
void C_PrintQueue (PrioQueueCustomer Q)
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
{
  //kamus
	customer X;
  //algoritma
	while (!C_IsEmpty(Q)) {
		C_Del(&Q,&X);
		printf("%d %d\n",C_Prio(X),C_Jumlah(X));
	}
	printf("#\n");
}
