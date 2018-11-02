/* ********** Definisi TYPE MatTile dengan indeks dan elemen integer ********** */
/* Kelompok  : UAS
   Nama file : MatTile.c
   Topik     : Engi's Kitchen Game
   Tanggal   : 27-10-2018
   Deskripsi : ADT untuk tipe MatTile*/

#include "matTile.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MatTile *** */
void MT_MakeMatriks (int NB, int NK, MatTile * M)
/* Membentuk sebuah MatTile "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori MatTile yang dibuat */
/* F.S. MatTile M sesuai dengan definisi di atas terbentuk */
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  MT_NBrsEff(*M) = NB;
  MT_NKolEff(*M) = NK;
  for (int i = MT_GetFirstIdxBrs(*M);i<=MT_GetLastIdxBrs(*M);i++) {
    for (int j = MT_GetFirstIdxKol(*M);j<=MT_GetLastIdxKol(*M);j++) {
      MT_Elmt(*M,i,j) = MT_CreateTile(' ',ValUndeff);
    }
  }
}

/* *** Selektor "DUNIA MatTile" *** */
boolean MT_IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk MatTile apa pun */
{
  return (((i>=BrsMin)&&(i<=BrsMax))&&((j>=KolMin)&&(j<=KolMax)));
}

/* *** Selektor: Untuk sebuah MatTile M yang terdefinisi: *** */
indeks MT_GetFirstIdxBrs (MatTile M)
/* Mengirimkan indeks baris terkecil M */
{
  return BrsMin;
}
indeks MT_GetFirstIdxKol (MatTile M)
/* Mengirimkan indeks kolom terkecil M */
{
  return KolMin;
}
indeks MT_GetLastIdxBrs (MatTile M)
/* Mengirimkan indeks baris terbesar M */
{
  return BrsMin + MT_NBrsEff(M) -1;
}
indeks MT_GetLastIdxKol (MatTile M)
/* Mengirimkan indeks kolom terbesar M */
{
  return KolMin + MT_NKolEff(M) -1;
}
boolean MT_IsIdxEff (MatTile M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
  return ((i>=MT_GetFirstIdxBrs(M)&&i<=MT_GetLastIdxBrs(M))&&((j>=MT_GetFirstIdxKol(M))&&(j<=MT_GetLastIdxKol(M))));
}

/* ********** Assignment  MatTile ********** */
void MT_CopyMatriks (MatTile MIn, MatTile * MHsl)
/* Melakukan assignment MHsl  MIn */
{
  /* KAMUS LOKAL */
  indeks i,j;

  /* ALGORITMA */
  MT_MakeMatriks(MT_NBrsEff(MIn),MT_NKolEff(MIn),MHsl);

  for(i=MT_GetFirstIdxBrs(MIn);i<=MT_GetLastIdxBrs(MIn);i++){
    for(j=MT_GetFirstIdxKol(MIn);j<=MT_GetLastIdxKol(MIn);j++){
      MT_Elmt(*MHsl,i,j) = MT_Elmt(MIn,i,j);
    }
  }
}
Tile MT_CreateTile(char karakter,int value)
/* fungsi menghasilkan tile yang sudah di set berdasarkan input */
{
  //KAMUS
  Tile tmp;
  //ALGORITMA
  Karakter(tmp) = karakter;
  Value(tmp) = value;
  return tmp;
}

/* ********** KELOMPOK BACA/TULIS ********** */
void MT_BacaMatriks (MatTile * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMatTile(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi MatTile :
1 2 3
4 5 6
8 9 10
*/
{
  //KAMUS
  indeks i,j;
  char kar;
  int val;
  Tile elmt;
  //ALGORITMA
  MT_MakeMatriks(NB,NK,M);
  for(i=MT_GetFirstIdxBrs(*M);i<=MT_GetLastIdxBrs(*M);i++){
    for(j=MT_GetFirstIdxKol(*M);j<=MT_GetLastIdxKol(*M);j++){
      printf("Karakter[%d][%d]: ",i,j);
      scanf("\n%c",&kar);
      printf("Value[%d][%d]: ",i,j);
      scanf("%d",&val);
      MT_Elmt(*M,i,j) = MT_CreateTile(kar,val);
    }
  }
}
void MT_TulisMatriks (MatTile M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis MatTile 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
  //KAMUS
  indeks i,j;
  //ALGORITMA
  printf("Karakter:\n");
  for(i=MT_GetFirstIdxBrs(M);i<=MT_GetLastIdxBrs(M);i++){
    for(j=MT_GetFirstIdxKol(M);j<=MT_GetLastIdxKol(M);j++){
      printf("%c",Karakter(MT_Elmt(M,i,j)));
      if (j<MT_GetLastIdxKol(M)) printf(" ");
    }
    printf("\n");
  }
  printf("Value:\n");
  for(i=MT_GetFirstIdxBrs(M);i<=MT_GetLastIdxBrs(M);i++){
    for(j=MT_GetFirstIdxKol(M);j<=MT_GetLastIdxKol(M);j++){
      printf("%d",Value(MT_Elmt(M,i,j)));
      if (j<MT_GetLastIdxKol(M)) printf(" ");
    }
    printf("\n");
  }
}

/* ********** Operasi lain ********** */
int MT_NBElmt (MatTile M)
/* Mengirimkan banyaknya elemen M */
{
  return MT_NBrsEff(M)*MT_NKolEff(M);
}
