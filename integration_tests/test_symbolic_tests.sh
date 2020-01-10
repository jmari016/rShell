echo hello || echo world && echo #comment
echo hello && echo world || echo lorem && echo ipsum
ls -a; echo hello && echo world
test -e ../rshell || echo “rshell executable missing, check submission instruction section of the specifications”
[ -e ../test ] || echo “names.txt file missing, check submission instruction section of the specifications”
test -d ../unit_tests || echo “unit_tests/ directory missing, check submission instruction section of the specifications”
exit
