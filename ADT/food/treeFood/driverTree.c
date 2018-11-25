/* Kelompok  : UAS
   Nama file : driverTree.c
   Deskripsi : Driver ADT untuk tipe tree makanan*/

#include "treeFood.h"
#include "../food.h"

void printTree(TreeFood tf)
{
  if(TF_IsEmpty(tf)){

  }else{
    printf("(%d",F_IDMakanan(TF_Akar(tf)));
    printf("(");
    printTree(TF_Left(tf));
    printf(")(");
    printTree(TF_Right(tf));
    printf("))");
  }
}

int main(){
  /* KAMUS */
  int opsi,opsi2,opsi3,opsi4;
  TreeFood tf;
  Food tempFood;
  TF_address temp;
  int level;

  /* ALGORITMA */
  TF_CreateEmpty(&tf);

  do {
    printf("\n\n");
    printTree(tf);
    printf("\n\n");
    printf("0. Exit\n1. Add\n2. Search\n3. Depth\n4. IsEmpty\nChoice = ");
    scanf("%d",&opsi);

    switch(opsi){
      case 1:
        printf("Isi = ");
        scanf("%d",&opsi2);
        tempFood = F_CreateFood(opsi2, K_MakeKata("Nama"),10000);
        if(TF_IsEmpty(tf)){
          tf = TF_CreateTree(tempFood,Nil,Nil);
        }else{
          printf("isi ke id mana = ");
          scanf("%d",&opsi3);
          printf("kiri = ");
          scanf("%d",&opsi4);
          temp = TF_Search(tf, opsi3);

          if(temp!=Nil){
            TF_AddLeaf(&tf, temp,opsi4, tempFood);
          }else{
            printf("not found \n");
          }

        }

        break;
      case 2:
        printf("search id = ");
        scanf("%d",&opsi2);
        level = 10;
        TF_SearchL(tf, opsi2,&temp,&level);

        if(temp!=Nil){
          printf("found\n");
          printf("level = %d\n",level);
          printTree(temp);
        }else{
          printf("not found \n");
        }
        break;
      case 3:
        printf("depth = %d\n",TF_DeepestLeaf(tf));
        break;
      case 4:
        printf("isempty = %d\n",TF_IsEmpty(tf));
        break;
    }

  } while(opsi!=0);
}
