#!/bin/bash
exec > >(tee "./integration_text.txt")
echo -e TEST RESULTS ARE FORWARDED INTO integration_test.txt '\n\n'

echo -e Testing Symbolic Test Commands...'\n'
echo TEST_1: "[ -e test_literal_tests.sh ] && echo file exists || echo file does not exist"
echo -e ' \t' 
cmd="[ -e test_literal_tests.sh ] && echo file exists || echo file does not exist"

echo -e ' \t'----Expected----
eval $cmd

echo -e ' \t'----Actual----
../rshell "integration_test" "[ -e test_literal_tests.sh ] && echo file exists || echo file does not exist"

echo -e '\n'
echo TEST_2: "[ -e haha.sh ] && echo file exists || echo file does not exist"
echo -e ' \t' 
cmd="[ -e haha.sh ] && echo file exists || echo file does not exist"

echo -e ' \t'----Expected----
eval $cmd

echo -e ' \t'----Actual----
../rshell "integration_test" "[ -e haha.sh ] && echo file exists || echo file does not exist"

echo -e '\n'
echo TEST_3: "[ -f ../README.md ] && echo file exists || echo file does not exist"
echo -e ' \t' 
cmd="[ -f ../README.md ] && echo file exists || echo file does not exist"

echo -e ' \t'----Expected----
eval $cmd

echo -e ' \t'----Actual----
../rshell "integration_test" "[ -f ../README.md ] && echo file exists || echo file does not exist"

echo -e '\n'
echo TEST_4: "[ -d ../unit_tests/ ] && echo dir exists || echo dir does not exist"
echo -e ' \t' 
cmd="[ -d ../unit_tests/ ] && echo dir exists || echo dir does not exist"

echo -e ' \t'----Expected----
eval $cmd

echo -e ' \t'----Actual----
../rshell "integration_test" "[ -d ../unit_tests/ ] && echo dir exists || echo dir does not exist"