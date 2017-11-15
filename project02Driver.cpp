/*********************************************************************************************
** Program name:project02Driver.cpp
** Author:Joshua Herrera
** Date:04/30/2017
** Description: This class contains the code used to make a grocery list. It makes menus and 
** makes a List object to store user defined Item objects.
*********************************************************************************************/

#include <iostream>
#include <string>
#include "Item.hpp"
#include "List.hpp"
#include "Menu.hpp"
#include "utilities.hpp"

int main()
{
    int mainChoice = 0;
    Menu main("Add/Update item to list");
    main.addEntry("Remove item from list");
    main.addEntry("Display list");
    main.addEntry("Exit");
    List list;
    clearScreen();
    std::cout << "Let's make a grocery list. To do so, we must enter items into a list.\n"
              << "This program also allows for the removal of added items, updating existing items and displaying the list.\n";

    do
    {
       main.display();
       mainChoice = getUserInt(1, 4);

       switch (mainChoice)
       {
        //add an item
        case 1:
        {
            clearScreen();
            std::string itemName,
                        unit;
            double unitPrice = 0.0;
            const double MIN = 0.0, MAX = 3999.99;
            int quantity = 0,
                addChoice = 0;
            const int LOWER = 0, UPPER = 99;
            //booleans so program knows if any information is not input by user
            bool i = false,
                 u = false,
                 uP = false,
                 q = false;

            Menu add("Input item name");
            add.addEntry("Input unit type");
            add.addEntry("Input price per unit");
            add.addEntry("Input quantity");
            add.addEntry("Add Item to list");

            do
            {
                std::cout << "To update an item that is already in the list, enter the current item "
                          << "name and input all other required information\n";
                add.display();
                addChoice = getUserInt(1, 5);

                switch (addChoice)
                {
                    //item name
                    case 1:
                    {
                        clearScreen();
                        std::cout << "Please enter the item name\n";
                        itemName = getUserString();
                        i = true;
                        break;
                    }

                    //unit type
                    case 2:
                    {
                        clearScreen();
                        std::cout << "Please enter the unit type\n";
                        unit = getUserString();
                        u =true;
                        break;
                    }

                    //unit price
                    case 3:
                    {
                        clearScreen();
                        std::cout << "Please enter the price per unit\n"
                                  << "The price should be between $" << MIN << " and $" << MAX << '\n';
                        unitPrice = getUserDouble(MIN, MAX);
                        uP = true;
                        break;
                    }

                    //quantity
                    case 4:
                    {
                        clearScreen();
                        std::cout << "Please enter the quantity to be bought\n"
                                  << "The amount must be between " << LOWER << " and " << UPPER << '\n';
                        quantity = getUserInt(LOWER, UPPER);
                        q = true;
                        break;
                    }

                    //exit. if empty ask to reenter. else make the item and add to the list
                    case 5:
                    {
                        clearScreen();
                        if (i == false || u == false || uP == false || q == false)
                        {
                            std::cout << "Some information is missing.\n"
                                      << "The item will NOT be added to the list.\n"
                                      << "Please reenter option 1 from the main menu and ensure all information is entered to have the item added.\n";
                        }
                        else
                        {
                            Item item(itemName, unit, quantity, unitPrice);
                            list.addToList(item);
                        }
                        break;
                    }
                }
            } while (addChoice != 5);

            break;
        }

        //remove
        case 2:
        {
            clearScreen();
            if (list.isEmpty() == true)
            {
                std::cout << "The list is empty! No items to remove.\n";
            }
            else
            {
                std::string itemToRemove;
                clearScreen();
                std::cout << "Enter the name of the item you wish to remove\n";
                itemToRemove = getUserString();
                list.removeFromList(itemToRemove);
            }

            break;
        }

        //display
        case 3:
        {
            clearScreen();
            if (list.isEmpty() == true)
            {
                std::cout << "The list is empty! No items to display.\n";
            }
            else
            {
                list.printList();
            }
            break;
        }

        //exit
        case 4:
        {
            clearScreen();
            break;
        }
       }
    } while (mainChoice != 4);

    std::cout << "Exiting...\n";

    return 0;
}