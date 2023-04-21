#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "recipe.h"

void readRecipes(std::vector<Recipe>& recipes, std::string fileName);

int main()
{
    // initializes a vector to store the recipes
    std::vector<Recipe> recipes;

    readRecipes(recipes, "C://Users/emely/OneDrive/Desktop/Spring 2023/COP3530/RAW_recipes.csv");

    return 0;
}

void readRecipes(std::vector<Recipe>& recipes, std::string fileName)
{
    // opens the csv file
    std::ifstream file(fileName);
    //std::cout << file.is_open() << std::endl;

    // initializes variable to store each csv line
    std::string line;

    // reads the category names
    getline(file, line);

    // while there is a line in the csv file to be read
    while (getline(file, line))
    {
        // stores the recipe name
        std::string name = line.substr(0, line.find(','));

        // does not store the recipe id
        line = line.substr(line.find(',') + 1);

        // stores the recipe minutes
        line = line.substr(line.find(',') + 1);
        int minutes = stoi(line.substr(0, line.find(',')));

        // does not store the contributor id or date submitted
        line = line.substr(line.find(',') + 1);
        line = line.substr(line.find(',') + 1);

        // does not store the recipe tags
        line = line.substr(line.find(']') + 1);

        // stores the recipe nutrition facts
        line = line.substr(line.find(',') + 1);
        float calories = stof(line.substr(line.find(',') + 1));
        float totalFatPDV;
        float sugarPDV;
        float sodiumPDV;
        float proteinPDV;
        float saturatedFat;




    }
}
