#include <assert.h>
#include <stdio.h>

template<class AnyType>
class Queue
{
public:
	Queue(size_t cap){
		capacity = cap;
		in = 0;
		out = 0;
		count  = 0;
		data = new AnyType[capacity];
	}

	~Queue(){
		delete[] data;
	}

	bool isEmpty() {
		return count == 0;
	}

	bool isFull() {
		return count == capacity;
	}

	void put(AnyType item) {
		if(!isFull()) {
			data[in] = item;
			in = ( in + 1 ) % capacity;
			count += 1;
		}
	}

	AnyType take() {
		if(!isEmpty()) {
			size_t ret = out;
			out = ( out + 1 ) % capacity;
			count -= 1;
			return data[ret];
		}
		return -1;
	}
	void print() {
		// printf("%lu ",capacity);
		for (int i = 0; i < capacity; ++i)
		{
			printf("%d ", (data)[i]);
		}
		printf("\n");
	}

private:
	AnyType *data;
	size_t in;
	size_t out;
	size_t capacity;
	size_t count;
};


int main(int argc, char const *argv[])
{
	/* code */
	Queue<int> queue(3);
	
	assert(queue.isEmpty());

	queue.put(0);
	queue.print();

	assert(!queue.isEmpty());
	
	queue.put(1);

	queue.put(2);
	assert(queue.isFull());
	queue.put(3);
	queue.print();
	
	assert( queue.take() == 0);
	assert( queue.take() == 1);
	assert( queue.take() == 2);
	assert( queue.take() == -1);

	assert( queue.isEmpty());

	queue.put(3);
	queue.print();
	return 0;
}

