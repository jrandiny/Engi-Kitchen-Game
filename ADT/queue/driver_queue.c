#include "queue.h"
#include "../../std.h"

void PrintQ(Queue q);

int main() {
  //kamus
  Queue q;
  int input; //input user
  infotype elmt; //elmt queue
  //algoritma
  printf("Masukan panjang max Q: ");
  scanf("%d",&input); //maxel
  CreateEmptyQ(&q,input);

  if (q.T != NULL) { //CreateEmptyQ berhasil
    printf("Terbentuk queue kosong dengan maksimum %d elemen\n",MaxElQ(q));

    do { //meminta input hingga benar
      printf("\n1. Add\n2. Del\n3.Exit\nInput: ");
      scanf("%d",&input);
    } while (input!=1 && input!=2 && input!=3);

    while (input!=3) {
      if (input==1) { //add
        if (!IsFullQ(q)) { //Q tidak penuh
          printf("\nAdd: ");
          scanf("%d", &elmt); //input elmt dari user
          AddQ(&q,elmt); //memasukkan ke queue
          PrintQueue(q); //print hasil queue
        } else { // Q penuh
          printf("Q is full\n");
        }
      } else if (input==2) { //del
        if (!IsEmptyQ(q)) { //Q tidak kosong
          DelQ(&q,&elmt); //mengeluarkan elmt dari queue
          printf("\nDel: %d\n",elmt); //menuliskan elmt yang di-del
          PrintQueue(q); //print hasil queue
        } else { //Q kosong
          printf("Q is empty\n");
        }
      }

      do { //meminta input hingga benar
        printf("\n1. Add\n2. Del\n3.Exit\nInput: ");
        scanf("%d",&input);
      } while (input!=1 && input!=2 && input!=3);

    } // input == 3 then exit
    printf("Exit\n");

  } else { //gagal alokasi
    printf("Queue gagal alokasi memori\n");
  }

  return 0;
}

void PrintQ(Queue q){
  if (IsEmptyQ(q)) printf("Q kosong");
  else {
    printf("Q= |");
    // if (Tail(q)==Head(q)) printf(" %d |",q.T[1]);
    // else {
      for (int i=1;i<=MaxElQ(q);i++){ // print semua elemt queue
        if (TailQ(q)<HeadQ(q)) { //tail dulu baru head
          if (i<=TailQ(q) || i>=HeadQ(q)) { //print semua elmt antara tail dan head
            printf(" %d",q.T[i]);
          } else printf(" ~"); //elmt kosong
        } else { //head dulu baru tail
          if (i<=TailQ(q) && i>=HeadQ(q)) { //print semua elmt antara head dan tail
            printf(" %d",q.T[i]);
          } else printf(" ~"); //elmt kosong
        }
        printf(" |"); //pemisah antar elemt
      }
    // }
  }
  //menampilkan alamat head dan isinya
  printf("\nHead    : %d\nInfoHead: %d",HeadQ(q),InfoHeadQ(q));
  //menamilkan alamat tail dan isinya
  printf("\nTail    : %d\nInfoTail: %d\n",TailQ(q),InfoTailQ(q));
}
