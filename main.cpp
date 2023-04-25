#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include "recipe.h"
#include "binarySearch.h"
#include "QuickSort.h"
#include "mergeSort.h"

void readRecipes(std::vector<Recipe>& recipes, std::string fileName);

int main()
{
    // prints welcome message
    std::cout << "Welcome to InstaRecipe! We're happy to have you here :)" << std::endl;

    // initialize booleans to check if vectors for each category have been sorted
    bool checkCalories = false;
    bool checkTotalFatPDV = false;
    bool checkSugarPDV = false;
    bool checkSodiumPDV = false;
    bool checkProteinPDV = false;
    bool checkSaturatedFatPDV = false;
    bool checkTotalCarbohydratePDV = false;

    // initializes a vectors to store the recipes
    std::vector<Recipe> recipes;

    // sets a start time
    auto start = std::chrono::high_resolution_clock::now();

    // stores recipes in a recipe vector
    readRecipes(recipes, "C://Users/emely/OneDrive/Desktop/Spring 2023/COP3530/RAW_recipes.csv");

    // sets a stop time
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << "Time in milliseconds to load CSV file: " << duration.count() << std::endl << std::endl;


    // initializes vectors to store the recipes sorted for each category
    std::vector<Recipe> recipesCaloriesQuick = recipes;
    std::vector<Recipe> recipesCaloriesMerge = recipes;
    std::vector<Recipe> recipesTotalFatPDVQuick = recipes;
    std::vector<Recipe> recipesTotalFatPDVMerge = recipes;
    std::vector<Recipe> recipesSugarQuick = recipes;
    std::vector<Recipe> recipesSugarMerge = recipes;
    std::vector<Recipe> recipesSodiumQuick = recipes;
    std::vector<Recipe> recipesSodiumMerge = recipes;
    std::vector<Recipe> recipesProteinQuick = recipes;
    std::vector<Recipe> recipesProteinMerge = recipes;
    std::vector<Recipe> recipesSaturatedFatPDVQuick = recipes;
    std::vector<Recipe> recipesSaturatedFatPDVMerge = recipes;
    std::vector<Recipe> recipesTotalCarbohydrateQuick = recipes;
    std::vector<Recipe> recipesTotalCarbohydrateMerge = recipes;

    // initializes integers to store the time taken to finish each sort
    auto durationCaloriesQuick = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    auto durationCaloriesMerge = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    auto durationTotalFatPDVQuick = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    auto durationTotalFatPDVMerge = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    auto durationSugarQuick = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    auto durationSugarMerge = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    auto durationSodiumQuick = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    auto durationSodiumMerge = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    auto durationProteinQuick = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    auto durationProteinMerge = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    auto durationSaturatedFatPDVQuick = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    auto durationSaturatedFatPDVMerge = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    auto durationTotalCarbohydrateQuick = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    auto durationTotalCarbohydrateMerge = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

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

            // checks if the calorie vectors have been sorted
            if (checkCalories == false)
            {
                checkCalories = true;

                // sets a start time
                start = std::chrono::high_resolution_clock::now();

                quickSort(recipesCaloriesQuick, 0, recipesCaloriesQuick.size() - 1, 1);

                // sets a stop time
                stop = std::chrono::high_resolution_clock::now();
                durationCaloriesQuick = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

                // sets a start time
                start = std::chrono::high_resolution_clock::now();

                MergeSort(recipesCaloriesMerge, 0, recipesCaloriesMerge.size() - 1, 1);

                // sets a stop time
                stop = std::chrono::high_resolution_clock::now();
                durationCaloriesMerge = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
            }

            std::cout << "Time in milliseconds to sort with Quick Sort: " << durationCaloriesQuick.count() << std::endl;
            std::cout << "Time in milliseconds to sort with Merge Sort: " << durationCaloriesMerge.count() << std::endl << std::endl;

            // print result
            std::cout << "Enter a target value for Calories: " << std::endl;
            float target;
            std::cin >> target;
            std::cout << "\nYour search for a recipe with " << target << " Calories returned:" << std::endl;
            binarySearch(recipesCaloriesQuick, 1, target).print();
            // binarySearch(recipesCaloriesMerge, 1, target).print();
        }
        else if (option == 2)
        {
            // total fat

            // checks if the calorie vectors have been sorted
            if (checkTotalFatPDV == false)
            {
                checkTotalFatPDV = true;

                // sets a start time
                start = std::chrono::high_resolution_clock::now();

                quickSort(recipesTotalFatPDVQuick, 0, recipes.size() - 1, 2);

                // sets a stop time
                stop = std::chrono::high_resolution_clock::now();
                durationTotalFatPDVQuick = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

                // sets a start time
                start = std::chrono::high_resolution_clock::now();

                MergeSort(recipesTotalFatPDVMerge, 0, recipes.size() - 1, 2);

                // sets a stop time
                stop = std::chrono::high_resolution_clock::now();
                durationTotalFatPDVMerge = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
            }

            std::cout << "Time in milliseconds to sort with Quick Sort: " << durationTotalFatPDVQuick.count() << std::endl;
            std::cout << "Time in milliseconds to sort with Merge Sort: " << durationTotalFatPDVMerge.count() << std::endl << std::endl;

            // print result
            std::cout << "Enter a target value for Total Fat (PDV): " << std::endl;
            float target;
            std::cin >> target;
            std::cout << "\nYour search for a recipe with " << target << " Total Fat (PDV) returned:" << std::endl;
            binarySearch(recipesTotalFatPDVQuick, 2, target).print();
            // binarySearch(recipesTotalFatPDVMerge, 2, target).print();
        }
        else if (option == 3)
        {
            // sugar

            // checks if the sugar vectors have been sorted
            if (checkSugarPDV == false)
            {
                checkSugarPDV = true;

                // sets a start time
                start = std::chrono::high_resolution_clock::now();

                quickSort(recipesSugarQuick, 0, recipes.size() - 1, 3);

                // sets a stop time
                stop = std::chrono::high_resolution_clock::now();
                durationSugarQuick = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

                // sets a start time
                start = std::chrono::high_resolution_clock::now();

                MergeSort(recipesSugarMerge, 0, recipes.size() - 1, 3);

                // sets a stop time
                stop = std::chrono::high_resolution_clock::now();
                durationSugarMerge = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
            }

            std::cout << "Time in milliseconds to sort with Quick Sort: " << durationSugarQuick.count() << std::endl;
            std::cout << "Time in milliseconds to sort with Merge Sort: " << durationSugarMerge.count() << std::endl << std::endl;

            // print result
            std::cout << "Enter a target value for Sugar (PDV): " << std::endl;
            float target;
            std::cin >> target;
            std::cout << "\nYour search for a recipe with " << target << " Sugar (PDV) returned:" << std::endl;
            binarySearch(recipesSugarQuick, 3, target).print();
            // binarySearch(recipesSugarMerge, 3, target).print();
        }
        else if (option == 4)
        {
            // sodium

            // checks if the sodium vectors have been sorted
            if (checkSodiumPDV == false)
            {
                checkSodiumPDV = true;

                // sets a start time
                start = std::chrono::high_resolution_clock::now();

                quickSort(recipesSodiumQuick, 0, recipes.size() - 1, 4);

                // sets a stop time
                stop = std::chrono::high_resolution_clock::now();
                durationSodiumQuick = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

                // sets a start time
                start = std::chrono::high_resolution_clock::now();

                MergeSort(recipesSodiumMerge, 0, recipes.size() - 1, 4);

                // sets a stop time
                stop = std::chrono::high_resolution_clock::now();
                durationSodiumMerge = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
            }

            std::cout << "Time in milliseconds to sort with Quick Sort: " << durationSodiumQuick.count() << std::endl;
            std::cout << "Time in milliseconds to sort with Merge Sort: " << durationSodiumMerge.count() << std::endl << std::endl;

            // print result
            std::cout << "Enter a target value for Sodium (PDV): " << std::endl;
            float target;
            std::cin >> target;
            std::cout << "\nYour search for a recipe with " << target << " Sodium (PDV) returned:" << std::endl;
            binarySearch(recipesSodiumQuick, 4, target).print();
            // binarySearch(recipesSodiumMerge, 4, target).print();
        }
        else if (option == 5)
        {
            // protein

            // checks if the protein vectors have been sorted
            if (checkProteinPDV == false)
            {
                checkProteinPDV = true;

                // sets a start time
                start = std::chrono::high_resolution_clock::now();

                quickSort(recipesProteinQuick, 0, recipes.size() - 1, 5);

                // sets a stop time
                stop = std::chrono::high_resolution_clock::now();
                durationProteinQuick = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

                // sets a start time
                start = std::chrono::high_resolution_clock::now();

                MergeSort(recipesProteinMerge, 0, recipes.size() - 1, 5);

                // sets a stop time
                stop = std::chrono::high_resolution_clock::now();
                durationProteinMerge = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
            }

            std::cout << "Time in milliseconds to sort with Quick Sort: " << durationProteinQuick.count() << std::endl;
            std::cout << "Time in milliseconds to sort with Merge Sort: " << durationProteinMerge.count() << std::endl << std::endl;

            // print result
            std::cout << "Enter a target value for Protein (PDV): " << std::endl;
            float target;
            std::cin >> target;
            std::cout << "\nYour search for a recipe with " << target << " Protein (PDV) returned:" << std::endl;
            binarySearch(recipesProteinQuick, 5, target).print();
            // binarySearch(recipesProteinMerge, 5, target).print();
        }
        else if (option == 6)
        {
            // saturated fat

            // checks if the saturated fat vectors have been sorted
            if (checkSaturatedFatPDV == false)
            {
                checkSaturatedFatPDV = true;

                // sets a start time
                start = std::chrono::high_resolution_clock::now();

                quickSort(recipesSaturatedFatPDVQuick, 0, recipes.size() - 1, 6);

                // sets a stop time
                stop = std::chrono::high_resolution_clock::now();
                durationSaturatedFatPDVQuick = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

                // sets a start time
                start = std::chrono::high_resolution_clock::now();

                MergeSort(recipesSaturatedFatPDVMerge, 0, recipes.size() - 1, 6);

                // sets a stop time
                stop = std::chrono::high_resolution_clock::now();
                durationSaturatedFatPDVMerge = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
            }

            std::cout << "Time in milliseconds to sort with Quick Sort: " << durationSaturatedFatPDVQuick.count() << std::endl;
            std::cout << "Time in milliseconds to sort with Merge Sort: " << durationSaturatedFatPDVMerge.count() << std::endl << std::endl;

            // print result
            std::cout << "Enter a target value for Saturated Fat (PDV): " << std::endl;
            float target;
            std::cin >> target;
            std::cout << "\nYour search for a recipe with " << target << " Saturated Fat (PDV) returned:" << std::endl;
            binarySearch(recipesSaturatedFatPDVQuick, 6, target).print();
            // binarySearch(recipesSaturateFatPDVMerge, 6, target).print();
        }
        else if (option == 7)
        {
            // carbs

            // checks if the carbohydrate vectors have been sorted
            if (checkTotalCarbohydratePDV == false)
            {
                checkTotalCarbohydratePDV = true;

                // sets a start time
                start = std::chrono::high_resolution_clock::now();

                quickSort(recipesTotalCarbohydrateQuick, 0, recipes.size() - 1, 7);

                // sets a stop time
                stop = std::chrono::high_resolution_clock::now();
                durationTotalCarbohydrateQuick = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

                // sets a start time
                start = std::chrono::high_resolution_clock::now();

                MergeSort(recipesTotalCarbohydrateMerge, 0, recipes.size() - 1, 7);

                // sets a stop time
                stop = std::chrono::high_resolution_clock::now();
                durationTotalCarbohydrateMerge = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
            }

            std::cout << "Time in milliseconds to sort with Quick Sort: " << durationTotalCarbohydrateQuick.count() << std::endl;
            std::cout << "Time in milliseconds to sort with Merge Sort: " << durationTotalCarbohydrateMerge.count() << std::endl << std::endl;

            // print result
            std::cout << "Enter a target value for Total Carbohydrate (PDV): " << std::endl;
            float target;
            std::cin >> target;
            std::cout << "\nYour search for a recipe with " << target << " Total Carbohydrate (PDV) returned:" << std::endl;
            binarySearch(recipesTotalCarbohydrateQuick, 7, target).print();
            // binarySearch(recipesTotalCarbohydrateMerge, 7, target).print();
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