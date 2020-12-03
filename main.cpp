#include <iostream>
#include <string>
#include <fstream>
#include "Queue.h"


Queue* ReadInput(std::string filename);


int main(int argc, char* argv[]) {
  Queue* pageCalls = new Queue();

  if (argc == 4)

    if (atoi(argv[2]) == 0) {
      Queue* pageCalls = ReadInput(argv[2]);
      std::cout << "FIFO\n";
      Queue* finishedFCFS = Fcfs(newProcessQueue);
      finishedFCFS->print();
      finishedFCFS->printStats();
      std::cout << '\n';


  }else {

    std::cout << "Input error\n";


}


  return 0;
}



Queue* ReadInput(std::string filename){
  std::ifstream infile(filename);
  int pid, arrival, burst, priority;
  Queue* newProcessQueue = new Queue();

  while (infile >> pid >> arrival >> burst >> priority){
    PCB* temp = new PCB(pid, arrival, burst, priority);
    newProcessQueue->Enqueue(temp);

    //temp->print();
  }
  //newProcessQueue->print();
  return newProcessQueue;
}
