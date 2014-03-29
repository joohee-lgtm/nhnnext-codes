#!/bin/bash
echo "enter time(s)"
read TIME
for ((i=0;i<$TIME;i++));
do
	sleep 1 & echo $i
	wait
done

echo
echo
echo
