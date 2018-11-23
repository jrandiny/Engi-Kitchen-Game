#include "queue.h"

void Q_Print(Queue q){
  printf("\nQ= |");
  // if (Tail(q)==Head(q)) printf(" %d |",q.T[1]);
  // else {
    for (int i=1;i<=Q_MaxEl(q);i++){ // print semua elemt queue
      if (Q_Tail(q)<Q_Head(q)) { //tail dulu baru head
        if (i<=Q_Tail(q) || i>=Q_Head(q)) { //print semua elmt antara tail dan head
          printf(" %d",q.T[i]);
        } else printf(" ~"); //elmt kosong
      } else { //head dulu baru tail
        if (i<=Q_Tail(q) && i>=Q_Head(q)) { //print semua elmt antara head dan tail
          printf(" %d",q.T[i]);
        } else printf(" ~"); //elmt kosong
      }
      printf(" |"); //pemisah antar elemt
    }
  if (!Q_IsEmpty(q)) {
    //menampilkan alamat head dan isinya
    printf("\nHead    : %d\nInfoHead: %d",Q_Head(q),Q_InfoHead(q));
    //menamilkan alamat tail dan isinya
    printf("\nTail    : %d\nInfoTail: %d\n",Q_Tail(q),Q_InfoTail(q));
  } else printf("\n");
}

int main() {
  /* KAMUS LOKAL */
  Queue q;
  int input; //input user
  Q_infotype elmt; //elmt queue
  /* ALGORITMA */
  printf("Masukan panjang max Q: ");
  scanf("%d",&input); //maxel
  Q_CreateEmpty(&q,input);

  if (q.T != NULL) { //Q_NBElmt berhasil
    printf("Terbentuk queue kosong dengan maksimum %d elemen\n",Q_MaxEl(q));

    do { //meminta input hingga benar
      printf("\n1. Add\n2. Del\n3. Exit\nInput: ");
      scanf("%d",&input);
    } while (input!=1 && input!=2 && input!=3);

    while (input!=3) {
      if (input==1) { //add
        if (!Q_IsFull(q)) { //Q tidak penuh
          printf("\nAdd: ");
          scanf("%d", &elmt); //input elmt dari user
          Q_Add(&q,elmt); //memasukkan ke queue
          Q_Print(q); //print hasil queue
        } else { // Q penuh
          printf("\nQ is full\n");
        }
      } else if (input==2) { //del
        if (!Q_IsEmpty(q)) { //Q tidak kosong
          Q_Del(&q,&elmt); //mengeluarkan elmt dari queue
          printf("\nDel: %d\n",elmt); //menuliskan elmt yang di-del
          Q_Print(q); //print hasil queue
        } else { //Q kosong
          printf("\nQ is empty\n");
        }
      }

      do { //meminta input hingga benar
        printf("\n1. Add\n2. Del\n3. Exit\nInput: ");
        scanf("%d",&input);
      } while (input!=1 && input!=2 && input!=3);

    } // input == 3 then exit
    printf("\nExit\n");

  } else { //gagal alokasi
    printf("\nQueue gagal alokasi memori\n");
  }

  return 0;
}
