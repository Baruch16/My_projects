
class Stack
{
public:
	explicit Stack();
	explicit Stack(int size);
	explicit Stack(const Stack &other);
    	Stack &operator=(const Stack &other);
	~Stack();
	
	void push(int x);
	int pop();
	int topEl() const;
	bool isEmpty() const;
	bool isFull() const;
	int get_m_top() const;
	void print() const;
	int get_m_array() const;
private:
	int default_size=50;
	int* m_array;
	int m_top;
	int m_size;
};
