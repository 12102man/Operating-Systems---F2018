if test ! -f numbers
then                                                 
    echo 0 > numbers
fi


for i in `seq 1 100`;
do

	LASTNUMBER=`tail -1 numbers`
	LASTNUMBER=$((LASTNUMBER+1))

	echo $LASTNUMBER >> numbers
done