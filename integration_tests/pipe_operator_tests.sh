#!/bin/bash
exec > >(tee "./integration_text.txt")

echo -e TEST RESULTS ARE FORWARDED INTO output.txt and output2.txt for comparison '\n\n'

echo -e Testing piping...'\n'
echo TEST_1: "ls | tr a-z A-Z | tee output.txt"
echo -e ' \t' 
cmd="ls | tr a-z A-Z | tee output.txt"

echo -e ' \t'----Expected----
eval $cmd
result="cat output.txt"
eval $result

echo -e ' \t'----Actual----
../rshell "integration_test" "ls | tr a-z A-Z | tee output2.txt"
result="cat output2.txt"
eval $result

echo -e '\n'

echo TEST_2: "echo to uppercase | tr a-z A-Z"
echo -e ' \t' 
cmd="echo to uppercase | tr a-z A-Z"

echo -e ' \t'----Expected----
eval $cmd

echo -e ' \t'----Actual----
../rshell "integration_test" "echo to uppercase | tr a-z A-Z"

echo -e '\n'

echo TEST_3: "cat ../names.txt | tr a-z A-Z"
echo -e ' \t' 
cmd="cat ../names.txt | tr a-z A-Z"

echo -e ' \t'----Expected----
eval $cmd

echo -e ' \t'----Actual----
../rshell "integration_test" "cat ../names.txt | tr a-z A-Z"
