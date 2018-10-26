#include "prioqueue.h"

/* ********* Prototype ********* */
boolean IsEmptyPQ (PrioQueue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
	//algoritma
  return (HeadPQ(Q)==Nol && TailPQ(Q)==Nol);
}
boolean IsFullPQ (PrioQueue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxElPQ */
{
  //algoritma
	return (NBElmtPQ(Q)==MaxElPQ(Q));
}
int NBElmtPQ (PrioQueue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
	//kamus
  address count;
  //algoritma
  if (IsEmptyPQ(Q)) return 0;
  else {
    count = TailPQ(Q);
    if (TailPQ(Q)<HeadPQ(Q)) count += MaxElPQ(Q);
    return(count-HeadPQ(Q)+1);
  }
}

/* *** Kreator *** */
void CreateEmptyPQ (PrioQueue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxElPQ=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
	//algoritma
  (*Q).T = (infotype*) malloc ((Max+1)* sizeof(infotype));
  if ((*Q).T != NULL) {
    MaxElPQ(*Q) = Max;
    HeadPQ(*Q) = TailPQ(*Q) = Nol;
  } else MaxElPQ(*Q) = Nol;
}

/* *** Destruktor *** */
void DeAlokasiPQ (PrioQueue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxElPQ(Q) diset 0 */
{
	//algoritma
  free((*Q).T);
  MaxElPQ(*Q) = Nol;
}

/* *** Primitif Add/Delete *** */
void AddPQ (PrioQueue * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer;
        elemen baru disisipkan pada posisi yang tepat sesuai dengan prioritas */
{
  //kamus
  int i,j;
  int indeks;
	//algoritma
  if (IsEmptyPQ(*Q)) {
		HeadPQ(*Q) = 1;
		TailPQ(*Q) = 1;
		InfoTailPQ(*Q) = X;
	}
  else {
    i=HeadPQ(*Q);
    j=TailPQ(*Q);
		while (Prio(ElmtPQ(*Q,j))<Prio(X) && j!=i) {
      indeks = j+1;
      if (indeks > MaxElPQ(*Q)) indeks%=MaxElPQ(*Q);
			ElmtPQ(*Q,indeks) = ElmtPQ(*Q,j);
			j--;
      if (j==0) j=MaxElPQ(*Q);
		} //Prio(ElmtPQ(*Q,j))==Prio(X) || j==i
    indeks = j+1;
    if (indeks > MaxElPQ(*Q)) indeks%=MaxElPQ(*Q);
    if (Prio(ElmtPQ(*Q,j))<Prio(X)) {
      ElmtPQ(*Q,indeks) = ElmtPQ(*Q,j);
      ElmtPQ(*Q,j) = X;
    } else {
      ElmtPQ(*Q,indeks) = X;
    }
		if (TailPQ(*Q)==MaxElPQ(*Q)) TailPQ(*Q) = 1;
    else TailPQ(*Q)++;
  }
}
void DelPQ (PrioQueue * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
	//algoritma
  *X = InfoHeadPQ(*Q);
  if (HeadPQ(*Q)==TailPQ(*Q)) {
    HeadPQ(*Q) = Nol;
    TailPQ(*Q) = Nol;
  } else if (HeadPQ(*Q)==MaxElPQ(*Q)) HeadPQ(*Q) = 1;
  else HeadPQ(*Q)++;
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
	while (!IsEmptyPQ(Q)) {
		DelPQ(&Q,&X);
		printf("%d %d\n",Prio(X),InfoPQ(X));
	}
	printf("#\n");
}
