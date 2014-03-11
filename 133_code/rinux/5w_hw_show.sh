#!/bin/bash
FILES=*
for i in $FILES
do
	sleep 1
	echo $i
	wait
done
