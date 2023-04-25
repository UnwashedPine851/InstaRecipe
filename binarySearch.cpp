#include <iostream>
#include "binarySearch.h"
#include "recipe.h"

Recipe binarySearch(std::vector<Recipe>& recipes, int nutrientChoice, float target)
{
    switch(nutrientChoice)
    {
        case 1:
            return binarySearchHelperCalories(recipes, target, 0, recipes.size() - 1);
            break;
        case 2:
            return binarySearchHelperTotalFatPDV(recipes, target, 0, recipes.size() - 1);
            break;
        case 3:
            return binarySearchHelperSugarPDV(recipes, target, 0, recipes.size() - 1);
            break;
        case 4:
            return binarySearchHelperSodiumPDV(recipes, target, 0, recipes.size() - 1);
            break;
        case 5:
            return binarySearchHelperProteinPDV(recipes, target, 0, recipes.size() - 1);
            break;
        case 6:
            return binarySearchHelperSaturatedFatPDV(recipes, target, 0, recipes.size() - 1);
            break;
        case 7:
            return binarySearchHelperTotalCarbohydratePDV(recipes, target, 0, recipes.size() - 1);
            break;
    }
}

Recipe binarySearchHelperCalories(std::vector<Recipe>& recipes, float target, int low, int high)
{
    int middle = 0;

    while (low <= high)
    {
        middle = (low + high) / 2;

        // checks if the target is equal to the value at the middle index
        if (recipes[middle].getCalories() == target)
            return recipes[middle];
            // if the target is less than the value at the middle index
        else if (recipes[middle].getCalories() > target)
            high = middle - 1;
            // if the target is greater than the value at the middle index
        else
            low = middle + 1;
    }

    // if the target is not found return the recipe with the closest value to target
    return recipes[middle];
}

Recipe binarySearchHelperTotalFatPDV(std::vector<Recipe>& recipes, float target, int low, int high)
{
    int middle = 0;

    while (low <= high)
    {
        middle = (low + high) / 2;

        // checks if the target is equal to the value at the middle index
        if (recipes[middle].getTotalFatPDV() == target)
            return recipes[middle];
            // if the target is less than the value at the middle index
        else if (recipes[middle].getTotalFatPDV() > target)
            high = middle - 1;
            // if the target is greater than the value at the middle index
        else
            low = middle + 1;
    }

    // if the target is not found return the recipe with the closest value to target
    return recipes[middle];
}

Recipe binarySearchHelperSugarPDV(std::vector<Recipe>& recipes, float target, int low, int high)
{
    {
        int middle = 0;

        while (low <= high)
        {
            middle = (low + high) / 2;

            // checks if the target is equal to the value at the middle index
            if (recipes[middle].getSugarPDV() == target)
                return recipes[middle];
                // if the target is less than the value at the middle index
            else if (recipes[middle].getSugarPDV() > target)
                high = middle - 1;
                // if the target is greater than the value at the middle index
            else
                low = middle + 1;
        }

        // if the target is not found return the recipe with the closest value to target
        return recipes[middle];
    }
}

Recipe binarySearchHelperSodiumPDV(std::vector<Recipe>& recipes, float target, int low, int high)
{
    {
        int middle = 0;

        while (low <= high)
        {
            middle = (low + high) / 2;

            // checks if the target is equal to the value at the middle index
            if (recipes[middle].getSodiumPDV() == target)
                return recipes[middle];
                // if the target is less than the value at the middle index
            else if (recipes[middle].getSodiumPDV() > target)
                high = middle - 1;
                // if the target is greater than the value at the middle index
            else
                low = middle + 1;
        }

        // if the target is not found return the recipe with the closest value to target
        return recipes[middle];
    }
}

Recipe binarySearchHelperProteinPDV(std::vector<Recipe>& recipes, float target, int low, int high)
{
    {
        int middle = 0;

        while (low <= high)
        {
            middle = (low + high) / 2;

            // checks if the target is equal to the value at the middle index
            if (recipes[middle].getProteinPDV() == target)
                return recipes[middle];
                // if the target is less than the value at the middle index
            else if (recipes[middle].getProteinPDV() > target)
                high = middle - 1;
                // if the target is greater than the value at the middle index
            else
                low = middle + 1;
        }

        // if the target is not found return the recipe with the closest value to target
        return recipes[middle];
    }
}

Recipe binarySearchHelperSaturatedFatPDV(std::vector<Recipe>& recipes, float target, int low, int high)
{
    {
        int middle = 0;

        while (low <= high)
        {
            middle = (low + high) / 2;

            // checks if the target is equal to the value at the middle index
            if (recipes[middle].getSaturatedFatPDV() == target)
                return recipes[middle];
                // if the target is less than the value at the middle index
            else if (recipes[middle].getSaturatedFatPDV() > target)
                high = middle - 1;
                // if the target is greater than the value at the middle index
            else
                low = middle + 1;
        }

        // if the target is not found return the recipe with the closest value to target
        return recipes[middle];
    }
}

Recipe binarySearchHelperTotalCarbohydratePDV(std::vector<Recipe>& recipes, float target, int low, int high)
{
    {
        int middle = 0;

        while (low <= high)
        {
            middle = (low + high) / 2;

            // checks if the target is equal to the value at the middle index
            if (recipes[middle].getTotalCarbohydratePDV() == target)
                return recipes[middle];
                // if the target is less than the value at the middle index
            else if (recipes[middle].getTotalCarbohydratePDV() > target)
                high = middle - 1;
                // if the target is greater than the value at the middle index
            else
                low = middle + 1;
        }

        // if the target is not found return the recipe with the closest value to target
        return recipes[middle];
    }
}