#include "Deque.h"
template <typename T>
class Stack
{
private:
	Deque<T> stack_;

public:
	Stack(void) {}
	~Stack(void) {}

	void   push(const T& value) { stack_.push_back(value);  }
	void   pop()                { stack_.pop_back();        }
	T&     top()                { return stack_.back();     }
	size_t size()               { return stack_.size();     }
	T&     at(size_t index)  	{ return stack_.at(index);  }
	string toString() const     { return stack_.toString(); }
};