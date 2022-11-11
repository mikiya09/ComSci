
#include "QueType.h"

// Post: (1) maxQue, front, and rear have been initialized. 
//       (2) The array to hold the queue elements has been dynamically allocated.
QueType::QueType(int max)
{
  maxQue = max + 1;
  front = maxQue - 1;
  rear = maxQue - 1;
  items = new int[maxQue];
}


// Post: (1) maxQue, front, and rear have been initialized. 
//       (2) The array to hold the queue elements has been dynamically allocated.

QueType::QueType()                                  // Default class constructor
{
  maxQue = 501;
  front = maxQue - 1;                               // space precede the first item
                                                    // so it's the last index
  rear = maxQue - 1;                                // actual last index
                                                    // make sense since front = rear is empty
                                                    // front = rear + 1 is full
  items = new int[maxQue];
}


// Destructor
QueType::~QueType()
{
  delete [] items;
}


// Post: front and rear have been reset to the empty state.
void QueType::MakeEmpty() 
{
  front = maxQue - 1;                               // don't really need to delete
  rear = maxQue - 1;                                // array-based just override
}


bool QueType::IsEmpty() const
{
  return (rear == front);
}


bool QueType::IsFull() const
{
  return ((rear + 1) % maxQue == front);            // mod used here
}


// Post: If (queue is not full) newItem is at the rear of the queue; 
// otherwise a FullQueue exception is thrown.  
void QueType::Enqueue(int newItem) 
{
  if (IsFull())
    throw FullQueue();
  else
  {
    rear = (rear +1) % maxQue;                     // include % in the calculation
    items[rear] = newItem;                         // deal with the situation rear is the end
  }
}



// Post: If (queue is not empty) the front of the queue has been removed 
// and a copy returned in item; othersiwe a EmptyQueue exception has been thrown.
void QueType::Dequeue(int& item)
{
  if (IsEmpty())
    throw EmptyQueue();
  else
  {
    front = (front + 1) % maxQue;
    item = items[front];
  }
}


