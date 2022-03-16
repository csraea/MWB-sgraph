#!/bin/bash

# visual effects
BOLD=`tput bold`
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

rm -rf ./out/build/
mkdir --mode=0777 ./out/build/

if [[ ${1} == "-r" ]]; then
    rm -rf ./out/
fi

cmake -S . -B ./out/build/
CMAKE=$?

if [[ ${CMAKE} != 0 ]]; then
    echo -e "${RED}${BOLD}***** ERROR:  cmake *****${NC}"
    exit 1
fi

make -C ./out/build/
MAKE=$?

if [[ ${MAKE} != 0 ]]; then 
    echo -e "${RED}${BOLD}***** ERROR:  make *****${NC}"
    exit 2
fi

mv ./out/build/mwb-sgraph ./out/

echo -e "${GREEN}${BOLD}***** SUCCESS *****${NC}"