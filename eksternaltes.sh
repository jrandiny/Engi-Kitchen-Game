#!/bin/bash

gcc -o eksternaltes eksternaltes.c ADT/point/point.c ADT/arrInt/arrInt.c ADT/space/space.c ADT/space/arrMeja/arrMeja.c ADT/space/matTile/matTile.c Modul/UI/UI.c Modul/eksternal/eksternal.c ADT/mesinkata/mesinkata.c ADT/mesinkata/mesinkar.c ADT/mesinkata/arrKata/arrKata.c ADT/space/grafRuangan/grafRuangan.c ADT/customer/prioqueuecustomer.c ADT/food/treeFood/treeFood.c ADT/food/food.c ADT/food/stacktfood.c ADT/arrOrder/arrOrder.c ADT/arrOrder/order.c -lncurses
