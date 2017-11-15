/*********************************************************************************************
** Program name:List.hpp
** Author:Joshua Herrera
** Date:04/30/2017
** Description: This class header contains the private variables and prototypes that are to be used in the 
** Item class. It is used to abstract away the items to be added to a grocery list. In depth
** explanations of the functions can be found in Item.cpp
*********************************************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP
#include <iostream>
#include <string>

class Item
{
private:
    std::string itemName,
                unit;
    int quantity = 0; 
    double unitPrice = 0.0;
public:
    Item();
    Item(std::string, std::string, int, double);
    double totalCost();
    void printItem();
    std::string getItemName();
    bool operator==(Item);
    
};

#endif // ITEM_HPP

