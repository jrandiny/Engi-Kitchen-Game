#ifndef GRAFRUANGAN_H
#define GRAFRUANGAN_H

#include "../../../std.h"
#include "../ruangan.h"
#include "../door.h"

typedef Ruangan GR_infotype;
typedef Door GRD_infotype;

typedef struct tElmtgraf *GR_address;
typedef struct tElmtdoor *GRD_address;

typedef struct tElmtdoor{
  GRD_infotype info;
  GRD_address next;
  GRD_address to;
  GR_address parent;
} GRD_Elmt;

typedef struct tElmtgraf {
  GR_infotype info;
  GR_address next;
  GRD_address doors;
} GR_Elmt;

typedef struct{
  GR_address First;
} GrafRuangan;


#define GR_First(GR) (GR).First
#define GR_Info(P) (P)->info
#define GR_Doors(P) (P)->doors
#define GR_Next(P) (P)->next

#define GRD_Info(PD) (PD)->info
#define GRD_Next(PD) (PD)->next
#define GRD_To(PD) (PD)->to
#define GRD_Parent(PD) (PD)->parent

/* PROTOTYPE */
/****************** TEST GRAF KOSONG ******************/
boolean GR_IsEmpty (GrafRuangan GR);
/* Mengirim true jika graf kosong */

/****************** PEMBUATAN GRAF KOSONG ******************/
void GR_CreateEmpty (GrafRuangan *GR);
/* I.S. sembarang             */
/* F.S. Terbentuk graf kosong */

/****************** Manajemen Memori ******************/
GR_address GR_Alokasi (GR_infotype X);
/* Mengirimkan GR_address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka GR_address tidak nil, dan misalnya */
/* menghasilkan P, maka GR_Info(P)=X, GR_Next(P)=Nil GR_Doors=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void GR_Dealokasi (GR_address *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian GR_address P */

GRD_address GRD_Alokasi(GRD_infotype doors);

void GRD_Dealokasi(GRD_address *P);

void GR_InsVFirst(GrafRuangan *GR, GR_infotype X);

void GRD_InsVFirst(GR_address *GRa, GRD_infotype X);

void GRD_InsertVDoors(GR_address *GR1, GR_address *GR2, GRD_infotype D1, GRD_infotype D2);


#endif
