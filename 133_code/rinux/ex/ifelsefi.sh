#!/bin/bash

if [ -z $1 ]; then
	echo "usage: $0 <filename>" > /dev/stderr
	exit 1
else
	DIR=$1
fi

if [ -d $DIR ]; then
	echo "$DIR is directory"
else
	echo "$DIR is not directory"
fi
