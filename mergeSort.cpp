#include "mergeSort.h"
#include "recipe.h"
//Credit to COP3530 Slides

void MergeHelper(std::vector<Recipe> &recipeList, int left, int mid, int right, int nutrientChoice)
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