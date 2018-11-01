/* MODUL TABEL INTEGER */
/* Kelompok  : UAS
   Nama file : array.c
   Topik     : Modul Prapraktikum 02
   Tanggal   : 04-09-2018
   Deskripsi : ADT untuk tipe Array statik eksplisit*/
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi I : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori tabel statik */

#include "array.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void A_CreateEmpty (TabInt * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
  A_Neff(*T) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int A_NbElmt (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
  return A_Neff(T);
}
/* *** Daya tampung container *** */
int A_MaxNbEl (TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
  return IdxMax;
}
/* *** Selektor INDEKS *** */
IdxType A_GetFirstIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
  return IdxMin;
}
IdxType A_GetLastIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
  return (IdxMin + A_Neff(T) -1);
}

/* ********** Test Indeks yang valid ********** */
boolean A_IsIdxValid (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
  return ((i >= IdxMin)&&(i <= IdxMax));
}
boolean A_IsIdxEff (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
  return ((i >= A_GetFirstIdx(T))&&(i <= A_GetLastIdx(T)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean A_IsEmpty (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
  return (A_Neff(T) == 0);
}
/* *** Test tabel penuh *** */
boolean A_IsFull (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
  return (A_Neff(T) >= IdxMax);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void A_BacaIsi (TabInt * T)
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
  ElType isi;

  /* ALGORITMA */
  N = -99;
  while(!(A_IsIdxValid(*T,N)||(N==0))){
    scanf("%d",&N);
  }

  /* N>=0 dan IsIdxValid(N)*/
  A_CreateEmpty(T);
  A_Neff(*T) = N;

  for(i = IdxMin;i<=N;i++){
    scanf("%d",&isi);
    A_Elmt(*T,i) = isi;
  }
}
void A_BacaIsiTab (TabInt * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca elemen T sampai dimasukkan nilai -9999 */
/* Dibaca elemen satu per satu dan disimpan mulai dari IdxMin */
/* Pembacaan dihentikan jika pengguna memasukkan nilai -9999 */
/* Jika dari pertama dimasukkan nilai -9999 maka terbentuk T kosong */
{
  /* KAMUS LOKAL */
  ElType input;
  IdxType i;

  /* ALGORITMA */
  A_CreateEmpty(T);
  scanf("%d",&input);
  i = IdxMin;

  while((input!=-9999)&&(i<=IdxMax)){
    A_Elmt(*T,i) = input;
    if(i!=IdxMax){
      scanf("%d",&input);
    }
    i++;
  }

  A_Neff(*T) = i-1;
}
void A_TulisIsi (TabInt T)
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

  /* ALGORITMA */
  if(A_IsEmpty(T)){
    printf("Tabel kosong\n");
  }else{
    for(i=A_GetFirstIdx(T);i<=A_GetLastIdx(T);i++){
      printf("[%d]%d\n",i,A_Elmt(T,i));
    }
  }

}
void A_TulisIsiTab (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
  /* KAMUS LOKAL */
  IdxType i;

  /* ALGORITMA */
  printf("[");

  if(!A_IsEmpty(T)){
    for(i=A_GetFirstIdx(T);i<=(A_GetLastIdx(T)-1);i++){
      printf("%d,",A_Elmt(T,i));
    }
    printf("%d",A_Elmt(T,A_GetLastIdx(T)));
  }



  printf("]");

}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt A_PlusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
{
  /* KAMUS LOKAL */
  TabInt TOut;
  IdxType i,j,k;

  /* ALGORTIMA */
  A_CreateEmpty(&TOut);

  i = A_GetFirstIdx(T1);
  j = A_GetFirstIdx(T2);
  k = IdxMin;

  while(i<=A_GetLastIdx(T1)){
    A_Elmt(TOut,k) = A_Elmt(T1,i) + A_Elmt(T2,j);
    k++;
    i++;
    j++;
  }

  A_Neff(TOut) = A_Neff(T1);

  return TOut;
}
TabInt A_MinusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{
  /* KAMUS LOKAL */
  TabInt TOut;
  IdxType i,j,k;

  /* ALGORTIMA */
  A_CreateEmpty(&TOut);

  i = A_GetFirstIdx(T1);
  j = A_GetFirstIdx(T2);
  k = IdxMin;

  while(i<=A_GetLastIdx(T1)){
    A_Elmt(TOut,k) = A_Elmt(T1,i) - A_Elmt(T2,j);
    k++;
    i++;
    j++;
  }

  A_Neff(TOut) = A_Neff(T1);

  return TOut;
}
TabInt A_KaliTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 * T2 dengan definisi setiap elemen dengan indeks yang sama dikalikan */
{
  /* KAMUS LOKAL */
  TabInt TOut;
  IdxType i,j,k;

  /* ALGORTIMA */
  A_CreateEmpty(&TOut);

  i = A_GetFirstIdx(T1);
  j = A_GetFirstIdx(T2);
  k = IdxMin;

  while(i<=A_GetLastIdx(T1)){
    A_Elmt(TOut,k) = A_Elmt(T1,i) * A_Elmt(T2,j);
    k++;
    i++;
    j++;
  }

  A_Neff(TOut) = A_Neff(T1);

  return TOut;
}
TabInt A_KaliKons (TabInt Tin, ElType c)
/* Prekondisi : Tin tidak kosong */
/* Mengirimkan tabel dengan setiap elemen Tin dikalikan c */
{
  /* KAMUS LOKAL */
  TabInt TOut;
  IdxType i,j;

  /* ALGORTIMA */
  A_CreateEmpty(&TOut);

  i = A_GetFirstIdx(Tin);
  j = IdxMin;

  while(i<=A_GetLastIdx(Tin)){
    A_Elmt(TOut,j) = A_Elmt(Tin,i) * c;
    i++;
    j++;
  }

  A_Neff(TOut) = A_Neff(Tin);

  return TOut;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean A_IsEQ (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
{
  /* KAMUS LOKAL */
  boolean sama;
  IdxType i,j;

  /* ALGORITMA */
  if(A_Neff(T1)==A_Neff(T2)){
    sama = true;
    i = A_GetFirstIdx(T1);
    j = A_GetFirstIdx(T2);

    while( sama && (i<=A_GetLastIdx(T1))){
      if(A_Elmt(T1,i)!=A_Elmt(T2,j)){
        sama = false;
      }
      i++;
      j++;
    }

    return sama;
  }else{
    return false;
  }
}
boolean A_IsLess (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 < T2, */
/* yaitu : sesuai dg analogi 'Ali' < Badu'; maka [0, 1] < [2, 3] */
{
  /* KAMUS LOKAL */
  boolean iLess;
  IdxType i,j;

  /* ALGORITMA */
  if(A_Neff(T1)>A_Neff(T2)){
    return false;
  }else if(A_Neff(T1)<A_Neff(T2)){
    return true;
  }else if(A_Neff(T1)==A_Neff(T2)&&(!A_IsEQ(T1,T2))){
    iLess = true;
    i = A_GetFirstIdx(T1);
    j = A_GetFirstIdx(T2);

    while((A_Elmt(T1,i)>=A_Elmt(T2,j))&&iLess && (i<=A_GetLastIdx(T1))){
      if(A_Elmt(T1,i)>A_Elmt(T2,j)){
        iLess = false;
      }
      i++;
      j++;
    }

    return iLess;
  }else{
    return false;
  }

}
/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType A_Search1 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */
{
  /* KAMUS LOKAL */
  IdxType i;

  /* ALGORITMA */
  if(A_IsEmpty(T)){
    return IdxUndef;
  }else{
    i = A_GetFirstIdx(T);

    while((A_Elmt(T,i)!=X)&&(i<A_GetLastIdx(T))){
      i++;
    }

    if(A_Elmt(T,i)==X){
      return i;
    }else{
      return IdxUndef;
    }

  }
}
IdxType A_Search2 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */
{
  /* KAMUS LOKAL */
  IdxType i;
  boolean Found;

  /* ALGORITMA */
  i = A_GetFirstIdx(T);
  Found = false;

  while(!Found && (i<=A_GetLastIdx(T))){
    if(A_Elmt(T,i)==X){
      Found = true;
    }else{
      i++;
    }
  }

  if(Found){
    return i;
  }else{
    return IdxUndef;
  }
}
boolean A_SearchB (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Memakai Skema search DENGAN boolean */
{
  /* KAMUS LOKAL */
  IdxType i;
  boolean Found;

  /* ALGORITMA */
  i = A_GetFirstIdx(T);
  Found = false;

  while(!Found && (i<=A_GetLastIdx(T))){
    if(A_Elmt(T,i)==X){
      Found = true;
    }else{
      i++;
    }
  }

  return Found;
}
boolean A_SearchSentinel (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* dengan metoda sequential search dengan sentinel */
/* Untuk sentinel, manfaatkan indeks ke-0 dalam definisi array dalam Bahasa C
   yang tidak dipakai dalam definisi tabel */
{
  /* KAMUS LOKAL */
  IdxType i;

  /* ALGORITMA */
  A_Elmt(T,0) = X;
  i = A_GetLastIdx(T);

  while(A_Elmt(T,i)!=X){
    i--;
  }

  if(i == 0){
    return false;
  }else{
    return true;
  }
}

/* ********** NILAI EKSTREM ********** */
ElType A_ValMax (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
{
  /* KAMUS LOKAL */
  ElType max;
  IdxType i;

  /* ALGORITMA */
  max = A_Elmt(T,A_GetFirstIdx(T));

  for(i=A_GetFirstIdx(T)+1;i<=A_GetLastIdx(T);i++){
    if(A_Elmt(T,i)>max){
      max = A_Elmt(T,i);
    }
  }

  return max;
}
ElType A_ValMin (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
{
  /* KAMUS LOKAL */
  ElType min;
  IdxType i;

  /* ALGORITMA */
  min = A_Elmt(T,A_GetFirstIdx(T));

  for(i=A_GetFirstIdx(T)+1;i<=A_GetLastIdx(T);i++){
    if(A_Elmt(T,i)<min){
      min = A_Elmt(T,i);
    }
  }

  return min;
}
/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
IdxType A_IdxMaxTab (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai maksimum pada tabel */
{
  /* KAMUS LOKAL */
  IdxType iMax;
  IdxType i;

  /* ALGORITMA */
  iMax = A_GetFirstIdx(T);

  for(i=A_GetFirstIdx(T)+1;i<=A_GetLastIdx(T);i++){
    if(A_Elmt(T,i)>A_Elmt(T,iMax)){
      iMax = i;
    }
  }

  return iMax;
}
IdxType A_IdxMinTab (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai minimum pada tabel */
{
  /* KAMUS LOKAL */
  IdxType iMin;
  IdxType i;

  /* ALGORITMA */
  iMin = A_GetFirstIdx(T);

  for(i=A_GetFirstIdx(T)+1;i<=A_GetLastIdx(T);i++){
    if(A_Elmt(T,i)<A_Elmt(T,iMin)){
      iMin = i;
    }
  }

  return iMin;
}
/* ********** OPERASI LAIN ********** */
void A_CopyTab (TabInt Tin, TabInt * Tout)
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
{
  /* KAMUS LOKAL */
  IdxType i;

  /* ALGORTIMA */
  A_CreateEmpty(Tout);

  for(i=A_GetFirstIdx(Tin);i<=A_GetLastIdx(Tin);i++){
    A_Elmt(*Tout,i) = A_Elmt(Tin,i);
  }

  A_Neff(*Tout) = A_Neff(Tin);
}
TabInt A_InverseTab (TabInt T)
/* Menghasilkan tabel dengan urutan tempat yang terbalik, yaitu : */
/* elemen pertama menjadi terakhir, */
/* elemen kedua menjadi elemen sebelum terakhir, dst.. */
/* Tabel kosong menghasilkan tabel kosong */
{
  /* KAMUS LOKAL */
  IdxType i;
  TabInt Tinv;

  /* ALGORITMA */
  if(!A_IsEmpty(T)){
    A_CreateEmpty(&Tinv);

    for(i=A_GetFirstIdx(T);i<=A_GetLastIdx(T);i++){
      A_Elmt(Tinv,A_GetLastIdx(T)-i+1) = A_Elmt(T,i);
    }
    A_Neff(Tinv) = A_Neff(T);

    return Tinv;
  }else{
    return T;
  }

}
boolean A_IsSimetris (TabInt T)
/* Menghasilkan true jika tabel simetrik */
/* Tabel disebut simetrik jika: */
/*      elemen pertama = elemen terakhir, */
/*      elemen kedua = elemen sebelum terakhir, dan seterusnya */
/* Tabel kosong adalah tabel simetris */
{
  /* KAMUS LOKAL */
  boolean simetris;
  IdxType i,j;

  /* ALGORITMA */
  simetris = true;
  i = A_GetFirstIdx(T);
  j = A_GetLastIdx(T);

  while(simetris && (i<j)){
    if(A_Elmt(T,i)!=A_Elmt(T,j)){
      simetris = false;
    }
    i++;
    j--;
  }

  return simetris;
}

/* ********** SORTING ********** */
void A_MaxSortDesc (TabInt * T)
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menurun dengan Maximum Sort */
/* Proses : mengurutkan T sehingga elemennya menurun/mengecil */
/*          tanpa menggunakan tabel kerja */
{
  /* KAMUS LOKAL */
  IdxType i,j,max;
  ElType temp;

  /* ALGORITMA */
  if(!A_IsEmpty(*T)&&(A_Neff(*T)>1)){
    for(i=A_GetFirstIdx(*T);i<=A_GetLastIdx(*T)-1;i++){
      max = i;
      for(j=i+1;j<=A_GetLastIdx(*T);j++){
        if(A_Elmt(*T,j)>A_Elmt(*T,max)){
          max = j;
        }
      }

      temp = A_Elmt(*T,max);
      A_Elmt(*T,max) = A_Elmt(*T,i);
      A_Elmt(*T,i) =temp;
    }
  }
}
void A_InsSortAsc (TabInt * T)
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menaik dengan Insertion Sort */
/* Proses : mengurutkan T sehingga elemennya menaik/membesar */
/*          tanpa menggunakan tabel kerja */
{
  /* KAMUS LOKAL */
  IdxType i,j;
  ElType temp;

  /* ALGORITMA */
  if(!A_IsEmpty(*T)&&(A_Neff(*T)>1)){
    for(i=A_GetFirstIdx(*T)+1;i<=A_GetLastIdx(*T);i++){
      temp = A_Elmt(*T,i);

      j = i-1;
      while(j>A_GetFirstIdx(*T)&&(A_Elmt(*T,j)>temp)){
        A_Elmt(*T,j+1) = A_Elmt(*T,j);
        j--;
      }

      if(A_Elmt(*T,j)<=temp){
        A_Elmt(*T,j+1) = temp;
      }else{
        A_Elmt(*T,j+1) = A_Elmt(*T,j);
        A_Elmt(*T,j) = temp;
      }


    }
  }
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void A_AddAsLastEl (TabInt * T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  A_Elmt(*T,A_GetLastIdx(*T)+1) = X;
  A_Neff(*T)++;
}
void A_AddEli (TabInt * T, ElType X, IdxType i)
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
  for(j=A_GetLastIdx(*T);j>=i;j--){
    A_Elmt(*T,j+1) = A_Elmt(*T,j);
  }

  A_Elmt(*T,i) = X;
  A_Neff(*T)++;
}

/* ********** MENGHAPUS ELEMEN ********** */
void A_DelLastEl (TabInt * T, ElType * X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  *X = A_Elmt(*T,A_GetLastIdx(*T));
  A_Neff(*T)--;
}
void A_DelEli (TabInt * T, IdxType i, ElType * X)
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

  /* ALGORITMA */
  *X = A_Elmt(*T,i);

  for(j=i+1;j<=A_GetLastIdx(*T);j++){
    A_Elmt(*T,j-1)=A_Elmt(*T,j);
  }

  A_Neff(*T)--;
}

/* ********** TABEL DGN ELEMEN UNIK (SETIAP ELEMEN HANYA MUNCUL 1 KALI) ********** */
void A_AddElUnik (TabInt * T, ElType X)
/* Menambahkan X sebagai elemen terakhir tabel, pada tabel dengan elemen unik */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/*      dan semua elemennya bernilai unik, tidak terurut */
/* F.S. Jika tabel belum penuh, menambahkan X sbg elemen terakhir T,
        jika belum ada elemen yang bernilai X.
		Jika sudah ada elemen tabel yang bernilai X maka I.S. = F.S.
		dan dituliskan pesan "nilai sudah ada" */
/* Proses : Cek keunikan dengan sequential search dengan sentinel */
/*          Kemudian tambahkan elemen jika belum ada */
{
  /* KAMUS LOKAL */
  IdxType i;

  /* ALGORITMA */
  A_Elmt(*T,A_GetLastIdx(*T)+1) = X;
  i = A_GetFirstIdx(*T);

  while(A_Elmt(*T,i)!=X){
    i++;
  }

  if(i == A_GetLastIdx(*T)+1){
    A_Neff(*T)++;
  }else{
    printf("nilai sudah ada\n");
  }
}

/* ********** TABEL DGN ELEMEN TERURUT MEMBESAR ********** */
IdxType A_SearchUrut (TabInt T, ElType X)
/* Prekondisi: Tabel T boleh kosong. Jika tidak kosong, elemen terurut membesar. */
/* Mengirimkan indeks di mana harga X dengan indeks terkecil diketemukan */
/* Mengirimkan IdxUndef jika tidak ada elemen tabel bernilai X */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel kosong */
{
  /* KAMUS LOKAL */
  IdxType i;

  /* ALGORITMA */
  if(A_IsEmpty(T)){
    return IdxUndef;
  }else{
    i = A_GetFirstIdx(T);
    while((A_Elmt(T,i)<X)&&(i<A_GetLastIdx(T))){
      i++;
    }

    if(A_Elmt(T,i)==X){
      return i;
    }else{
      return IdxUndef;
    }
  }

}
ElType A_MaxUrut (TabInt T)
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai maksimum pada tabel */
{
  return A_Elmt(T,A_GetLastIdx(T));
}
ElType A_MinUrut (TabInt T)
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai minimum pada tabel*/
{
  return A_Elmt(T,A_GetFirstIdx(T));
}
void A_MaxMinUrut (TabInt T, ElType * Max, ElType * Min)
/* I.S. Tabel T tidak kosong, elemen terurut membesar */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{
  *Max = A_MaxUrut(T);
  *Min = A_MinUrut(T);
}
void A_Add1Urut (TabInt * T, ElType X)
/* Menambahkan X tanpa mengganggu keterurutan nilai dalam tabel */
/* Nilai dalam tabel tidak harus unik. */
/* I.S. Tabel T boleh kosong, boleh penuh. */
/*      Jika tabel isi, elemennya terurut membesar. */
/* F.S. Jika tabel belum penuh, menambahkan X. */
/*      Jika tabel penuh, maka tabel tetap. */
/* Proses : Search tempat yang tepat sambil geser */
/*          Insert X pada tempat yang tepat tersebut tanpa mengganggu keterurutan */
{
  /* KAMUS LOKAL */
  IdxType i;

  /* ALGORITMA */
  if(!A_IsFull(*T)){
    if(A_IsEmpty(*T)){
      A_Elmt(*T,IdxMin) = X;
      A_Neff(*T)++;
    }else{
      i = A_GetLastIdx(*T)+1;

      while((A_Elmt(*T,i-1)>X)&&(i>A_GetFirstIdx(*T))){
        A_Elmt(*T,i) = A_Elmt(*T,i-1);
        i--;
      }

      A_Elmt(*T,i) = X;
      A_Neff(*T)++;
    }
  }
}
void A_Del1Urut (TabInt * T, ElType X)
/* Menghapus X yang pertama kali (pada indeks terkecil) yang ditemukan */
/* I.S. Tabel tidak kosong */
/* F.S. Jika ada elemen tabel bernilai X , */
/*      maka banyaknya elemen tabel berkurang satu. */
/*      Jika tidak ada yang bernilai X, tabel tetap. */
/*      Setelah penghapusan, elemen tabel tetap kontigu! */
/* Proses : Search indeks ke-i dengan elemen ke-i = X. */
/*          Delete jika ada. */
{
  /* KAMUS LOKAL */
  IdxType i,lokasi;

  /* ALGORITMA */
  lokasi = A_SearchUrut(*T,X);

  if(lokasi != IdxUndef){
    for(i = lokasi+1;i<=A_GetLastIdx(*T);i++){
      A_Elmt(*T,i-1) = A_Elmt(*T,i);
    }
    A_Neff(*T)--;
  }
}
