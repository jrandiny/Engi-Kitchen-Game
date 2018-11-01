//File pelayan.h
/* merupakan tipe data pelayan */

typedef struct {
  Point posisi; //posisi Pelayan mengikuti baris dan kolom matriks
  Tile up;      // menyatakan karakter di posisi atas Pelayan
  Tile down;    // menyatakan karakter di posisi bawah Pelayan
  Tile left;    // menyatakan karakter di posisi kiri Pelayan
  Tile right;   // menyatakan karakter di posisi kanan Pelayan
} Pelayan;
//merupakan tipe Pelayan dengan posisi dan karakter disekitarnya

/* up down left right akan bernilai
    sesuai dengan definisi Tile di matRoom.h
*/
// *** SELEKTOR ***
#define Posisi(P) (P).posisi
#define Up(P) (P).up
#define Down(P) (P).down
#define Left(P) (P).left
#define Right(P) (P).right
