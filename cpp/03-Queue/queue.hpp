#ifndef QUEUE_HPP
#define QUEUE_HPP


#include "../02-Stack/arrstack.hpp"


class Queue
{	
	
public:
	
	explicit Queue();
	explicit Queue(int size);
	
	void enqueue(int x);
	int dequeue();
	bool Qis_empty() const;
	bool Qis_full() const;
	int top_El() const;
	
private:
	int deafult_size=50;
	int m_size;
	Stack stack1;
	Stack stack2;
	
};
#endif

