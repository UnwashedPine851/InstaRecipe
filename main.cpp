#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include "recipe.h"

void readRecipes(std::vector<Recipe>& recipes, std::string fileName);

void MergeHelper(std::vector<Recipe> recipeList, int left, int mid, int right, int nutrientChoice);

void MergeSort(std::vector<Recipe> &recipeList, int left, int right, int nutrientChoice);

int main()
{
    // initializes a vector to store the recipes
    std::vector<Recipe> recipes;

    // sets a start time
    auto start = std::chrono::high_resolution_clock::now();

    // stores recipes in a recipe vector
    readRecipes(recipes, "C://Users/emely/OneDrive/Desktop/Spring 2023/COP3530/RAW_recipes.csv");

    // sets a stop time
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << "Time in milliseconds to load CSV file: " << duration.count() << std::endl << std::endl;

    // prints welcome message
    std::cout << "Welcome to InstaRecipe! We're happy to have you here :)" << std::endl;

    int option = 0;

    MergeSort(recipes, 0, recipes.size() - 1, 1);

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

//Credit to COP3530 Slides

void MergeHelper(std::vector<Recipe> recipeList, int left, int mid, int right, int nutrientChoice)
{
    //Create X < arr[left..mid] & Y < arr[mid+1..right]
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<Recipe> X(n1);
    std::vector<Recipe> Y(n2);

    for(int i = 0; i < n1; i++)
        X.insert(X.begin() + i, recipeList[left + i]);
    for(int j = 0; j < n2; j++)
        Y.insert(Y.begin() + j, recipeList[mid + 1 + j]);

    //Merge arrays X and Y into arr
    int i, j, k;
    i = 0;
    j = 0;
    k = left;

    switch(nutrientChoice)
    {
        case 1:
            while(i < n1 && j < n2)
            {
                if(X[i].getCalories() <= Y[j].getCalories())
                {
                    recipeList[k] = X[i];
                    i++;
                }
                else
                {
                    recipeList[k] = Y[j];
                    j++;
                }
                k++;
            }
            break;
        case 2:
            while(i < n1 && j < n2)
            {
                if(X[i].getTotalFatPDV() <= Y[j].getTotalFatPDV())
                {
                    recipeList[k] = X[i];
                    i++;
                }
                else
                {
                    recipeList[k] = Y[j];
                    j++;
                }
                k++;
            }
            break;
        case 3:
            while(i < n1 && j < n2)
            {
                if(X[i].getSugarPDV() <= Y[j].getSugarPDV())
                {
                    recipeList[k] = X[i];
                    i++;
                }
                else
                {
                    recipeList[k] = Y[j];
                    j++;
                }
                k++;
            }
            break;
        case 4:
            while(i < n1 && j < n2)
            {
                if(X[i].getSodiumPDV() <= Y[j].getSodiumPDV())
                {
                    recipeList[k] = X[i];
                    i++;
                }
                else
                {
                    recipeList[k] = Y[j];
                    j++;
                }
                k++;
            }
            break;
        case 5:
            while(i < n1 && j < n2)
            {
                if(X[i].getProteinPDV() <= Y[j].getProteinPDV())
                {
                    recipeList[k] = X[i];
                    i++;
                }
                else
                {
                    recipeList[k] = Y[j];
                    j++;
                }
                k++;
            }
            break;
        case 6:
            while(i < n1 && j < n2)
            {
                if(X[i].getSaturatedFatPDV() <= Y[j].getSaturatedFatPDV())
                {
                    recipeList[k] = X[i];
                    i++;
                }
                else
                {
                    recipeList[k] = Y[j];
                    j++;
                }
                k++;
            }
            break;
    }

    //When we run out of element in either X or Y append the remaining elements
    while(i < n1)
    {
        recipeList[k] = X[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        recipeList[k] = Y[j];
        j++;
        k++;
    }
}

void MergeSort(std::vector<Recipe> &recipeList, int left, int right, int nutrientChoice) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        MergeSort(recipeList, left, mid, nutrientChoice);
        MergeSort(recipeList, mid + 1, right, nutrientChoice);

        //Merge the sorted subarrays
        MergeHelper(recipeList, left, mid, right, nutrientChoice);
    }
}
