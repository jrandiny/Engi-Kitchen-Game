#include "UI.h"
#include <ncurses.h>
#include <unistd.h>

#include "../../ADT/point/point.h"
#include "../../ADT/mesinkata/mesinkata.h"

int main(){
  GameScreen gs;
  InitScreen(&gs);

  Kata abc,up,orig3;

  up = K_MakeKata("GU");

  wrefresh(Hand_Panel(gs));

  Kata prompt;
  prompt = K_MakeKata("Hello : ");
  ArrKata ak;
  AK_CreateEmpty(&ak);
  AK_AddAsLastEl(&ak,K_MakeKata("Menu contoh"));
  AK_AddAsLastEl(&ak,K_MakeKata("Input 1 untuk lanjut"));
  WriteText(&gs,ak);

  do {
    abc = GetInput(&gs, prompt);
  } while(!K_IsKataSama(abc, K_MakeKata("1")));

  while(true){
    RefreshTopPanel(&gs,orig3,1,2,3);
    RefreshMap(&gs);
    abc  = GetInput(&gs,prompt);

    if(K_IsKataSama(abc, up)){
      break;
    }

  }

  endwin();
}
