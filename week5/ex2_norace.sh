#!/bin/bash 
           
#                                     
if test ! -f numbers
then
    echo 0 > numbers
fi


if ln numbers numbers.lock
	then                                                                    

	for i in `seq 1 100`;
	do
		LAST=`tail -1 numbers`
		LAST=$((LAST+1))

		echo $LAST >> numbers
	done
	rm numbers.lock
fi