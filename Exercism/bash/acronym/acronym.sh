#!/usr/bin/env bash

main () {
  sresult=""
  set -f # disable the glob (noglob) to pass the last test
  arr=(${@})
  IFS='-*_'
  arr=(${arr[@]})
  for ((i=0; i < ${#arr[@]}; i++)); do
    arr[${i}]="${arr[${i}]^}"
    fstchar="${arr[${i}]:0:1}"
    sresult="$sresult$fstchar"
  done
  echo "$sresult"
  exit 0
}

main "$@"
