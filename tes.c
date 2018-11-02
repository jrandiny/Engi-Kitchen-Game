
#include "std.h"
// #include "ADT Lain/Map + Movement/space.h"
#include "Modul/UI/UI.h"
#include "ADT/space/space.h"
#include "ADT/customer/prioqueuecustomer.h"
#include "Modul/eksternal/eksternal.h"

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

ArrKata Credit(){
  ArrKata isicredit;
  AK_CreateEmpty(&isicredit);
  AK_AddAsLastEl(&isicredit,K_MakeKata("GAME OVER"));
  AK_AddAsLastEl(&isicredit,K_MakeKata(""));
  AK_AddAsLastEl(&isicredit,K_MakeKata(""));
  AK_AddAsLastEl(&isicredit,K_MakeKata("THIS GAME IS CREATED BY :"));
  AK_AddAsLastEl(&isicredit,K_MakeKata(""));
  AK_AddAsLastEl(&isicredit,K_MakeKata("13517012 - JOHANES"));
  AK_AddAsLastEl(&isicredit,K_MakeKata("13517039 - STEVE ANDREAS"));
  AK_AddAsLastEl(&isicredit,K_MakeKata("13517063 - JOSHUA CHRISTO RANDINY"));
  AK_AddAsLastEl(&isicredit,K_MakeKata("13517066 - WILLY SANTOSO"));
  AK_AddAsLastEl(&isicredit,K_MakeKata("13517114 - SEKAR LARASATI MUSLIMAH"));
  return isicredit;
}

int main (){
  //KAMUS
  const int maxcost =  10;   //nilai maksimum costumer untuk ngantri
  int money,life,time,nomormeja,kabur,idmakanan,waktuout;   //jumlah keuntungan dari restoran  //nyawa pemain //tik untuk satuan waktu
  time_t t;
  Pelayan P;   //pelayan
  Ruangan Room;  //info restoran
  Restoran R;
  MatTile M;
  // Stack tray,hand,order;  //food stack sementara //hand stack sementara
  PrioQueueCustomer customer1 customer2; //customer sementara
  customer cust;
  Kata input,aksi,username,resep,kalah; //input dan aksi user
  boolean lose,aksivalid; //kalah dari permainan //true jika command yang dimasukan valid
  GameScreen gs;

  //ALGORITMA
  InitScreen(&gs);
  do{
    WriteText(&gs,MainMenu());
    input=GetInput(&gs,K_MakeKata("INPUT ANDA : "));
    if(K_IsKataSama(input,K_MakeKata("NEW"))||K_IsKataSama(input,K_MakeKata("START")) || K_IsKataSama(input,K_MakeKata("LOAD"))){
      if(K_IsKataSama(input,K_MakeKata("NEW"))||K_IsKataSama(input,K_MakeKata("START"))){
        if(K_IsKataSama(input,K_MakeKata("NEW"))){//kalo new game
          username=GetInput(&gs,K_MakeKata("USERNAME : "));
        }else if (K_IsKataSama(input,K_MakeKata("START"))){//kalo start game
          if(username.Length==0){
            username=GetInput(&gs,K_MakeKata("USERNAME : "));
          }
        }

        money = 0;   //inisialisasi keuntungan awal = 0
        life = 10;   //inisialisasi nyawa awal = 10
        time = 1;    //inisialisasi waktu awal = 1
        RefreshTopPanel(&gs,K_KataToChar(username),money,life,time);
        InitPelayan(&P);
        InitRestoran(&R);
        // S_CreateEmpty(&tray);
        // S_CreateEmpty(&hand);
        PQC_CreateEmpty(&customer1);
        PQC_CreateEmpty(&customer2);
      }
      else if(K_IsKataSama(input,K_MakeKata("LOAD"))){//kalo load game
        //procedure load game
      }

      aksivalid = false;
      do{
        RefreshTopPanel(&gs,K_KataToChar(username),money,life,time);
        M = GetRuangSekarang(R);
        nomormeja = IsNearTable(P,Room);
        aksi=GetInput(&gs,K_MakeKata("COMMAND : "));
        if(K_IsKataSama(aksi,K_MakeKata("GU"))){
          if (CanMoveUp(P,M)){
            MoveUp(&P,M);
            aksivalid = true;
          }
          else if(RoomNow(R)==4 && P_Absis(Pelayan_Posisi(P))==1 && P_Ordinat(Pelayan_Posisi(P))==5){
            RoomNow(R) = 1;
            PlacePelayan(&P,8,5,Room(AR_Elmt(Ruangan(R),1)));
            aksivalid = true;
          }
          else if(RoomNow(R)==3 && P_Absis(Pelayan_Posisi(P))==1 && P_Ordinat(Pelayan_Posisi(P))==5){
            RoomNow(R) = 2;
            PlacePelayan(&P,8,5,Room(AR_Elmt(Ruangan(R),2)));
            aksivalid = true;
          }
        }
        else if(K_IsKataSama(aksi,K_MakeKata("GD"))){
          if (CanMoveDown(P,M)){
            MoveDown(&P,M);
            aksivalid = true;
          }
          else if(RoomNow(R)==1 && P_Absis(Pelayan_Posisi(P))==8 && P_Ordinat(Pelayan_Posisi(P))==5){
            RoomNow(R) = 4;
            PlacePelayan(&P,1,5,Room(AR_Elmt(Ruangan(R),4)));
            aksivalid = true;
          }
          else if(RoomNow(R)==2 && P_Absis(Pelayan_Posisi(P))==8 && P_Ordinat(Pelayan_Posisi(P))==5){
            RoomNow(R) = 3;
            PlacePelayan(&P,1,5,Room(AR_Elmt(Ruangan(R),3)));
            aksivalid = true;
          }
        }
        else if(K_IsKataSama(aksi,K_MakeKata("GR"))){
          if (CanMoveRight(P,M)){
            MoveRight(&P,M);
            aksivalid = true;
          }
          else if(RoomNow(R)==1 && P_Absis(Pelayan_Posisi(P))==5 && P_Ordinat(Pelayan_Posisi(P))==8){
            RoomNow(R) = 2;
            PlacePelayan(&P,2,1,Room(AR_Elmt(Ruangan(R),2)));
            aksivalid = true;
          }
          else if(RoomNow(R)==4 && P_Absis(Pelayan_Posisi(P))==5 && P_Ordinat(Pelayan_Posisi(P))==8){
            RoomNow(R) = 3;
            PlacePelayan(&P,2,1,Room(AR_Elmt(Ruangan(R),3)));
            aksivalid = true;
          }
        }
        else if(K_IsKataSama(aksi,K_MakeKata("GL"))){
          if (CanMoveLeft(P,M)){
            MoveLeft(&P,M);
            aksivalid = true;
          }
          else if(RoomNow(R)==2 && P_Absis(Pelayan_Posisi(P))==2 && P_Ordinat(Pelayan_Posisi(P))==1){
            RoomNow(R) = 1;
            PlacePelayan(&P,5,8,Room(AR_Elmt(Ruangan(R),1)));
            aksivalid = true;
          }
          else if(RoomNow(R)==3 && P_Absis(Pelayan_Posisi(P))==2 && P_Ordinat(Pelayan_Posisi(P))==1){
            RoomNow(R) = 4;
            PlacePelayan(&P,5,8,Room(AR_Elmt(Ruangan(R),4)));
            aksivalid = true;
          }
        }
        else if(K_IsKataSama(aksi,K_MakeKata("PUT"))){ //nunggu stack
          aksivalid = true;
          //1. validasi apakah tumpukan bahan makanan dapat dijadikan makanan
          //2. cek id makanan sesuai tree
          //3. pop makanan yang sudah jadi dari hand
          //4. push makanan yang sudah jadi ke tray
        }
        else if(K_IsKataSama(aksi,K_MakeKata("TAKE"))){ //nunggu stack
          aksivalid = true;
          //1. validasi apakah berada didekat M / tempat mengolah makanan
          //2. cek apakah bahan makanan yang akan diambil adalah urutan yang sesuai
          //3. push bahan makanan ke stack hand
          //manggil function Taking(P);
        }
        else if(K_IsKataSama(aksi,K_MakeKata("CH"))){ //nunggu stack
          // if(!S_IsEmpty(hand)){
            // S_CreateEmpty(&hand);
            aksivalid = true;
          // }
        }
        else if(K_IsKataSama(aksi,K_MakeKata("CT"))){ //nunggu stack
          // if(!S_IsEmpty(tray)){
            // S_CreateEmpty(&tray);
            aksivalid = true;
          // }
        }
        else if(K_IsKataSama(aksi,K_MakeKata("RECIPE"))){ //nunggu tree makanan
          aksivalid = true;
          //show tree makanan
          resep=GetInput(&gs,K_MakeKata("COMMAND : "));
        }
        else if(nomormeja!=0){
          if(K_IsKataSama(aksi,K_MakeKata("PLACE"))){ //nunggu prioqueue
            if(IsTableEmpty(nomormeja,Room)){
              //1. cek apakah jumlah pelanggan di head prioqueuecustomer memenuhi pada meja yang kosong
              //2. ulang pengecekan hingga ditemukan jumlah pelanggana yang cocok atau tidak ada sama sekali
              //3. buat prioqueuecustomer ke dua untuk menampung update antrian Customer
              //4. jika jumlah customer head memenuhi, set waktu random untuk waktuout costumer menunggu makanan
              //5. lakukan aksi placing terhadap infohead
              //6. del prioqueuecustomer
              //7. pindahkan sisa elemen prioqueuecustomer
              //Placing()
              int i=1;
              while(!CanPlace(PQC_Jumlah(PQC_Elmt(customer1,i)),P,R) && PQC_Elmt(customer1,i)!=PQC_InfoHead(customer1)){
                PQC_Del(&customer1,&cust);
                PQC_Add(&customer2,cust);
                i++;
              }//bisa place atau sudah dicek semua
              customer1 = customer2;

              if(CanPlace(PQC_Jumlah(PQC_Elmt(customer1,i)),P,R){
                PQC_Del(&customer1,&cust);
                srand((unsigned) time(&t));
                if(PQC_Prio(cust)==1){
                  waktuout = time + (rand()%20+21);
                }
                else{
                  waktuout = time + (rand()%20+31);
                }
                aksivalid = true;
                Placing(PQC_Jumlah(cust),waktuout,&P,&R);
              }
            }
          }
          else if(K_IsKataSama(aksi,K_MakeKata("GIVE"))){  //nunggu stack
            aksivalid = true;
            //1. validasi nomormeja yang memesan makanan pada top stack tray
            //2. search harga makanan di data harga makanan
            //3. tambahkan money dengan harga makanan
            //4. pop top stack tray
            //5. SetTableEmpty(nomormeja,&Room);
          }
          else if(K_IsKataSama(aksi,K_MakeKata("ORDER"))){ //nunggu stack dan converter idmakanan
            if(CanOrder(P,Room)){
              aksivalid = true;
              Ordering(P,&Room,&idmakanan,&nomormeja);
              // S_Push(room,idmakanan,nomormeja);
            }
          }
        }
        else if(K_IsKataSama(aksi,K_MakeKata("SAVE"))){
          //procedure save
        } //save current state
        else if(K_IsKataSama(aksi,K_MakeKata("EXIT"))){
          aksi=GetInput(&gs,K_MakeKata("ARE YOU SURE EXIT WITHOUT SAVE CURRENT FILE ? : "));

          if(K_IsKataSama(aksi,K_MakeKata("YES"))){
            aksi = K_MakeKata("EXIT");
          }
        }

        if(aksivalid){
          time++;
          PelangganKabur(time,&P,&R,&kabur);
          life -=kabur;
          if(life==0){
            lose = true;
          }
        }

      }while(!K_IsKataSama(aksi,K_MakeKata("EXIT")) && !lose);

      if(lose){
        WriteText(&gs,Credit());
        kalah=GetInput(&gs,K_MakeKata("COMMAND : "));
      }
     }

  }while(!K_IsKataSama(input,K_MakeKata("EXIT")));
  QuitScreen(&gs);


  return 0;
}
