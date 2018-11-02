#include "grafRuangan.h"

boolean GR_IsEmpty(GrafRuangan GR)
{
  return GR_First(GR)==Nil;
}

void GR_CreateEmpty(GrafRuangan *GR)
{
  GR_First(*GR)=Nil;
}

GR_address GR_Alokasi (GR_infotype X)
{
  /* KAMUS LOKAL */
  GR_address pt;

  /* ALGORITMA */
  pt = (GR_address) malloc(sizeof(GR_Elmt));
  if(pt!=Nil){
    GR_Info(pt) = X;
    GR_Next(pt) = Nil;
    GR_Doors(pt) = Nil;
  }

  return pt;
}

void GR_Dealokasi(GR_address *P)
{
  /* KAMUS LOKAL */
  GRD_address pt;
  GRD_address prev;

  /* ALGORITMA */
  pt = GR_Doors(*P);

  if(pt!=Nil){
    while(pt!=Nil){
      prev = pt;
      pt=GRD_Next(pt);
      GRD_Dealokasi(&prev);
    }
  }

  free(*P);

  *P = Nil;
}

GRD_address GRD_Alokasi(GRD_infotype doors)
{
  /* KAMUS LOKAL */
  GRD_address pt;

  /* ALGORITMA */
  pt = (GRD_address) malloc(sizeof(GRD_Elmt));
  if(pt!=Nil){
    GRD_Info(pt) = doors;
    GRD_Next(pt) = Nil;
    GRD_To(pt) = Nil;
  }

  return pt;
}

void GRD_Dealokasi(GRD_address *P)
{
  free(*P);

  *P = Nil;
}

void GR_InsVFirst(GrafRuangan *GR, GR_infotype X)
{
  /* KAMUS LOKAL */
  GR_address pt;

  /* ALGORITMA */
  pt = GR_Alokasi(X);
  if(pt!=Nil){
    GR_Next(pt) = GR_First(*GR);
    GR_First(*GR) = pt;
  }
}

void GRD_InsertVDoors(GR_address *GR1, GR_address *GR2, GRD_infotype D1, GRD_infotype D2)
{
  /* KAMUS LOKAL */
  GRD_address pt1;
  GRD_address pt2;

  /* ALGORITMA */
  pt1 = GRD_Alokasi(D1);
  pt2 = GRD_Alokasi(D2);

  if(pt1==Nil && pt2!=Nil){
    GRD_Dealokasi(&pt2);
  }

  if(pt2==Nil && pt1!=Nil){
    GRD_Dealokasi(&pt1);
  }

  if(pt1!=Nil && pt2!=Nil){
    GRD_Parent(pt1) = *GR1;
    GRD_Parent(pt2) = *GR2;

    GRD_Next(pt1) = GR_Doors(*GR1);
    GRD_Next(pt2) = GR_Doors(*GR2);

    GR_Doors(*GR1) = pt1;
    GR_Doors(*GR2) = pt2;

    GRD_To(pt1) = pt2;
    GRD_To(pt2) = pt1;
  }
}

void GRD_InsVFirst(GR_address *GRa, GRD_infotype X)
{
  /* KAMUS LOKAL */
  GRD_address pt;

  /* ALGORITMA */
  pt = GRD_Alokasi(X);
  if(pt!=Nil){
    GRD_Parent(pt) = *GRa;
    GRD_Next(pt) = GR_Doors(*GRa);
    GR_Doors(*GRa) = pt;
  }

}

GR_address GR_Search(GrafRuangan GR, int roomSearch)
{
  /* KAMUS LOKAL */
  GR_address pt;
  boolean found;

  /* ALGORITMA */
  pt = GR_First(GR);
  while(!found && pt!=Nil){
    if(RoomID(GR_Info(pt))==roomSearch){
      found = true;
    }else{
      pt = GR_Next(pt);
    }
  }

  return pt;
}

GRD_address GRD_Search(GRD_address pt,Point lokasi)
{
  /* KAMUS LOKAL */
  boolean found;
  Point doorPoint;

  /* ALGORITMA */
  found = false;
  while(pt!=Nil && !found){
    doorPoint = DoorLocation(GRD_Info(pt));
    if((P_Absis(lokasi)==P_Absis(doorPoint))&&(P_Ordinat(lokasi)==P_Ordinat(doorPoint))){
      found = true;
    }else{
      pt = GRD_Next(pt);
    }

  }

  return pt;
}
