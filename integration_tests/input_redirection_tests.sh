cat < ../names.txt
cat < src/main.cpp
cat < input_redirection_tests_rshell.sh > test1.txt
cat < input_redirection_tests.sh >> test2.txt

rm test1.txt
rm test2.txt
exit
