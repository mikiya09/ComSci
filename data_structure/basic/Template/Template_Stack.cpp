class FullStack {};
class EmptyStack {};

// .h
// ===========================================
template<class ItemType>
class StackType 
{
public:
    StackType();
    bool IsEmpty() const;
    bool IsFull() const;
    void Push(ItemType item);
    void Pop();
    ItemType Top() const;

private:
    int top;
    ItemType items<100>
};

// .cpp
// ===========================================
// constructor 
template<class ItemType> 
StackType<ItemType>::StackType()
{
    top = -1;
}

// is empty
template<class ItemType>
bool StackType<ItemType>::IsEmpty() const
{
    return (top == -1);
}

// is full
template<class ItemType>
bool StackType<ItemType>::IsFull() const
{
    return (top == 100 -1);
}

// push
template<class ItemType>
void StackType<ItemType>::Push(ItemType newItem)
{
    if (IsFull())
        throw FullStack();
    top ++;
    items<top> = newItem;
}

// pop
template<class ItemType>
void StackType<ItemType>::Pop()
{
    if (IsEmpty())
        throw EmptyStack();
    top --;
}

// return top value
template<class ItemType>
ItemType StackType<ItemType>::Top()
{
    if (IsEmpty())
        throw EmptyStack();
    return items<top>;
}
