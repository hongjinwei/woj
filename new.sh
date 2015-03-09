#!/bin/bash

touch $1
echo "#include<stdio.h>
#include<stdlib.h>

int main()
{

}" > $1
vim $1
