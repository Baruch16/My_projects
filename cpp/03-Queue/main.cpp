#include <iostream>
#include "queue.hpp"

int main()
{
	Queue q1(5);
	q1.enqueue(1);
	q1.enqueue(2);
	q1.enqueue(3);
	q1.enqueue(4);
	for (int i=0;i<=3;++i){
		std::cout<<q1.dequeue()<<","<<"\n";
		}
	q1.enqueue(9);
	std::cout<<q1.top_El()<<"\n";
	std::cout<<q1.dequeue()<<","<<"\n";
	if (q1.Qis_empty())
		std::cout<<"q1 is  empty"<<","<<"\n";
		
	if (!q1.Qis_full())
		std::cout<<"q1 is not full"<<","<<"\n";
	q1.enqueue(5);
	Queue q2(6);
	q2=q1;
	std::cout<<q2.dequeue()<<","<<"\n";
	Queue q3(q1);
	std::cout<<q3.dequeue()<<","<<"\n";
}
