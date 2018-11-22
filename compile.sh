#!/bin/bash

gcc -o main main.c ADT/food/stacktfood.c ADT/point/point.c ADT/arrInt/arrInt.c ADT/arrOrder/order.c ADT/arrOrder/arrOrder.c ADT/food/food.c ADT/food/treeFood/treeFood.c ADT/space/space.c ADT/space/arrMeja/arrMeja.c ADT/space/matTile/matTile.c Modul/UI/UI.c Modul/eksternal/eksternal.c ADT/mesinkata/mesinkata.c ADT/mesinkata/mesinkar.c ADT/mesinkata/arrKata/arrKata.c ADT/space/grafRuangan/grafRuangan.c ADT/customer/prioQueueCustomer.c ADT/jam/jam.c -lncursesw
./main
