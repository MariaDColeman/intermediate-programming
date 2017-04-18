
#!/bin/sh


LAST=10

PASS=true

for ((i=1;i<=$LAST;i++)); do

    ./hw7b $(cat arg"$i"b.txt) > out.txt

    DIFF=$(diff out.txt out"$i"b.txt)

    if [ "$DIFF" != "" ]; then

       echo "7b: FAILED test $i!"

       PASS=false

       break

    fi

done

if [ $PASS = true ]; then

    echo "7b: PASSED all tests"
fi
