template <typename T>
void LinkedList<T>::copyList(const LinkedList &other) {

	Node *curr = other.head;
	while (curr) {
		push_back(curr->data);
		curr = curr->next;
	}
}

template <typename T>
void LinkedList<T>::deleteList() {
	while (head) {
		Node *node = head;
		head = head->next;
		delete node;
	}
	tail = nullptr;
	sz = 0;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList &other)
: head(nullptr),
tail(nullptr), sz(0) {
copyList(other);
}

template <typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList &other) {
if (this != &other) {
deleteList();
copyList(other);
}
return *this;
}

template <typename T>
LinkedList<T>::~LinkedList() {
deleteList();
}

template <typename T>
void LinkedList<T>::push_back(const T &data) {
	Node *node = new Node(data);
	if (!head) {
		head = tail = node;
	} else {
		tail->next = node;
		tail = node;
	}
	++sz;
}


template <typename T>
	void LinkedList<T>::pop_back() {
	if (!head) {
		return;
	}
	if (head == tail) {
		delete head;
		head = tail = nullptr;
	} 
	else {
		Node *curr = head;
		while (curr->next != tail) {
			curr = curr->next;
		}
		delete tail;
		curr->next = nullptr;
		tail = curr;
	}
	--sz;
}

template <typename T>
void LinkedList<T>::push_front(const T &data) {
	Node *node = new Node(data);
	node->next = head;
	head = node;
	if (!tail) {
		tail = node;
	}
	++sz;
}

template <typename T>
void LinkedList<T>::pop_front() {
	if (!head) {
		return;
	}
	Node *node = head;
	head = head->next;
	delete node;
	if (!head) {
		tail = nullptr;
	}
	--sz;
}

template <typename T>
std::size_t LinkedList<T>::size() const {
	
	return sz;
}

template <typename T>
LinkedList<T> LinkedList<T>::weave(const LinkedList<T> &other) const {
	LinkedList<T> result;
	Node *curr1 = head;
	Node *curr2 = other.head;
	while (curr1 && curr2) {
		result.push_back(curr1->data);
		result.push_back(curr2->data);
		curr1 = curr1->next;
		curr2 = curr2->next;
	}
	while (curr1) {
		result.push_back(curr1->data);
		curr1 = curr1->next;
	}
	while (curr2) {
		result.push_back(curr2->data);
		curr2 = curr2->next;
	}
	return result;
}

template <typename T>
void LinkedList<T>::print(std::ostream& os) const {
    Node* current = head;
    while (current) {
        os << current->data << " ";
        current = current->next;
    }
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list){
    list.print(os);
    return os;
}

template <typename T>
typename LinkedList<T>::Iterator<T> LinkedList<T>::begin() {
    return Iterator<T>(head);
}

template <typename T>
typename LinkedList<T>::Iterator<T> LinkedList<T>::end() {
    return Iterator<T>(nullptr);
}

