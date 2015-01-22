#!/bin/bash

touch $1
echo "#include<stdio.h>\n#include<stdlib.h>\n\nint main()\n{\n\n}" >> $1
vim $1
