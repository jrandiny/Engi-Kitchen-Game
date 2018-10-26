#include "queue.h"
#include "../../std.h"

void PrintQueue(Queue q);

int main() {
  Queue  q;
  int n;
  infotype x;
  printf("Masukan panjang max Q: ");
  scanf("%d",&n);
  CreateEmpty_Queue(&q,n);
  if (q.T != NULL)
  do {
    printf("\n1. Add\n2. Del\n3.Exit\nInput: ");
    scanf("%d",&n);
  } while (n!=1 && n!=2 && n!=3);
  while (n!=3) {
    if (n==1) { //add
      //!IsFull_Queue(q)
      printf("\nAdd: ");
      scanf("%d", &x);
      Add_Queue(&q,x);
      PrintQueue(q);
      printf("Q full\n");
    } else if (n==2) { //del
      Del_Queue(&q,&x);
      printf("\nDel: %d\n",x);
      PrintQueue(q);
    }
    do {
      printf("\n1. Add\n2. Del\n3.Exit\nInput: ");
      scanf("%d",&n);
    } while (n!=1 && n!=2 && n!=3);
  }
  printf("Exit\n");
  return 0;
}

void PrintQueue(Queue q){
  if (IsEmpty_Queue(q)) printf("Q kosong");
  else {
    printf("Q= |");
    // if (Tail(q)==Head(q)) printf(" %d |",q.T[1]);
    // else {
      for (int i=1;i<=MaxEl(q);i++){
        if (Tail(q)<Head(q)) {
          if (i<=Tail(q) || i>=Head(q)) {
            printf(" %d",q.T[i]);
          } else printf(" ~");
        } else {
          if (i<=Tail(q) && i>=Head(q)) {
            printf(" %d",q.T[i]);
          } else printf(" ~");
        }
        printf(" |");
      }
    // }
  }
  printf("\nHead    : %d\nInfoHead: %d",Head(q),InfoHead(q));
  printf("\nTail    : %d\nInfoTail: %d\n",Tail(q),InfoTail(q));
}
