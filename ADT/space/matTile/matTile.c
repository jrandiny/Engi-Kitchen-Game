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
Tile MT_SetTile(char karakter,int value)
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
// void MT_BacaMatTile (MatTile * M, int NB, int NK)
// /* I.S. IsIdxValid(NB,NK) */
// /* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
// /* Proses: Melakukan MakeMatTile(M,NB,NK) dan mengisi nilai efektifnya */
// /* Selanjutnya membaca nilai elemen per baris dan kolom */
// /* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi MatTile :
// 1 2 3
// 4 5 6
// 8 9 10
// */
// {
//   /* KAMUS LOKAL */
//   indeks i,j;
//   Tile isi;
//
//   /* ALGORITMA */
//   MT_MakeMatTile(NB,NK,M);
//
//   for(i=MT_GetFirstIdxBrs(*M);i<=MT_GetLastIdxBrs(*M);i++){
//     for(j=MT_GetFirstIdxKol(*M);j<=MT_GetLastIdxKol(*M);j++){
//       scanf("%c",&isi);
//       MT_Elmt(*M,i,j) = isi;
//     }
//   }
// }
// void MT_TulisMatTile (MatTile M)
// /* I.S. M terdefinisi */
// /* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
//    dipisahkan sebuah spasi */
// /* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
// /* Contoh: menulis MatTile 3x3 (ingat di akhir tiap baris, tidak ada spasi)
// 1 2 3
// 4 5 6
// 8 9 10
// */
// {
//   /* KAMUS LOKAL */
//   indeks i,j;
//
//   /* ALGORTIMA */
//   for(i=MT_GetFirstIdxBrs(M);i<=MT_GetLastIdxBrs(M);i++){
//     for(j=MT_GetFirstIdxKol(M);j<=MT_GetLastIdxKol(M);j++){
//       if(j==MT_GetLastIdxKol(M)){
//         if(i==MT_GetLastIdxBrs(M)){
//           printf("%c",MT_Elmt(M,i,j));
//         }else{
//           printf("%c\n",MT_Elmt(M,i,j));
//         }
//
//       }else{
//         printf("%c ",MT_Elmt(M,i,j));
//       }
//
//
//     }
//
//   }
// }

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MatTile ********** */
// boolean MT_EQ (MatTile M1, MatTile M2)
// /* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
// /* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
// /* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
//    dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
// {
//   /* KAMUS LOKAL */
//   boolean sama;
//   indeks i,j,p,q;
//
//   /* ALGORITMA */
//   if(MT_EQSize(M1,M2)){
//     sama = true;
//     i = MT_GetFirstIdxBrs(M1);
//     j = MT_GetFirstIdxKol(M1);
//
//     p = MT_GetFirstIdxBrs(M2);
//     q = MT_GetFirstIdxKol(M2);
//
//     while(sama&&(i<=MT_GetLastIdxBrs(M1))){
//       while(sama&&(j<=MT_GetLastIdxKol(M1))){
//         if(MT_Elmt(M1,i,j)!=MT_Elmt(M2,p,q)){
//           sama = false;
//         }else{
//           i++;
//           j++;
//
//           p++;
//           q++;
//         }
//       }
//
//     }
//
//     return sama;
//   }else{
//     return false;
//   }
// }

// boolean MT_NEQ (MatTile M1, MatTile M2)
// /* Mengirimkan true jika M1 tidak sama dengan M2 */
// {
//   return !MT_EQ(M1,M2);
// }

/* ********** Operasi lain ********** */
int MT_NBElmt (MatTile M)
/* Mengirimkan banyaknya elemen M */
{
  return MT_NBrsEff(M)*MT_NKolEff(M);
}
