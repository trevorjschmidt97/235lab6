#include "Deque.h"
#ifndef VECTOR_H
#define VECTOR_H
template <typename T>
class Vector
{
private:
	Deque<T> vector_;

public:
	Vector(void) {}
	~Vector(void) {}

	void push_back(const T& data)
	{
		vector_.push_back(data);
	}

	T& pop_back()
	{
		T temp = vector_.back();
		vector_.pop_back();
		return temp;
	}

	T& back()
	{
		return vector_.back();
	}

	size_t size()
	{
		return vector_.size();
	}

	T& at(size_t index)
	{
		return vector_.at(index);
	}

	string toString() const
	{
		return vector_.toString();
	}
};
#endif // !VECTOR.H