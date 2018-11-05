/* Kelompok  : UAS
   Nama file : main.c
   Tanggal   : 3 November 2018
   Deskripsi : Program utama Engi's Kitchen Expansion */

#include "std.h"
#include "ADT.h"

//tampilan main menu
ArrKata MainMenu(){
  //KAMUS
  ArrKata hasil;
  //ALGORITMA
  AK_CreateEmpty(&hasil);
  AK_AddAsLastEl(&hasil,K_MakeKata("Engi's Kitchen"));
  AK_AddAsLastEl(&hasil,K_MakeKata(""));
  AK_AddAsLastEl(&hasil,K_MakeKata("MAIN MENU"));
  AK_AddAsLastEl(&hasil,K_MakeKata("--NEW"));
  AK_AddAsLastEl(&hasil,K_MakeKata("--START"));
  AK_AddAsLastEl(&hasil,K_MakeKata("--LOAD"));
  AK_AddAsLastEl(&hasil,K_MakeKata("--EXIT"));
  return hasil;
}

//tampilan credit
ArrKata Credit(){
  //KAMUS
  ArrKata isicredit;
  //ALGORITMA
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

ArrKata InputSalah(){
  //KAMUS
  ArrKata isiInputSalah;
  //ALGORITMA
  AK_CreateEmpty(&isiInputSalah);
  AK_AddAsLastEl(&isiInputSalah,K_MakeKata("INPUT YANG DIMASUKKAN SALAH"));
  AK_AddAsLastEl(&isiInputSalah,K_MakeKata(" "));
  AK_AddAsLastEl(&isiInputSalah,K_MakeKata("SILAHKAN INPUT ULANG!"));
  return isiInputSalah;
}

//fungsi bernilai true jika input adalah salah satu kata dari main menu
boolean InputBenar(Kata input,Kata new,Kata start,Kata load,Kata keluar){
  return (K_IsKataSama(input,new)||K_IsKataSama(input,start)||K_IsKataSama(input,load)||K_IsKataSama(input,keluar));
}

void RandomPelanggan(PrioQueueCustomer *pqc,int waktuNow)
/*
  I.S. pqc dan waktuNow terdefinisi
  F.S. me-random kedatangan pelanggan
*/
{
  //KAMUS
  int chance;
  int jumlah;
  customer pelanggan;
  //ALGORITMA
  chance = rand()%25;
  if (chance<5 && PQC_Tail(*pqc)<PQC_MaxEl){ // 1/5 kemungkinan
    PQC_Prio(pelanggan) = rand()%2;
    do {
      jumlah = rand()%3+2;
    } while (jumlah ==3);
    PQC_Jumlah(pelanggan) = jumlah;
    PQC_Waktu(pelanggan) = waktuNow + 30;
    PQC_Add(pqc, pelanggan);
  }
}

void PelangganPergi(PrioQueueCustomer *pqc,int waktuNow,int *jumlah)
/*
  I.S. pqc dan waktuNow terdefinisi
  F.S. jumlah = jumlah pelanggan yang waktu == waktuNow
*/
{
  //KAMUS
  PrioQueueCustomer Q2;
  customer pelanggan;
  //ALGORITMA
  PQC_CreateEmpty(&Q2);
  *jumlah = 0;
  while (!PQC_IsEmpty(*pqc)) {
    PQC_Del(pqc,&pelanggan);
    if (PQC_Waktu(pelanggan)==waktuNow) {
      *jumlah += 1;
    } else {
      PQC_Add(&Q2,pelanggan);
    }
  }
  *pqc = Q2;
}

int main() {
  //KAMUS PROGRAM UTAMA
  int money,life,waktu; //uang dan nyawa yang dimiliki pemain dan tik waktu
  int nomorMeja; //nomor meja di dekat pelayan
  int jumlahKabur; //jumlah pelanggan yang kabur (sudah duduk)
  int jumlahPergi; //jumlah pelangan yang pergi (belum duduk)
  int idMakanan; //id dari makanan
  int waktuOut; //waktu saat pelanggan akan kabur
  int kodeArah; //1==up, 2==right, 3==down, 4==left
  int status; //menyatakan berhasil load file atau tidak
  int harga; //harga makanan sesuai kedalaman food tree
  time_t t; //variabel random
  Restoran R; //tipe restoran dengan graf
  Ruangan *room; //tipe ruangan pada restoran
  MatTile lantai; //tipe MatTile untuk matriks representasi lantai
  Pelayan P; //tipe pelayan restoran
  PrioQueueCustomer Q1,Q2; //tipe barisan pelanggan
  customer pelanggan; //tipe pelanggan
  StackFood order;  //tipe tumpukan makanan di order
  StackFood hand; //tipe tumpukan makanan di hand
  StackFood tray; //tipe tumpukan makanan di tray
  Kata input; //input dari user
  Kata username,usernameSaved; // Kata untuk nama user
  Kata new,start,load,keluar; //tipe kata pembanding
  boolean lose,aksiValid; //tipe validasi
  boolean loaded; //menyatakan ada file yang di load
  boolean saved; //menyatakan sudah save di saat bermain
  GameScreen gs; //tipe untuk GameScreen ncruses

  //ALGORITMA PROGRAM UTAMA

  //inisialisasi
  srand((unsigned) time(&t)); //inisiasi random
  new = K_MakeKata("NEW");
  start = K_MakeKata("START");
  load = K_MakeKata("LOAD");
  keluar = K_MakeKata("EXIT");
  saved = true;

  do { //looping game
    InitScreen(&gs);
    WriteText(&gs,MainMenu()); //main menu
    loaded = false; // masuk main menu == belum load
    do { //meminta input hingga benar
      input = GetInput(&gs,K_MakeKata("CHOICE: "));
    }
    while (!InputBenar(input,new,start,load,keluar));

    if (!K_IsKataSama(input,keluar)) { //inputnya bukan exit
      if (K_IsKataSama(input,new)) { //NEW
        username=GetInput(&gs,K_MakeKata("USERNAME : "));
        //baca file konfigurasi normal
      }
      else if (K_IsKataSama(input,start)) { //START
        //menampilkan username yang tersedia
        username = GetInput(&gs,K_MakeKata("USERNAME: "));
        //dibaca diulang hingga daper username yang benar
        //baca save file dengan nama
      }
      else if (K_IsKataSama(input,load)) { //LOAD
        //prosedure load
        loaded = true;
        do {
          username = GetInput(&gs,K_MakeKata("USERNAME: "));
          LoadFile(&status,&username,&money,&life,&waktu,&R,&P,&Q1);
          if (status ==0) {
            WriteText(&gs,InputSalah()); //main menu
            input = GetInput(&gs,K_MakeKata("USERNAME SALAH!"));
          }
        } while (status==0);
      }
      if (!loaded) { //tidak ada file yang di load
        //load konfigurasi normal
        usernameSaved = K_MakeKata("basic");
        LoadFile(&status,&usernameSaved,&money,&life,&waktu,&R,&P,&Q1);
      }
      //inisialisasi game
      PQC_CreateEmpty(&Q1);

      do{ //looping command di dalam game
        RefreshTopPanel(&gs,K_KataToChar(username),money,life,waktu);
        aksiValid = false;
        lantai = GetMatTileSekarang(R);
        //refresh tampilan di layar
        RefreshMap(&gs,lantai,Pelayan_Posisi(P));
        RefreshWaitingPanel(&gs, Q1);
        //meminta input perintah
        input = GetInput(&gs,K_MakeKata("COMMAND : "));
        if(input.TabKata[1]=='G' && input.Length==2){ //inputnya move
          if(input.TabKata[2]=='U'){ //GU
            kodeArah=1;
          }
          else if(input.TabKata[2]=='R'){ //GR
            kodeArah=2;
          }
          else if(input.TabKata[2]=='D'){ //GD
            kodeArah=3;
          }
          else if(input.TabKata[2]=='L'){ //GL
            kodeArah=4;
          }
          Move(&P,&R,kodeArah,&aksiValid);
        }
        else if(K_IsKataSama(input,K_MakeKata("PUT"))){ //nunggu stack dan tree
          aksiValid = true;
          //if(!SF_IsFull(tray)){
          //}
          //1. validasi apakah tumpukan bahan makanan dapat dijadikan makanan
          //2. cek id makanan sesuai tree
          //3. pop makanan yang sudah jadi dari hand
          //4. push makanan yang sudah jadi ke tray
        } //akhir command put
        else if(K_IsKataSama(input,K_MakeKata("TAKE"))){ //nunggu stack tree
          if (CanTake(P)) {
            aksiValid = true;
            idMakanan = Taking(P);
          }
          //1. validasi apakah berada didekat M / tempat mengolah makanan
          //2. cek apakah bahan makanan yang akan diambil adalah urutan yang sesuai
          //3. push bahan makanan ke stack hand
          //manggil function Taking(P);
        } //akhir command take
        else if(K_IsKataSama(input,K_MakeKata("CH"))){ //nunggu stack
          if(!SF_IsEmpty(hand)){
            SF_CreateEmpty(&hand);
            aksiValid = true;
          }
        } //akhir command ch
        else if(K_IsKataSama(input,K_MakeKata("CT"))){ //nunggu stack
          if(!SF_IsEmpty(tray)){
            SF_CreateEmpty(&tray);
            aksiValid = true;
          }
        } //akhir command ct
        else if(K_IsKataSama(input,K_MakeKata("RECIPE"))){ //nunggu tree makanan
          aksiValid = true;
          //show tree makanan
          //input = GetInput(&gs,K_MakeKata("COMMAND : "));
        } //akhir command recipe
        else if(K_IsKataSama(input,K_MakeKata("RESIZE"))) {
          refreshLayout(&gs);
        } //akhir command resize
        else if(K_IsKataSama(input,K_MakeKata("SAVE"))){
          //procedure save
          saved = true;
          SaveFile(username,money,life,waktu,R,P,Q1);
          input = GetInput(&gs,K_MakeKata("GAME SAVED."));
        }//akhir command save
        else if(K_IsKataSama(input,K_MakeKata("EXIT"))){
          if (!saved) { //dipanggil jika belum di save
            input=GetInput(&gs,K_MakeKata("ARE YOU SURE EXIT WITHOUT SAVE CURRENT FILE ? : "));
            if(K_IsKataSama(input,K_MakeKata("YES"))){ //jadi exit
              input = K_MakeKata("EXIT");
            }
            else { //batal exit
              //inisialisasi agar tidak exit game
              input = K_MakeKata("batalexit");
            }
          }
        } //akhir comman exit
        else { //aksi2 yang butuh dekat Meja
          room = GetRuanganSekarang(R);
          nomorMeja = GetTableNumber(P,*room);

          if (nomorMeja!=0) { //artinya deket meja
            if(K_IsKataSama(input,K_MakeKata("PLACE"))){
              PQC_CreateEmpty(&Q2);
              while(!CanPlace(PQC_Jumlah(PQC_InfoHead(Q1)),P,*room) && !PQC_IsEmpty(Q1)){
                PQC_Del(&Q1,&pelanggan);
                PQC_Add(&Q2,pelanggan);
              }//bisa place atau sudah dicek semua

              if (CanPlace(PQC_Jumlah(PQC_InfoHead(Q1)),P,*room)) { //ada yang bisa di place
                aksiValid = true;
                PQC_Del(&Q1,&pelanggan);
                if(PQC_Prio(pelanggan)==1){
                  waktuOut = waktu + (rand()%20+21); //[21..40]
                }
                else{
                  waktuOut = waktu + (rand()%20+31); //[31..50]
                }

                Placing(PQC_Jumlah(pelanggan),waktuOut,&P,room);

                while(!PQC_IsEmpty(Q1)) {
                  PQC_Del(&Q1,&pelanggan);
                  PQC_Add(&Q2,pelanggan);
                } //Q1 pasti kosong
              } //akhir placing
              Q1 = Q2;
            } //akhir command place
            else if(K_IsKataSama(input,K_MakeKata("GIVE"))){  //nunggu stack
              if (CanGive(P,*room,nomorMeja)) {
                aksiValid = true;
                //SF_Pop(&tray,&food);
                //money += harga
                //SetTableEmpty(nomorMeja,room);
              }
              //1. validasi nomormeja yang memesan makanan pada top stack tray
              //2. search harga makanan di data harga makanan
              //3. tambahkan money dengan harga makanan
              //4. pop top stack tray
              //5. SetTableEmpty(nomormeja,&Room);
            } //akhir command give
            else if(K_IsKataSama(input,K_MakeKata("ORDER"))){ //nunggu stack dan converter idmakanan
              if(CanOrder(P,*room)){
                aksiValid = true;
                Ordering(P,room,&idMakanan,&nomorMeja);
                // money = idMakanan;
                // SF_Push(room,idmakanan,nomormeja);
              } //akhir can order
            } //akhir command order
          } //akhir cek nomor meja
        } //akhir proses validasi command

        if(aksiValid){//proses yang terjadi jika inputnya valid
          RandomPelanggan(&Q1,waktu);
          waktu++; //tik bertambah
          PelangganKabur(waktu,&P,&R,&jumlahKabur);
          PelangganPergi(&Q1,waktu,&jumlahPergi);
          life -=jumlahKabur+jumlahPergi;
          saved = false; //saved false karena ada aksi yang berhasil
          if(life<=0){ //jika nyawa==0 maka kalah
            lose = true;
          }
        }//akhir proses aksiValid
      }
      while(!K_IsKataSama(input,keluar) && !lose);

      if(lose){ //pemain kalah tampilkan credit
        InitScreen(&gs);
        WriteText(&gs,Credit());
        input = GetInput(&gs,K_MakeKata("YOU LOSE!"));
      }
      //inisialisasi input agar kembali ke main menu
      input = K_MakeKata("mainmenu");
    } //input == exit
  } while (!K_IsKataSama(input,keluar));
  //input == exit
  QuitScreen(&gs); //quit game
  return 0;
}
