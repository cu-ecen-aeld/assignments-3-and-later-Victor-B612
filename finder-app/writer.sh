#!/bin/bash
#basic script to creates a new file with name and path writefile with content writestr, overwriting any existing file and creating the path if it doesn’t exist
#Author Víctor BB

if [ $# -lt 2 ]
then
	echo You need to provide two arguments
	exit 1
else
	dir_path=$(dirname $1)
	file_name=$(basename $1)
	mkdir -p $dir_path && touch $_/$file_name
	if [ -e $1 ]; then 
		echo file was created!!!
		echo $2 > $1 
		exit 0
	else
		echo file does not exist
		exit 1
	fi
fi
