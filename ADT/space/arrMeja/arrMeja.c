/* Kelompok  : UAS
   Nama file : arrMeja.c
   Topik     : Engi's Kitchen Game
   Tanggal   : 1 November 2018
   Deskripsi : ADT untuk tipe array Meja*/
/* Berisi definisi dan semua primitif pemrosesan tabel meja */
/* Idx awal tidak di idxmin */
/* Versi I : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori tabel statik */

#include "arrMeja.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void AM_CreateEmpty (ArrMeja * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas AM_AM_IdxMax-AM_AM_IdxMin+1 */
{
  //KAMUS
  Meja tmp;
  Point pos;
  //ALGORITMA
  AM_Neff(*T) = 0;
  P_CreatePoint(&pos);
  tmp = AM_CreateMeja(0,pos,0);
  for (int i = AM_IdxMin; i<=AM_IdxMax;i++){
    AM_Elmt(*T,i) = tmp;
  }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int AM_NbElmt (ArrMeja T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
  return AM_Neff(T);
}
/* *** Daya tampung container *** */
int AM_MaxNbEl (ArrMeja T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
  return AM_IdxMax;
}
/* *** Selektor INDEKS *** */
IdxType AM_GetFirstIdx (ArrMeja T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
  //KAMUS
  IdxType i;
  //ALGORTIMA
  i = AM_IdxMin;
  while (i<AM_IdxMax && Bangku(AM_Elmt(T,i))==0) {
    i++;
  }
  if (Bangku(AM_Elmt(T,i))!=0) {
    return i;
  } else {
    return IdxUndeff;
  }
}
IdxType AM_GetLastIdx (ArrMeja T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
  return (AM_GetFirstIdx(T) + AM_Neff(T) -1);
}

/* ********** Test Indeks yang valid ********** */
boolean AM_IsIdxValid (ArrMeja T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
  return ((i >= AM_IdxMin)&&(i <= AM_IdxMax));
}
boolean AM_IsIdxEff (ArrMeja T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
  return ((i >= AM_GetFirstIdx(T))&&(i <= AM_GetLastIdx(T)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean AM_IsEmpty (ArrMeja T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
  return (AM_Neff(T) == 0);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void AM_BacaIsi (ArrMeja * T)
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
  /* KAMUS LOKAL */
  int N;
  int i;
  Meja meja;
  Point pos;
  int bangku, status;

  /* ALGORITMA */
  printf("N= ");
  N = -99;
  while(!(AM_IsIdxValid(*T,N)||(N==0))){
    scanf("%d",&N);
  }

  /* N>=0 dan IsIdxValid(N)*/
  AM_CreateEmpty(T);
  AM_Neff(*T) = N;

  P_CreatePoint(&pos);

  for(i = AM_IdxMin;i<=N;i++){
    printf("JumlahBangku[%d]: ",i); scanf("%d",&bangku);
    printf("PosisiXY[%d]: ",i); scanf("%d %d",&P_Baris(pos),&P_Kolom(pos));
    printf("Status[%d]: ",i); scanf("%d",&status);
    meja = AM_CreateMeja(bangku,pos,status);
    AM_Elmt(*T,i) = meja;
  }
}
void AM_TulisIsi (ArrMeja T)
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
  /* KAMUS LOKAL */
  IdxType i;
  int x,y;
  /* ALGORITMA */
  if(AM_IsEmpty(T)){
    printf("Tabel kosong\n");
  }else{
    for(i=AM_GetFirstIdx(T);i<=AM_GetLastIdx(T);i++){
      P_GetXY(Meja_Posisi(AM_Elmt(T,i)),&x,&y);
      printf("[%d] Bangku: %d\n",i,Bangku(AM_Elmt(T,i)));
      printf("     Pos: (%d,%d)\n",x,y);
      printf("     Status: %d\n",Status(AM_Elmt(T,i)));
    }
  }

}

/* ********** OPERASI LAIN ********** */
void AM_CopyTab (ArrMeja Tin, ArrMeja * Tout)
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
{
  /* KAMUS LOKAL */
  IdxType i;

  /* ALGORTIMA */
  AM_CreateEmpty(Tout);

  for(i=AM_GetFirstIdx(Tin);i<=AM_GetLastIdx(Tin);i++){
    AM_Elmt(*Tout,i) = AM_Elmt(Tin,i);
  }

  AM_Neff(*Tout) = AM_Neff(Tin);
}
Meja AM_CreateMeja(int bangku,Point pos,int status)
/*
	fungsi menhasilkan meja yang sudah di set berdasarkan input
*/
{
  //KAMUS
  Meja tmp;
  //ALGORITMA
  Bangku(tmp) = bangku;
  Meja_Posisi(tmp) = pos;
  Status(tmp) = status;
  return tmp;
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AM_AddAsLastEl (ArrMeja * T, Meja X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  AM_Elmt(*T,AM_GetLastIdx(*T)+1) = X;
  AM_Neff(*T)++;
}
void AM_AddEli (ArrMeja * T, Meja X, IdxType i)
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas
   terhadap elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses : Geser elemen ke-i+1 s.d. terakhir */
/*          Isi elemen ke-i dengan X */
{
  /* KAMUS LOKAL */
  IdxType j;

  /* ALGORTIMA */
  for(j=AM_GetLastIdx(*T);j>=i;j--){
    AM_Elmt(*T,j+1) = AM_Elmt(*T,j);
  }

  AM_Elmt(*T,i) = X;
  AM_Neff(*T)++;
}

/* ********** MENGHAPUS ELEMEN ********** */
void AM_DelLastEl (ArrMeja * T, Meja * X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
  /* KAMUS LOKAL */
  Point p;
  /* ALGORITMA */
  *X = AM_Elmt(*T,AM_GetLastIdx(*T));
  P_CreatePoint(&p);
  AM_Elmt(*T,AM_GetLastIdx(*T)) = AM_CreateMeja(0,p,0);
  AM_Neff(*T)--;
}
void AM_DelEli (ArrMeja * T, IdxType i, Meja * X)
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */
{
  /* KAMUS LOKAL */
  IdxType j;
  Point p;
  /* ALGORITMA */
  *X = AM_Elmt(*T,i);

  for(j=i+1;j<=AM_GetLastIdx(*T);j++){
    AM_Elmt(*T,j-1)=AM_Elmt(*T,j);
  }
  P_CreatePoint(&p);
  AM_Elmt(*T,AM_GetLastIdx(*T)) = AM_CreateMeja(0,p,0);
  AM_Neff(*T)--;
}
