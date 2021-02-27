#! /bin/bash

# Simple test for the medArray program.

run () {
  echo "$*"
  if $*
  then echo 'success'
  else echo 'error'
  fi
}

run ./medArray <<EOF
-3 15 -8 29 17
EOF

run ./medArray <<EOF
0 100 4 5
EOF

run ./medArray <<EOF
2 5 -3 56 -12 33 11
EOF

run ./medArray <<EOF
EOF

run ./medArray <<EOF
10 a 2
EOF

exit 0
