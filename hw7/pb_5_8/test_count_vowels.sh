#! /bin/bash

# Simple test for the count_vowels program.

run () {
  echo "$*"
  if $*
  then echo 'success'
  else echo 'error'
  fi
}

run ./count_vowels <<EOF
Adieu, Bo!
EOF
echo '-----------------------------------'

run ./count_vowels <<EOF
Incurably insomniac, Anton Vowl turns on a light.
According to his watch it's only 12.20.  With a loud
and languorous sigh Vowl sits up, stuffs a pillow at
his back, draws his quilt up around his chin, picks up
his whodunit and idly scans a paragraph or two; but,
judging its plot impossibly difficult to follow in his
condition, its vocabulary too whimsically multisyllabic
for comfort, throws it away in disgust.
EOF
echo '-----------------------------------'

run ./count_vowels <<EOF
Peiorem semper sequitur conclusio partem.
EOF
echo '-----------------------------------'

run ./count_vowels <<EOF
abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789 ~!@#$%^&*
EOF
echo '-----------------------------------'

run ./count_vowels <<EOF
EOF

exit 0
