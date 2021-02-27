#! /bin/bash

run () {
  echo "$*"           # echo the command
  if $*               # execute it and test result
  then echo 'success'
  else echo 'error'
  fi
}


run ./shout_whisper s < in1.txt
run ./shout_whisper w < in2.txt
run ./shout_whisper s < in3.txt
run ./shout_whisper w < in3.txt

exit 0
