#include "StackType_LL.h"

struct NodeType                             // Node Type
{
  int info;
  NodeType* next;
};


StackType::StackType()
{
  topPtr = NULL;                            // constructor
}


bool StackType::IsFull() const              // check if there's still memory
{
    NodeType* location;
  try
  {
    location = new NodeType;
    delete location;
    return false;
  }
  catch(std::bad_alloc exception)
  {
    return true;
  }
}


// destructor (iterator)
StackType::~StackType()
{
  NodeType* tempPtr;                        // use tempPtr 

  while (topPtr != NULL)                    // as long as tempPtr != NULL
  {                                         // not yet reach the end
    tempPtr = topPtr;
    topPtr = topPtr->next;
    delete tempPtr;
  }
}


bool StackType::IsEmpty() const
{
  return (topPtr == NULL);
}


// Linked-List is automatically a stack seeing from left to right (as Top to Down in stack)
void StackType::Push(int newItem)
{
  if (IsFull())
    throw FullStack();                      // check if full
  else
  {
    NodeType* location;                     // not full, create new node to store newItem
    location = new NodeType;                // record address 
    location->info = newItem;               // record info
    location->next = topPtr;                // let newNode point to the first Node
    topPtr = location;                      // set topPtr pointing to the new Node
  }
}


void StackType::Pop()
{
  if (IsEmpty())
    throw EmptyStack();                     // check if empty
  else
  {  
    NodeType* tempPtr;                      // use tempPtr for deletion from the head
    tempPtr = topPtr;                       // refer to the figure below
    topPtr = topPtr->next;
    delete tempPtr;
  }
}


int StackType::Top()
{
  if (IsEmpty())
    throw EmptyStack();                     // check if empty
  else
    return topPtr->info;                    // return top value
}


