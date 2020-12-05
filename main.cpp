#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Queue.h"
#include "PageReplace.h"

void PrintGrid(int frameSize);
void PrintToFile(std::string filename, int frameSize);
Queue* ReadInput(std::string filename);


int main(int argc, char* argv[]) {
  Queue* pageListInput = new Queue();
  Queue* fifoPageFaults= new Queue();
  Queue* lruPageFaults = new Queue();


  if (argc == 4) {
      //read input
      Queue* pageListInput = ReadInput(argv[2]);

      //run algorithms
      Queue* fifoPageFaults = Fifo(pageListInput, atoi(argv[1]));
      pageListInput = ReadInput(argv[2]);
      Queue* lruPageFaults = LRU(pageListInput, atoi(argv[1]));

      //Print to console
      PrintGrid(atoi(argv[1]));
      std::cout << "FIFO                  ";
      fifoPageFaults->print();
      std::cout << '\n';
      std::cout << "LRU                   ";
      lruPageFaults->print();
      std::cout << '\n';

      //test->Enqueue(76);
      //test->printChars();


      //Print to file
      PrintToFile(argv[3], atoi(argv[1]));
      fifoPageFaults->printToFile(argv[3]);
      lruPageFaults->printToFile(argv[3]);

  }else {
    std::cout << "Input error\n";
        }


  return 0;
}


void PrintGrid(int frameSize) {
  std::cout << "============================================================================\n";
  std::cout << "\tPage Replacement Algorithm Simulation (frame size = " << frameSize << ")\n";
  std::cout << "============================================================================\n";
  std::cout << "\t\t\t\t\tPage fault rates\n";
  std::cout << "Algorithm\tTotal page faults\t2000\t4000\t6000\t8000\t1000\n";
  std::cout << "----------------------------------------------------------------------------\n";

}

void PrintToFile(std::string filename, int frameSize) {
  std::ofstream outFile;
  outFile.open(filename, std::ios::ate | std::ios::app);
  outFile << "============================================================================\n";
  outFile << "\tPage Replacement Algorithm Simulation (frame size = " << frameSize << ")\n";
  outFile << "============================================================================\n";
  outFile << "                                 Page fault rates\n";
  outFile << "Algorithm\tTotal page faults\t2000\t4000\t6000\t8000\t1000\n";
  outFile << "----------------------------------------------------------------------------\n";
  outFile << "FIFO          ";

  outFile.close();
}


Queue* ReadInput(std::string filename){
  std::ifstream infile(filename);
  int page;
  Queue* newPageList = new Queue();

  while (infile >> page){
    newPageList->Enqueue(page);

    //temp->print();
  }
  //newProcessQueue->print();
  return newPageList;
}
