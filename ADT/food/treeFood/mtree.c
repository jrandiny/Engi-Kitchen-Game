#include "treeFood.h"
#include "../food.h"

void printGraf(TreeFood tf)
{
  if(TF_IsEmpty(tf)){

  }else{
    printf("-> %d\n",F_IDMakanan(TF_Akar(tf)));
    printf("left\n");
    printGraf(TF_Left(tf));
    printf("right\n");
    printGraf(TF_Right(tf));
  }
}

int main(){
  /* KAMUS */
  int opsi,opsi2,opsi3,opsi4;
  TreeFood tf;
  Food tempFood;
  TF_address temp;

  /* ALGORITMA */
  TF_CreateEmpty(&tf);

  do {
    printf("\n\n");
    printGraf(tf);
    printf("\n\n");
    printf("0) Exit\n1) Add\n2) Search\n");
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
        temp = TF_Search(tf, opsi3);

        if(temp!=Nil){
          printf("found\n");
          printGraf(temp);
        }else{
          printf("not found \n");
        }
        break;
    }

  } while(opsi!=0);
}
