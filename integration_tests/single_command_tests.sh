#!/bin/bash
exec > >(tee "./integration_text.txt")
echo -e TEST RESULTS ARE FORWARDED INTO integration_test.txt '\n\n'

echo -e Testing single command...'\n'
echo TEST_1: "echo hello"
echo -e ' \t' 
cmd="echo hello"

echo -e ' \t'----Expected----
eval $cmd

echo -e ' \t'----Actual----
../rshell "integration_test" "echo hello"

echo -e '\n'
echo TEST_2: "ls -a"
echo -e ' \t' 
cmd="ls -a"

echo -e ' \t'----Expected----
eval $cmd

echo -e ' \t'----Actual----
../rshell "integration_test" "ls -a"