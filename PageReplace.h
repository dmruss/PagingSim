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

    pageFaults->Enqueue(numPageFaults);
    return pageFaults;
}

Queue* OPT(Queue* pageList, int frames) {
    std::cout << "called\n";
    Queue* pageFaults = new Queue();
    Queue* frameList = new Queue();
    int numPageFaults = 0;


    while (pageList->size > 0) {


      int pagesExec = 10000 - pageList->size;
      int currentPage = pageList->front->data;
      Node* nodeBeforeFound = frameList->searchForNode(currentPage);
      std::cout << std::endl;
      std::cout << "Page called: " << currentPage << std::endl;
      Node* aNode = frameList->front;
      while(aNode != NULL) {
        std::cout << aNode->data << '\t';
        aNode = aNode->next;
      }
      std::cout << std::endl;

      if (pagesExec % 2000 == 0 && pagesExec != 0) {pageFaults->Enqueue(numPageFaults);}

      if (nodeBeforeFound == NULL) {
        if (frameList->size < frames) {
          //std::cout << "called2\n";
          frameList->Enqueue(pageList->front->data);
          pageList->deQueue();
          numPageFaults += 1;
        }
        else if (frameList->size == frames) {
        //  std::cout << "called3\n";


          frameList->setPriority(pageList);

        //  std::cout << "called4\n";
          frameList->removeLowestPriority();




          std::cout << "rear: " << frameList->rear->data << std::endl;
          frameList->Enqueue(pageList->front->data);
          


          std::cout << "size1: "<<frameList->size << std::endl;
          pageList->deQueue();
          numPageFaults += 1;
        }else {
        //  std::cout << "what happened\n";
          std::cout << frames << '\t' << frameList->size << std::endl;
        }
      }
      else if (nodeBeforeFound != NULL) {
        //MOVETOTAILINFRAMELIST
        pageList->deQueue();
        std::cout << "no fault\n";

        /*if (nodeBeforeFound->data == currentPage) {
          frameList->recentlyUsedFront(nodeBeforeFound);
        }else if (nodeBeforeFound->data != currentPage) {
          frameList->recentlyUsedMiddle(nodeBeforeFound);
        }*/
      }
      //frameList->printFrames();
    }

    pageFaults->Enqueue(numPageFaults);
    return pageFaults;
}




#endif
