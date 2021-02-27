#! /bin/bash

# Simple test for the hide program.

run () {
  echo "$*"
  if $*
  then echo 'success'
  else echo 'error'
  fi
}

# The "here document" (between <<EOF and EOF) is text that is passed
# to hide as if it were typed from the keyboard.
run ./hide -encrypt <<EOF
attention home planet STOP prepare invasion stop earth is
ripe for the taking STOP cu soon FULL STOP
EOF

# Pipe the encrypted text through hide in decryption mode.
./hide -encrypt <<EOF | run ./hide -decrypt
attention home planet STOP prepare invasion stop earth is
ripe for the taking STOP cu soon FULL STOP
EOF

run ./hide -encrypt <<EOF
abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789 ~!@#$%^&*
EOF

exit 0
