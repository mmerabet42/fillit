#!/bin/bash
c=1
n=10
while [ $c -le $n ]
do
	Tetriminos-generator/./tetri-gen $1 -f $(( ( RANDOM % 26 )  + 1 ))
	if [ $c -ge 2 ]; then
	/bin/rm -f tests/*
fi
	cp sample.fillit tests/test$c
		echo "test$c : \c" && ./a.out "tests/test$c"
			(( c++ ))
done

/bin/rm -f sample.fillit
