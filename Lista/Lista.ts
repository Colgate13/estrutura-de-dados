class ListNode<Tnode> {
  private node: Tnode;
  private next: ListNode<Tnode> = null as any;

  constructor(node: Tnode) {
    this.node = node;
  }

  public setNext(next: ListNode<Tnode>) {
    this.next = next;
  }

  public getNext() {
    return this.next;
  }

  public getNode() {
    return this.node;
  }

  public setNode(node: Tnode) {
    this.node = node;
  }
}

class Lista<TLista> {
  protected head: ListNode<TLista> | null = null;

  constructor() {
    this.head = null;
  }
  // add new node to the end of the list
  public add(node: TLista) {
    if (this.head == null) {
      // if the list is empty
      this.head = new ListNode<TLista>(node);
    } else {
      // loop in the list until the last node
      let aux = this.head;
      while (aux.getNext() != null) {
        if (aux == null) break;
        aux = aux.getNext();
      }
      aux.setNext(new ListNode<TLista>(node));
    }
  }

  public remove(node: TLista) {
    if (this.head != null) {
      // if the list is empty
      if (this.head.getNode() == node) {
        // if head is the node to be removed
        this.head = this.head.getNext();
      } else {
        let aux = this.head;
        // loop in the list to find the node to be removed and remove
        while (aux.getNext() != null) {
          if (aux.getNext().getNode() == node) {
            // if the next node is the node to be removed
            aux.setNext(aux.getNext().getNext());
            break;
          }
          aux = aux.getNext();
        }
      }
    }
  }

  public print() {
    let aux = this.head;
    while (aux != null) {
      console.log(aux.getNode());
      aux = aux.getNext();
    }
  }
}

const lista = new Lista<number>();

lista.add(1);
lista.add(2);
lista.add(3);
lista.print();
lista.remove(1);
console.log("remove 1");
lista.print();

const multiAdd = (list: Lista<number>) => {
  for (let i = 0; i < 2e10000; i++) {
    list.add(i);
    list.add(i + 1);
    list.add(i * 2e10);
  }
};
multiAdd(lista);