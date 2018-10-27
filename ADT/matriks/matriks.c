/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */
/* Kelompok  : UAS
   Nama file : matriks.c
   Topik     : Engi's Kitchen Game
   Tanggal   : 27-10-2018
   Deskripsi : ADT untuk tipe MATRIKS*/

#include "matriks.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void M_MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  M_NBrsEff(*M) = NB;
  M_NKolEff(*M) = NK;
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean M_IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
  return (((i>=BrsMin)&&(i<=BrsMax))&&((j>=KolMin)&&(j<=KolMax)));
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks M_GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
  return BrsMin;
}
indeks M_GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
  return KolMin;
}
indeks M_GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
  return BrsMin + M_NBrsEff(M) -1;
}
indeks M_GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
  return KolMin + M_NKolEff(M) -1;
}
boolean M_IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
  return ((i>=M_GetFirstIdxBrs(M)&&i<=M_GetLastIdxBrs(M))&&((j>=M_GetFirstIdxKol(M))&&(j<=M_GetLastIdxKol(M))));
}
ElType M_GetElmtDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
  return M_Elmt(M,i,i);
}

/* ********** Assignment  MATRIKS ********** */
void M_CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{
  /* KAMUS LOKAL */
  indeks i,j;

  /* ALGORITMA */
  M_MakeMATRIKS(M_NBrsEff(MIn),M_NKolEff(MIn),MHsl);

  for(i=M_GetFirstIdxBrs(MIn);i<=M_GetLastIdxBrs(MIn);i++){
    for(j=M_GetFirstIdxKol(MIn);j<=M_GetLastIdxKol(MIn);j++){
      M_Elmt(*MHsl,i,j) = M_Elmt(MIn,i,j);
    }
  }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void M_BacaMATRIKS (MATRIKS * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
{
  /* KAMUS LOKAL */
  indeks i,j;
  ElType isi;

  /* ALGORITMA */
  M_MakeMATRIKS(NB,NK,M);

  for(i=M_GetFirstIdxBrs(*M);i<=M_GetLastIdxBrs(*M);i++){
    for(j=M_GetFirstIdxKol(*M);j<=M_GetLastIdxKol(*M);j++){
      scanf("%d",&isi);
      M_Elmt(*M,i,j) = isi;
    }
  }
}
void M_TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
  /* KAMUS LOKAL */
  indeks i,j;

  /* ALGORTIMA */
  for(i=M_GetFirstIdxBrs(M);i<=M_GetLastIdxBrs(M);i++){
    for(j=M_GetFirstIdxKol(M);j<=M_GetLastIdxKol(M);j++){
      if(j==M_GetLastIdxKol(M)){
        if(i==M_GetLastIdxBrs(M)){
          printf("%d",M_Elmt(M,i,j));
        }else{
          printf("%d\n",M_Elmt(M,i,j));
        }

      }else{
        printf("%d ",M_Elmt(M,i,j));
      }


    }

  }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
MATRIKS M_TambahMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */
{
  /* KAMUS LOKAL */
  MATRIKS Mout;
  indeks i,j;

  /* ALGORITMA */
  M_MakeMATRIKS(M_NBrsEff(M1),M_NKolEff(M1),&Mout);

  for(i=M_GetFirstIdxBrs(M1);i<=M_GetLastIdxBrs(M1);i++){
    for(j=M_GetFirstIdxKol(M1);j<=M_GetLastIdxKol(M1);j++){
      M_Elmt(Mout,i,j) = M_Elmt(M1,i,j) + M_Elmt(M2,i,j);
    }
  }

  return Mout;
}

MATRIKS M_KurangMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */
{
  /* KAMUS LOKAL */
  MATRIKS Mout;
  indeks i,j;

  /* ALGORITMA */
  M_MakeMATRIKS(M_NBrsEff(M1),M_NKolEff(M1),&Mout);

  for(i=M_GetFirstIdxBrs(M1);i<=M_GetLastIdxBrs(M1);i++){
    for(j=M_GetFirstIdxKol(M1);j<=M_GetLastIdxKol(M1);j++){
      M_Elmt(Mout,i,j) = M_Elmt(M1,i,j) - M_Elmt(M2,i,j);
    }
  }

  return Mout;
}

MATRIKS M_KaliMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
{
  /* KAMUS LOKAL */
  MATRIKS Mout;
  indeks i,j,p;
  ElType hasil;

  /* ALGORITMA */
  M_MakeMATRIKS(M_NBrsEff(M1),M_NKolEff(M2),&Mout);

  for(i=M_GetFirstIdxBrs(Mout);i<=M_GetLastIdxBrs(Mout);i++){
    for(j=M_GetFirstIdxKol(Mout);j<=M_GetLastIdxKol(Mout);j++){

      hasil =0;
      for(p=M_GetFirstIdxKol(M1);p<=M_GetLastIdxKol(M1);p++){
        hasil += M_Elmt(M1,i,p)*M_Elmt(M2,p,j);
      }
      M_Elmt(Mout,i,j) = hasil;
    }
  }

  return Mout;
}

MATRIKS M_KaliKons (MATRIKS M, ElType X)
/* Mengirim hasil perkalian setiap elemen M dengan X */
{
  /* KAMUS LOKAL */
  MATRIKS Mout;
  indeks i,j;

  /* ALGORITMA */
  M_MakeMATRIKS(M_NBrsEff(M),M_NKolEff(M),&Mout);

  for(i=M_GetFirstIdxBrs(M);i<=M_GetLastIdxBrs(M);i++){
    for(j=M_GetFirstIdxKol(M);j<=M_GetLastIdxKol(M);j++){
      M_Elmt(Mout,i,j) = M_Elmt(M,i,j) * X;
    }
  }

  return Mout;
}

void M_PKaliKons (MATRIKS * M, ElType K)
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
{
  *M = M_KaliKons(*M,K);
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean M_EQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
{
  /* KAMUS LOKAL */
  boolean sama;
  indeks i,j,p,q;

  /* ALGORITMA */
  if(M_EQSize(M1,M2)){
    sama = true;
    i = M_GetFirstIdxBrs(M1);
    j = M_GetFirstIdxKol(M1);

    p = M_GetFirstIdxBrs(M2);
    q = M_GetFirstIdxKol(M2);

    while(sama&&(i<=M_GetLastIdxBrs(M1))){
      while(sama&&(j<=M_GetLastIdxKol(M1))){
        if(M_Elmt(M1,i,j)!=M_Elmt(M2,p,q)){
          sama = false;
        }else{
          i++;
          j++;

          p++;
          q++;
        }
      }

    }

    return sama;
  }else{
    return false;
  }
}

boolean M_NEQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{
  return !M_EQ(M1,M2);
}

boolean M_EQSize (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{
  return (M_NBrsEff(M1)==M_NBrsEff(M2))&&(M_NKolEff(M1)==M_NKolEff(M2));
}

/* ********** Operasi lain ********** */
int M_NBElmt (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
  return M_NBrsEff(M)*M_NKolEff(M);
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean M_IsBujurSangkar (MATRIKS M)
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
{
  return (M_NBrsEff(M)==M_NKolEff(M));
}

boolean M_IsSimetri (MATRIKS M)
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M)
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
{
  /* KAMUS LOKAL */
  indeks i,j;
  boolean simetris;

  /* ALGORITMA */
  if(M_IsBujurSangkar(M)){

    i = M_GetFirstIdxBrs(M);
    j = M_GetFirstIdxKol(M);
    simetris = true;

    while(simetris&&(i<=M_GetLastIdxBrs(M))){
      while(simetris&&(j<=M_GetLastIdxKol(M))){
        if(M_Elmt(M,i,j)!=M_Elmt(M,j,i)){
          simetris = false;
        }else{
          j++;
        }
      }

      if(simetris){
        i++;
      }

    }

    return simetris;
  }else{
    return false;
  }
}
boolean M_IsSatuan (MATRIKS M)
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
{
  /* KAMUS LOKAL */
  indeks i,j;
  boolean satuan;

  /* ALGORTIMA */
  if(M_IsBujurSangkar(M)){
    i = M_GetFirstIdxBrs(M);
    j = M_GetFirstIdxKol(M);

    satuan = true;

    while(satuan&&(i<=M_GetLastIdxBrs(M))){
      while(satuan&&(j<=M_GetLastIdxKol(M))){
        if((i==j)&&(M_Elmt(M,i,j)!=1)){
          satuan = false;
        }else if((i!=j)&&(M_Elmt(M,i,j)!=0)){
          satuan = false;
        }else{
          j++;
        }
      }

      if(satuan){
        i++;
      }

    }

    return satuan;
  }else{
    return false;
  }

}
boolean M_IsSparse (MATRIKS M)
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi:
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
{
  /* KAMUS LOKAL */
  indeks i,j;
  int jumlahMaks;
  int jumlahIsi;

  /* ALGORITMA */
  i = M_GetFirstIdxBrs(M);
  j = M_GetFirstIdxKol(M);

  jumlahMaks = (5*M_NBElmt(M))/100;
  jumlahIsi = 0;

  while((jumlahIsi<=jumlahMaks)&&(i<=M_GetLastIdxBrs(M))){
    while((jumlahIsi<=jumlahMaks)&&(j<=M_GetLastIdxKol(M))){
      if(M_Elmt(M,i,j)!=0){
        jumlahIsi++;
      }
      j++;
    }
    i++;
    j=M_GetFirstIdxKol(M);
  }

  return (jumlahIsi<=jumlahMaks);

}
MATRIKS M_Inverse1 (MATRIKS M)
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{
  return M_KaliKons(M,-1);
}

float M_Determinan (MATRIKS M)
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
{
  /* KAMUS LOKAL */
  indeks i,j,k;
  indeks mbar,mkol;
  float det;
  MATRIKS Mminor;

  /* ALGORITMA */
  if(M_NBElmt(M)==4){
    i = M_GetFirstIdxBrs(M);
    j = M_GetFirstIdxKol(M);

    return ((M_Elmt(M,i,j)*M_Elmt(M,i+1,j+1))-(M_Elmt(M,i,j+1)*M_Elmt(M,i+1,j)));
  }else{
    det = 0;
    for(i=M_GetFirstIdxBrs(M);i<=M_GetLastIdxBrs(M);i++){
      M_MakeMATRIKS(M_NBrsEff(M)-1,M_NKolEff(M)-1,&Mminor);
      mbar = M_GetFirstIdxBrs(Mminor);
      mkol = M_GetFirstIdxKol(Mminor);

      for(j=M_GetFirstIdxBrs(M);j<=M_GetLastIdxBrs(M);j++){
        if(j!=i){
          for(k=M_GetFirstIdxKol(M);k<=M_GetLastIdxKol(M);k++){
            if(k!=1){
              M_Elmt(Mminor,mbar,mkol) = M_Elmt(M,j,k);
              mkol++;
            }

          }
          mbar++;
          mkol= M_GetFirstIdxKol(Mminor);
        }
      }

      det += pow(-1,(1+i))*M_Elmt(M,i,1)*M_Determinan(Mminor);
    }


    return det;
  }
}
void M_PInverse1 (MATRIKS * M)
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
  *M = M_Inverse1(*M);
}
void M_Transpose (MATRIKS * M)
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
{
  /* KAMUS LOKAL */
  MATRIKS Mout;
  indeks i,j;

  /* ALGORITMA */
  M_MakeMATRIKS(M_NKolEff(*M),M_NBrsEff(*M),&Mout);

  for(i=M_GetFirstIdxBrs(*M);i<=M_GetLastIdxBrs(*M);i++){
    for(j=M_GetFirstIdxKol(*M);j<=M_GetLastIdxKol(*M);j++){
      M_Elmt(Mout,j,i) = M_Elmt(*M,i,j);
    }
  }

  *M = Mout;
}
