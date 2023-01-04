
struct NodeType;

class StackType
{
	
public:
  StackType();

  ~StackType();
  
  void Push(int newItem);
  
  void Pop();
  
  int Top();

  bool IsFull() const;

  bool IsEmpty() const;

public:
  NodeType* topPtr;

};
