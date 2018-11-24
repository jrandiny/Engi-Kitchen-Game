/* Kelompok  : UAS
   Nama file : treefood.h
   Deskripsi : ADT untuk tipe tree makanan*/
#ifndef TREEFOOD_H
#define TREEFOOD_H

#include "../food.h"
#include "../../../std.h"

/* Definisi TreeFood*/
typedef Food TF_infotype;
typedef struct tNode *TF_address;
typedef struct tNode{
  TF_infotype info;
  TF_address left;
  TF_address right;
} TF_Node;

typedef TF_address TreeFood;

/* Selektor */
#define TF_Akar(P) (P)->info
#define TF_Left(P) (P)->left
#define TF_Right(P) (P)->right

/* Primitif */
TreeFood TF_CreateTree(TF_infotype akar, TreeFood L, TreeFood R);
/* Menghasilkan sebuah pohon biner dengan akar dan kiri kanan LR */

void TF_CreateEmpty(TreeFood *tf);
/* I.S. : Bebas */
/* F.S. : tf terinisialisasi kosong */

TF_address TF_Alokasi(TF_infotype X);
/* Mengirimkan address hasil alokasi elemen X */
/* Info(P) = X, Left(P) = Nil, Right(P) = Nil */
/* Jika alokasi gagal return Nil */

void TF_Dealokasi(TF_address P);
/* I.S. : P terdefinisi */
/* F.S. : P dikembalikan ke sistem */

boolean TF_IsEmpty(TreeFood tf);
/* Mengembalikan true jika tf kosong */

int TF_DeepestLeaf(TreeFood tf);
/* Mengembalikan kedalaman dari tree di titik terdalamanya */

void TF_AddLeafS(TreeFood *tf,int pangkal,boolean kiri,TF_infotype X);
/* I.S. : tf, pangkal, td, x terdefinisi. Pangkal berada pada tf */
/* F.S. : Ditambahkan daun X pada node dengan id pangkal, pada kiri atau kanan sesuai variabel kiri */

void TF_AddLeaf(TreeFood *tf,TF_address pangkal,boolean kiri,TF_infotype X);
/* I.S. : tf, pangkal, td, x terdefinisi. Pangkal berada pada tf */
/* F.S. : Ditambahkan daun X pada pangkal, pada kiri atau kanan sesuai variabel kiri */

/* Search */
TF_address TF_Search(TreeFood tf,int foodId);
/* Mengembalikan address yang id makanannya sesuai */

void TF_SearchL(TreeFood tf,int foodId,TF_address *result, int *level);
/* Mengembalikan address yang id makanannya sesuai dan level dari node itu */


#endif
