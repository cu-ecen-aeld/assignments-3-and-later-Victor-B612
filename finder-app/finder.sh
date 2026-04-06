#!/bin/bash
#Basic script to search a string in provided file directory
#Author Víctor BB

if [ $# -lt 2 ]
then
	echo You need to provide two arguments
	exit 1
else
	if [ -e $1 ]; then 
		echo directory/file exist!!!
		total_files=$(find $1 -type f | wc -l)
        total_matches=$(grep -r $2 $1 | wc -l)
        echo The number of files are $total_files and the number of matching lines are $total_matches
		exit 0
	else
		echo directory/file does not exist
		exit 1
	fi
fi