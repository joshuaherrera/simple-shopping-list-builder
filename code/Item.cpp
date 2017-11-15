/*********************************************************************************************
** Program name:Item.cpp
** Author:Joshua Herrera
** Date:04/30/2017
** Description: The Item.cpp class contains the definitions of the member functions for Item. They include
** the constructors, finding the total cost, printing the item, getting the item name of a 
** class and overloading the == operator.
*********************************************************************************************/

#include "Item.hpp"
#include <algorithm>
#include <iomanip>

/*************************************************************************************
** Item constructor (default)
** The default constructor sets the private variables either to empty or to zeroes. 
** It should never be used and is only declared as a fallback.
*************************************************************************************/
Item::Item()
{
    itemName = "empty";
    unit = "empty";
    quantity = 0;
    unitPrice = 0;
}

/*************************************************************************************
** Item constructor
** The constructor takes as arguments two strings, an int, and a double. It returns nothing.
** It is used to declare an Item object and assign it's private variables.
*************************************************************************************/
Item::Item(std::string i, std::string u, int q, double uP)
{
    itemName = i;
    //make the item name lower case for search purposes
    std::transform(itemName.begin(), itemName.end(), itemName.begin(), ::tolower);
    unit = u;
    quantity = q;
    unitPrice = uP;
}

/*************************************************************************************
** totalCost
** This function returns a double and takes no arguments. The purpose of this code
** is to find the total cost of the desired item(s), by multiplying quantity and unitPrice
*************************************************************************************/
double Item::totalCost()
{
    return double(quantity) * double(unitPrice);
}

/*************************************************************************************
** printItem
** This function takes no arguments and returns nothing. It's sole purpose is to print
** the Item information; itemName, unit, unitPrice, and the total cost of the item.
*************************************************************************************/
void Item::printItem()
{
    std::cout << "\n***********************************\n"
              << "Item name: " << itemName
              << "\nUnit: " << unit
              << "\nQuantity: " << quantity
              << "\nPrice per unit: $" << std::fixed << std::showpoint << std::setprecision(2) << unitPrice
              << "\nTotal cost for " << itemName << ": $" << std::fixed << std::showpoint << std::setprecision(2) << totalCost()
              << "\n***********************************\n";
}

/*************************************************************************************
** getItemName
** The code returns a string and takes no arguments. It is meant to just return the 
** private variable itemName. It will be used for comparison purposes mainly.
*************************************************************************************/
std::string Item::getItemName()
{
    return itemName;
}

bool Item::operator==(Item toTest)
{
    //should already be all lowercase
    return this->getItemName() == toTest.getItemName();
}
