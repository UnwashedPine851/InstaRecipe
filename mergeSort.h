#pragma once
//Credit to COP3530 Slides

class mergeSort
{
public:
    void MergeHelper(std::vector<Recipe> &recipeList, int left, int mid, int right, int nutrientChoice);

    void MergeSort(std::vector<Recipe> &recipeList, int left, int right, int nutrientChoice);

};
