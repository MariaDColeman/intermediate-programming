#!/bin/sh                                                                                               


LAST=$1

PASS=true

for ((i=1;i<=$LAST;i++)); do

    ./hw7a $(cat arg"$i"a.txt) > out.txt

    DIFF=$(diff out.txt out"$i"a.txt)

    if [ "$DIFF" != "" ]; then

       echo "7a: FAILED test $i!"

       PASS=false

       break

    fi

done

if [ $PASS = true ]; then

    echo "7a: PASSED all tests"
fi
