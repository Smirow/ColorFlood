#!/bin/sh

main=./colorflood

if [ ! -x $main ]; then
	make
fi

for args in '' 'hello' '123'; do
	$main $args
	if [ $? -eq 1 ]; then
		printf '\033[1;32msuccess\033[0m\n'
	else
		printf '\033[1;31mfailure\033[0m\n'
	fi
done
