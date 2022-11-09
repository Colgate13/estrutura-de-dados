#include <iostream>
#include <stdlib.h> 

using namespace std;

class Pilha {

  private:
    int max;
    int topo;
    int *pilha;

  public:
    Pilha(int len) {
      this->max = len - 1;
      this->topo = -1;
      this->pilha = (int*) calloc(sizeof(int), len + 1); // Alloc a Block in memory HEAP
    }
    ~Pilha() { free(this->pilha); this->pilha = NULL; } // Clear block of memory HEAP
    void push(int value) {
      this->topo++;
      this->pilha[this->topo] = value; 
    }
    int pop() {
      int value = this->pilha[this->topo];
      this->topo--;
      return value;
    }
    bool isEmpty() { return !(this->topo >= 0); }
    bool isFull() { return (this->topo >= this->max); }
    void clear() { topo = -1; }
};


int main() {

  Pilha pilha1(15000);

  int x = 0;
  while(!pilha1.isFull()) {
    pilha1.push(x);
    x++;
  }

  while(!pilha1.isEmpty()) {
    cout << "Pop: ";
    cout << pilha1.pop() << endl;
  }

  return 0;
}