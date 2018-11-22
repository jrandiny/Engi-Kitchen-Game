#!/bin/bash
mkdir -p bin
case $1 in
main)
	gcc -Wall -o main main.c ADT/food/stacktfood.c ADT/point/point.c ADT/arrInt/arrInt.c ADT/arrOrder/order.c ADT/arrOrder/arrOrder.c ADT/food/food.c ADT/food/treeFood/treeFood.c ADT/space/space.c ADT/space/arrMeja/arrMeja.c ADT/space/matTile/matTile.c Modul/UI/UI.c Modul/eksternal/eksternal.c ADT/mesinkata/mesinkata.c ADT/mesinkata/mesinkar.c ADT/mesinkata/arrKata/arrKata.c ADT/space/grafRuangan/grafRuangan.c ADT/customer/prioQueueCustomer.c ADT/jam/jam.c -lncursesw
  mv main bin/main
  ./bin/main
	;;
test)
	case $2 in
  ui)
    cd Modul/UI
    gcc -Wall -o test-ui UI.c UItest.c ../../ADT/customer/prioQueueCustomer.c ../../ADT/space/matTile/matTile.c ../../ADT/mesinkata/mesinka*.c ../../ADT/mesinkata/arrKata/arrKata.c ../../ADT/food/stacktfood.c ../../ADT/food/food.c ../../ADT/food/treeFood/treeFood.c ../../ADT/arrOrder/arrOrder.c ../../ADT/arrOrder/order.c -lncursesw
    mv test-ui ../../bin/test-ui
    cd ../..
    ./bin/test-ui
    ;;
  grafRuangan)
    cd ADT/space/grafRuangan
    gcc -Wall mgraf.c grafRuangan.c ../matTile/matTile.c ../arrMeja/arrMeja.c ../../point/point.c
    mv a.out ../../../bin/test-grafRuangan
    cd ../../..
    ./bin/test-grafRuangan
    ;;
  space)
    cd ADT/space
    gcc -Wall mspace.c space.c arrMeja/arrMeja.c grafRuangan/grafRuangan.c matTile/matTile.c ../point/point.c -o mspace
    mv mspace ../../bin/test-space
    cd ../..
    ./bin/test-space
    ;;
  arrOrder)
    cd ADT/arrOrder
    gcc -Wall driverArrOrder.c arrOrder.c order.c ../mesinkata/mesinkata.c ../mesinkata/mesinkar.c
    mv a.out ../../bin/test-arrOrder
    cd ../..
    ./bin/test-arrOrder
    ;;
  *)
    echo "Unimplemented tester '$2'"
    echo ""
    echo "Implemented tester"
    echo "ui                  - Modul UI"
    echo "arrOrder            - ADT Array Order"
    echo "grafRuangan         - ADT Graf Ruangan"
    ;;
    
  esac
	;;
*)
	echo "Usage"
  echo "compile <argument>"
  echo "Supported arguments"
  echo "main        - Main Program"
  echo "test <type> - Tester"
	;;
esac
