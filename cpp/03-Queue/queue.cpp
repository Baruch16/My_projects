#include "queue.hpp"

Queue::Queue()
:m_size(deafult_size)
,stack1(deafult_size)
,stack2(deafult_size)
{}

Queue::Queue(int size)
:m_size(size)
,stack1 (m_size)
,stack2 (m_size)
{}


bool Queue::Qis_empty() const
{
	if (stack1.isEmpty() && stack2.isEmpty())
		return true;
		
	return false;
}

bool Queue::Qis_full() const
{
	if (stack1.isFull() || stack2.isFull())
		return true;
		
	return false;
}

void Queue::enqueue(int x) 
{	
	stack1.push(x);

}

int Queue::dequeue()
{
	if(stack2.isEmpty()){
		while(!stack1.isEmpty()){
			stack2.push(stack1.pop());
		}
	}
	
	return stack2.pop();
}

int Queue::top_El() const
{
	return stack1.topEl();
}
