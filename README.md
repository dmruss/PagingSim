# Paging Simulator

This project is a simulation program of virtual memory replacement algorithms written in C++.  The algorithms are First in First Out (FIFO), Least Recently Used (LRU), and Optimal page replacement (OPT).  This program runs simulations of each algorithm with a input file and reports on the their performance.  These algorithms are run in comparison with each other and also with different frame sizes.  The program is run 4 times with 4 different page sizes (128, 256, 512, and 1024).

## How to Use

This program will run in a Unix CLI environment.  

Download the project files, navigate to their root folder and unzip.  The program requires 4 arguments including the program name

In the shell:

            prompt> make
            prompt> ./memsim <number of frames> <input file> <output file>

The shell script with test cases can be run using the command:

            prompt> ./test.sh

## Input Requirements

### Number of Frames

The number of frames will dictate how many pages can be held in "memory" at a time.  


### Input file

The input file must be in .txt format and be integers delineated by new lines.


### Output file

This is the name of a .txt which the program can print the same output seen in the shell.
