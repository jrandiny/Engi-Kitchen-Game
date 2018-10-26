
#include "queue.h"

boolean Q_IsEmpty (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
  return Q_Head(Q)==0 && Q_Tail(Q) ==0;
}

boolean Q_IsFull (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak Q_MaxEl */
{
  return Q_NBElmt(Q) == Q_MaxEl(Q);
}
int Q_NBElmt (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
  if(Q_IsEmpty(Q)){
    return 0;
  }else{
    if(Q_Tail(Q)>=Q_Head(Q)){
      return Q_Tail(Q)-Q_Head(Q) + 1;
    }else{
      return Q_Tail(Q)+Q_MaxEl(Q) - Q_Head(Q) + 1;
    }
  }
}

/* *** Kreator *** */
void Q_CreateEmpty (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg Q_MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
  (*Q).T = (infotype*)malloc((Max+1) * sizeof(infotype));
  if ((*Q).T != NULL) {
    Q_MaxEl(*Q) = Max;
    Q_Head(*Q) = Nol;
    Q_Tail(*Q) = Nol;
  }
}

/* *** Destruktor *** */
void Q_DeAlokasi (Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, Q_MaxEl(Q) diset 0 */
{
  Q_MaxEl(*Q) = 0;
  free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Q_Add (Queue * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
{
  if(Q_IsEmpty(*Q)){
    Q_Head(*Q) = 1;
    Q_Tail(*Q) = 1;
    Q_InfoTail(*Q) = X;
  }else{
    Q_Tail(*Q)++;
    if(Q_Tail(*Q)>Q_MaxEl(*Q)){
      Q_Tail(*Q) = 1;
    }
    Q_InfoTail(*Q) = X;
  }
}
void Q_Del (Queue * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer
        Q mungkin kosong */
{
  *X = Q_InfoHead(*Q);
  if(Q_NBElmt(*Q)==1){
    Q_Head(*Q) = 0;
    Q_Tail(*Q) = 0;
  }else {
    Q_Head(*Q)++;
    if(Q_Head(*Q)>Q_MaxEl(*Q)){
      Q_Head(*Q)=1;
    }
  }
}
