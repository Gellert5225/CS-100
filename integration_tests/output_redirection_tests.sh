#!/bin/bash
exec > >(tee "./integration_text.txt")

echo -e TEST RESULTS ARE FORWARDED INTO output.txt and output2.txt for comparison '\n\n'

echo -e Testing output redirection...'\n'
echo TEST_1: "ls > output.txt"
echo -e ' \t' 
cmd="ls > output.txt"

echo -e ' \t'----Expected----
eval $cmd
result="cat output.txt"
eval $result

echo -e ' \t'----Actual----
../rshell "integration_test" "ls > output2.txt"
result="cat output2.txt"
eval $result

echo -e '\n'

echo TEST_2: "tr a-z A-Z < names.txt > output.txt"
echo -e ' \t' 
cmd="tr a-z A-Z < ../names.txt > output.txt"

echo -e ' \t'----Expected----
eval $cmd
result="cat output.txt"
eval $result

echo -e ' \t'----Actual----
../rshell "integration_test" "tr a-z A-Z < ../names.txt > output2.txt"
result="cat output2.txt"
eval $result

echo -e '\n'

echo TEST_3: "echo plese redirect this > output.txt"
echo -e ' \t' 
cmd="echo plese redirect this > output.txt"

echo -e ' \t'----Expected----
eval $cmd
result="cat output.txt"
eval $result

echo -e ' \t'----Actual----
../rshell "integration_test" "echo plese redirect this > output2.txt"
result="cat output2.txt"
eval $result
