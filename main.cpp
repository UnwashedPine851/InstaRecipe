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
    recipes[0].print();

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
    int i = 0;

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
        line = line.substr(line.find('[') + 1);
        float calories = stof(line.substr(0, line.find(',')));
        line = line.substr(line.find(',') + 1);
        float totalFatPDV = stof(line.substr(0, line.find(',')));
        line = line.substr(line.find(',') + 1);
        float sugarPDV = stof(line.substr(0, line.find(',')));
        line = line.substr(line.find(',') + 1);
        float sodiumPDV = stof(line.substr(0, line.find(',')));
        line = line.substr(line.find(',') + 1);
        float proteinPDV = stof(line.substr(0, line.find(',')));
        line = line.substr(line.find(',') + 1);
        float saturatedFatPDV = stof(line.substr(0, line.find(',')));
        line = line.substr(line.find(',') + 1);
        float totalCarbohydratePDV = stof(line.substr(0, line.find(']')));

        // does not store the number of steps
        line = line.substr(line.find('\'') + 1);

        // stores the steps into a vector
        std::vector<std::string> steps;
        std::string stepsList = line.substr(0, line.find(']'));
        while (stepsList.find(',') != std::string::npos)
        {
            steps.push_back(stepsList.substr(0, stepsList.find('\'', 1)));
            if (stepsList.find('\'') + 3 < stepsList.size())
                stepsList = stepsList.substr(stepsList.find('\'') + 4);
            else
                break;
        }

        // stores the ingredients into a vector
        line = line.substr(line.find(']') + 4);
        line = line.substr(line.find('[') + 2);
        std::vector<std::string> ingredients;
        std::string ingredientsList = line.substr(0, line.find(']'));
        while (ingredientsList.find(',') != std::string::npos)
        {
            ingredients.push_back(ingredientsList.substr(0, ingredientsList.find('\'', 1)));
            if (ingredientsList.find('\'') + 3 < ingredientsList.size())
                ingredientsList = ingredientsList.substr(ingredientsList.find('\'') + 4);
            else
            {
                break;
            }
        }
        ingredients.push_back(ingredientsList.substr(0, ingredientsList.find('\'')));

        // creates a new recipe object and adds it to the vector of recipes
        Recipe newRecipe = Recipe(name, minutes, calories, totalFatPDV, sugarPDV, sodiumPDV, proteinPDV, saturatedFatPDV, totalCarbohydratePDV, steps, ingredients);
        recipes.push_back(newRecipe);
    }
}
