#include <iostream>
#include "recipe.h"

// default constructor
Recipe::Recipe()
{

}

// constructor with arguments
Recipe::Recipe(std::string name, int minutes, float calories, float totalFatPDV, float sugarPDV, float sodiumPDV,
               float proteinPDV, float saturatedFat, std::vector<std::string> steps, std::vector<std::string> ingredients)
{
    this->name = name;
    this->minutes = minutes;
    this->calories = calories;
    this->totalFatPDV = totalFatPDV;
    this->sugarPDV = sugarPDV;
    this->sodiumPDV = sodiumPDV;
    this->proteinPDV = proteinPDV;
    this->saturatedFat = saturatedFat;
    this->steps = steps;
    this->ingredients = ingredients;
}

// accessors
std::string Recipe::getName()
{
    return name;
}

int Recipe::getMinutes()
{
    return minutes;
}

float Recipe::getCalories()
{
    return calories;
}

float Recipe::getTotalFatPDV()
{
    return totalFatPDV;
}

float Recipe::getSugarPDV()
{
    return sugarPDV;
}

float Recipe::getSodiumPDV()
{
    return sodiumPDV;
}

float Recipe::getProteinPDV()
{
    return proteinPDV;
}

float Recipe::getSaturatedFat()
{
    return saturatedFat;
}

std::vector<std::string> Recipe::getSteps()
{
    return steps;
}

std::vector<std::string> Recipe::getIngredients()
{
    return ingredients;
}

// methods
void Recipe::print()
{

}
