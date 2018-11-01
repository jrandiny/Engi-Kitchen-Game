typedef int IdxType;  /* type indeks */
typedef struct {
  int bangku;
  Point posisi;
  int status; //[0,1,2]
  /*
    0 : kosong
    1 : ada pelanggan belum order
    2 : ada pelanggan sudah order
  */
} Meja; /* type elemen tabel */
