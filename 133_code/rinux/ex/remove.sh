#!/bin/bash
FILES=*
for DIR in $FILES
do
	if [ -d $DIR ]; then
		rmdir $DIR
	fi
done

echo $FILES
