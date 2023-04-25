#pragma once
#include "recipe.h"
void quickSort(std::vector<Recipe>& numbers, float low, float high, int nutrientChoice);
float split(std::vector<Recipe>& numbers, float low, float high, int nutrientChoice);
void swap(Recipe* up, Recipe* down);