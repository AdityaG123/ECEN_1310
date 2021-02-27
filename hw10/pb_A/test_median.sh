#! /bin/bash

# Simple test for the median program.

run () {
  echo "$*"
  if $*
  then echo 'success'
  else echo 'error'
  fi
}

run ./median <<EOF
-3 15 -8 29 17
EOF

run ./median <<EOF
0 100 4 5
EOF

run ./median <<EOF
2 5 -3 56 -12 33 11
EOF

run ./median <<EOF
EOF

run ./median <<EOF
10 a 2
EOF

exit 0
