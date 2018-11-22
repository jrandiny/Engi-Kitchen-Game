#include "order.h"

Order O_CreateOrder (int idMakanan, Kata namaMakanan, int noMeja)
/* Fungsi membuat tipe order dari parameter */
{
    //kamus
    Order O;
    
    /* ALGORITMA */
    O_IDMakanan(O) = idMakanan;
    O_NamaMakanan(O) = namaMakanan;
    O_NoMeja(O) = noMeja;
    return O;
}