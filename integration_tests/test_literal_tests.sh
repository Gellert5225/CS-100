#!/bin/bash
exec > >(tee "./integration_text.txt")
echo -e TEST RESULTS ARE FORWARDED INTO integration_test.txt '\n\n'

echo -e Testing Literal Test Commands...'\n'
echo TEST_1: "test -e README.txt || echo file does not exist"
echo -e ' \t' 
cmd="test -e README.txt"

echo -e ' \t'----Expected----
eval $cmd

echo -e ' \t'----Actual----
../rshell "integration_test" "test -e README.txt"

echo -e '\n'
echo TEST_2: "ls -a"
echo -e ' \t' 
cmd="ls -a"

echo -e ' \t'----Expected----
eval $cmd

echo -e ' \t'----Actual----
../rshell "integration_test" "ls -a"