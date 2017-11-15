/*********************************************************************************************
** Program name:List.cpp
** Author:Joshua Herrera
** Date:04/30/2017
** Description: This code contains the List class. It's purpose is to contain the definitions of the member
** functions. They include code to make a dynamic array, adding an Item object to the dynamic
** array, setting the size of the array, getting the size of the array, making the array bigger
** or smaller, removing Item objects from the list, and printing the array.
*********************************************************************************************/

#include "List.hpp"
#include "utilities.hpp"
#include <algorithm>
#include <iomanip>

/*************************************************************************************
** List constructor
** This takes no arguments and returns nothing. It's sole purpose is to initialize our
** dynamic array
*************************************************************************************/
List::List()
{
    //allocate an array of ints
    list = new Item[arraySize];
}

/*************************************************************************************
** setSize
** This constructor sets the size of our array. takes as an argument an int and returns
** nothing
*************************************************************************************/
void List::setSize(int size)
{
    //make sure new array size is >= 4
    arraySize = size;
}

/*************************************************************************************
** getSize
** takes no arguments and returns an int, the arraySize
*************************************************************************************/
int List::getSize()
{
    return arraySize;
}

/*************************************************************************************
** resizeListBigger
** This class takes no arguments and returns nothing. It's purpose is to make the array
** bigger by one space to allocate new items. 
*************************************************************************************/
void List::resizeListBigger()
{
    //take in the old size of the array, because arraySize will be increased to allow
    //for another element
    int oldSize = arraySize;
    arraySize++;
    //initialize a dynamaic array with new arraySize
    temp = new Item[arraySize];
    //use c++11 standard to copy
    std::copy(list, list + oldSize, temp);
    //free memory of old list
    delete[] list;
    //assign old pointer to our new array
    list = temp;
    resized = true;
}

/*************************************************************************************
** addtoList
** returns nothing and takes as an argument an Item object. It is used to add an Item 
** to the List object. It first checks to see if the item is present in the list. If
** it is, we ask the user if we want to update it. If the item is not in the list, we
** add it to the list.
*************************************************************************************/
void List::addToList(Item newItem)
{
    //may need to reset dupeFound to false each time called, to ensure no errors
    dupeFound = false;
    if (counter != 0)
    {
        ///used for switch statement
        int userChoice = 0;
        //loop to check if an item is already present in the array
        for (int i = 0; i < arraySize; i++)
        {
            if (list[i] == newItem)
            {
                //change bool flag to true so program knows not to add the item twice
                dupeFound = true;
                //let user know the item was found and display the old items attributes
                std::cout << "Item found in list.\n";
                list[i].printItem();
                std::cout <<  "\nUpdate information? Enter 1 for yes, 2 for no\n";
                userChoice = getUserInt(1,2);
                switch (userChoice)
                {
                    //the user wants to update the item. In this case we assign the new Item
                    //to the space of the old one
                    case 1:
                    {
                        list[i] = newItem;
                        std::cout << "\nItem added successfully.\n";
                        break;
                    }
                    //in this case, nothing is changed.
                    case 2:
                    {
                        std::cout << "\nLeaving current item in list.\n";
                        break;
                    }
                }
            }
        }
    }
    //dupeFound is false when a duplicate item was not found in the list
    if (dupeFound == false)
    {
        //if conditional should check each space starting from array[0]
        //as long as counter is less than arraySize, that means we have space, specifically at
        //the cell number for counter's int. So we add the item there
        if (counter < arraySize)
        {
            list[counter] = newItem;
        }
        //once count == arraySize, the array is full so we call resize
        //to increase array by one and add it at the last spot.
        else
        {
            //increase array size by 1
            resizeListBigger();
            list[counter] = newItem;        
        }
        counter++;
        std::cout << "\nItem added successfully.\n";
    }
}

/*************************************************************************************
** resizeListSmaller
** This class takes no arguments and returns nothing. It's purpose is to make the array
** smaller by one space to remove a duplicate item. 
*************************************************************************************/
void List::resizeListSmaller()
{
    arraySize--;
    //trying to initialize temp pointer in private
    temp = new Item[arraySize];
    //use c++11 standard to copy
    std::copy(list, list + arraySize, temp);
    delete[] list;
    list = temp;
    resized = true;
}
/*************************************************************************************
** removeFromList
** This function takes a string as an argument and returns nothing. The purpose of this
** code is to remove the item from the list. It does so by searching each element by
** item name and comparing it to the item name given.
*************************************************************************************/
void List::removeFromList(std::string item)
{
    //bool flag to determine if an item has been found or not
    bool itemFound = false;
    //make item all lowercase for comparison purposes
    std::transform(item.begin(), item.end(), item.begin(), ::tolower);
    //std::cout << item << '\n';
    //loop through list and check to see if any elements are the same
    for(int i = 0; i < arraySize; i++)
    {
        //check by item names
        std::cout << "Checking list...\n";
        if (list[i].getItemName() == item)
        {
            //change bool to true to indicate we found the item
            itemFound = true;
            std::cout << "Found item.\nRemoving...\n";
            //copy the last item in the list to the location of the 
            //item to be removed
            list[i] = list[counter - 1];
            //copy over desired values into a smaller array and
            //free the memory from the old array.
            resizeListSmaller();            
            counter--;
        }
    }
    //we checked the whole list, and the item was never found
    if(itemFound == false)
    {
        std::cout << "Item not found in list.\n";
    }
    else
    {
        std::cout << "Item removed successfully.\n";
    }
    
}

/*************************************************************************************
** printList
** takes no arguments and returns nothing. The sole purpose of this function is to 
** print the list of Items.
*************************************************************************************/
void List::printList()
{
    //placeholder for the total price of the grocery list
    double total = 0.0;
    //use a loop to print through each element and print it's attributes
    //then add the cost of that item to the total.
    for(int i = 0; i < counter; i++)
    {
        list[i].printItem();
        total += list[i].totalCost();
    }
    std::cout << "Total cost of grocery list: $" << std::fixed << std::showpoint << std::setprecision(2) << total << std::endl;
}

/************************************************************************************
** isEmpty
************************************************************************************/
bool List::isEmpty()
{
    if (counter > 0)
    {
        return false;
    }
    return true;
}

/*************************************************************************************
** ~List deconstructor
** takes no arguments and returns nothing
** It's sole purpose is to free the memory used by the temp array
*************************************************************************************/
List::~List()
{
    delete[] temp;
    /***********************************************
    **if the array was not resized, we need to deallocate
    **the memory allocated for list. When it IS resized
    **the memory is freed in the resized function
    ***********************************************/
    if (resized == false)
    {
        delete[] list;
    }
    
}