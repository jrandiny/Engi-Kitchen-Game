#include "prioqueue.h"

/* ********* Prototype ********* */
boolean PQ_IsEmpty (PrioQueue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
	/* ALGORITMA */
  return (PQ_Head(Q)==Nol && PQ_Tail(Q)==Nol);
}
boolean PQ_IsFull (PrioQueue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak PQ_MaxEl */
{
  /* ALGORITMA */
	return (PQ_NBElmt(Q)==PQ_MaxEl(Q));
}
int PQ_NBElmt (PrioQueue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
	//kamus
  address count;
  /* ALGORITMA */
  if (PQ_IsEmpty(Q)) return 0;
  else {
    count = PQ_Tail(Q);
    if (PQ_Tail(Q)<PQ_Head(Q)) count += PQ_MaxEl(Q);
    return(count-PQ_Head(Q)+1);
  }
}

/* *** Kreator *** */
void PQ_CreateEmpty (PrioQueue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg PQ_MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
	/* ALGORITMA */
  (*Q).T = (PQ_infotype*) malloc ((Max+1)* sizeof(PQ_infotype));
  if ((*Q).T != NULL) {
    PQ_MaxEl(*Q) = Max;
    PQ_Head(*Q) = PQ_Tail(*Q) = Nol;
  } else PQ_MaxEl(*Q) = Nol;
}

/* *** Destruktor *** */
void PQ_DeAlokasi (PrioQueue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, PQ_MaxEl(Q) diset 0 */
{
	/* ALGORITMA */
  free((*Q).T);
  PQ_MaxEl(*Q) = Nol;
}

/* *** Primitif Add/Delete *** */
void PQ_Add (PrioQueue * Q, PQ_infotype X)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer;
        elemen baru disisipkan pada posisi yang tepat sesuai dengan prioritas */
{
  //kamus
  int i,j;
  int indeks;
	/* ALGORITMA */
  if (PQ_IsEmpty(*Q)) {
		PQ_Head(*Q) = 1;
		PQ_Tail(*Q) = 1;
		PQ_InfoTail(*Q) = X;
	}
  else {
    i=PQ_Head(*Q);
    j=PQ_Tail(*Q);
		while (PQ_Prio(PQ_Elmt(*Q,j))<PQ_Prio(X) && j!=i) {
      indeks = j+1;
      if (indeks > PQ_MaxEl(*Q)) indeks%=PQ_MaxEl(*Q);
			PQ_Elmt(*Q,indeks) = PQ_Elmt(*Q,j);
			j--;
      if (j==0) j=PQ_MaxEl(*Q);
		} //PQ_Prio(PQ_Elmt(*Q,j))==PQ_Prio(X) || j==i
    indeks = j+1;
    if (indeks > PQ_MaxEl(*Q)) indeks%=PQ_MaxEl(*Q);
    if (PQ_Prio(PQ_Elmt(*Q,j))<PQ_Prio(X)) {
      PQ_Elmt(*Q,indeks) = PQ_Elmt(*Q,j);
      PQ_Elmt(*Q,j) = X;
    } else {
      PQ_Elmt(*Q,indeks) = X;
    }
		if (PQ_Tail(*Q)==PQ_MaxEl(*Q)) PQ_Tail(*Q) = 1;
    else PQ_Tail(*Q)++;
  }
}
void PQ_Del (PrioQueue * Q, PQ_infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
	/* ALGORITMA */
  *X = PQ_InfoHead(*Q);
  if (PQ_Head(*Q)==PQ_Tail(*Q)) {
    PQ_Head(*Q) = Nol;
    PQ_Tail(*Q) = Nol;
  } else if (PQ_Head(*Q)==PQ_MaxEl(*Q)) PQ_Head(*Q) = 1;
  else PQ_Head(*Q)++;
}
/* Operasi Tambahan */
void PQ_PrintQueue (PrioQueue Q)
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
	PQ_infotype X;
  /* ALGORITMA */
	while (!PQ_IsEmpty(Q)) {
		PQ_Del(&Q,&X);
		printf("%d %d\n",PQ_Prio(X),PQ_Info(X));
	}
	printf("#\n");
}
