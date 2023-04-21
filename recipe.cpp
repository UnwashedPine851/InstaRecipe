#include <iostream>
#include "recipe.h"

// default constructor
Recipe::Recipe()
{

}

// constructor with arguments
Recipe::Recipe(std::string name, int minutes, float calories, float totalFatPDV, float sugarPDV, float sodiumPDV,
               float proteinPDV, float saturatedFatPDV, float totalCarbohydratePDV, std::vector<std::string> steps, std::vector<std::string> ingredients)
{
    this->name = name;
    this->minutes = minutes;
    this->calories = calories;
    this->totalFatPDV = totalFatPDV;
    this->sugarPDV = sugarPDV;
    this->sodiumPDV = sodiumPDV;
    this->proteinPDV = proteinPDV;
    this->saturatedFatPDV = saturatedFatPDV;
    this->totalCarbohydratePDV = totalCarbohydratePDV;
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

float Recipe::getSaturatedFatPDV()
{
    return saturatedFatPDV;
}

float Recipe::getTotalCarbohydratePDV()
{
    return totalCarbohydratePDV;
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
    std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "Recipe Name: " << name << std::endl;
    std::cout << std::endl;
    std::cout << "Minutes to prepare recipe: " << minutes << std::endl;
    std::cout << std::endl;
    std::cout << "Nutrition Facts: " << std::endl;
    std::cout << "Calories: " << calories << std::endl;
    std::cout << "Total Fat (PDV): " << totalFatPDV << std::endl;
    std::cout << "Sugar (PDV): " << sugarPDV << std::endl;
    std::cout << "Sodium (PDV): " << sodiumPDV << std::endl;
    std::cout << "Protein (PDV): " << proteinPDV << std::endl;
    std::cout << "Saturated Fat (PDV): " << saturatedFatPDV << std::endl;
    std::cout << "Total Carbohydrate (PDV): " << totalCarbohydratePDV << std::endl;
    std::cout << std::endl;
    std::cout << "Ingredients: " << std::endl;
    for (int i = 0; i < ingredients.size(); i++)
    {
        std::cout << i + 1 << ". " << ingredients[i] << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Steps: " << std::endl;
    for (int i = 0; i < steps.size(); i++)
    {
        std::cout << i + 1 << ". " << steps[i] << std::endl;
    }

    std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
}
