#include "UI.h"
#include <ncurses.h>
#include <unistd.h>

#include "../../ADT/point/point.h"
#include "../../ADT/mesinkata/mesinkata.h"
#include "../../ADT/space/matTile/matTile.h"

int main(){
  /* KAMUS */
  GameScreen gs;
  Kata input,up;
  Kata prompt;
  ArrKata ak;
  MatTile mt;

  int i,j;

  /* ALGORITMA */
  up = K_MakeKata("GU");
  prompt = K_MakeKata("Hello : ");

  AK_CreateEmpty(&ak);
  AK_AddAsLastEl(&ak,K_MakeKata("Menu contoh"));
  AK_AddAsLastEl(&ak,K_MakeKata("Input 1 untuk lanjut"));

  InitScreen(&gs);

  do {
    WriteText(&gs,ak);
    input = GetInput(&gs, prompt);
    if(K_IsKataSama(input,K_MakeKata("RESIZE"))){
      refreshLayout(&gs);
    }
  } while(!K_IsKataSama(input, K_MakeKata("1")));

  MT_MakeMatriks(8, 8, &mt);
  for(i=1;i<=8;i++){
    for(j=1;j<=8;j++){
      MT_Elmt(mt, i, j) = MT_SetTile(65+i, 5);
    }
  }



  while(true){
    RefreshTopPanel(&gs,"Nama",1,2,3);
    RefreshMap(&gs,mt);
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
