#include "prioqueue.h"

int main() {
  //kamus
  PrioQueue q;
  int input,prio,info; //input user
  PQ_infotype elmt; //elmt queue
  //algoritma
  printf("Masukan panjang max Q: ");
  scanf("%d",&input); //maxel
  PQ_CreateEmpty(&q,input);
  if (q.T != NULL) { //Q_NBElmt berhasil
    printf("Terbentuk queue kosong dengan maksimum %d elemen\n",PQ_MaxEl(q));

    do { //meminta input hingga benar
      printf("\n1. Add\n2. Del\n3. Exit\nInput: ");
      scanf("%d",&input);
    } while (input!=1 && input!=2 && input!=3);

    while (input!=3) {
      if (input==1) { //add
        if (!PQ_IsFull(q)) { //Q tidak penuh
          printf("prio: "); scanf("%d",&prio);
          printf("info: "); scanf("%d",&info);
          PQ_Prio(elmt) = prio;
          PQ_Info(elmt) = info;
          PQ_Add(&q,elmt);
          printf("queue:\n");
          PQ_PrintQueue(q);
        } else { // Q penuh
          printf("\nQ is full\n");
        }
      } else if (input==2) { //del
        if (!PQ_IsEmpty(q)) { //Q tidak kosong
          PQ_Del(&q,&elmt); //mengeluarkan elmt dari queue
          printf("del= prio:%d info:%d\n",PQ_Prio(elmt),PQ_Info(elmt));
          printf("queue:\n");
          PQ_PrintQueue(q);
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
