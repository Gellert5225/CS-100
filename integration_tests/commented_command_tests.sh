#!/bin/bash
exec > >(tee "./integration_text.txt")

echo -e Testing commented commands...'\n'
echo TEST_1: "echo hello; invalid_command haha # echo thisshouldprint"
echo -e ' \t' 
cmd="echo hello; invalid_command haha # echo thisshouldprint"

echo -e ' \t'----Expected----
eval $cmd

echo -e ' \t'----Actual----
../rshellexe "integration_test" "echo hello; invalid_command haha # echo thisshouldprint"

echo -e '\n'
echo TEST_2: "echo hello; ls -a # echo whoa"
echo -e ' \t' 
cmd="echo hello; ls -a # echo whoa"

echo -e ' \t'----Expected----
eval $cmd

echo -e ' \t'----Actual----
../rshellexe "integration_test" "echo hello; ls -a # echo whoa"

echo -e '\n'
echo TEST_3: "#doesnt make sense"
echo -e ' \t' 
cmd="#doesnt make sense"

echo -e ' \t'----Expected----
eval $cmd

echo -e ' \t'----Actual----
../rshellexe "integration_test" "#doesnt make sense"
