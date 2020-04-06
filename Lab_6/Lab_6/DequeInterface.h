//**** YOU MAY NOT MODIFY THIS DOCUMENT ****/
#ifndef DEQUE_INTERFACE_H
#define DEQUE_INTERFACE_H
#include <string>

#define DEFAULT_CAPACITY 4

template<typename T>
class DequeInterface
{
private:
	size_t capacity;
	size_t num_items;
	size_t front_index;
	size_t rear_index;
	T* the_data;

public:
	DequeInterface(void) {}
	virtual ~DequeInterface(void) {}

	virtual void push_front(const T& value) = 0;	/** Insert item at front of deque */
	virtual void push_back(const T& value) = 0;	/** Insert item at rear of deque */
	virtual void pop_front(void) = 0;	/** Remove the front item of the deque */
	virtual void pop_back(void) = 0;	/** Remove the rear item of the deque */
	virtual T& front(void) = 0;	/** Return the front item of the deque (Do not remove) */
	virtual T& back(void) = 0;	/** Return the rear item of the deque (Do not remove) */
	virtual size_t size(void) const = 0;	/** Return the number of items in the deque */
	virtual bool empty(void) const = 0;	/** Return true if deque is empty */
	virtual T& at(size_t index) = 0;	/** Return item in deque at index (0 based) */
	virtual std::string toString(void) const = 0;	/** Return the deque items */
};
#endif // DEQUE_INTERFACE_H