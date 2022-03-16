#!/bin/bash

if [[ "${2}" == "-D" ]]; then
    rm -rf ./out/results/*
fi

filename="${1}_$(date +"%d-%m@%H:%M:%S")_sol.dat"

for file in ./data/*
do
    echo "$file" && echo "$file" >> ./out/results/${filename}
    ./out/mwb-sgraph ${1} < $file >> ./out/results/${filename}
done
