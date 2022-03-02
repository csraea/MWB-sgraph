#!/bin/bash

valgrind --leak-check=full \
--show-leak-kinds=all \
--track-origins=yes \
--verbose \
--log-file=./out/valgrind-out.txt \
./out/mwb-sgraph ${1} < ./data/graf_10_7.txt
