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
  Queue* pageList = new Queue();
  Queue* pageFaults= new Queue();

  if (argc == 3) {

      FILE *fp;

      Queue* pageList = ReadInput(argv[2]);
      PrintGrid(atoi(argv[1]));


      Queue* pageFaults = Fifo(pageList, atoi(argv[1]));
      std::cout << "FIFO                  ";
      pageFaults->print();
      std::cout << '\n';


      PrintToFile("output.txt", atoi(argv[1]));
      pageFaults->printToFile("output.txt");



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
