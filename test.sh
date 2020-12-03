#!/bin/bash
make

./memsim 128 pg-reference.txt
echo ' '

./memsim 256 pg-reference.txt
