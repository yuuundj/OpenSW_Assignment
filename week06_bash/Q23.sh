#! /bin/bash

factorial() {
    result=1
    if [ $1 -eq 0 ]; then
	result=1
    else
        for i in $(seq $1); do
	    result=$(( $result * $i ))
        done
    fi
    echo "Factorial of $1 is $result"
}

read -p "Enter a number: " NUM
factorial $NUM
