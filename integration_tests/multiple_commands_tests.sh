#!/bin/bash
exec > >(tee "./integration_text.txt")

echo -e TEST RESULTS ARE FORWARDED INTO integration_test.txt '\n\n'

echo -e Testing multiple commands...'\n'
echo TEST_1: "echo hello; invalid_command haha || echo thisshouldprint"
echo -e ' \t' 
cmd="echo hello; invalid_command haha || echo thisshouldprint"

echo -e ' \t'----Expected----
eval $cmd

echo -e ' \t'----Actual----
../rshellexe "integration_test" "echo hello; invalid_command haha || echo thisshouldprint"

echo -e '\n'
echo TEST_2: "echo hello; ls -a && echo whoa"
echo -e ' \t' 
cmd="echo hello; ls -a && echo whoa"

echo -e ' \t'----Expected----
eval $cmd

echo -e ' \t'----Actual----
../rshellexe "integration_test" "echo hello; ls -a && echo whoa"
