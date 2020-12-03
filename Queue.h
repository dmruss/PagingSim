#ifndef QUEUE_HEAD
#define QUEUE_HEAD

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
    Node* current = front;

    while (current != NULL) {
      std::cout << current->data << '\n';

      current = current->next;
    }
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
