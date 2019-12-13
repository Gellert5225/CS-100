#!/bin/bash
exec > >(tee "./integration_text.txt")

echo -e TEST RESULTS ARE FORWARDED INTO integration_test.txt '\n\n'

echo -e Testing input redirection...'\n'
echo TEST_1: "cat < names.txt"
echo -e ' \t' 
cmd="cat < ../names.txt"

echo -e ' \t'----Expected----
eval $cmd

echo -e ' \t'----Actual----
../rshell "integration_test" "cat < ../names.txt"

echo -e '\n'

echo TEST_2: "tr a-z A-Z < names.txt"
echo -e ' \t' 
cmd="tr a-z A-Z < ../names.txt"

echo -e ' \t'----Expected----
eval $cmd

echo -e ' \t'----Actual----
../rshell "integration_test" "tr a-z A-Z < ../names.txt"

echo -e '\n'

echo TEST_3: "cat < wrong.txt"
echo -e ' \t' 
cmd="cat < wrong.txt"

echo -e ' \t'----Expected----
eval $cmd

echo -e ' \t'----Actual----
../rshell "integration_test" "cat < wrong.txt"