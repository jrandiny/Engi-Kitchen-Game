/* Kelompok  : UAS
   Nama file : grafRuangan.h
   Tanggal   : 2 November 2018
   Deskripsi : ADT Graf Ruangan dengan implementasi multilist*/

#ifndef GRAFRUANGAN_H
#define GRAFRUANGAN_H

#include "../../../std.h"
#include "../ruangan.h"
#include "../door.h"


/* Definisi Graf : */
/* Graf kosong : GR_First(GR) = Nil */
/* Setiap Node dengan address P dapat diacu
  GR_Info(P)  -> infonya (bertipe Ruangan)
  GR_Next(P)  -> Address node berikut
  GR_Doors(P) -> Alamat list pintu (bertindak sebagai terminal untuk vertex)
  */
/* Setiap Doors (terminal untuk vertex) dengan address P dapat diacu
  GRD_Info(P)   -> infonya (bertipe Door)
  GRD_Next(P)   -> Adress Door berikut
  GRD_Parent(P) -> Parent dari Door ini (Node induknya)
  GRD_To(P)     -> Tujuan dari Door ini (vertex ke Door lainnya)
*/
/* Elemen terakhir Graf : jika addressnya Last, maka Next(Last)=Nil */

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


/* SELEKTOR */
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
/* menghasilkan P, maka GR_Info(P)=X, GR_Next(P)=Nil GR_Doors(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void GR_Dealokasi (GR_address *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian GR_address P */

GRD_address GRD_Alokasi(GRD_infotype doors);
/* Mengalokasi Door sesuai input, jika berhasil mereturn addressnya, jika gagal Nil*/

void GRD_Dealokasi(GRD_address *P);
/* I.S. : *P teralokasi */
/* F.S. : *P terdealokasi*/

/* Manipulasi Data */
void GR_InsVFirst(GrafRuangan *GR, GR_infotype X);
/* I.S. : GR terinisialisasi, boleh kosong */
/* F.S. : Dimasukkan node ke GrafRuangan GR*/

void GRD_InsVFirst(GR_address *GRa, GRD_infotype X);
/* I.S. : GRa valid (alamat node)*/
/* F.S. : Dibuat door (bertindak sebagai terminal koneksi)*/

void GRD_InsertVDoors(GR_address *GR1, GR_address *GR2, GRD_infotype D1, GRD_infotype D2);
/* I.S. : GR1, GR2 alamat node valid, D1 dan D2 door valid */
/* F.S. : Terbentuk vertex antara GR1 dan GR2 menggunakan D1 dan D2*/

/* Search */
GR_address GR_Search(GrafRuangan GR, int roomSearch);
/* Mengembalikan alamat node yang mempunyai id roomSearch, jika tidak ada Nil*/

GRD_address GRD_Search(GRD_address pt, Point lokasi);
/* Mengembalikan alamat pintu pada node pt yang sesuai lokasi */

#endif
