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

    // stores recipes in a recipe vector
    readRecipes(recipes, "C://Users/emely/OneDrive/Desktop/Spring 2023/COP3530/RAW_recipes.csv");

    // prints welcome message
    std::cout << "Welcome to InstaRecipe! We're happy to have you here :)" << std::endl;

    int option = 0;

    // infinite loop until the user exits
    while (option != 8)
    {
        // prints the menu and asks the user to input an option
        std::cout << "\nWhich nutrition fact would you like to search by?" << std::endl;
        std::cout << "1. Calories\n2. Total Fat (PDV)\n3. Sugar (PDV)\n4. Sodium (PDV)\n5. Protein (PDV)\n6. Saturated Fat (PDV)\n7. Total Carbohydrate (PDV)\n8. Quit" << std::endl;
        std::cin >> option;

        if (option == 8)
        {
            break;
        }
        else if (option == 1)
        {
            // calories
        }
        else if (option == 2)
        {
            // total fat
        }
        else if (option == 3)
        {
            // sugar
        }
        else if (option == 4)
        {
            // sodium
        }
        else if (option == 5)
        {
            // protein
        }
        else if (option == 6)
        {
            // saturated fat
        }
        else if (option == 7)
        {
            // carbs
        }
        else
        {
            std::cout << "Please input a valid option." << std::endl;
        }

    }

    // prints exit message
    std::cout << "Thanks for using InstaRecipe! We hope you found a recipe that fits your desired needs!" << std::endl;

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
