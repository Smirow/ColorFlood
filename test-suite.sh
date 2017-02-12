#!/bin/sh

main=./colorflood

if [ ! -x $main ]; then
	make
fi

for args in '' 'hello' '123' '0'; do
	$main $args
	if [ $? -eq 1 ]; then
		printf '\033[1;32msuccess\033[0m\n'
	else
		printf '\033[1;31mfailure\033[0m\n'
	fi
done

for args in $(seq 4 8 32); do
	$main $args
	if [ $? -eq 0 ]; then
		printf '\033[1;32msuccess\033[0m\n'
	else
		printf '\033[1;31mfailure\033[0m\n'
	fi
done

# Valgrind
valgrind \
--leak-check=full \
--show-leak-kinds=all \
--track-origins=yes \
--log-file=colorflood.valgrind \
$main 4 > /dev/null
