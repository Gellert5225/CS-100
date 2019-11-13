#!/bin/bash
exec > >(tee "./integration_text.txt")
echo -e Testing single command...'\n'
echo TEST_1: "echo hello"
echo -e ' \t' 
cmd="echo hello"

echo -e ' \t'----Expected----
eval $cmd

echo -e ' \t'----Actual----
../rshellexe "integration_test" "echo hello"

echo -e '\n'
echo TEST_2: "ls -a"
echo -e ' \t' 
cmd="ls -a"

echo -e ' \t'----Expected----
eval $cmd

echo -e ' \t'----Actual----
../rshellexe "integration_test" "ls -a"