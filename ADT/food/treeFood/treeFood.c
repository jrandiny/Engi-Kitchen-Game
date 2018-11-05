/* Kelompok  : UAS
   Nama file : treefood.h
   Topik     : Engi's Kitchen Game
   Tanggal   : 5 November 2018
   Deskripsi : ADT untuk tipe array kata*/

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
/* mereturn true jika tf kosong*/
{
  return (tf==Nil);
}

TF_address TF_Search(TreeFood tf,int foodId)
/* Mengembalikan address yang id makanannya sesuai */
{
  /* KAMUS LOKAL */
  TF_address P1,P2;

  /* ALGORITMA */
  if(TF_IsEmpty(tf)){
    return Nil;
  }else{
    printf("cek %d",F_IDMakanan(TF_Akar(tf)));
    if(F_IDMakanan(TF_Akar(tf))==foodId){
      return tf;
    }else{
      P1 = TF_Search(TF_Left(tf),foodId);
      P2 = TF_Search(TF_Left(tf),foodId);
      if(P1!=Nil){
        return P1;
      }else if(P2!=Nil){
        return P2;
      }else{
        return Nil;
      }

    }
  }

}
