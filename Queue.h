#ifndef QUEUE_HEAD
#define QUEUE_HEAD

#include <iostream>
#include <fstream>
#include <string>

struct Node {
  int data;
  Node* next;

  Node() {
    data = NULL;
    next = NULL;
  }

  Node(int pageNumber){
    data = pageNumber;
    next = NULL;
  }


};

struct Queue {
  Node *front, *rear;
  int size;

  Queue() {
    front = NULL;
    rear = NULL;
    size = 0;
  }

  /*Queue(const Queue &aQueue){
    Node* temp = aQueue->front;

    while (temp != NULL) {

    }

    if (front == NULL) {
      rear = NULL;
    }else {
      rear = temp;
    }
  }*/

  void Enqueue(int pageNumber){
    Node* temp = new Node(pageNumber);
    if (front == NULL) {
      front = temp;
      rear = temp;
      front->next = NULL;
    }
    else {
      rear->next = temp;
      rear = temp;
      rear->next = NULL;
    }
    size += 1;
  }

  void deQueue() {
    if (front == NULL) {return;}
    Node* temp = front;
    front = temp->next;
    temp->next = NULL;
    delete(temp);
    size -= 1;

  }

  bool searchFor(int pageNumber) {
    bool isIn = false;
    if (front == NULL) {return false;}

    Node* temp = front;
    while (temp != NULL && isIn == false) {
      if (temp->data == pageNumber) {

        isIn = true;
      }
      temp = temp->next;

    }

    return isIn;
  }

  Node* searchForNode(int pageNumber) {
    Node* nodeBeforeFound = NULL;
    Node* foundNode = NULL;
    if (front == NULL) {return foundNode;}

    foundNode = front;
    while (foundNode != NULL) {
      if (foundNode->data == pageNumber) {

        break;
      }
      nodeBeforeFound = foundNode;
      foundNode = foundNode->next;

    }
    if (nodeBeforeFound == NULL) {
      nodeBeforeFound = foundNode;
    }

    if (foundNode == NULL) {
      nodeBeforeFound = NULL;
    }

    return nodeBeforeFound;
  }

  void recentlyUsedMiddle(Node* nodeBeforeFound) {
    Node* usedNode = nodeBeforeFound->next;
    nodeBeforeFound->next = usedNode->next;
    rear->next = usedNode;
    rear = usedNode;
    usedNode->next = NULL;
  }

  void recentlyUsedFront(Node* foundNode) {
    front = foundNode->next;
    rear->next = foundNode;
    rear = foundNode;
    rear->next = NULL;
  }

  /*void printStats() {
    float avgBurst = 0, avgWait = 0, avgTurn = 0, avgResponse = 0, totalContext = 0;
    Node* current = front;

    while (current != NULL) {
      avgBurst += current->data->burst;
      avgWait += current->data->wait;
      avgTurn += current->data->turnaround;
      avgResponse += current->data->response;
      totalContext += current->data->contextSwitches;

      current = current->next;
    }
    avgBurst = avgBurst / size;
    avgWait = avgWait / size;
    avgTurn = avgTurn / size;
    avgResponse = avgResponse / size;

    std::cout << "Average CPU burst time: " << avgBurst << '\t'
              << "Average waiting time: " << avgWait << '\n'
              << "Average turn around time: " << avgTurn << '\t'
              << "Average response time: " << avgResponse << '\n'
              << "Total No. context switches: " << totalContext << '\n';
  }*/

  void print() {
    Node* current = rear;
    std::cout << current->data << "              ";

    current = front;
    float count = 2000;
    while (current != NULL) {
      float pageFaultRate = current->data / count;

      std::cout << std::setprecision(3) << pageFaultRate << '\t';

      current = current->next;
      count += 2000;
    }
  }


  void printToFile(std::string filename) {
    std::ofstream outFile;
    outFile.open(filename, std::ios::ate | std::ios::app);

    Node* current = rear;
    outFile << current->data << "         ";

    current = front;
    float count = 2000;
    while (current != NULL) {
      float pageFaultRate = current->data / count;

      outFile << std::setprecision(3) << pageFaultRate << '\t';

      current = current->next;
      count += 2000;
    }
    outFile << '\n';
    outFile.close();
  }

  void printChars() {
    int aChar = front->data;
    std::cout << static_cast<char>(aChar);
  }

};





/*struct BurstPQueue : Queue {
  BurstPQueue() {
    front = NULL;
    rear = NULL;
    size = 0;
  }

  void Enqueue(PCB* aPCB) {
    Node* aNode = new Node(aPCB);
    if (front == NULL) {
      front = aNode;
      front->next = NULL;
      rear = front;
    }
    else if (front->data->burst > aNode->data->burst) {
      aNode->next = front;
      front = aNode;
    }
    else {
      Node* temp = front;
      while (temp->next != NULL && temp->next->data->burst < aNode->data->burst) {
        temp = temp->next;
      }
      aNode->next = temp->next;
      temp->next = aNode;
      if (aNode->next == NULL) {
        rear = aNode;
      }
    }
    size += 1;
  }

};

struct PriorityPQueue : Queue {
  PriorityPQueue() {
    front = NULL;
    rear = NULL;
    size = 0;
  }

  void Enqueue(PCB* aPCB) {
    Node* aNode = new Node(aPCB);
    if (front == NULL) {
      front = aNode;
      front->next = NULL;
      rear = front;
    }
    else if (front->data->priority > aNode->data->priority) {
      aNode->next = front;
      front = aNode;
    }
    else {
      Node* temp = front;
      while (temp->next != NULL && temp->next->data->priority < aNode->data->priority) {
        temp = temp->next;
      }
      aNode->next = temp->next;
      temp->next = aNode;
      if (aNode->next == NULL) {
        rear = aNode;
      }
    }
    size += 1;
  }

};*/



#endif
