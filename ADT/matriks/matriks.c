/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */
/* NIM/Nama  : 13517063/Joshua Christo Randiny
   Nama file : array.c
   Topik     : Modul Prapraktikum 02
   Tanggal   : 04-09-2018
   Deskripsi : ADT untuk tipe Matriks statik*/

#include "matriks.h"
#include <math.h>
#include <stdio.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  NBrsEff(*M) = NB;
  NKolEff(*M) = NK;
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
  return (((i>=BrsMin)&&(i<=BrsMax))&&((j>=KolMin)&&(j<=KolMax)));
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
  return BrsMin;
}
indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
  return KolMin;
}
indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
  return BrsMin + NBrsEff(M) -1;
}
indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
  return KolMin + NKolEff(M) -1;
}
boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
  return ((i>=GetFirstIdxBrs(M)&&i<=GetLastIdxBrs(M))&&((j>=GetFirstIdxKol(M))&&(j<=GetLastIdxKol(M))));
}
ElType GetElmtDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
  return Elmt(M,i,i);
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{
  /* KAMUS LOKAL */
  indeks i,j;

  /* ALGORITMA */
  MakeMATRIKS(NBrsEff(MIn),NKolEff(MIn),MHsl);

  for(i=GetFirstIdxBrs(MIn);i<=GetLastIdxBrs(MIn);i++){
    for(j=GetFirstIdxKol(MIn);j<=GetLastIdxKol(MIn);j++){
      Elmt(*MHsl,i,j) = Elmt(MIn,i,j);
    }
  }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
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
  MakeMATRIKS(NB,NK,M);

  for(i=GetFirstIdxBrs(*M);i<=GetLastIdxBrs(*M);i++){
    for(j=GetFirstIdxKol(*M);j<=GetLastIdxKol(*M);j++){
      scanf("%d",&isi);
      Elmt(*M,i,j) = isi;
    }
  }
}
void TulisMATRIKS (MATRIKS M)
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
  for(i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++){
    for(j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++){
      if(j==GetLastIdxKol(M)){
        if(i==GetLastIdxBrs(M)){
          printf("%d",Elmt(M,i,j));
        }else{
          printf("%d\n",Elmt(M,i,j));
        }

      }else{
        printf("%d ",Elmt(M,i,j));
      }


    }

  }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */
{
  /* KAMUS LOKAL */
  MATRIKS Mout;
  indeks i,j;

  /* ALGORITMA */
  MakeMATRIKS( NBrsEff(M1),NKolEff(M1),&Mout);

  for(i=GetFirstIdxBrs(M1);i<=GetLastIdxBrs(M1);i++){
    for(j=GetFirstIdxKol(M1);j<=GetLastIdxKol(M1);j++){
      Elmt(Mout,i,j) = Elmt(M1,i,j) + Elmt(M2,i,j);
    }
  }

  return Mout;
}

MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */
{
  /* KAMUS LOKAL */
  MATRIKS Mout;
  indeks i,j;

  /* ALGORITMA */
  MakeMATRIKS(NBrsEff(M1),NKolEff(M1),&Mout);

  for(i=GetFirstIdxBrs(M1);i<=GetLastIdxBrs(M1);i++){
    for(j=GetFirstIdxKol(M1);j<=GetLastIdxKol(M1);j++){
      Elmt(Mout,i,j) = Elmt(M1,i,j) - Elmt(M2,i,j);
    }
  }

  return Mout;
}

MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
{
  /* KAMUS LOKAL */
  MATRIKS Mout;
  indeks i,j,p;
  ElType hasil;

  /* ALGORITMA */
  MakeMATRIKS(NBrsEff(M1),NKolEff(M2),&Mout);

  for(i=GetFirstIdxBrs(Mout);i<=GetLastIdxBrs(Mout);i++){
    for(j=GetFirstIdxKol(Mout);j<=GetLastIdxKol(Mout);j++){

      hasil =0;
      for(p=GetFirstIdxKol(M1);p<=GetLastIdxKol(M1);p++){
        hasil += Elmt(M1,i,p)*Elmt(M2,p,j);
      }
      Elmt(Mout,i,j) = hasil;
    }
  }

  return Mout;
}

MATRIKS KaliKons (MATRIKS M, ElType X)
/* Mengirim hasil perkalian setiap elemen M dengan X */
{
  /* KAMUS LOKAL */
  MATRIKS Mout;
  indeks i,j;

  /* ALGORITMA */
  MakeMATRIKS(NBrsEff(M),NKolEff(M),&Mout);

  for(i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++){
    for(j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++){
      Elmt(Mout,i,j) = Elmt(M,i,j) * X;
    }
  }

  return Mout;
}

void PKaliKons (MATRIKS * M, ElType K)
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
{
  *M = KaliKons(*M,K);
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
{
  /* KAMUS LOKAL */
  boolean sama;
  indeks i,j,p,q;

  /* ALGORITMA */
  if(EQSize(M1,M2)){
    sama = true;
    i = GetFirstIdxBrs(M1);
    j = GetFirstIdxKol(M1);

    p = GetFirstIdxBrs(M2);
    q = GetFirstIdxKol(M2);

    while(sama&&(i<=GetLastIdxBrs(M1))){
      while(sama&&(j<=GetLastIdxKol(M1))){
        if(Elmt(M1,i,j)!=Elmt(M2,p,q)){
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

boolean NEQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{
  return !EQ(M1,M2);
}

boolean EQSize (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{
  return (NBrsEff(M1)==NBrsEff(M2))&&(NKolEff(M1)==NKolEff(M2));
}

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
  return NBrsEff(M)*NKolEff(M);
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M)
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
{
  return (NBrsEff(M)==NKolEff(M));
}

boolean IsSimetri (MATRIKS M)
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M)
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
{
  /* KAMUS LOKAL */
  indeks i,j;
  boolean simetris;

  /* ALGORITMA */
  if(IsBujurSangkar(M)){

    i = GetFirstIdxBrs(M);
    j = GetFirstIdxKol(M);
    simetris = true;

    while(simetris&&(i<=GetLastIdxBrs(M))){
      while(simetris&&(j<=GetLastIdxKol(M))){
        if(Elmt(M,i,j)!=Elmt(M,j,i)){
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
boolean IsSatuan (MATRIKS M)
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
{
  /* KAMUS LOKAL */
  indeks i,j;
  boolean satuan;

  /* ALGORTIMA */
  if(IsBujurSangkar(M)){
    i = GetFirstIdxBrs(M);
    j = GetFirstIdxKol(M);

    satuan = true;

    while(satuan&&(i<=GetLastIdxBrs(M))){
      while(satuan&&(j<=GetLastIdxKol(M))){
        if((i==j)&&(Elmt(M,i,j)!=1)){
          satuan = false;
        }else if((i!=j)&&(Elmt(M,i,j)!=0)){
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
boolean IsSparse (MATRIKS M)
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi:
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
{
  /* KAMUS LOKAL */
  indeks i,j;
  int jumlahMaks;
  int jumlahIsi;

  /* ALGORITMA */
  i = GetFirstIdxBrs(M);
  j = GetFirstIdxKol(M);

  jumlahMaks = (5*NBElmt(M))/100;
  jumlahIsi = 0;

  while((jumlahIsi<=jumlahMaks)&&(i<=GetLastIdxBrs(M))){
    while((jumlahIsi<=jumlahMaks)&&(j<=GetLastIdxKol(M))){
      if(Elmt(M,i,j)!=0){
        jumlahIsi++;
      }
      j++;
    }
    i++;
    j=GetFirstIdxKol(M);
  }

  return (jumlahIsi<=jumlahMaks);

}
MATRIKS Inverse1 (MATRIKS M)
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{
  return KaliKons(M,-1);
}

float Determinan (MATRIKS M)
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
{
  /* KAMUS LOKAL */
  indeks i,j,k;
  indeks mbar,mkol;
  float det;
  MATRIKS Mminor;

  /* ALGORITMA */
  if(NBElmt(M)==4){
    i = GetFirstIdxBrs(M);
    j = GetFirstIdxKol(M);

    return ((Elmt(M,i,j)*Elmt(M,i+1,j+1))-(Elmt(M,i,j+1)*Elmt(M,i+1,j)));
  }else{
    det = 0;
    for(i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++){
      MakeMATRIKS(NBrsEff(M)-1,NKolEff(M)-1,&Mminor);
      mbar = GetFirstIdxBrs(Mminor);
      mkol = GetFirstIdxKol(Mminor);

      for(j=GetFirstIdxBrs(M);j<=GetLastIdxBrs(M);j++){
        if(j!=i){
          for(k=GetFirstIdxKol(M);k<=GetLastIdxKol(M);k++){
            if(k!=1){
              Elmt(Mminor,mbar,mkol) = Elmt(M,j,k);
              mkol++;
            }

          }
          mbar++;
          mkol= GetFirstIdxKol(Mminor);
        }
      }

      det += pow(-1,(1+i))*Elmt(M,i,1)*Determinan(Mminor);
    }


    return det;
  }
}
void PInverse1 (MATRIKS * M)
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
  *M = Inverse1(*M);
}
void Transpose (MATRIKS * M)
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
{
  /* KAMUS LOKAL */
  MATRIKS Mout;
  indeks i,j;

  /* ALGORITMA */
  MakeMATRIKS(NKolEff(*M),NBrsEff(*M),&Mout);

  for(i=GetFirstIdxBrs(*M);i<=GetLastIdxBrs(*M);i++){
    for(j=GetFirstIdxKol(*M);j<=GetLastIdxKol(*M);j++){
      Elmt(Mout,j,i) = Elmt(*M,i,j);
    }
  }

  *M = Mout;
}
