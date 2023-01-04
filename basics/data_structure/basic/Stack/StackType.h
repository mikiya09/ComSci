
class FullStack
// Exception class thrown by Push when stack is full.
{};

class EmptyStack
// Exception class thrown by Pop and Top when stack is emtpy.
{};

class StackType
{
public:

   StackType();
   
   StackType(int size);

   ~StackType();

   bool IsFull() const;

   bool IsEmpty() const;

   void Push(int item);

   void Pop();

   int Top();


private:
   int top;
   int maxStack;
   int* items;
};
