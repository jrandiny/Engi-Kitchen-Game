#include "stacktfood.h"

void SF_CreateEmpty (StackFood *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas SF_MaxEl */
/* jadi indeksnya antara 1.. SF_MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */
{
  SF_Top(*S)=Nol;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean SF_IsEmpty (StackFood S)
/* Mengirim true jika StackFood kosong: lihat definisi di atas */
{
  return SF_Top(S)==Nol;
}

boolean SF_IsFull (StackFood S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
  return SF_Top(S)==SF_MaxEl;
}

/* ************ Menambahkan sebuah elemen ke StackFood ************ */
void SF_Push (StackFood * S, SF_infotype X)
/* Menambahkan X sebagai elemen StackFood S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
  SF_Top(*S)++;
  SF_InfoTop(*S)=X;
}

/* ************ Menghapus sebuah elemen StackFood ************ */
void SF_Pop (StackFood * S, SF_infotype* X)
/* Menghapus X dari StackFood S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
  *X=SF_InfoTop(*S);
  SF_Top(*S)--;
}