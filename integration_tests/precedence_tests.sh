#!/bin/bash
exec > >(tee "./integration_text.txt")
echo -e TEST RESULTS ARE FORWARDED INTO integration_test.txt '\n\n'

echo -e Testing Precedence Commands...'\n'
echo TEST_1: "echo file exists || echo file does not exist"
echo -e ' \t' 
cmd="echo file exists || echo file does not exist"

echo -e ' \t'----Expected----
eval $cmd

echo -e ' \t'----Actual----
../rshell "integration_test" "echo file exists || echo file does not exist"

echo -e '\n'
echo TEST_2: "(echo file exists || echo file does not exist)"
echo -e ' \t' 
cmd="(echo file exists || echo file does not exist)"

echo -e ' \t'----Expected----
eval $cmd

echo -e ' \t'----Actual----
../rshell "integration_test" "(echo file exists || echo file does not exist)"

echo -e '\n'
echo TEST_3: "(echo A && echo B) || (echo C && echo D)"
echo -e ' \t' 
cmd="(echo A && echo B) || (echo C && echo D)"

echo -e ' \t'----Expected----
eval $cmd

echo -e ' \t'----Actual----
../rshell "integration_test" "(echo A && echo B) || (echo C && echo D)"

echo -e '\n'
echo TEST_4: "(echo A && echo B) || (echo C && echo D) && (ech dd)"
echo -e ' \t' 
cmd="(echo A && echo B) || (echo C && echo D) && (ech dd)"

echo -e ' \t'----Expected----
eval $cmd

echo -e ' \t'----Actual----
../rshell "integration_test" "(echo A && echo B) || (echo C && echo D) && (ech dd)"