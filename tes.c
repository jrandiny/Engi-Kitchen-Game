
#include "std.h"
// #include "ADT Lain/Map + Movement/space.h"
#include "Modul/UI/UI.h"
#include "ADT/space/tile.h"
#include "ADT/space/matTile/matTile.h"

ArrKata MainMenu(){
  ArrKata hasil;
  AK_CreateEmpty(&hasil);
  AK_AddAsLastEl(&hasil,K_MakeKata("Engi's Kitchen"));
  AK_AddAsLastEl(&hasil,K_MakeKata(""));
  AK_AddAsLastEl(&hasil,K_MakeKata("Pilihan :"));
  AK_AddAsLastEl(&hasil,K_MakeKata("- New"));
  AK_AddAsLastEl(&hasil,K_MakeKata("- Start"));
  AK_AddAsLastEl(&hasil,K_MakeKata("- Load"));
  AK_AddAsLastEl(&hasil,K_MakeKata("- Exit"));
  return hasil;
}

int main (){
  const int maxcost =  5;   //nilai maksimum costumer untuk ngantri
  int money,life,time;   //jumlah keuntungan dari restoran  //nyawa pemain //tik untuk satuan waktu
  // pelayan P;   //pelayan
  // restoran R;  //info restoran
  // Stack tray,hand,order;  //food stack sementara //hand stack sementara
  // PrioQueue customer; //customer sementara
  Kata input,aksi,username; //input dan aksi user
  boolean lose,aksivalid; //kalah dari permainan //true jika command yang dimasukan valid
  GameScreen gs;
  Restoran R;
  Pelayan P;

  InitScreen(&gs);
  do{
    WriteText(&gs,MainMenu());
    input=GetInput(&gs,K_MakeKata("INPUT ANDA : "));
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
        RefreshTopPanel(&gs,K_KataToChar(username),money,life,time);
        InitPelayan(&P);
        InitRuangan(&R);
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
