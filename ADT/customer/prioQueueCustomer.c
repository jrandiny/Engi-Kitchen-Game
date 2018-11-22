/* Kelompok  : UAS
   Nama file : prioQueueCustomer.c
   Deskripsi : ADT untuk prio queue customer */

#include "prioQueueCustomer.h"

/* ********* Prototype ********* */
boolean PQC_IsEmpty (PrioQueueCustomer Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
	/* ALGORITMA */
	return (PQC_Head(Q)==Nol && PQC_Tail(Q)==Nol);
}
boolean PQC_IsFull (PrioQueueCustomer Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak PQC_MaxEl */
{
	/* ALGORITMA */
	return (PQC_NBElmt(Q)==PQC_MaxEl);
}
int PQC_NBElmt (PrioQueueCustomer Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
	/* KAMUS */
	PQC_address count;
	/* ALGORITMA */
	if (PQC_IsEmpty(Q)) return 0;
	else {
		if(PQC_Head(Q)<=PQC_Tail(Q)){
			return PQC_Tail(Q)-PQC_Head(Q)+1;
		}else{
			return PQC_MaxEl-PQC_Head(Q)+1+PQC_Tail(Q);
		}
	}
}

/* *** Kreator *** */
void PQC_CreateEmpty (PrioQueueCustomer * Q)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg PQC_MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
	/* ALGORITMA */
	PQC_Tail(*Q) = Nol;
	PQC_Head(*Q) = Nol;
}


/* *** Primitif Add/Delete *** */
void PQC_Add (PrioQueueCustomer * Q, Customer X)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer;
        elemen baru disisipkan pada posisi yang tepat sesuai dengan prioritas */
{
	/* KAMUS */
	int i,j;
	int indeks;
	/* ALGORITMA */
	if (PQC_IsEmpty(*Q)) {
		PQC_Head(*Q) = 1;
		PQC_Tail(*Q) = 1;
		PQC_InfoTail(*Q) = X;
	}
	else {
		i=PQC_Head(*Q);
		j=PQC_Tail(*Q);
		while (PQC_Prio(PQC_Elmt(*Q,j))<PQC_Prio(X) && j!=i) {
			indeks = j+1;
			if (indeks > PQC_MaxEl) indeks%=PQC_MaxEl;
			PQC_Elmt(*Q,indeks) = PQC_Elmt(*Q,j);
			j--;
			if (j==0) j=PQC_MaxEl;
		}
		indeks = j+1;
		if (indeks > PQC_MaxEl) indeks%=PQC_MaxEl;
		if (PQC_Prio(PQC_Elmt(*Q,j))<PQC_Prio(X)) {
		PQC_Elmt(*Q,indeks) = PQC_Elmt(*Q,j);
		PQC_Elmt(*Q,j) = X;
		} else {
			PQC_Elmt(*Q,indeks) = X;
		}
		if (PQC_Tail(*Q)==PQC_MaxEl) PQC_Tail(*Q) = 1;
		else PQC_Tail(*Q)++;
	}
}

void PQC_Del (PrioQueueCustomer * Q, Customer * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
	/* ALGORITMA */
	*X = PQC_InfoHead(*Q);
	if (PQC_Head(*Q)==PQC_Tail(*Q)) {
		PQC_Head(*Q) = Nol;
		PQC_Tail(*Q) = Nol;
	} else {
		if (PQC_Head(*Q)==PQC_MaxEl) PQC_Head(*Q) = 1;
		else PQC_Head(*Q)++;
	}
}
/* Operasi Tambahan */
void PQC_PrintQueue (PrioQueueCustomer Q)
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
{
	/* KAMUS */
	Customer X;
	/* ALGORITMA */
	while (!PQC_IsEmpty(Q)) {
		PQC_Del(&Q,&X);
		printf("%d %d %d\n",PQC_Prio(X),PQC_Jumlah(X), PQC_Waktu(X));
	}
	printf("#\n");
}
