
#include "queue.h"

boolean IsEmptyQ (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
  return HeadQ(Q)==0 && TailQ(Q) ==0;
}

boolean IsFullQ (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxElQ */
{
  return NBElmtQ(Q) == MaxElQ(Q);
}
int NBElmtQ (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
  if(IsEmptyQ(Q)){
    return 0;
  }else{
    if(TailQ(Q)>=HeadQ(Q)){
      return TailQ(Q)-HeadQ(Q) + 1;
    }else{
      return TailQ(Q)+MaxElQ(Q) - HeadQ(Q) + 1;
    }
  }
}

/* *** Kreator *** */
void CreateEmptyQ (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxElQ=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
  (*Q).T = (infotype*)malloc((Max+1) * sizeof(infotype));
  if ((*Q).T != NULL) {
    MaxElQ(*Q) = Max;
    HeadQ(*Q) = Nil;
    TailQ(*Q) = Nil;
  }
}

/* *** Destruktor *** */
void DeAlokasiQ (Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxElQ(Q) diset 0 */
{
  MaxElQ(*Q) = 0;
  free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void AddQ (Queue * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
{
  if(IsEmptyQ(*Q)){
    HeadQ(*Q) = 1;
    TailQ(*Q) = 1;
    InfoTailQ(*Q) = X;
  }else{
    TailQ(*Q)++;
    if(TailQ(*Q)>MaxElQ(*Q)){
      TailQ(*Q) = 1;
    }
    InfoTailQ(*Q) = X;
  }
}
void DelQ (Queue * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer
        Q mungkin kosong */
{
  *X = InfoHead_Q(*Q);
  if(NBElmtQ(*Q)==1){
    HeadQ(*Q) = 0;
    TailQ(*Q) = 0;
  }else {
    HeadQ(*Q)++;
    if(HeadQ(*Q)>MaxElQ(*Q)){
      HeadQ(*Q)=1;
    }
  }
}
