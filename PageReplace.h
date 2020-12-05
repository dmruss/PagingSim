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
      Node* nodeBeforeFound = frameList->searchForNode(currentPage);


      std::cout << "size" << frameList->size << '\n';
      if (nodeBeforeFound != NULL) {
        //std::cout << currentPage << '\t' << nodeBeforeFound->next->data << std::endl;

      }
      if (pagesExec % 2000 == 0 && pagesExec != 0) {pageFaults->Enqueue(numPageFaults);}

      if (nodeBeforeFound == NULL) {
        if (frameList->size < frames) {
          std::cout << "add\n";
          frameList->Enqueue(pageList->front->data);
          pageList->deQueue();
          numPageFaults += 1;
        }
        else if (frameList->size == frames) {
          std::cout << "swap\n";
          frameList->deQueue();
          frameList->Enqueue(pageList->front->data);
          pageList->deQueue();
          numPageFaults += 1;
        }else {
          std::cout << "what happened\n";
          std::cout << frames << '\t' << frameList->size << std::endl;
        }
      }
      else if (nodeBeforeFound != NULL) {
        //MOVETOTAILINFRAMELIST
        pageList->deQueue();
        if (nodeBeforeFound->data != currentPage) {
          if (nodeBeforeFound->next == frameList->rear) {continue;}
          //std::cout << "middle\n";
          Node* temp = nodeBeforeFound->next;
          nodeBeforeFound->next = temp->next;
          temp->next = NULL;
          delete(temp);
          frameList->size -= 1;
          frameList->Enqueue(currentPage);
          std::cout << "reorder\n";

          //frameList->Enqueue(nodeBeforeFound->next->data);
          //frameList->recentlyUsedMiddle(nodeBeforeFound);

        }else if(nodeBeforeFound->data == currentPage) {
          if (nodeBeforeFound == frameList->rear) {continue;}
          Node* temp = frameList->front;
          frameList->front = temp->next;
          temp->next = NULL;
          delete(temp);
          frameList->size -= 1;
          frameList->Enqueue(currentPage);

          std::cout << "front reorder\n";
          //frameList->recentlyUsedFront(nodeBeforeFound);
      }
        /*if (nodeBeforeFound->data == currentPage) {
          frameList->recentlyUsedFront(nodeBeforeFound);
        }else if (nodeBeforeFound->data != currentPage) {
          frameList->recentlyUsedMiddle(nodeBeforeFound);
        }*/
      }
      //frameList->printFrames();
    }
      std::cout << "here2\n";
    pageFaults->Enqueue(numPageFaults);
    return pageFaults;
}




#endif
