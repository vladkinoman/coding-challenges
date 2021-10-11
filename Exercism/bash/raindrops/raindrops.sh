#!/usr/bin/env bash

main () {
  s=""
  if [ $(($1 % 3)) == 0 ]
  then
    s+="Pling"
  fi
  if [ $(($1 % 5)) == 0 ]
  then
    s+="Plang"
  fi
  if [ $(($1 % 7)) == 0 ]
  then
    s+="Plong"
  fi
  if [ -z "$s" ]
  then
    s+=$1
  fi
  echo $s
  return 0
}

main "$@"
