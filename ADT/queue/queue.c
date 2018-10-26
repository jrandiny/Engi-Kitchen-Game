
#include "queue.h"

boolean IsEmpty_Queue (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
  return Head_Q(Q)==0 && Tail_Q(Q) ==0;
}

boolean IsFull_Queue (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl_Q */
{
  return NBElmt_Queue(Q) == MaxEl_Q(Q);
}
int NBElmt_Queue (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
  if(IsEmpty_Queue(Q)){
    return 0;
  }else{
    if(Tail_Q(Q)>=Head_Q(Q)){
      return Tail_Q(Q)-Head_Q(Q) + 1;
    }else{
      return Tail_Q(Q)+MaxEl_Q(Q) - Head_Q(Q) + 1;
    }
  }
}

/* *** Kreator *** */
void CreateEmpty_Queue (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl_Q=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
  (*Q).T = (infotype*)malloc((Max+1) * sizeof(infotype));
  if ((*Q).T != NULL) {
    MaxEl_Q(*Q) = Max;
    Head_Q(*Q) = Nil;
    Tail_Q(*Q) = Nil;
  }
}

/* *** Destruktor *** */
void DeAlokasi_Queue (Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl_Q(Q) diset 0 */
{
  MaxEl_Q(*Q) = 0;
  free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Add_Queue (Queue * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
{
  if(IsEmpty_Queue(*Q)){
    Head_Q(*Q) = 1;
    Tail_Q(*Q) = 1;
    InfoTail_Q(*Q) = X;
  }else{
    Tail_Q(*Q)++;
    if(Tail_Q(*Q)>MaxEl_Q(*Q)){
      Tail_Q(*Q) = 1;
    }
    InfoTail_Q(*Q) = X;
  }
}
void Del_Queue (Queue * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer
        Q mungkin kosong */
{
  *X = InfoHead_Q(*Q);
  if(NBElmt_Queue(*Q)==1){
    Head_Q(*Q) = 0;
    Tail_Q(*Q) = 0;
  }else {
    Head_Q(*Q)++;
    if(Head_Q(*Q)>MaxEl_Q(*Q)){
      Head_Q(*Q)=1;
    }
  }
}
