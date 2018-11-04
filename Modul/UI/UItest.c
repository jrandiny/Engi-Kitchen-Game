#include "UI.h"
#include <ncurses.h>
#include <unistd.h>

#include "../../ADT/point/point.h"
#include "../../ADT/mesinkata/mesinkata.h"
#include "../../ADT/space/matTile/matTile.h"
#include "../../ADT/customer/prioqueuecustomer.h"

int main(){
  /* KAMUS */
  GameScreen gs;
  Kata input,up;
  Kata prompt;
  ArrKata ak;
  MatTile mt;
  PrioQueueCustomer pqc;
  customer cust;
  Point waiter;

  int i,j;

  /* ALGORITMA */
  up = K_MakeKata("GU");
  prompt = K_MakeKata("Hello : ");

  AK_CreateEmpty(&ak);
  AK_AddAsLastEl(&ak,K_MakeKata("Menu contoh 😁"));
  AK_AddAsLastEl(&ak,K_MakeKata("Input 1 untuk lanjut"));

  InitScreen(&gs);

  do {
    WriteText(&gs,ak);
    input = GetInput(&gs, prompt);
    if(K_IsKataSama(input,K_MakeKata("RESIZE"))){
      refreshLayout(&gs);
    }
  } while(!K_IsKataSama(input, K_MakeKata("1")));

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
  PQC_Prio(cust) = 1;
  PQC_Waktu(cust) = 2;
  PQC_Jumlah(cust) = 2;
  PQC_Add(&pqc, cust);
  PQC_Add(&pqc, cust);


  while(true){
    RefreshTopPanel(&gs,"Nama",1,2,3);
    RefreshWaitingPanel(&gs, pqc);
    RefreshMap(&gs,mt,waiter);
    input  = GetInput(&gs,prompt);

    if(K_IsKataSama(input,K_MakeKata("RESIZE"))){
      refreshLayout(&gs);
    }

    if(K_IsKataSama(input, up)){
      break;
    }

  }

  endwin();
}
