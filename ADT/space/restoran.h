//File : restoran.h
/* merupakan tipe data restoran */

typedef struct {
  int roomNow;
  ArrRuangan ruangan; //array yang berisi ruangan
  //List hubungan; //mapping
} Restoran;
//tipe Restoran dengan 4 ruangan berukuran 8x8
// dengan terdapat 4 pintu yang menghubungkan keempat ruangan tersebut
/*
  room1 (5,8) -> (2,1) room2
  room1 (8,5) -> (1,5) room4
  room2 (8,5) -> (1,5) room3
  room3 (2,1) -> (5,8) room4
*/
#define RoomNow(R) (R).roomNow
#define Ruangan(R) (R).ruangan
