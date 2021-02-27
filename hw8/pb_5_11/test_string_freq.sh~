#! /bin/bash

# Simple test for the string_freq program.

run () {
  echo "$*"
  if $*
  then echo 'success'
  else echo 'error'
  fi
}

# A few valid inputs.
run ./string_freq <<EOF
At first glance, it seems that for S infinite we have to
examine uncountably many different infinite models in order
to find out whether a sentence is valid.  This is because
validity is a semantical notion, defined in terms of models.
However, as the reader surely knows, there is a simple and
uniform test by which we can find out in only finitely many
steps whether or not a sentence is valid.

This decision procedure for validity is based on a syntactical
notion, the notion of tautology.
EOF

run ./string_freq -s 8 <<EOF
attention home planet STOP prepare invasion STOP earth is
ripe for the taking STOP cu soon FULL STOP
EOF

run ./string_freq -s 10 <<EOF
Incurably insomniac, Anton Vowl turns on a light.
According to his watch it's only 12.20.  With a loud
and languorous sigh Vowl sits up, stuffs a pillow at
his back, draws his quilt up around his chin, picks up
his whodunit and idly scans a paragraph or two; but,
judging its plot impossibly difficult to follow in his
condition, its vocabulary too whimsically multisyllabic
for comfort, throws it away in disgust.
EOF

# Test empty set of strings.
run ./string_freq <<EOF
EOF

# Test usage message.
run ./string_freq -h <<EOF
abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789 ~!@#$%^&*
EOF

# These last runs test invalid input.
run ./string_freq -s <<EOF
not looking good
EOF

run ./string_freq -s -h <<EOF
not looking good either
EOF

run ./string_freq -s 16 -w <<EOF
one more dud
EOF

exit 0
