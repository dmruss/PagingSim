#ifndef PAGEREPLACE_HEAD
#define PAGEREPLACE_HEAD

#include "Queue.h"




Queue* Fifo(Queue* pageList, int frames) {

  Queue* pageFaults = new Queue();
  Queue* frameList = new Queue();
  int numPageFaults = 0;

  while (pageList->size > 0) {


    int pagesExec = 10000 - pageList->size;
    int currentPage = pageList->front->data;
    bool pageInMemory = frameList->searchFor(currentPage);


    if (pagesExec % 2000 == 0 && pagesExec != 10000) {pageFaults->Enqueue(numPageFaults);}


    if (pageInMemory == false) {
      if (frameList->size < frames) {
        frameList->Enqueue(pageList->front->data);
        pageList->deQueue();
        numPageFaults += 1;
      }
      else if (frameList->size == frames) {
        frameList->deQueue();
        frameList->Enqueue(pageList->front->data);
        pageList->deQueue();

        numPageFaults += 1;
      }

    }
    else if (pageInMemory == true) {
      pageList->deQueue();
    }
  }

  pageFaults->Enqueue(numPageFaults);



  return pageFaults;
}




#endif
