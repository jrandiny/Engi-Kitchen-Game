#include "queue.h"
#include <stdio.h>

void tulisQ(Queue q);

int main() {
  Queue  q;
  int n;
  infotype x;
  printf("Masukan panjang max Q: ");
  scanf("%d",&n);
  CreateEmpty(&q,n);
  while (!IsFull(q)) {
    do {
      printf("\n1. Add\n2. Del\nInput: ");
      scanf("%d",&n);
    } while (n!=1 && n!=2);
    if (n==1) {
      printf("\nAdd: ");
      scanf("%d", &x);
      Add(&q,x);
      tulisQ(q);
    } else {
      Del(&q,&x);
      printf("\nDel: %d\n",x);
      tulisQ(q);
    }
  }
  printf("Q full\n");
  return 0;
}

void tulisQ(Queue q){
  if (IsEmpty(q)) printf("Q kosong");
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
