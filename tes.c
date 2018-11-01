
#include "std.h"
// #include "ADT Lain/Map + Movement/space.h"
#include "Modul/UI/UI.h"

int main (){
  int money;   //jumlah keuntungan dari restoran
  int life;    //nyawa pemain
  int time;    //tik untuk satuan waktu()
  // pelayan P;   //pelayan
  // restoran R;  //info restoran
  // Stack tray;  //food stack sementara
  // Stack hand;  //hand stack sementara
  // Stack order
  // PrioQueue customer; //customer sementara
  Kata input,aksi,username; //input dan aksi user
  GameScreen gs;
  ArrKata menuutama;
  AK_CreateEmpty(&menuutama);
  AK_AddAsLastEl(&menuutama,K_MakeKata("Engi's Kitchen"));
  AK_AddAsLastEl(&menuutama,K_MakeKata("Halo halo"));
  AK_AddAsLastEl(&menuutama,K_MakeKata("Random gatau apa"));
  InitScreen(&gs);

  do{
    //show all the fucking things to the screen
    //show matriks = GetRuangSekarang(R)
    WriteText(&gs,menuutama);
    input=GetInput(&gs,K_MakeKata("COMMAND : "));
    if(!K_IsKataSama(input,K_MakeKata("EXIT"))){
      if(K_IsKataSama(input,K_MakeKata("NEW"))||K_IsKataSama(input,K_MakeKata("START"))){
        if(K_IsKataSama(input,K_MakeKata("NEW"))){//kalo new game
          username=GetInput(&gs,K_MakeKata("USERNAME : "));
        }else if (K_IsKataSama(input,K_MakeKata("START"))){//kalo start game
          if(username.Length==0){
            username=GetInput(&gs,K_MakeKata("USERNAME : "));
          }
        }

        money = 0;   //keuntungan awal = 0
        life = 10;   //nyawa awal = 10
        time = 1;    //waktu awal = 1
        RefreshTopPanel(&gs,username,money,life,time);
        // InitScreen();
        // InitPelayan(&P);
        // InitRuangan(&R);
        // S_CreateEmpty(&tray);
        // S_CreateEmpty(&hand);
        // PQ_CreateEmpty(&customer,maxcost);
      }else if(K_IsKataSama(input,K_MakeKata("LOAD"))){//kalo load game
      }
        if(K_IsKataSama(aksi,K_MakeKata("GU"))){
          time++;
        }
        else if(K_IsKataSama(aksi,K_MakeKata("GD"))){
          time++;
        }
        else if(K_IsKataSama(aksi,K_MakeKata("GR"))){
          time++;
        }
        else if(K_IsKataSama(aksi,K_MakeKata("GL"))){
          time++;
        }
        else if(K_IsKataSama(aksi,K_MakeKata("ORDER"))){
          time++;
        }
        else if(K_IsKataSama(aksi,K_MakeKata("PUT"))){
          time++;
        }
        else if(K_IsKataSama(aksi,K_MakeKata("TAKE"))){
          time++;
        }
        else if(K_IsKataSama(aksi,K_MakeKata("CH"))){
          time++;
        }
        else if(K_IsKataSama(aksi,K_MakeKata("CT"))){
          time++;
        }
        else if(K_IsKataSama(aksi,K_MakeKata("PLACE"))){
          time++;
        }
        else if(K_IsKataSama(aksi,K_MakeKata("GIVE"))){
          time++;
        }
        else if(K_IsKataSama(aksi,K_MakeKata("RECIPE"))){
          time++;
        }
    }

  }while(!K_IsKataSama(input,K_MakeKata("EXIT")));
}
