
template <typename T>
SingleLinkedList<T>::~SingleLinkedList() {
clear();
}

template <typename T>
SingleLinkedList<T>::SingleLinkedList(const SingleLinkedList<T>& other) {
head = nullptr;
size = 0;

Node* temp = other.head;

while (temp != nullptr) {
insert(temp->data);
temp = temp->next;
}
}

template <typename T>
SingleLinkedList<T>& SingleLinkedList<T>::operator=(const SingleLinkedList<T>& other) {
  if (this == &other) return *this;
  clear();
  Node* current = other.head;
  while (current != nullptr) {
    insert(current->data);
    current = current->next;
  }
  return *this;
}

template <typename T>
void SingleLinkedList<T>::insert_to_front(T data) {
  Node* node = new Node(data);
  node->next = head;
  head = node;
  size++;
}

template <typename T>
void SingleLinkedList<T>::remove(T data) {
  if (isEmpty()) return;
  if (head->data == data) {
    Node* temp = head;
    head = head->next;
    delete temp;
    size--;
    return;
  }
  Node* current = head;
  while (current->next != nullptr && current->next->data != data)
    current = current->next;
  if (current->next == nullptr) return;
  Node* temp = current->next;
  current->next = temp->next;
  delete temp;
  size--;
}

template <typename T>
void SingleLinkedList<T>::clear() {
  while (head != nullptr) {
    Node* temp = head;
    head = head->next;
    delete temp;
  }
  size = 0;
}

template<typename T>
void SingleLinkedList<T>::add_to_end(const T &value) {
  Node *new_node = new Node(value);
  if (!head) {
    head = new_node;
  } else {
    Node *current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = new_node;
  }
 
}


template <typename T>
int SingleLinkedList<T>::getSize() const {
  return size;
}

template <typename T>
bool SingleLinkedList<T>::isEmpty() const {
  return size == 0;
}

template <typename T>
void SingleLinkedList<T>::reverse() {
  Node* current = head;
  Node* prev = nullptr;
  Node* next = nullptr;
  while (current != nullptr) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  head = prev;
}


template <typename T>
typename SingleLinkedList<T>::Iterator SingleLinkedList<T>::begin() const {
  return Iterator(head);
}

template <typename T>
typename SingleLinkedList<T>::Iterator SingleLinkedList<T>::end() const {
  return Iterator(nullptr);
  
}

template <typename T>
typename SingleLinkedList<T>::Iterator SingleLinkedList<T>::getLast() const {
  Node* current = head;
  while (current->next != nullptr) {
    current = current->next;
  }
  return Iterator(current);
}


template <typename T>
void SingleLinkedList<T>::print() const {
	Node* current = head;
            while (current) {
                std::cout << current->data << " ";
                current = current->next;
            }
           
}
        
template <typename T>
std::ostream& operator<<(std::ostream& os, const SingleLinkedList<T>& list){
	
	list.print();
	return os;
	
}

template <typename T>
void SingleLinkedList<T>::weave(SingleLinkedList<T>& other) {
  Node *current1 = head, *current2 = other.head;
  head = nullptr;
  Node *tail = nullptr;
  size = 0;
  while (current1 != nullptr || current2 != nullptr) {
    if (current1 != nullptr) {
      if (head == nullptr) {
        head = current1;
        tail = head;
      } else {
        tail->next = current1;
        tail = tail->next;
      }
      current1 = current1->next;
      size++;
    }
    if (current2 != nullptr) {
      if (head == nullptr) {
        head = current2;
        tail = head;
      } else {
        tail->next = current2;
        tail = tail->next;
      }
      current2 = current2->next;
      size++;
    }
  }
  other.head = nullptr;
  other.size = 0;
}

