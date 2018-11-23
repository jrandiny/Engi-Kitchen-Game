/* MODUL TABEL ORDER */
/* Kelompok  : UAS
   Nama file : arrOrder.c
   Deskripsi : ADT untuk tipe Array order */

#include "arrOrder.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void AO_CreateEmpty (ArrOrder * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas AO_IdxMax-AO_IdxMin+1 */
{
  AO_Neff(*T) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int AO_NbElmt (ArrOrder T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
  return AO_Neff(T);
}

/* *** Daya tampung container *** */
int AO_MaxNbEl (ArrOrder T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
  return AO_IdxMax;
}

/* *** Selektor INDEKS *** */
AO_IdxType AO_GetFirstIdx (ArrOrder T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
  return AO_IdxMin;
}

AO_IdxType AO_GetLastIdx (ArrOrder T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
  return (AO_IdxMin + AO_Neff(T) -1);
}

/* ********** Test Indeks yang valid ********** */
boolean AO_IsIdxValid (ArrOrder T, AO_IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
  return ((i >= AO_IdxMin)&&(i <= AO_IdxMax));
}

boolean AO_IsIdxEff (ArrOrder T, AO_IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
  return ((i >= AO_GetFirstIdx(T))&&(i <= AO_GetLastIdx(T)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean AO_IsEmpty (ArrOrder T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
  return (AO_Neff(T) == 0);
}

/* *** Test tabel penuh *** */
boolean AO_IsFull (ArrOrder T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
  return (AO_Neff(T) >= AO_IdxMax);
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
AO_IdxType AO_Search (ArrOrder T, int X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */
{
  /* KAMUS LOKAL */
  AO_IdxType i;

  /* ALGORITMA */
  if(AO_IsEmpty(T)){
    return IdxUndeff;
  }else{
    i = AO_GetFirstIdx(T);

    while(O_NoMeja(AO_Elmt(T,i))!=X&&(i<AO_GetLastIdx(T))){
      i++;
    }

    if(O_NoMeja(AO_Elmt(T,i))==X){
      return i;
    }else{
      return IdxUndeff;
    }

  }
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AO_AddAsLastEl (ArrOrder * T, AO_ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  AO_Elmt(*T,AO_GetLastIdx(*T)+1) = X;
  AO_Neff(*T)++;
}

void AO_AddEli (ArrOrder * T, AO_ElType X, AO_IdxType i)
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas
   terhadap elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses : Geser elemen ke-i+1 s.d. terakhir */
/*          Isi elemen ke-i dengan X */
{
  /* KAMUS LOKAL */
  AO_IdxType j;

  /* ALGORTIMA */
  for(j=AO_GetLastIdx(*T);j>=i;j--){
    AO_Elmt(*T,j+1) = AO_Elmt(*T,j);
  }

  AO_Elmt(*T,i) = X;
  AO_Neff(*T)++;
}

/* ********** MENGHAPUS ELEMEN ********** */
void AO_DelLastEl (ArrOrder * T, AO_ElType * X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  *X = AO_Elmt(*T,AO_GetLastIdx(*T));
  AO_Neff(*T)--;
}

void AO_DelEli (ArrOrder * T, AO_IdxType i, AO_ElType * X)
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */
{
  /* KAMUS LOKAL */
  AO_IdxType j;

  /* ALGORITMA */
  *X = AO_Elmt(*T,i);

  for(j=i+1;j<=AO_GetLastIdx(*T);j++){
    AO_Elmt(*T,j-1)=AO_Elmt(*T,j);
  }

  AO_Neff(*T)--;
}
