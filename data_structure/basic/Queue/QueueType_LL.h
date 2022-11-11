
// .h
// Header file for ADT queue

class FullQueue {};
class EmptyQueue {};

typedef char ItemType;
struct NodeType;

class QueType
{
public:
    QueType();
    ~QueType();

    void MakeEmpty();
    void Enqueue(ItemType);
    void Dequque(ItemType&);        // item store copies is a node, modify it ditectly
    bool IsEmpty() const;
    bool IsFull() const;

private:
    NodeType* front;
    NodeType* rear;
};
