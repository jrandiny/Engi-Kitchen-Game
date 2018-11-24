/* Kelompok  : UAS
   Nama file : treefood.c
   Deskripsi : Implementasi ADT untuk tipe tree makanan*/

#include "../food.h"
#include "../../../std.h"
#include "treeFood.h"

/* Primitif */
TreeFood TF_CreateTree(TF_infotype akar, TreeFood L, TreeFood R)
/* Menghasilkan sebuah pohon biner dengan akar dan kiri kanan LR */
{
  /* KAMUS LOKAL */
  TF_address tempadd;

  /* ALGORITMA */
  tempadd = TF_Alokasi(akar);
  if(tempadd!=Nil){
    TF_Left(tempadd) = L;
    TF_Right(tempadd) = R;
  }

  return tempadd;

}

void TF_CreateEmpty(TreeFood *tf)
/* I.S. : Bebas */
/* F.S. : tf terinisialisasi kosong */
{
  *tf = Nil;
}

TF_address TF_Alokasi(TF_infotype X)
/* Mengirimkan address hasil alokasi elemen X */
/* Info(P) = X, Left(P) = Nil, Right(P) = Nil */
/* Jika alokasi gagal return Nil */
{
  /* KAMUS LOKAL */
  TF_address tempAdd;

  /* ALGORITMA */
  tempAdd = (TF_address) malloc(sizeof(TF_Node));
  TF_Akar(tempAdd) = X;
  return tempAdd;
}

void TF_Dealokasi(TF_address P)
/* I.S. : P terdefinisi */
/* F.S. : P dikembalikan ke sistem */
{
  free(P);
}

void TF_AddLeaf(TreeFood *tf,TF_address pangkal,boolean kiri,TF_infotype X)
/* I.S. : tf, pangkal, td, x terdefinisi. Pangkal berada pada tf */
/* F.S. : Ditambahkan daun X pada pangkal, pada kiri atau kanan sesuai variabel kiri */
{
  /* KAMUS LOKAL */
  TF_address addTemp;

  /* ALGORITMA */
  addTemp = TF_CreateTree(X, Nil, Nil);
  if(addTemp != Nil){
    if(kiri){
      TF_Left(pangkal) = addTemp;
    }else{
      TF_Right(pangkal) = addTemp;
    }
  }
}

void TF_AddLeafS(TreeFood *tf,int pangkal,boolean kiri,TF_infotype X)
/* I.S. : tf, pangkal, td, x terdefinisi. Pangkal berada pada tf */
/* F.S. : Ditambahkan daun X pada node dengan id pangkal, pada kiri atau kanan sesuai variabel kiri */
{
  /* KAMUS LOKAL */
  TF_address searchTemp;

  /* ALGORITMA */
  searchTemp  =TF_Search(*tf, pangkal);
  if(searchTemp!=Nil){
    TF_AddLeaf(tf, searchTemp, kiri, X);
  }
}

boolean TF_IsEmpty(TreeFood tf)
/* Mengembalikan true jika tf kosong */
{
  return (tf==Nil);
}

int TF_DeepestLeaf(TreeFood tf)
/* Mengembalikan kedalaman dari tree di titik terdalamanya */
{
  /* KAMUS LOKAL */
  int leftCount;
  int rightCount;

  /* ALGORITMA */
  if(TF_IsEmpty(tf)){
    return 0;
  }else{
    leftCount = TF_DeepestLeaf(TF_Left(tf));
    rightCount = TF_DeepestLeaf(TF_Right(tf));
    if(leftCount>rightCount){
      return leftCount + 1;
    }else{
      return rightCount + 1;
    }
  }
}

TF_address TF_Search(TreeFood tf,int foodId)
/* Mengembalikan address yang id makanannya sesuai */
{
  /* KAMUS LOKAL */
  TF_address add;
  int temp;

  /* AGORITMA */
  TF_SearchL(tf, foodId, &add,&temp);
  return add;
}

void TF_SearchL(TreeFood tf,int foodId,TF_address *result, int *level)
/* Mengembalikan address yang id makanannya sesuai dan level dari node itu */

{
  /* KAMUS LOKAL */
  TF_address P1,P2;
  int levelTempL,levelTempR;

  /* ALGORITMA */
  if(TF_IsEmpty(tf)){
    *result =  Nil;
  }else{
    if(F_IDMakanan(TF_Akar(tf))==foodId){
      *level = 1;
      *result = tf;
    }else{
      TF_SearchL(TF_Left(tf),foodId,&P1,&levelTempL);
      TF_SearchL(TF_Right(tf),foodId,&P2,&levelTempR);
      if(P1!=Nil){
        levelTempL++;
        *result = P1;
        *level = levelTempL;
      }else if(P2!=Nil){
        levelTempR++;
        *result = P2;
        *level = levelTempR;
      }else{
        *result = Nil;
      }

    }
  }

}
