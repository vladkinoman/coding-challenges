#!/usr/bin/env bash


number_of_digits () {
    local n=$1
    local amount=0
    while [[ $n -ne 0 ]]; do
        ((amount++))
        ((n /= 10))
    done
    echo $amount
}

is_armstrong_number () {
    local n=$1
    local candidate=$n
    local sum=0
    local digits=0
    digits=$(number_of_digits "$n")
    while [[ $n -ne 0 ]]; do
        ((sum += (n % 10) ** digits))
        ((n /= 10))
    done
    [[ sum -eq candidate ]] && echo "true" || echo "false"
}

main () {
    if [ "$#" -ne 1 ]
    then
        echo "Usage: armstrong_numbers.sh <number>"
        exit 1
    fi

    is_armstrong_number "$1"
    exit 0
}

main "$@"
