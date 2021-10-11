#!/usr/bin/env bash

main () {
  if [[ "$#" != 2 ]]
  then
    echo "Usage: hamming.sh <string1> <string2>"
    return 1
  fi

  s1=$1
  s2=$2

  if [ ${#s1} != ${#s2} ]
  then
    echo "strands must be of equal length"
    return 1
  fi

  if [ -z "$s1" ]
  then
    echo "0"
    return 0
  fi

  count=0
  n=${#s1}
  for i in $(seq 0 $n)
  do
    if [ "${s1:i:1}" != "${s2:i:1}" ]
    then
      count=$((count+1))
    fi
  done

  echo "$count"
  return 0
}

main "$@"
