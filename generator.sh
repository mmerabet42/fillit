#!/bin/bash
c=1
n=1000
/bin/rm -f tests/*
while [ $c -le $n ]
do
	/bin/rm -f Tetriminos-generator/sample.fillit
	/bin/rm -f sample.fillit
	Tetriminos-generator/./tetri-gen $1 -f $(( ( RANDOM % 26 )  + 1 ))
	#if [ $c -ge 2 ]; then
	#/bin/rm -f tests/*
#fi
	cp sample.fillit tests/test$c
		echo "test$c : \c" && ./a.out "tests/test$c"
		let "c++"
done

/bin/rm -f Tetriminos-generator/sample.fillit
/bin/rm -f sample.fillit
