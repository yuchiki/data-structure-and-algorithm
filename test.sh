#!/bin/bash
set -eu

TARGETS=($(find . -print | find . -name "*.c" ))

pass=0
fail=0

for target in ${TARGETS[@]}; do


    if ! gcc -o $target.out -D TEST $target; then
        echo -e "\e[31mcompile error\e[m"
        continue
    fi

    if $target.out; then
        echo -e "$target: \e[32mpass\e[m"
        pass=$(expr $pass + 1)
    else
        echo -e "$target: \e[31mfail\e[m"
        fail=$(expr $fail + 1)
    fi
done

echo -e "\e[32m $pass passes \e[m and \e[31m $fail fails\e[m."
