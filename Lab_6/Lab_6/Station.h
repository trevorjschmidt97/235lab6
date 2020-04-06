#ifndef STATION_H
#define STATION_H
#include "Deque.h"
#include "Vector.h"
#include "Stack.h"
#include "Queue.h"

template <typename T>
class Station
{
private:
	Vector<T> train_;
	Stack<T> stack_;
	Queue<T> queue_;
	T turnTableCar;
	bool empty = true;

public:
	Station(void) {}
	~Station(void) {}

	string addCar(const T& data)
	{	
		if (empty)
		{
			turnTableCar = data;
			empty = false;
			return "OK";
		}
		return "Turntable occupied!";
	}

	string removeCar()
	{
		if (!empty)
		{
			train_.push_back(turnTableCar);
			empty = true;
			return "OK";
		}
		return "Turntable empty!";
	}

	string topCar()
	{
		return "Not Yet Implemented";
	}

	string addStack()
	{
		if (!empty)
		{
			stack_.push(turnTableCar);
			empty = true;
			return "OK";
		}
		return "Turntable empty!";
	}

	string removeStack()
	{
		if (!empty)
		{
			return "Turntable occupied!";
		}
		else if (stack_.size() == 0)
		{
			return "Stack empty!";
		}
		turnTableCar = stack_.top();
		stack_.pop();
		empty = false;
		return "OK";
	}

	string topStack()
	{
		if (stack_.size() != 0)
		{
			return to_string(stack_.top());
		}
		return "Stack empty!";
	}

	string sizeStack()
	{
		return to_string(stack_.size());
	}

	string addQueue()
	{
		if (!empty)
		{
			queue_.push(turnTableCar);
			empty = true;
			return "OK";
		}
		return "Turntable empty!";
	}

	string removeQueue()
	{
		if (!empty)
		{
			return "Turntable occupied!";
		}
		else if (queue_.size() == 0)
		{
			return "Queue empty!";
		}
		turnTableCar = queue_.top();
		queue_.pop();
		empty = false;
		return "OK";
	}

	string topQueue()
	{
		if (queue_.size() != 0)
		{
			return to_string(queue_.top());
		}
		return "Queue empty!";
	}

	size_t sizeQueue()
	{
		return queue_.size();
	}

	string find(T data)
	{

		for (size_t i = 0; i < train_.size(); i++)
		{
			if (train_.at(i) == data)
			{
				return "Train[" + to_string(i) + "]";
			}
		}

		for (size_t i = 0; i < queue_.size(); i++)
		{
			if (queue_.at(i) == data)
			{
				return "Queue[" + to_string(i) + "]";
			}
		}
		

		for (size_t i = 0; i < stack_.size(); i++)
		{
			if (stack_.at(i) == data)
			{
				return "Stack[" + to_string(i) + "]";
			}
		}

		if (turnTableCar == data)
		{
			return "Turntable";
		}

		return "Not Found!";
	}

	string toString() const
	{
		return train_.toString();
	}
};

#endif // STATION_H