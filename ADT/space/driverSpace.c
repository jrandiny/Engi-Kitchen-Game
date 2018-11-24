/* Kelompok  : UAS
   Nama file : driverSpace.c
   Deskripsi : Driver ADT untuk tipe space*/

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
  /* KAMUS */
  Pelayan P;
  Restoran R;
  int input;
  int i;
  int x,y;
  int status,money,life,waktu;
  int kodeArah;
  Kata nama;
  PrioQueueCustomer prioqueue;
  StackFood hand,tray;
  ArrOrder arrorder;
  Ruangan *room;
  char masukan[3];
  boolean aksiValid,pindahRuang;
  int nomorMeja;
  int pelanggan;
  int idMakanan;
  ArrInt mejaKabur;
  time_t saat;

  /* ALGORITMA */
  Inisiasi(&status,&nama,&money,&life,&waktu,&R,&P,&prioqueue,&hand,&tray,&arrorder);
  srand((unsigned) time(&saat));
  do {
    printf("\n0. Exit\n1. PlacePelayan\n2. Move\n3. CanOrder\n");
    printf("4. CanTake\n5. CanPut\n6. SetTile\n7. IsTableEmpty\n");
    printf("8. CanPlace\n9. Ordering\n10. Taking\n11. Placing\n");
    printf("12. GetMatTileSekarang\n13. GetRuanganSekarang\n14. PelangganKabur\n");
    printf("15. IndeksMeja\n16. SetTableEmpty\n17. GetTableNumber\nCHOICE= ");
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
              PlacePelayan(&P, x, y,GetMatTileSekarang(R));
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
              if(masukan[0]=='u'){ //u
                kodeArah=1;
              }
              else if(masukan[0]=='r'){ //r
                kodeArah=2;
              }
              else if(masukan[0]=='d'){ //d
                kodeArah=3;
              }
              else if(masukan[0]=='l'){ //l
                kodeArah=4;
              }
              Move(&P,&R,kodeArah,&aksiValid,&pindahRuang);
            PrintSurround(P);
            printf("aksiValid= %d\npindahRuang= %d\n",aksiValid,pindahRuang);
              break;
      case 3:
              MT_TulisMatriks(GetMatTileSekarang(R));
              PrintSurround(P);
              printf("CanOrder= %d\n",nomorMeja!=0&&CanOrder(P,*room));
              break;
      case 4:
              MT_TulisMatriks(GetMatTileSekarang(R));
              PrintSurround(P);
              printf("CanTake= %d\n",CanTake(P));
              break;
      case 5:
              MT_TulisMatriks(GetMatTileSekarang(R));
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
              PlacePelayan(&P, x, y,GetMatTileSekarang(R));
              PrintSurround(P);
              break;
      case 7:
              MT_TulisMatriks(GetMatTileSekarang(R));
              PrintSurround(P);
              if (nomorMeja!=0)
                printf("IsTableEmpty= %d\n",IsTableEmpty(nomorMeja,*room));
              else
                printf("Tidak dekat meja\n");
              break;
      case 8:
            MT_TulisMatriks(GetMatTileSekarang(R));
            PrintSurround(P);
            pelanggan = (rand()%2)?2:4;
            printf("pelanggan= %d\n",pelanggan);
            if (nomorMeja!=0)
              printf("CanPlace= %d\n",CanPlace(pelanggan,P,*room));
            else
              printf("Tidak dekat meja\n");
            break;
      case 9:
            MT_TulisMatriks(GetMatTileSekarang(R));
            PrintSurround(P);
            if (nomorMeja!=0) {
              Ordering(P,room,&idMakanan,nomorMeja);
              printf("idMakanan= %d\n",idMakanan);
            }
            else
              printf("Tidak dekat meja\n");
            break;
      case 10:
            MT_TulisMatriks(GetMatTileSekarang(R));
            PrintSurround(P);
            if (CanTake(P)){
              printf("Id yang diambil= %d\n",Taking(P));
            } else {
              printf("cant take\n");
            }
              break;
      case 11:
              MT_TulisMatriks(GetMatTileSekarang(R));
              PrintSurround(P);
              if (nomorMeja!=0) {
                pelanggan = (rand()%2)?2:4;
                printf("pelanggan= %d\n",pelanggan);
                if (CanPlace(pelanggan,P,*room)){
                  do{
                    printf("waktu now= %d\nwaktu keluar= ",waktu);
                    scanf("%d",&i);
                    if (i <= waktu)
                      printf("waktu harus lebih besar dari %d\n",waktu);
                  }while(i <= waktu);
                  Placing(pelanggan,i, &P, room);
                  MT_TulisMatriks(GetMatTileSekarang(R));
                  PrintSurround(P);
                }
                else
                  printf("cant't place\n");
              }
              else
                printf("Tidak dekat meja\n");
              break;
      case 12:
              MT_TulisMatriks(GetMatTileSekarang(R));
              break;
      case 13:
              room = GetRuanganSekarang(R);
              printf("nomor ruangan sekarang= %d\n",RoomID(*room));
              break;
      case 14:
              do{
                printf("waktu tadi= %d\nwaktu sekarang= ",waktu);
                scanf("%d",&i);
                if (i <= waktu)
                  printf("waktu harus lebih besar dari %d\n",waktu);
              }while(i <= waktu);
              waktu = i;
              PelangganKabur(waktu,&P,&R,&i,&mejaKabur);
              printf("jumlah kabur= %d\n",i);
              for (i=AI_GetFirstIdx(mejaKabur);i<=AI_GetLastIdx(mejaKabur);i++){
                printf("%d. meja nomor %d\n",i,AI_Elmt(mejaKabur, i));
              }
              break;
      case 15:
              do{
                printf("tuliskan nomor meja= ");
                scanf("%d",&i);
                if (i>AM_GetLastIdx(Meja(*room))&&i<AM_GetFirstIdx(Meja(*room)))
                  printf("indeks out of bound\n");
              } while(i>AM_GetLastIdx(Meja(*room))&&i<AM_GetFirstIdx(Meja(*room)));
              printf("posisi meja= ");
              P_TulisPoint(IndeksMeja(i, *room));
              printf("\n");
              break;
      case 16:
              MT_TulisMatriks(GetMatTileSekarang(R));
              do{
                printf("tuliskan nomor meja= ");
                scanf("%d",&i);
                if (i>AM_GetLastIdx(Meja(*room))&&i<AM_GetFirstIdx(Meja(*room)))
                  printf("indeks out of bound\n");
              } while(i>AM_GetLastIdx(Meja(*room))&&i<AM_GetFirstIdx(Meja(*room)));
              SetTableEmpty(i,room);
              MT_TulisMatriks(GetMatTileSekarang(R));
              break;
      case 17:
              nomorMeja = GetTableNumber(P,*room);
              printf("nomor meja terdekat= %d\n",nomorMeja);
              break;
    }
  } while(input != 0);
  return 0;
}
