#!/bin/bash
c=1
n=100
while [ $c -le $n ]
do
	perl generator.perl $(( ( RANDOM % 26 )  + 1 )) 2 > "tests/test$c"
		echo "test$c : \c" && ./a.out "tests/test$c"
			(( c++ ))
		done
