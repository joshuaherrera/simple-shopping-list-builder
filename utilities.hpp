/*********************************************************************
** Program name:utilities.hpp
** Author:Joshua Herrera
** Date:04/08/2017
** Description: This is the header for the helper functions for 162.
** It contains the prototypes for the helper functions to be used.
*********************************************************************/
#include <string>

#ifndef FUNCTIONS_HERRERA_HPP
#define FUNCTIONS_HERRERA_HPP

bool isIntValid(std::string, int, int);

bool isDoubleValid(std::string, double, double);

int getUserInt(int, int);

double getUserDouble(double, double);

void clearScreen();

std::string getUserString();

#endif // FUNCTIONS_HERRERA_HPP
