#include "grafRuangan.h"
#include <stdio.h>
#include "../matTile/matTile.h"
#include "../arrMeja/arrMeja.h"

void printGraf(GrafRuangan GR);

void printGrafInfo(GR_address g);

int main(){
  /* KAMUS */
  GrafRuangan GR;
  int opsi;
  GR_infotype grinfo;
  GRD_infotype grdinfo,grdinfo2;
  int count;
  MatTile mt;
  ArrMeja am;

  GR_address pt,pt2;
  GRD_address ptd;

  Point p,p2;
  int rid;

  int opsi2;
  int opsi3;
  int opsi4;
  int opsi5;

  /* ALGORITMA */
  MT_MakeMatriks(5,5, &mt);
  Room(grinfo) = mt;
  AM_CreateEmpty(&am);
  Meja(grinfo) = am;

  RoomID(grinfo) = 1;

  GR_CreateEmpty(&GR);
  count = 0;

  do {
    printGraf(GR);
    printf("\n");
    printf("Menu\n");
    printf("0) Exit\n1) GR_InsVFirst\n2) GRD_InsVFirst\n3) Search\nChoice = ");
    scanf("%d",&opsi);

    switch (opsi) {
      case 1:
        printf("Room id = ");
        scanf("%d",&opsi2);
        RoomID(grinfo) = opsi2;
        GR_InsVFirst(&GR,grinfo);
        count++;
        break;
      case 2:
        if(count>=2){
          printf("X1 = ");
          scanf("%d",&opsi2);
          printf("Y1 = ");
          scanf("%d",&opsi3);

          printf("X2 = ");
          scanf("%d",&opsi4);
          printf("Y2 = ");
          scanf("%d",&opsi5);

          pt = GR_First(GR);
          pt2 = GR_Next(pt);

          P_Absis(DoorLocation(grdinfo)) = opsi2;
          P_Ordinat(DoorLocation(grdinfo)) = opsi3;

          P_Absis(DoorLocation(grdinfo2)) = opsi4;
          P_Ordinat(DoorLocation(grdinfo2)) = opsi5;

          GRD_InsertVDoors(&pt,&pt2,grdinfo,grdinfo2);

        }else{
          printf("Butuh minimal 2 ruangan\n");
        }
        break;
      case 3:
        printf("Search room id = ");
        scanf("%d",&opsi2);

        pt = GR_Search(GR, opsi2);
        if(pt!=Nil){
          printf("Found\n");

          printGrafInfo(pt);

          if(GR_Doors(pt) != Nil){
            printf("Search door (x y)= ");
            scanf("%d %d",&opsi2,&opsi3);

            P_Absis(p) = opsi2;
            P_Ordinat(p) = opsi3;

            ptd = GRD_Search(GR_Doors(pt), p);

            if(ptd!=Nil){
              printf("Found\n");

              p = DoorLocation(GRD_Info(ptd));
              p2 = DoorLocation(GRD_Info(GRD_To(ptd)));
              rid = RoomID(GR_Info(GRD_Parent(GRD_To(ptd))));
              printf("(%d,%d) -> %d (%d,%d)\n",P_Absis(p),P_Ordinat(p),rid,P_Absis(p2),P_Ordinat(p2));

            }else{
              printf("Not found door \n");
            }
          }



        }else{
          printf("Not found\n");
        }

        break;
    }


  } while(opsi!=0);
  GR_CreateEmpty(&GR);


  return 0;
}

void printGraf(GrafRuangan GR)
{
  /* KAMUS LOKAL */
  GR_address pt;
  Ruangan r;

  /* ALGORITMA */
  printf("\nIsi Graf\n");

  if(GR_IsEmpty(GR)){
    printf("Kosong \n");
  }else{
    pt = GR_First(GR);
    do {
      printGrafInfo(pt);
      pt = GR_Next(pt);
    } while(pt!=Nil);
  }

  printf("\n");

}

void printGrafInfo(GR_address pt){
  /* KAMUS LOKAL */
  GRD_address ptd;
  Point p,p2;
  int rid;

  /* ALGORITMA */
  printf("\nRuangan\n");
  printf("Id = %d\n",RoomID(GR_Info(pt)));
  if(GR_Doors(pt)!=Nil){
    ptd = GR_Doors(pt);
    printf("Pintu:\n");
    do {
      p = DoorLocation(GRD_Info(ptd));
      p2 = DoorLocation(GRD_Info(GRD_To(ptd)));
      rid = RoomID(GR_Info(GRD_Parent(GRD_To(ptd))));
      // rid = 1;
      printf("(%d,%d) -> %d (%d,%d)\n",P_Absis(p),P_Ordinat(p),rid,P_Absis(p2),P_Ordinat(p2));
      ptd = GRD_Next(ptd);
    } while(ptd!=Nil);
  }
}
