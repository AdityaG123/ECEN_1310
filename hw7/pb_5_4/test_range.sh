#! /bin/bash
run() {
    echo "$*"
    if $*
    then echo 'success'
    else echo 'error'
    fi
}

run ./range < in1.txt
run ./range < in2.txt
run ./range < in3.txt
exit 0
