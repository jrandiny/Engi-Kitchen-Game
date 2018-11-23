#include "space.h"
#include "../../Modul/eksternal/eksternal.h"
#include <string.h>
#include <time.h>

void Inisiasi(int *status, Kata *nama, int *money, int *life, int *waktu, Restoran *restoran, Pelayan *pelayan, PrioQueueCustomer *prioqueue, StackFood *hand, StackFood *tray, ArrOrder *arrorder){
  *nama = K_MakeKata("basic");
  LoadFile(status, nama, money, life, waktu,restoran,pelayan,prioqueue, hand, tray, arrorder);
}

void PrintSurround(Pelayan P){
  printf("\t%c,%d\n",Karakter(Up(P)),Value(Up(P)));
  printf("%c,%d\t%d,%d\t%c,%d\n",Karakter(Left(P)),Value(Left(P)),P_Baris(Pelayan_Posisi(P)),P_Kolom(Pelayan_Posisi(P)),Karakter(Right(P)),Value(Right(P)));
  printf("\t%c,%d\n",Karakter(Down(P)),Value(Down(P)));
}

int main() {
  //KAMUS
  Pelayan P;
  Restoran R;
  int input;
  int x,y;
  int status,money,life,waktu;
  int kodeArah;
  Kata nama;
  PrioQueueCustomer prioqueue;
  StackFood hand,tray;
  ArrOrder arrorder;
  Ruangan *room;
  MatTile M;
  char masukan[3];
  boolean aksiValid,pindahRuang;
  int nomorMeja;
  char kar;
  int val;
  Tile t;
  int pelanggan;
  int idMakanan;
  time_t saat;
  //ALGORITMA
  Inisiasi(&status,&nama,&money,&life,&waktu,&R,&P,&prioqueue,&hand,&tray,&arrorder);
  srand((unsigned) time(&saat));
  do {
    printf("\n0. Exit\n1. PlacePelayan\n2. Move\n3. CanOrder\n");
    printf("4. CanTake\n5. CanPut\n6. SetTile\n7. IsTableEmpty\n");
    printf("8. CanPlace\n9. Ordering\n10. Taking\n11. Placing\n");
    printf("12. GetTableTile\n13. GetMatTileSekarang\n14. GetRuanganSekarang\n");
    printf("15. PelangganKabur\n16. IndeksMeja\n17. SetTableEmpty\n");
    printf("18. GetTableNumber\nCHOICE= ");
    scanf("%d",&input);
    printf("\n");



    switch(input){
      case 0:
              printf("Bye!\n");
              break;
      case 1:
              PrintSurround(P);
              do {
                printf("input x,y: ");
                scanf("%d %d",&x,&y);
                if (!MT_IsIdxValid(x,y))
                  printf("invalid!\n");
              } while(!MT_IsIdxValid(x,y));
              PlacePelayan(&P, x, y,M);
              PrintSurround(P);
              break;
      case 2:
            PrintSurround(P);
            do {
              printf("masukan tujuan (u|r|d|l): ");
              scanf("%s",masukan);
              if (!(!strcmp(masukan,"u")||!strcmp(masukan,"d")||!strcmp(masukan,"r")||!strcmp(masukan,"l")))
                printf("invalid!\n");
            } while(!(!strcmp(masukan,"u")||!strcmp(masukan,"d")||!strcmp(masukan,"r")||!strcmp(masukan,"l")));
            if(masukan[0]=='G'){ //masukannya move
              if(masukan[1]=='U'){ //u
                kodeArah=1;
              }
              else if(masukan[1]=='R'){ //r
                kodeArah=2;
              }
              else if(masukan[1]=='D'){ //d
                kodeArah=3;
              }
              else if(masukan[1]=='L'){ //l
                kodeArah=4;
              }
              Move(&P,&R,kodeArah,&aksiValid,&pindahRuang);
            }
            PrintSurround(P);
            printf("aksiValid= %d\npindahRuang= %d\n",aksiValid,pindahRuang);
              break;
      case 3:
              MT_TulisMatriks(M);
              PrintSurround(P);
              printf("CanOrder= %d\n",nomorMeja!=0&&CanOrder(P,*room));
              break;
      case 4:
              MT_TulisMatriks(M);
              PrintSurround(P);
              printf("CanTake= %d\n",CanTake(P));
              break;
      case 5:
              MT_TulisMatriks(M);
              PrintSurround(P);
              printf("CanPut= %d\n",CanPut(P));
              break;
      case 6:
              printf("SetTile dipanggil saat PlacePelayan\n");
              PrintSurround(P);
              do {
                printf("input x,y: ");
                scanf("%d %d",&x,&y);
                if (!MT_IsIdxValid(x,y))
                  printf("invalid!\n");
              } while(!MT_IsIdxValid(x,y));
              PlacePelayan(&P, x, y,M);
              PrintSurround(P);
              break;
      case 7:
              MT_TulisMatriks(M);
              PrintSurround(P);
              if (nomorMeja!=0)
                printf("IsTableEmpty= %d\n",IsTableEmpty(nomorMeja,*room));
              else
                printf("Tidak dekat meja\n");
              break;
      case 8:
            MT_TulisMatriks(M);
            PrintSurround(P);
            pelanggan = (rand()%2)?2:4;
            printf("pelanggan= %d\n",pelanggan);
            if (nomorMeja!=0)
              printf("CanPlace= %d\n",CanPlace(pelanggan,P,*room));
            else
              printf("Tidak dekat meja\n");
            break;
      case 9:
            if (nomorMeja!=0) {
              if (CanPlace(pelanggan,P,*room)){
                Ordering(P,room,&idMakanan,nomorMeja);
                printf("idMakanan= %d\n",idMakanan);
              }
              else
                printf("cant't place\n");
            }
            else
              printf("Tidak dekat meja\n");
            break;
      case 10:

              break;
      case 11:

              break;
      case 12:

              break;
      case 13:
              M = GetMatTileSekarang(R);
              MT_TulisMatriks(M);
              break;
      case 14:
              room = GetRuanganSekarang(R);
              printf("nomor ruangan sekarang= %d\n",RoomID(*room));
              break;
      case 15:

              break;
      case 16:

              break;
      case 17:

              break;
      case 18:
              nomorMeja = GetTableNumber(P,*room);
              printf("nomor meja terdekat= %d\n",nomorMeja);
              break;
    }
  } while(input != 0);
  return 0;
}
