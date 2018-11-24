#!/bin/bash
mkdir -p bin
case $1 in
main)
	gcc -Wall -o main main.c ADT/food/stackFood/stacktfood.c ADT/point/point.c ADT/arrInt/arrInt.c ADT/order/order.c ADT/order/arrOrder/arrOrder.c ADT/food/food.c ADT/food/treeFood/treeFood.c ADT/space/space.c ADT/space/arrMeja/arrMeja.c ADT/space/matTile/matTile.c Modul/UI/UI.c Modul/eksternal/eksternal.c ADT/mesinkata/mesinkata.c ADT/mesinkata/mesinkar.c ADT/mesinkata/arrKata/arrKata.c ADT/space/grafRuangan/grafRuangan.c ADT/customer/prioQueueCustomer.c -lncursesw
  mv main bin/main
  ./bin/main
	;;
test)
	case $2 in
  UI)
    cd Modul/UI
    gcc -Wall -o test-ui UI.c UItest.c ../../ADT/customer/prioQueueCustomer.c ../../ADT/space/matTile/matTile.c ../../ADT/mesinkata/mesinka*.c ../../ADT/mesinkata/arrKata/arrKata.c ../../ADT/food/stackFood/stacktfood.c ../../ADT/food/food.c ../../ADT/food/treeFood/treeFood.c ../../ADT/order/arrOrder/arrOrder.c ../../ADT/order/order.c -lncursesw
    mv test-ui ../../bin/test-ui
    cd ../..
    ./bin/test-ui
    ;;
  eksternal)
    cd Modul/eksternal
    gcc -Wall -o eksternaltes eksternaltes.c ../../ADT/point/point.c ../../ADT/arrInt/arrInt.c ../../ADT/space/space.c ../../ADT/space/arrMeja/arrMeja.c ../../ADT/space/matTile/matTile.c eksternal.c ../../ADT/mesinkata/mesinkata.c ../../ADT/mesinkata/mesinkar.c ../../ADT/mesinkata/arrKata/arrKata.c ../../ADT/space/grafRuangan/grafRuangan.c ../../ADT/customer/prioQueueCustomer.c ../../ADT/food/treeFood/treeFood.c ../../ADT/food/food.c ../../ADT/food/stackFood/stacktfood.c ../../ADT/order/arrOrder/arrOrder.c ../../ADT/order/order.c -lncurses
    mv eksternaltes ../../bin/test-eksternal
    cd ../..
    ./bin/test-eksternal
    ;;
  grafRuangan)
    cd ADT/space/grafRuangan
    gcc -Wall driverGraf.c grafRuangan.c ../matTile/matTile.c ../arrMeja/arrMeja.c ../../point/point.c
    mv a.out ../../../bin/test-grafRuangan
    cd ../../..
    ./bin/test-grafRuangan
    ;;
  space)
    cd ADT/space
		gcc -Wall -o mspace mspace.c ../food/stackFood/stacktfood.c ../food/treeFood/treeFood.c ../point/point.c ../arrInt/arrInt.c ../order/order.c ../order/arrOrder/arrOrder.c ../food/food.c space.c arrMeja/arrMeja.c matTile/matTile.c  ../../Modul/eksternal/eksternal.c ../mesinkata/mesinkata.c ../mesinkata/mesinkar.c ../mesinkata/arrKata/arrKata.c grafRuangan/grafRuangan.c ../customer/prioQueueCustomer.c
    mv mspace ../../bin/test-space
    cd ../..
    ./bin/test-space
    ;;
  arrInt)
    cd ADT/arrInt
    gcc -Wall arrInt.c driverArrInt.c
    mv a.out ../../bin/test-arrInt
    cd ../..
    ./bin/test-arrInt
    ;;
  stackFood)
    cd ADT/food/stackFood
    gcc -Wall stacktfood.c driverStacktfood.c
    mv a.out ../../../bin/test-stackFood
    cd ../../..
    ./bin/test-stackFood
    ;;
  PQC)
    cd ADT/customer
    gcc -Wall driverPrioQueueCustomer.c prioQueueCustomer.c
    mv a.out ../../bin/test-PQC
    cd ../..
    ./bin/test-PQC
    ;;
  treeFood)
    cd ADT/food/treeFood
    gcc -Wall treeFood.c driverTree.c ../../mesinkata/mesinkata.c ../../mesinkata/mesinkar.c ../food.c
    mv a.out ../../../bin/test-treeFood
    cd ../../..
    ./bin/test-treeFood
    ;;
  mesinkata)
    cd ADT/mesinkata
    gcc -Wall mesinkata.c mesinkar.c driverMesinkata.c
    mv a.out ../../bin/test-mesinkata
    cd ../..
    ./bin/test-mesinkata
    ;;
  arrOrder)
    cd ADT/order/arrOrder
    gcc -Wall driverArrOrder.c arrOrder.c ../order.c ../../mesinkata/mesinkata.c ../../mesinkata/mesinkar.c
    mv a.out ../../../bin/test-arrOrder
    cd ../../..
    ./bin/test-arrOrder
    ;;
  arrKata)
    cd ADT/mesinkata/arrKata
    gcc -Wall arrKata.c driverArrKata.c
    mv a.out ../../../bin/test-arrKata
    cd ../../..
    ./bin/test-arrKata
    ;;
  point)
    cd ADT/point
    gcc -Wall driverPoint.c  point.c
    mv a.out ../../bin/test-point
    cd ../..
    ./bin/test-point
    ;;
  arrMeja)
    cd ADT/space/arrMeja
    gcc -Wall arrMeja.c driverArrMeja.c  ../../point/point.c
    mv a.out ../../../bin/test-arrMeja
    cd ../../..
    ./bin/test-arrMeja
    ;;
  matTile)
    cd ADT/space/matTile
    gcc -Wall driverMatTile.c matTile.c
    mv a.out ../../../bin/test-matTile
    cd ../../..
    ./bin/test-matTile
    ;;
  treeFood)
    cd ADT/food/treeFood
    gcc -Wall mtree.c treeFood.c ../../mesinkata/mesinkar.c ../../mesinkata/mesinkata.c ../food.c
    mv a.out ../../../bin/test-treeFood
    cd ../../..
    ./bin/test-treeFood
    ;;
	jam)
		cd ADT/jam
		gcc -Wall mjam.c. jam.c
		mv a.out ../../bin/test/test-jam
		cd ../..
		./bin/test-jam
  *)

    echo "Unimplemented tester '$2'"
    echo ""
    echo "Implemented tester"
    echo "UI                  - Modul UI"
    echo "eksternal           - Modul eksternal"
    echo "arrInt              - ADT Array Integer"
    echo "arrKata             - ADT Array Kata"
    echo "arrMeja             - ADT Array Meja"
    echo "arrOrder            - ADT Array Order"
    echo "grafRuangan         - ADT Graf Ruangan"
    echo "mesinkata           - ADT Mesin Kata"
    echo "point               - ADT Point"
    echo "PQC                 - ADT Priority Queue Customer"
    echo "space               - ADT Space"
    echo "stackFood           - ADT Stack Food"
    echo "treeFood            - ADT Tree Food"
		echo "jam 								- ADT Jam"

    ;;

  esac
	;;
*)
	echo "Usage"
  echo "run <argument>"
  echo "Supported arguments"
  echo "main        - Main Program"
  echo "test <type> - Tester"
	;;
esac
