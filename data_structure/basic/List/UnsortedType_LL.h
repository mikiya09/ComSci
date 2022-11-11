
#include <iostream>
using namespace std;

struct NodeType;

class UnsortedType
{
public:
    //Constructor 
    UnsortedType();
    // Destructor
    ~UnsortedType();

    void MakeEmpty();
    bool IsFull() const;

    int GetLength() const;
    ItemType GetItem(ItemType& item, bool& found);
    void PutItem(ItemType item);
    void DeleteItem(ItemType item);

    void ResetList();
    ItemType GetNextItem();

private:
  NodeType* listData;
  int length;
  NodeType* currentPos;
};

