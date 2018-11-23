#include "UI.h"
#include <ncurses.h>
#include <unistd.h>

#include "../../ADT/point/point.h"
#include "../../ADT/mesinkata/mesinkata.h"
#include "../../ADT/space/matTile/matTile.h"
#include "../../ADT/customer/prioQueueCustomer.h"
#include "../../ADT/food/stackFood/stacktfood.h"
#include "../../ADT/food/treeFood/treeFood.h"
#include "../../ADT/food/food.h"

#include <string.h>

int main(){
  /* KAMUS */
  GameScreen gs;
  Kata input,up;
  Kata prompt;
  Kata tooltip;
  ArrKata ak;
  MatTile mt;
  PrioQueueCustomer pqc;
  Customer cust;
  Point waiter;
  StackFood sf,sh;
  SF_infotype testinfo;
  TreeFood tf;
  Food tempFood;
  Order tempOrder;
  ArrOrder ao;

  int i,j;

  /* ALGORITMA */
  up = K_MakeKata("GU");
  prompt = K_MakeKata("Hello : ");

  AK_CreateEmpty(&ak);
  AK_AddAsLastEl(&ak,K_MakeKata("Menu contoh 😁"));
  AK_AddAsLastEl(&ak,K_MakeKata("Input 1 untuk lanjut"));

  /* Create sample matTile */
  MT_MakeMatriks(8, 8, &mt);
  for(i=1;i<=8;i++){
    for(j=1;j<=8;j++){
      MT_Elmt(mt, i, j) = MT_CreateTile(65+i, 5);
    }
  }

  /* Create a sample waiter loc */
  P_Baris(waiter) = 2;
  P_Kolom(waiter) = 2;


  /* Create simple Queue*/
  PQC_CreateEmpty(&pqc);
  C_Prio(cust) = 1;
  C_Waktu(cust) = 2;
  C_Jumlah(cust) = 2;
  PQC_Add(&pqc, cust);
  PQC_Add(&pqc, cust);

  C_Prio(cust) = 0;
  C_Jumlah(cust) = 4;
  PQC_Add(&pqc, cust);
  PQC_Add(&pqc, cust);

  /* Create sample food stack */
  SF_CreateEmpty(&sf,10);
  F_IDMakanan(testinfo) = 1;
  F_NamaMakanan(testinfo) = K_MakeKata("Manusia");
  SF_Push(&sf, testinfo);
  F_IDMakanan(testinfo) = 2;
  F_NamaMakanan(testinfo) = K_MakeKata("Tubes bkr");
  SF_Push(&sf, testinfo);

  /* Create sample hand stack */
  SF_CreateEmpty(&sh,5);
  F_IDMakanan(testinfo) = 1;
  F_NamaMakanan(testinfo) = K_MakeKata("Otak");
  SF_Push(&sh, testinfo);
  F_IDMakanan(testinfo) = 2;
  F_NamaMakanan(testinfo) = K_MakeKata("Tubes");
  SF_Push(&sh, testinfo);

  /* Create sample tree */
  TF_CreateEmpty(&tf);
  tempFood = F_CreateFood(1, K_MakeKata("Nama"),10000);
  tf = TF_CreateTree(tempFood, Nil, Nil);
  tempFood = F_CreateFood(2, K_MakeKata("Nama 2"),999);
  TF_AddLeafS(&tf, 1, 1,tempFood);
  tempFood = F_CreateFood(3, K_MakeKata("Nama 3"),999);
  TF_AddLeafS(&tf, 1, 0,tempFood);
  tempFood = F_CreateFood(4, K_MakeKata("Nama 4"),999);
  TF_AddLeafS(&tf, 2, 1,tempFood);
  tempFood = F_CreateFood(5, K_MakeKata("Nama 5"),999);
  TF_AddLeafS(&tf, 2, 0,tempFood);

  /* Create sample order */
  AO_CreateEmpty(&ao);
  tempOrder = O_CreateOrder(-1, K_MakeKata("makanan"),1);
  AO_AddAsLastEl(&ao, tempOrder);

  tooltip = K_MakeKata("Hello");

  InitScreen(&gs);

  /* Test menu */
  do {
    WriteText(&gs,ak);
    input = GetInput(&gs, prompt);
    if(K_IsKataSama(input,K_MakeKata("RESIZE"))){
      refreshLayout(&gs);
    }
  } while(!K_IsKataSama(input, K_MakeKata("1")));


  /* Test Main game*/
  while(true){
    RefreshTopPanel(&gs,"Up to quit",1,2,3);
    RefreshWaitingPanel(&gs, pqc);
    RefreshFoodPanel(&gs,sf);
    RefreshHandPanel(&gs,sh);
    RefreshMap(&gs,mt,waiter);
    RefreshOrderPanel(&gs,ao);
    input  = GetInput(&gs,prompt);

    if(K_IsKataSama(input,K_MakeKata("TOOLTIP"))){
      RefreshTooltipPanel(&gs,tooltip);
    }

    if(K_IsKataSama(input,K_MakeKata("TREE"))){
      ShowTree(&gs,tf);
    }

    if(K_IsKataSama(input, up)){
      break;
    }

  }

  endwin();
}
