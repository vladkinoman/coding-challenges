#!/usr/bin/env bash

main ()
{
    if [ "$#" -eq 1 ]
    then
        echo "Hello, $1"
    else
        echo "Usage: error_handling.sh <person>"
        return 1
    fi
    return 0
}

main "$@"


