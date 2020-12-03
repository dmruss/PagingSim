#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Queue.h"
#include "PageReplace.h"

void PrintGrid(int frameSize);
Queue* ReadInput(std::string filename);


int main(int argc, char* argv[]) {
  Queue* pageList = new Queue();
  Queue* pageFaults= new Queue();

  if (argc == 3) {


      Queue* pageList = ReadInput(argv[2]);
      PrintGrid(atoi(argv[1]));
      std::cout << "FIFO                  ";

      Queue* pageFaults = Fifo(pageList, atoi(argv[1]));

      pageFaults->print();
      std::cout << '\n';


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
