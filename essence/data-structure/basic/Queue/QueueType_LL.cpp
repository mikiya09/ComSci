
#include <new>                                      // for bad_alloc
#include "QueueType_LL.h"

struct NodeType
{
    ItemType info;
    NodeType* next;
};

// Post: front and rear are set to NULL
QueType::QueType()                                  // class constructor
{
    front = NULL;
    rear = NULL;
}


// Post: Queue is empty; all elements have been deallocated
// don't have to worry about floating queue concept, because queue linked-list don't float
void QueType::MakeEmpty()
{
    NodeType* tempPtr;

    while (front != NULL)
    {
        tempPtr = front;
        front  = front->next;
        delete tempPtr;
    }
    rear = NULL;
}


// destructor
QueType::~QueType()
{
    MakeEmpty();                // deallocate all the nodes, set front and rear to NULL
}


// returns true if there is no space for another NodeType object in heap memory
// false otherwise
bool QueType::IsFull() const
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


// return true if there are no elements on the queue and false otherwise
bool QueType::IsEmpty() const
{
    return (front == NULL);             // only need to check front's value, front is a node
}


// add newItem to the rear of the queue
// pre:  Queue has been initialized
// post: If (queue is not full), newItem is at the rear of the queue, otherwise FullQueue()

void QueType::Enqueue(ItemType newItem)
{
    if (IsFull())
        throw FullQueue();
    else
    {
        NodeType* newNode;              // create newNode for storing newItem into info

        newNode = new NodeType;
        newNode->info = newItem;
        newNode->next = NULL;           // item is added from the rear, it points to NULL
        if (rear == NULL)               // check if this is the first node
            front = newNode;
        else
            rear->next == newNode;      // rear originally point to second last node
                                        // rear->next make the second last point to newNode
                                        // remember newNode here is a pointer (address)
        rear = newNode;                 // directly make rear pointer = newNode pointer
    }
}


// remove front item from the queue and returns(store) it in item variable
// pre:  Queue has been initialized
// post: If (queue is not empty), the front of the queue has been removed 
//       and a copy returned in item, otherwise EmptypQueue() exception

void QueType::Dequeue(ItemType& item)
{
    if (IsEmpty())
        throw EmptyQueue();
    else
    {
        NodeType* tempPtr;

        tempPtr = front;
        item = front->info;
        front = front->next;

        if (front == NULL)          // if the one deleted is the only node
            rear = NULL;            // make both pointer point to NULL
        delete tempPtr;
    }
}
