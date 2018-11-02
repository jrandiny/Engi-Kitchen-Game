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

void GRD_InsVFirst(GR_address *GRa, GRD_infotype X)
{
  /* KAMUS LOKAL */
  GRD_address pt;

  /* ALGORITMA */
  pt = GRD_Alokasi(X);
  if(pt!=Nil){
    GRD_Next(pt) = GR_Doors(*GRa);
    GR_Doors(*GRa) = pt;
  }

}
