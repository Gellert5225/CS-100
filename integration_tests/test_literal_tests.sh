#!/bin/bash
exec > >(tee "./integration_text.txt")
echo -e TEST RESULTS ARE FORWARDED INTO integration_test.txt '\n\n'

echo -e Testing Literal Test Commands...'\n'
echo TEST_1: "test -e test_literal_tests.sh && echo file exists || echo file does not exist"
echo -e ' \t' 
cmd="test -e test_literal_tests.sh && echo file exists || echo file does not exist"

echo -e ' \t'----Expected----
eval $cmd

echo -e ' \t'----Actual----
../rshell "integration_test" "test -e test_literal_tests.sh && echo file exists || echo file does not exist"

echo -e '\n'
echo TEST_2: "test -e haha.sh && echo file exists || echo file does not exist"
echo -e ' \t' 
cmd="test -e haha.sh && echo file exists || echo file does not exist"

echo -e ' \t'----Expected----
eval $cmd

echo -e ' \t'----Actual----
../rshell "integration_test" "test -e haha.sh && echo file exists || echo file does not exist"

echo -e '\n'
echo TEST_3: "test -f ../README.md && echo file exists || echo file does not exist"
echo -e ' \t' 
cmd="test -f ../README.md && echo file exists || echo file does not exist"

echo -e ' \t'----Expected----
eval $cmd

echo -e ' \t'----Actual----
../rshell "integration_test" "test -f ../README.md && echo file exists || echo file does not exist"

echo -e '\n'
echo TEST_4: "test -d ../unit_tests/ && echo dir exists || echo dir does not exist"
echo -e ' \t' 
cmd="test -d ../unit_tests/ && echo dir exists || echo dir does not exist"

echo -e ' \t'----Expected----
eval $cmd

echo -e ' \t'----Actual----
../rshell "integration_test" "test -d ../unit_tests/ && echo dir exists || echo dir does not exist"