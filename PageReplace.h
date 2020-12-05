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

    if (pagesExec % 2000 == 0 && pagesExec != 0) {pageFaults->Enqueue(numPageFaults);}

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

Queue* LRU(Queue* pageList, int frames) {

    Queue* pageFaults = new Queue();
    Queue* frameList = new Queue();
    int numPageFaults = 0;


    while (pageList->size > 0) {
      int pagesExec = 10000 - pageList->size;
      int currentPage = pageList->front->data;
      bool nodeBeforeFound = frameList->searchForNode(currentPage);

      if (pagesExec % 2000 == 0 && pagesExec != 0) {pageFaults->Enqueue(numPageFaults);}

      if (nodeBeforeFound == NULL) {
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
      else if (nodeBeforeFound != NULL) {
        //MOVETOTAILINFRAMELIST
        pageList->deQueue();
        /*if (nodeBeforeFound->data == currentPage) {
          frameList->recentlyUsedFront(nodeBeforeFound);
        }else if (nodeBeforeFound->data != currentPage) {
          frameList->recentlyUsedMiddle(nodeBeforeFound);
        }*/
      }
    }
    pageFaults->Enqueue(numPageFaults);
    return pageFaults;
}




#endif
