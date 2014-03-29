#!/bin/bash
MEMBER=$(cat member.txt)
for i in $MEMBER
do
	mkdir $i
done

FOLDERS=$(ls -F)
echo $FOLDERS
