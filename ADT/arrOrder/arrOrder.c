/* MODUL TABEL ORDER */
/* Kelompok  : UAS
   Nama file : arrOrder.c
   Topik     : Tubes ALSTRUKDAT
   Tanggal   : 05-11-2018
   Deskripsi : ADT untuk tipe Array statik eksplisit*/
/* Berisi definisi dan semua primitif pemrosesan tabel Order */
/* Penempatan elemen selalu rapat kiri */
/* Versi I : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori tabel statik */

#include "arrOrder.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void AO_CreateEmpty (ArrOrder * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
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
  return IdxMax;
}

/* *** Selektor INDEKS *** */
AO_IdxType AO_GetFirstIdx (ArrOrder T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
  return IdxMin;
}

AO_IdxType AO_GetLastIdx (ArrOrder T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
  return (IdxMin + AO_Neff(T) -1);
}

/* ********** Test Indeks yang valid ********** */
boolean AO_IsIdxValid (ArrOrder T, AO_IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
  return ((i >= IdxMin)&&(i <= IdxMax));
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
  return (AO_Neff(T) >= IdxMax);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void AO_BacaIsi (ArrOrder * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
  // /* KAMUS LOKAL */
  // int N;
  // int i;
  // AO_ElType isi;

  // /* ALGORITMA */
  // N = -99;
  // while(!(AO_IsIdxValid(*T,N)||(N==0))){
  //   scanf("%d",&N);
  // }

  // /* N>=0 dan IsIdxValid(N)*/
  // AO_CreateEmpty(T);
  // AO_Neff(*T) = N;

  // for(i = IdxMin;i<=N;i++){
  //   scanf("%d",&isi);
  //   AO_Elmt(*T,i) = isi;
  // }
}

void AO_TulisIsi (ArrOrder T)
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/*      Jika T kosong : Hanya menulis "Tabel kosong" */
/* Contoh: Jika isi Tabel: [1, 20, 30, 50]
   Maka tercetak di layar:
   [1]1
   [2]20
   [3]30
   [4]50
*/
{
  // /* KAMUS LOKAL */
  // AO_IdxType i;

  // /* ALGORITMA */
  // if(AO_IsEmpty(T)){
  //   printf("Tabel kosong\n");
  // }else{
  //   for(i=AO_GetFirstIdx(T);i<=AO_GetLastIdx(T);i++){
  //     printf("[%d]%d\n",i,AO_Elmt(T,i));
  //   }
  // }

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
