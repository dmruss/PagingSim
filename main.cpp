#include <iostream>
#include <string>
#include <fstream>
#include "Queue.h"
#include "PageReplace.h"


Queue* ReadInput(std::string filename);


int main(int argc, char* argv[]) {
  Queue* pageList = new Queue();
  Queue* pageFaults= new Queue();

  if (argc == 3) {


      Queue* pageList = ReadInput(argv[2]);
      std::cout << "FIFO\n";
    
      Queue* pageFaults = Fifo(pageList, atoi(argv[1]));

      pageFaults->print();
      std::cout << '\n';


  }else {

    std::cout << "Input error\n";


}


  return 0;
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
