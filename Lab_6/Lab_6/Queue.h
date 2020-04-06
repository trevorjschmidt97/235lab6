#include "Deque.h"
template <typename T>
class Queue
{
private:
	Deque<T> queue_;

public:
	Queue(void) {}

	~Queue(void) {}

	void   push(const T& value) { queue_.push_back(value); }

	void   pop()                { queue_.pop_front(); }

	T&     top()                { return queue_.front(); }

	size_t size()               { return queue_.size(); }

	T&     at(size_t index)     { return queue_.at(index); }

	string toString() const     { return queue_.toString(); }
};