/*Nama File : main.c */

#include "header/std.h"
#include "header/ADT.h"
#include "ADT Lain/Map + Movement/space.h"

//void LoadEksternal(*Matriks );
//void SaveEksternal();

/*Main Progam*/
int main () {

  //KAMUS
  int money;   //jumlah keuntungan dari restoran
  int life;    //nyawa pemain
  int time;    //tik untuk satuan waktu
  pelayan P;   //pelayan
  restoran R;  //info restoran
  Stack tray;  //food stack sementara
  Stack hand;  //hand stack sementara
  Stack order
  PrioQueue customer; //customer sementara
  Kata input,aksi; //input dan aksi user
  const int maxcost =  5;   //nilai maksimum costumer untuk ngantri
  boolean lose; //kalah dari permainan
  boolean aksivalid; //true jika command yang dimasukan valid

  //ALGORITMA
  do{
    //show all the fucking things to the screen
    //show matriks = GetRuangSekarang(R)

    input=GetInput();
    if(!K_IsKataSama(Input,K_MakeKata("EXIT"))){
      if(K_IsKataSama(input,K_MakeKata("NEW"))||K_IsKataSama(input,K_MakeKata("START"))){
        if(K_IsKataSama(input,K_MakeKata("NEW"))){//kalo new game
          username=GetInput();
        }else if (K_IsKataSama(input,K_MakeKata("START"))){//kalo start game
          if(username.Length==0){
            username=GetInput();
          }
        }

        money = 0;   //keuntungan awal = 0
        life = 10;   //nyawa awal = 10
        time = 1;    //waktu awal = 1
        InitScreen();
        InitPelayan(&P);
        InitRuangan(&R);
        S_CreateEmpty(&tray);
        S_CreateEmpty(&hand);
        PQ_CreateEmpty(&customer,maxcost);
      }else if(K_IsKataSama(input,K_MakeKata("LOAD"))){//kalo load game

      }

      lose = false;
      do {
        aksi=GetInput();
        aksivalid = false;

        if(K_IsKataSama(aksi,K_MakeKata("GU"))){
          if (Up(P)==''){
            MoveUp(&P,R);
            aksivalid = true;
          }
          else if(Ruangan(R)==4 && P_Absis(posisi(P))==1 && P_Ordinat(posisi(P))==5){
            Ruangan(R) = 1;
            PlacePelayan(&P,8,5,Room1(R));
            aksivalid = true;
          }
          else if(Ruangan(R)==3 && P_Absis(posisi(P))==1 && P_Ordinat(posisi(P))==5){
            Ruangan(R) = 2;
            PlacePelayan(&P,8,5,Room2(R));
            aksivalid = true;
          }
        }
        else if(K_IsKataSama(aksi,K_MakeKata("GD"))){
          if (Down(P)==''){
            MoveDown(&P,R);
            aksivalid = true;
          }
          else if(Ruangan(R)==1 && P_Absis(posisi(P))==8 && P_Ordinat(posisi(P))==5){
            Ruangan(R) = 4;
            PlacePelayan(&P,1,5,Room4(R));
            aksivalid = true;
          }
          else if(Ruangan(R)==2 && P_Absis(posisi(P))==8 && P_Ordinat(posisi(P))==5){
            Ruangan(R) = 3;
            PlacePelayan(&P,1,5,Room3(R));
            aksivalid = true;
          }
        }
        else if(K_IsKataSama(aksi,K_MakeKata("GR"))){
          if (Right(P)==''){
            MoveRight(&P,R);
            aksivalid = true;
          }
          else if(Ruangan(R)==1 && P_Absis(posisi(P))==5 && P_Ordinat(posisi(P))==8){
            Ruangan(R) = 2;
            PlacePelayan(&P,2,1,Room2(R));
            aksivalid = true;
          }
          else if(Ruangan(R)==4 && P_Absis(posisi(P))==5 && P_Ordinat(posisi(P))==8){
            Ruangan(R) = 3;
            PlacePelayan(&P,2,1,Room3(R));
            aksivalid = true;
          }
        }
        else if(K_IsKataSama(aksi,K_MakeKata("GL"))){
          if (Left(P)==''){
            MoveLeft(&P,R);
            aksivalid = true;
          }
          else if(Ruangan(R)==2 && P_Absis(posisi(P))==2 && P_Ordinat(posisi(P))==1){
            Ruangan(R) = 1;
            PlacePelayan(&P,5,8,Room1(R));
            aksivalid = true;
          }
          else if(Ruangan(R)==3 && P_Absis(posisi(P))==2 && P_Ordinat(posisi(P))==1){
            Ruangan(R) = 4;
            PlacePelayan(&P,5,8,Room4(R));
            aksivalid = true;
          }
        }
        else if(K_IsKataSama(aksi,K_MakeKata("ORDER"))){
          //push orderan
          if((Up(P).karakter=='X' && K_IsKataSama(Up(P).deskripsi,K_MakeKata("<idmakanan>"))) ||
             (Up(P).karakter=='C' && K_IsKataSama(Up(P).deskripsi,K_MakeKata("<idmakanan>"))) ||
             (Down(P).karakter=='X' && K_IsKataSama(Down(P).deskripsi,K_MakeKata("<idmakanan>"))) ||
             (Down(P).karakter=='C' && K_IsKataSama(Down(P).deskripsi,K_MakeKata("<idimakanan>"))) ||
             (Left(P).karakter=='X' && K_IsKataSama(Left(P).deskripsi,K_MakeKata("<idmakanan>")))||
             (Left(P).karakter=='C' && K_IsKataSama(Left(P).deskripsi,K_MakeKata("<idmakanan>")))||
             (Right(P).karakter=='X' && K_IsKataSama(Right(P).deskripsi,K_MakeKata("<idmakanan>"))) ||
             (Right(P).karakter=='C' && K_IsKataSama(Right(P).deskripsi,K_MakeKata("<idmakanan>")))){
               S_Push(*order,<idmakanan>);
          }
        } //adt makanan dan idmakanan untuk tiap makanan
        else if(K_IsKataSama(aksi,K_MakeKata("PUT"))){
          //push makanan ke hand
        }
        else if(K_IsKataSama(aksi,K_MakeKata("TAKE"))){
          //push bahan ke hand
        }
        else if(K_IsKataSama(aksi,K_MakeKata("CH"))){
          S_CreateEmpty(&hand);
          aksivalid = true;
        }
        else if(K_IsKataSama(aksi,K_MakeKata("CT"))){
            S_CreateEmpty(&tray);
          aksivalid = true;
        }
        else if(K_IsKataSama(aksi,K_MakeKata("PLACE"))){ //tu  ple prioqueue pelanggan
          if((Up(P).karakter=='X' && K_IsKataSama(Up(P).deskripsi,K_MakeKata("-"))) ||
             (Down(P).karakter=='X' && K_IsKataSama(Down(P).deskripsi,K_MakeKata("-"))) ||
             (Left(P).karakter=='X' && K_IsKataSama(Left(P).deskripsi,K_MakeKata("-")))||
             (Right(P).karakter=='X' && K_IsKataSama(Right(P).deskripsi,K_MakeKata("-")))){
               int i = 1;
               while(!CanPlace(PQ_Elmt(customer,i).jumlah,P,R) && i<=5){
                 i++;
               }
               //bisa placing / semua customer sudah dicek

               if(CanPlace(PQ_Elmt(customer,i).jumlah,P,R)){
                 Placing(PQ_Elmt(Customer,i).jumlah, PQ_Elmt(customer,i).waktu,menu,&P,GetRuangSekarang(R))
                 PQ_Del(&customer,PQ_Elmt(customer,i));
               }

          }

        }
        else if(K_IsKataSama(aksi,K_MakeKata("GIVE"))){
          //pop dari tray
          if((Up(P).karakter=='X' && K_IsKataSama(Up(P).deskripsi,K_MakeKata("<idmakanan>"))) ||
             (Up(P).karakter=='C' && K_IsKataSama(Up(P).deskripsi,K_MakeKata("<idmakanan>"))) ||
             (Down(P).karakter=='X' && K_IsKataSama(Down(P).deskripsi,K_MakeKata("<idmakanan>"))) ||
             (Down(P).karakter=='C' && K_IsKataSama(Down(P).deskripsi,K_MakeKata("<idimakanan>"))) ||
             (Left(P).karakter=='X' && K_IsKataSama(Left(P).deskripsi,K_MakeKata("<idmakanan>")))||
             (Left(P).karakter=='C' && K_IsKataSama(Left(P).deskripsi,K_MakeKata("<idmakanan>")))||
             (Right(P).karakter=='X' && K_IsKataSama(Right(P).deskripsi,K_MakeKata("<idmakanan>"))) ||
             (Right(P).karakter=='C' && K_IsKataSama(Right(P).deskripsi,K_MakeKata("<idmakanan>")))){
        }
        else if(K_IsKataSama(aksi,K_MakeKata("RECIPE"))){
          //show table makanan
        }

        if (aksivalid){
          time++;
        }
        //cek semua kesabaran

        if(life==0){
          lose = true;
        }

      } while(!K_IsKataSama(aksi,K_MakeKata("SAVE")) && !K_IsKataSama(aksi,K_MakeKata("EXIT")));

      if(K_IsKataSama(aksi,K_MakeKata("SAVE"))){
        //procedure save
      }

      if(lose){
        //show credit pembuat game
      }

      if(K_IsKataSama(aksi,K_MakeKata("EXIT"))){
        Input = K_MakeKata("EXIT");
      }
    }
  }while(!K_IsKataSama(Input,K_MakeKata("EXIT")));


  return 0;
}

/*//void loadEksternal(*Matriks)
{
  username=GetInput();
  K_STARTKATA(username);
  username.Length = CKata.Length;
  for(i=1;i<=CKata.Length;i++)
  {
    username.TabKata[i]=CKata.TabKata[i];
  }
  K_ADVKATA();

  money = 0;
  while(i<=CKata.Length)
  {
    money *= 10;
    money += (int) CKata.TabKata[i];
  }
  K_ADVKATA();

  life = 0;
  while(i<=CKata.Length)
  {
    life *= 10;
    life += (int) CKata.TabKata[i];
  }
  K_ADVKATA();

  time = 0;
  while(i<=CKata.Length)
  {
    time *= 10;
    time += (int) CKata.TabKata[i];
  }
} */
