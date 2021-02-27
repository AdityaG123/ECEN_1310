#! /bin/bash

# Simple test for the m_n_sum program.

# The opening line of a script starts with the two-character sequence known
# as "shebang."  It is a comment, but one that the shell interprets.  It
# specifies the interpreter to be used for the script; in this case /bin/bash.

# This function echoes and runs a command, printing "success" of "error"
# depending on whether the command returns 0 or not.  Note that $* is the
# list of all arguments passed to the function, which in this case contains
# the command to run and its arguments.
run () {
  echo "$*"           # echo the command
  if $*               # execute it and test result
  then echo 'success'
  else echo 'error'
  fi
}

run ./m_n_sum 3 5
run ./m_n_sum 1 2 3
run ./m_n_sum 3 2
run ./m_n_sum -2 4
run ./m_n_sum 1 r
# This is an Oh, not a zero!
run ./m_n_sum O 4

exit 0
