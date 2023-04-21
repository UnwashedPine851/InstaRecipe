#pragma once
#include <iostream>
#include <vector>

// Recipe class declaration
class Recipe {
public:
    Recipe();
    Recipe(std::string name, int minutes, float calories, float totalFatPDV, float sugarPDV, float sodiumPDV,
           float proteinPDV, float saturatedFat, std::vector<std::string> steps, std::vector<std::string> ingredients);
    std::string getName();
    int getMinutes();
    float getCalories();
    float getTotalFatPDV();
    float getSugarPDV();
    float getSodiumPDV();
    float getProteinPDV();
    float getSaturatedFat();
    std::vector<std::string> getSteps();
    std::vector<std::string> getIngredients();
    void print();
private:
    std::string name;
    int minutes;
    float calories;
    float totalFatPDV;
    float sugarPDV;
    float sodiumPDV;
    float proteinPDV;
    float saturatedFat;
    std::vector<std::string> steps;
    std::vector<std::string> ingredients;
};