#include "space.h"
#include "../../Modul/eksternal/eksternal.h"
#include <string.h>

void Inisiasi(int *status, Kata *nama, int *money, int *life, int *waktu, Restoran *restoran, Pelayan *pelayan, PrioQueueCustomer *prioqueue, StackFood *hand, StackFood *tray, ArrOrder *arrorder){
  *nama = K_MakeKata("basic");
  LoadFile(status, nama, money, life, waktu,restoran,pelayan,prioqueue, hand, tray, arrorder);
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
  //ALGORITMA
  Inisiasi(&status,&nama,&money,&life,&waktu,&R,&P,&prioqueue,&hand,&tray,&arrorder);

  do {
    printf("\n1. PlacePelayan\n2. Move\n3. CanOrder\n");
    printf("4. CanTake\n5. CanPut\n6. SetTile\n7. IsTableEmpty\n");
    printf("8. CanPlace\n9. Ordering\n10. Taking\n11. Placing\n");
    printf("12. GetTableTile\n13. GetMatTileSekarang\n14. GetRuanganSekarang\n");
    printf("15. PelangganKabur\n16. IndeksMeja\n17. SetTableEmpty\n");
    printf("18. GetTableNumber\n19. Exit\nYour choice: ");
    scanf("%d",&input);
    printf("\n");



    switch(input){
      case 1:
              printf("PosAwal(x,y)= (%d,%d)\n",P_Baris(Pelayan_Posisi(P)),P_Kolom(Pelayan_Posisi(P)));
              do {
                printf("input x,y: ");
                scanf("%d %d",&x,&y);
                if (!MT_IsIdxValid(x,y))
                  printf("invalid!\n");
              } while(!MT_IsIdxValid(x,y));
              PlacePelayan(&P, x, y,M);
              printf("PosAkhir(x,y)= (%d,%d)\n",P_Baris(Pelayan_Posisi(P)),P_Kolom(Pelayan_Posisi(P)));
              break;
      case 2:
            printf("PosAwal(x,y)= (%d,%d)\n",P_Baris(Pelayan_Posisi(P)),P_Kolom(Pelayan_Posisi(P)));
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
            printf("PosAkhir(x,y)= (%d,%d)\n",P_Baris(Pelayan_Posisi(P)),P_Kolom(Pelayan_Posisi(P)));
            printf("aksiValid= %d\npindahRuang= %d\n",aksiValid,pindahRuang);
              break;
      case 3:
              MT_TulisMatriks(M);
              printf("\nPosSekarang(x,y)= (%d,%d)\n",P_Baris(Pelayan_Posisi(P)),P_Kolom(Pelayan_Posisi(P)));
              printf("CanOrder= %d\n",nomorMeja!=0&&CanOrder(P,*room));
              break;
      case 4:
              MT_TulisMatriks(M);
              printf("\nPosSekarang(x,y)= (%d,%d)\n",P_Baris(Pelayan_Posisi(P)),P_Kolom(Pelayan_Posisi(P)));
              printf("CanTake= %d\n",CanTake(P));
              break;
      case 5:
              MT_TulisMatriks(M);
              printf("\nPosSekarang(x,y)= (%d,%d)\n",P_Baris(Pelayan_Posisi(P)),P_Kolom(Pelayan_Posisi(P)));
              printf("CanPut= %d\n",CanPut(P));
              break;
      case 6:
              printf("SetTile dipanggil saat PlacePelayan\n");

              printf("PosAwal(x,y)= (%d,%d)\n",P_Baris(Pelayan_Posisi(P)),P_Kolom(Pelayan_Posisi(P)));
              printf("karAwal= %c\nvalAwal= %d\n",Karakter(Up(P)),Value(Up(P)));
              printf("karAwal= %c\nvalAwal= %d\n",Karakter(Right(P)),Value(Right(P)));
              printf("karAwal= %c\nvalAwal= %d\n",Karakter(Down(P)),Value(Down(P)));
              printf("karAwal= %c\nvalAwal= %d\n",Karakter(Left(P)),Value(Left(P)));
              do {
                printf("input x,y: ");
                scanf("%d %d",&x,&y);
                if (!MT_IsIdxValid(x,y))
                  printf("invalid!\n");
              } while(!MT_IsIdxValid(x,y));
              PlacePelayan(&P, x, y,M);
              printf("PosAkhir(x,y)= (%d,%d)\n",P_Baris(Pelayan_Posisi(P)),P_Kolom(Pelayan_Posisi(P)));
              printf("karAkhir= %c\nvalAkhir= %d\n",Karakter(Up(P)),Value(Up(P)));
              printf("karAkhir= %c\nvalAkhir= %d\n",Karakter(Right(P)),Value(Right(P)));
              printf("karAkhir= %c\nvalAkhir= %d\n",Karakter(Down(P)),Value(Down(P)));
              printf("karAkhir= %c\nvalAkhir= %d\n",Karakter(Left(P)),Value(Left(P)));
              break;
      case 7:

              break;
      case 8:

              break;
      case 9:

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
      case 19:
              printf("Bye!\n");
              break;
      default:
        printf("Wrong input, try again.\n");
    }
  } while(input != 19);
  return 0;
}
