#include "prioqueue.h"
#include <stdlib.h>
#include <stdio.h>

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
	//algoritma
  return (Head(Q)==Nil && Tail(Q)==Nil);
}
boolean IsFull (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
  //algoritma
	return (NBElmt(Q)==MaxEl(Q));
}
int NBElmt (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
	//kamus
  address count;
  //algoritma
  if (IsEmpty(Q)) return 0;
  else {
    count = Tail(Q);
    if (Tail(Q)<Head(Q)) count += MaxEl(Q);
    return(count-Head(Q)+1);
  }
}

/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
	//algoritma
  (*Q).T = (infotype*) malloc ((Max+1)* sizeof(infotype));
  if ((*Q).T != NULL) {
    MaxEl(*Q) = Max;
    Head(*Q) = Tail(*Q) = Nil;
  } else MaxEl(*Q) = Nil;
}

/* *** Destruktor *** */
void DeAlokasi(Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
	//algoritma
  free((*Q).T);
  MaxEl(*Q) = Nil;
}

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer;
        elemen baru disisipkan pada posisi yang tepat sesuai dengan prioritas */
{
  //kamus
  int i,j;
  int indeks;
	//algoritma
  if (IsEmpty(*Q)) {
		Head(*Q) = 1;
		Tail(*Q) = 1;
		InfoTail(*Q) = X;
	}
  else {
    i=Head(*Q);
    j=Tail(*Q);
		while (Prio(Elmt(*Q,j))<Prio(X) && j!=i) {
      indeks = j+1;
      if (indeks > MaxEl(*Q)) indeks%=MaxEl(*Q);
			Elmt(*Q,indeks) = Elmt(*Q,j);
			j--;
      if (j==0) j=MaxEl(*Q);
		} //Prio(Elmt(*Q,j))==Prio(X) || j==i
    indeks = j+1;
    if (indeks > MaxEl(*Q)) indeks%=MaxEl(*Q);
    if (Prio(Elmt(*Q,j))<Prio(X)) {
      Elmt(*Q,indeks) = Elmt(*Q,j);
      Elmt(*Q,j) = X;
    } else {
      Elmt(*Q,indeks) = X;
    }
		if (Tail(*Q)==MaxEl(*Q)) Tail(*Q) = 1;
    else Tail(*Q)++;
  }
}
void Del (Queue * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
	//algoritma
  *X = InfoHead(*Q);
  if (Head(*Q)==Tail(*Q)) {
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
  } else if (Head(*Q)==MaxEl(*Q)) Head(*Q) = 1;
  else Head(*Q)++;
}
/* Operasi Tambahan */
void PrintQueue (Queue Q)
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
	infotype X;
  //algoritma
	while (!IsEmpty(Q)) {
		Del(&Q,&X);
		printf("%d %d\n",Prio(X),Info(X));
	}
	printf("#\n");
}
