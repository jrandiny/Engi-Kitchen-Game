/* ********** Definisi TYPE Matriks dengan indeks dan elemen integer ********** */
/* Kelompok  : UAS
   Nama file : matriks.c
   Topik     : Engi's Kitchen Game
   Tanggal   : 27-10-2018
   Deskripsi : ADT untuk tipe Matriks*/

#include "matTile.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matriks *** */
void M_MakeMatriks (int NB, int NK, Matriks * M)
/* Membentuk sebuah Matriks "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  M_NBrsEff(*M) = NB;
  M_NKolEff(*M) = NK;
}

/* *** Selektor "DUNIA Matriks" *** */
boolean M_IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
  return (((i>=BrsMin)&&(i<=BrsMax))&&((j>=KolMin)&&(j<=KolMax)));
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks M_GetFirstIdxBrs (Matriks M)
/* Mengirimkan indeks baris terkecil M */
{
  return BrsMin;
}
indeks M_GetFirstIdxKol (Matriks M)
/* Mengirimkan indeks kolom terkecil M */
{
  return KolMin;
}
indeks M_GetLastIdxBrs (Matriks M)
/* Mengirimkan indeks baris terbesar M */
{
  return BrsMin + M_NBrsEff(M) -1;
}
indeks M_GetLastIdxKol (Matriks M)
/* Mengirimkan indeks kolom terbesar M */
{
  return KolMin + M_NKolEff(M) -1;
}
boolean M_IsIdxEff (Matriks M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
  return ((i>=M_GetFirstIdxBrs(M)&&i<=M_GetLastIdxBrs(M))&&((j>=M_GetFirstIdxKol(M))&&(j<=M_GetLastIdxKol(M))));
}

/* ********** Assignment  Matriks ********** */
void M_CopyMatriks (Matriks MIn, Matriks * MHsl)
/* Melakukan assignment MHsl  MIn */
{
  /* KAMUS LOKAL */
  indeks i,j;

  /* ALGORITMA */
  M_MakeMatriks(M_NBrsEff(MIn),M_NKolEff(MIn),MHsl);

  for(i=M_GetFirstIdxBrs(MIn);i<=M_GetLastIdxBrs(MIn);i++){
    for(j=M_GetFirstIdxKol(MIn);j<=M_GetLastIdxKol(MIn);j++){
      M_Elmt(*MHsl,i,j) = M_Elmt(MIn,i,j);
    }
  }
}
Tile MT_SetTile(char karakter,int value,Kata deskripsi)
/* fungsi menghasilkan tile yang sudah di set berdasarkan input */
{
  //KAMUS
  Tile tmp;
  //ALGORITMA
  Karakter(tmp) = karakter;
  Value(tmp) = value;
  Deskripsi(tmp) = deskripsi;
  return tmp;
}

/* ********** KELOMPOK BACA/TULIS ********** */
// void M_BacaMatriks (Matriks * M, int NB, int NK)
// /* I.S. IsIdxValid(NB,NK) */
// /* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
// /* Proses: Melakukan MakeMatriks(M,NB,NK) dan mengisi nilai efektifnya */
// /* Selanjutnya membaca nilai elemen per baris dan kolom */
// /* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
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
//   M_MakeMatriks(NB,NK,M);
//
//   for(i=M_GetFirstIdxBrs(*M);i<=M_GetLastIdxBrs(*M);i++){
//     for(j=M_GetFirstIdxKol(*M);j<=M_GetLastIdxKol(*M);j++){
//       scanf("%c",&isi);
//       M_Elmt(*M,i,j) = isi;
//     }
//   }
// }
// void M_TulisMatriks (Matriks M)
// /* I.S. M terdefinisi */
// /* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
//    dipisahkan sebuah spasi */
// /* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
// /* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
// 1 2 3
// 4 5 6
// 8 9 10
// */
// {
//   /* KAMUS LOKAL */
//   indeks i,j;
//
//   /* ALGORTIMA */
//   for(i=M_GetFirstIdxBrs(M);i<=M_GetLastIdxBrs(M);i++){
//     for(j=M_GetFirstIdxKol(M);j<=M_GetLastIdxKol(M);j++){
//       if(j==M_GetLastIdxKol(M)){
//         if(i==M_GetLastIdxBrs(M)){
//           printf("%c",M_Elmt(M,i,j));
//         }else{
//           printf("%c\n",M_Elmt(M,i,j));
//         }
//
//       }else{
//         printf("%c ",M_Elmt(M,i,j));
//       }
//
//
//     }
//
//   }
// }

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matriks ********** */
// boolean M_EQ (Matriks M1, Matriks M2)
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
//   if(M_EQSize(M1,M2)){
//     sama = true;
//     i = M_GetFirstIdxBrs(M1);
//     j = M_GetFirstIdxKol(M1);
//
//     p = M_GetFirstIdxBrs(M2);
//     q = M_GetFirstIdxKol(M2);
//
//     while(sama&&(i<=M_GetLastIdxBrs(M1))){
//       while(sama&&(j<=M_GetLastIdxKol(M1))){
//         if(M_Elmt(M1,i,j)!=M_Elmt(M2,p,q)){
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

// boolean M_NEQ (Matriks M1, Matriks M2)
// /* Mengirimkan true jika M1 tidak sama dengan M2 */
// {
//   return !M_EQ(M1,M2);
// }

/* ********** Operasi lain ********** */
int M_NBElmt (Matriks M)
/* Mengirimkan banyaknya elemen M */
{
  return M_NBrsEff(M)*M_NKolEff(M);
}
