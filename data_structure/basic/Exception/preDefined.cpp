
#include <new>

bool UnsortedType::IsFull() const
// return true if there is no room for another ItemType 
// on the free store; false otherwise 
{
    NodeType* location;
    try
    {
        location = new NodeType;
        delete location;
        return false;
    }
    catch (std::bad_alloc exception)
    {
        return true;
    }
}

