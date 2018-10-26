#include "prioqueue.h"

/* ********* Prototype ********* */
boolean IsEmpty_PrioQueue (PrioQueue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
	//algoritma
  return (Head_PQ(Q)==Nil && Tail_PQ(Q)==Nil);
}
boolean IsFull_PrioQueue (PrioQueue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl_PQ */
{
  //algoritma
	return (NBElmt_PrioQueue(Q)==MaxEl_PQ(Q));
}
int NBElmt_PrioQueue (PrioQueue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
	//kamus
  address count;
  //algoritma
  if (IsEmpty_PrioQueue(Q)) return 0;
  else {
    count = Tail_PQ(Q);
    if (Tail_PQ(Q)<Head_PQ(Q)) count += MaxEl_PQ(Q);
    return(count-Head_PQ(Q)+1);
  }
}

/* *** Kreator *** */
void CreateEmpty_PrioQueue (PrioQueue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl_PQ=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
	//algoritma
  (*Q).T = (infotype*) malloc ((Max+1)* sizeof(infotype));
  if ((*Q).T != NULL) {
    MaxEl_PQ(*Q) = Max;
    Head_PQ(*Q) = Tail_PQ(*Q) = Nil;
  } else MaxEl_PQ(*Q) = Nil;
}

/* *** Destruktor *** */
void DeAlokasi_PrioQueue (PrioQueue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl_PQ(Q) diset 0 */
{
	//algoritma
  free((*Q).T);
  MaxEl_PQ(*Q) = Nil;
}

/* *** Primitif Add/Delete *** */
void Add_PrioQueue (PrioQueue * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer;
        elemen baru disisipkan pada posisi yang tepat sesuai dengan prioritas */
{
  //kamus
  int i,j;
  int indeks;
	//algoritma
  if (IsEmpty_PrioQueue(*Q)) {
		Head_PQ(*Q) = 1;
		Tail_PQ(*Q) = 1;
		InfoTail_PQ(*Q) = X;
	}
  else {
    i=Head_PQ(*Q);
    j=Tail_PQ(*Q);
		while (Prio(Elmt_PQ(*Q,j))<Prio(X) && j!=i) {
      indeks = j+1;
      if (indeks > MaxEl_PQ(*Q)) indeks%=MaxEl_PQ(*Q);
			Elmt_PQ(*Q,indeks) = Elmt_PQ(*Q,j);
			j--;
      if (j==0) j=MaxEl_PQ(*Q);
		} //Prio(Elmt_PQ(*Q,j))==Prio(X) || j==i
    indeks = j+1;
    if (indeks > MaxEl_PQ(*Q)) indeks%=MaxEl_PQ(*Q);
    if (Prio(Elmt_PQ(*Q,j))<Prio(X)) {
      Elmt_PQ(*Q,indeks) = Elmt_PQ(*Q,j);
      Elmt_PQ(*Q,j) = X;
    } else {
      Elmt_PQ(*Q,indeks) = X;
    }
		if (Tail_PQ(*Q)==MaxEl_PQ(*Q)) Tail_PQ(*Q) = 1;
    else Tail_PQ(*Q)++;
  }
}
void Del_PrioQueue (PrioQueue * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
	//algoritma
  *X = InfoHead_PQ(*Q);
  if (Head_PQ(*Q)==Tail_PQ(*Q)) {
    Head_PQ(*Q) = Nil;
    Tail_PQ(*Q) = Nil;
  } else if (Head_PQ(*Q)==MaxEl_PQ(*Q)) Head_PQ(*Q) = 1;
  else Head_PQ(*Q)++;
}
/* Operasi Tambahan */
void PrintPrioQueue (PrioQueue Q)
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
	while (!IsEmpty_PrioQueue(Q)) {
		Del_PrioQueue(&Q,&X);
		printf("%d %d\n",Prio(X),Info_PQ(X));
	}
	printf("#\n");
}
