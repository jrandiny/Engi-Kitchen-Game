#include "prioqueue.h"
#include <stdio.h>

int main() {
  Queue q;
  infotype x;
  int maxel,prio,info;
  printf("maxel: "); scanf("%d",&maxel);
  CreateEmpty(&q,maxel);
  PrintQueue(q);
  while (1) {
    printf("\n1.Add\n2.Del\nPilihan: ");
    scanf("%d",&maxel);
    if (maxel==1) {
      printf("prio: ");
      scanf("%d",&prio);
      printf("info: ");
      scanf("%d",&info);
      Prio(x) = prio;
      Info(x) = info;
      Add(&q,x);
      printf("queue:\n");
      PrintQueue(q);
    } else if (maxel==2) {
      Del(&q,&x);
      printf("del= prio: %d info:%d\n",Prio(x),Info(x));
      printf("queue:\n");
      PrintQueue(q);
    }
  }
return 0;
}
