
#ifndef SORTED
#define SORTED

#include "ItemType.h" 
// File ItemType.h must be provided by the user of this class. 
//  MAX_ITEMS:     100

class SortedType 
{
public:
  SortedType();

  void MakeEmtpy();
  
  bool IsFull() const;

  int GetLength() const;

  ItemType GetItem(ItemType item, bool& found);

  void PutItem(ItemType item);

  void DeleteItem(ItemType item);

  void ResetList();

  ItemType GetNextItem();

  void MakeEmpty();

private:
  int length;
  ItemType info[100];       // assume the max length = 100
  int currentPos;
};

#endif
