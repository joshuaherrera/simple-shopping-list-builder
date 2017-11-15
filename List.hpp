/*********************************************************************
** Program name:List.hpp
** Author:Joshua Herrera
** Date:04/30/2017
** Description: This class header contains the private variables and prototypes that are to be used in the 
** List class. It is used to abstract away the grocery list. In depth explanations of the functions
** can be found in Item.cpp
*********************************************************************/

#ifndef LIST_HPP
#define LIST_HPP

#include "Item.hpp"
#include <string>

class List
{
private:
    //max array size
    int arraySize = 4,
        //variable to keep track of how many items input
        counter = 0;
    //used in our addToList function. If a duplicate found, changed to true
    bool dupeFound = false,
    //used for our destructor, to let the program know whether to deallocate the 
    //list memory there or not.
         resized = false;
    //used to make arrays
    Item* list = NULL;
    Item* temp = NULL;
public:
    List();
    void setSize(int);
    int getSize();
    void addToList(Item);
    void resizeListBigger();
    void resizeListSmaller();
    void printList();
    void removeFromList(std::string);
    bool isEmpty();
    ~List();
};

#endif // LIST_HPP
