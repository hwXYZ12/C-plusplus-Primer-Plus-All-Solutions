// queue.h - ch12e5, ch14e3, & ch14e4
#ifndef QUEUE_H_
#define QUEUE_H_

namespace QUEUE
{

	template <class Item>
	class Queue
	{
	private:
		// "Node" is a nested structure definition local to the Queue class
		struct Node { Item item; struct Node * next; };
		enum {Q_SIZE = 10};
		Node * front;		// pointer to front of the Queue
		Node * rear;		// pointer to the end of the Queue
		int items;			// current number of items in the Queue
		const int qsize;	// maximum number of items in the Queue
		// prevents public copying
		Queue(const Queue & q) : qsize(0)	{}
		Queue & operator=(const Queue &)					{ return *this;}
	public:
		Queue(int qs = Q_SIZE);		// create queue with a qs limit
		~Queue();
		bool isempty() const;
		bool isfull() const;
		int queuecount() const;
		bool enqueue(const Item & item);	// add item to end
		bool dequeue(Item & item);
	};

	// implementation
	template <class Item>
	Queue<Item>::Queue(int qs) : qsize(qs)
	{
		front = rear = NULL;	// nullptr
		items = 0;
	}

	
	template <class Item>
	Queue<Item>::~Queue()
	{
		Node * temp;
		while (front != NULL)	// while queue is not yet empty
		{
			temp = front;			// save address of front item
			front = front->next;	// reset pointer to next item
			delete temp;			// delete former front
		}
	}
	
	template <class Item>
	bool Queue<Item>::isempty() const
	{
		return (0 == items);
	}
	
	template <class Item>
	bool Queue<Item>::isfull() const
	{
		return (qsize == items);
	}
	
	template <class Item>
	int Queue<Item>::queuecount() const
	{
		return items;
	}

	// Add item to queue
	template <class Item>
	bool Queue<Item>::enqueue(const Item & item)
	{
		if (isfull())
			return false;
		Node * add = new Node;	// create Node
		/// on failure, new throws std::bad_alloc exception
		add->item = item;		// set node pointers
		add->next = nullptr;
		++items;
		if (front == NULL)		// if queue is empty
			front = add;		// place item at front
		else
			rear->next = add;	// else place at rear
		rear = add;				// have rear point to new node
		return true;
	}

	// Place front item into item variable and remove from queue
	template <class Item>
	bool Queue<Item>::dequeue(Item & item)
	{
		if (nullptr == front)
			return false;
		item = front->item;		// set item to first item in queue
		--items;
		Node * temp = front;	// save location of first item
		front = front->next;	// reset front to next item
		delete temp;			// delete former first item
		if (0 == items)
			rear = nullptr;
		return true;
	}
}


#endif