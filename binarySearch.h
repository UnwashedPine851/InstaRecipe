#pragma once
#include <iostream>
#include <vector>

Recipe binarySearch(std::vector<Recipe>& recipes, int nutrientChoice, float target);

Recipe binarySearchHelperCalories(std::vector<Recipe>& recipes, float target, int low, int high);

Recipe binarySearchHelperTotalFatPDV(std::vector<Recipe>& recipes, float target, int low, int high);

Recipe binarySearchHelperSugarPDV(std::vector<Recipe>& recipes, float target, int low, int high);

Recipe binarySearchHelperSodiumPDV(std::vector<Recipe>& recipes, float target, int low, int high);

Recipe binarySearchHelperProteinPDV(std::vector<Recipe>& recipes, float target, int low, int high);

Recipe binarySearchHelperSaturatedFatPDV(std::vector<Recipe>& recipes, float target, int low, int high);

Recipe binarySearchHelperTotalCarbohydratePDV(std::vector<Recipe>& recipes, float target, int low, int high);