
#include "StackType.h"


StackType::StackType(int max)               // custom constructor
{
  maxStack = max;
  top = -1;                                 // because the first index = 0
  items = new int[maxStack];
}


StackType::StackType()                      // default constructor
{
  maxStack = 500;
  top = -1;
  items = new int[maxStack];
}


bool StackType::IsEmpty() const             // check if the top == -1
{
  return (top == -1);
}


bool StackType::IsFull() const              // check if the top == max - 1
{
  return (top == maxStack-1);
}


void StackType::Push(int newItem)           
{
  if (IsFull())                             // user-defined exception FullStack()
    throw FullStack();                      // throw that if IsFull() = true
  top++;                                    // else top increment 1
  items[top] = newItem;                     // let items[top] = newItem
}


void StackType::Pop()
{
  if( IsEmpty() )                           
    throw EmptyStack();                     // throw user-deined exception EmptyStack()
  top--;                                    // since it's array, don't really need to delete
}                                           // decrement top value, later overwrite for push


int StackType::Top()
{
  if (IsEmpty())
    throw EmptyStack();
  return items[top];                        // return the top item
}    


StackType::~StackType()
{
  delete [] items;                          // delete array pointer
}

