#!/bin/bash
exec > >(tee "./integration_text.txt")

echo -e TEST RESULTS ARE FORWARDED INTO integration_test.txt '\n\n'

echo -e Testing Exit commands...'\n'
echo TEST_1: "echo hello; exit"
echo -e ' \t' 
cmd="echo hello; #exit"

echo -e ' \t'----Expected----
eval $cmd

echo -e ' \t'----Actual----
../rshellexe "integration_test" "echo hello; exit"

echo -e '\n'
echo TEST_2: "exit; echo hello; ls -a # echo whoa"
echo -e ' \t' 
cmd="#exit; echo hello; ls -a # echo whoa"

echo -e ' \t'----Expected----
eval $cmd

echo -e ' \t'----Actual----
../rshellexe "integration_test" "exit; echo hello; ls -a # echo whoa"

echo -e '\n'
echo TEST_3: "exit && echo hello; ls -a # echo whoa"
echo -e ' \t' 
cmd="#exit && echo hello; ls -a # echo whoa"

echo -e ' \t'----Expected----
eval $cmd

echo -e ' \t'----Actual----
../rshellexe "exit && echo hello; ls -a # echo whoa"
