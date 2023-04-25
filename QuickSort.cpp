#include <iostream>
#include <vector>
#include "recipe.h"
#include "QuickSort.h"

//int main()
//{
//    // make a vector of floats to test with
//    std::vector<float> numVector;
//    numVector.push_back(3);
//    numVector.push_back(6);
//    numVector.push_back(2);
//    numVector.push_back(7);
//    numVector.push_back(9);
//    numVector.push_back(4);
//    numVector.push_back(1);
//    numVector.push_back(5);
//
//    float n = numVector.size();
//    quickSort(numVector, 0, n - 1);
//
//    // print out the vector after
//    for(int i = 0; i < numVector.size(); i++)
//    {
//        std::cout << numVector.at(i) << std::endl;
//    }
//
//}


// cited from Sorting Lecture, slide 121 and 122
void quickSort(std::vector<Recipe>& numbers, float low, float high, int nutrientChoice)
{
    // need pivot, up and down pointers
    if(low < high)
    {
        // pivot is the first element, but it gets swapped with the down pointer
        float pivot = split(numbers, low, high, nutrientChoice);
        // sort the numbers below the pivot
        quickSort(numbers, low, pivot - 1, nutrientChoice);
        // sort the numbers above the pivot
        quickSort(numbers, pivot + 1, high, nutrientChoice);
    }
}

float split(std::vector<Recipe>& numbers, float low, float high, int nutrientChoice)
{
    // implement the switch casing
    if(nutrientChoice == 1)
    {
        // pivot is the first element in the vector
        float pivot = numbers[low].getCalories();
        // up is initialized to 0 index (1st element)
        float up = low;
        // down is initialized to last element in vector
        float down = high;

        // quicksort algorithm. when up passes down, swap pivot and down
        while(up < down)
        {
            // move up until it finds a value > pivot
            for(float j = up; j < high; j++)
            {
                if(numbers[up].getCalories() > pivot)
                {
                    break;
                }
                up++;
            }
            // move down until it finds a value <= 7
            for(float j = high; j > low; j--)
            {
                if(numbers[down].getCalories() < pivot)
                {
                    break;
                }
                down--;
            }
            // swap up and down
            if(up < down)
            {
                swap(&numbers[up],&numbers[down]);
            }
        }
        // swap pivot(0 index) and down
        swap(&numbers[low], &numbers[down]);
        // return down
        return down;
    }
    else if(nutrientChoice == 2)
    {
        // pivot is the first element in the vector
        float pivot = numbers[low].getTotalFatPDV();
        // up is initialized to 0 index (1st element)
        float up = low;
        // down is initialized to last element in vector
        float down = high;

        // quicksort algorithm. when up passes down, swap pivot and down
        while(up < down)
        {
            // move up until it finds a value > pivot
            for(float j = up; j < high; j++)
            {
                if(numbers[up].getTotalFatPDV() > pivot)
                {
                    break;
                }
                up++;
            }
            // move down until it finds a value <= 7
            for(float j = high; j > low; j--)
            {
                if(numbers[down].getTotalFatPDV() < pivot)
                {
                    break;
                }
                down--;
            }
            // swap up and down
            if(up < down)
            {
                swap(&numbers[up],&numbers[down]);
            }
        }
        // swap pivot(0 index) and down
        swap(&numbers[low], &numbers[down]);
        // return down
        return down;
    }
    else if(nutrientChoice == 3)
    {
        // pivot is the first element in the vector
        float pivot = numbers[low].getSugarPDV();
        // up is initialized to 0 index (1st element)
        float up = low;
        // down is initialized to last element in vector
        float down = high;

        // quicksort algorithm. when up passes down, swap pivot and down
        while(up < down)
        {
            // move up until it finds a value > pivot
            for(float j = up; j < high; j++)
            {
                if(numbers[up].getSugarPDV() > pivot)
                {
                    break;
                }
                up++;
            }
            // move down until it finds a value <= 7
            for(float j = high; j > low; j--)
            {
                if(numbers[down].getSugarPDV() < pivot)
                {
                    break;
                }
                down--;
            }
            // swap up and down
            if(up < down)
            {
                swap(&numbers[up],&numbers[down]);
            }
        }
        // swap pivot(0 index) and down
        swap(&numbers[low], &numbers[down]);
        // return down
        return down;
    }
    else if(nutrientChoice == 4)
    {
        // pivot is the first element in the vector
        float pivot = numbers[low].getSodiumPDV();
        // up is initialized to 0 index (1st element)
        float up = low;
        // down is initialized to last element in vector
        float down = high;

        // quicksort algorithm. when up passes down, swap pivot and down
        while(up < down)
        {
            // move up until it finds a value > pivot
            for(float j = up; j < high; j++)
            {
                if(numbers[up].getSodiumPDV() > pivot)
                {
                    break;
                }
                up++;
            }
            // move down until it finds a value <= 7
            for(float j = high; j > low; j--)
            {
                if(numbers[down].getSodiumPDV() < pivot)
                {
                    break;
                }
                down--;
            }
            // swap up and down
            if(up < down)
            {
                swap(&numbers[up],&numbers[down]);
            }
        }
        // swap pivot(0 index) and down
        swap(&numbers[low], &numbers[down]);
        // return down
        return down;
    }
    else if(nutrientChoice == 5)
    {
        // pivot is the first element in the vector
        float pivot = numbers[low].getProteinPDV();
        // up is initialized to 0 index (1st element)
        float up = low;
        // down is initialized to last element in vector
        float down = high;

        // quicksort algorithm. when up passes down, swap pivot and down
        while(up < down)
        {
            // move up until it finds a value > pivot
            for(float j = up; j < high; j++)
            {
                if(numbers[up].getProteinPDV() > pivot)
                {
                    break;
                }
                up++;
            }
            // move down until it finds a value <= 7
            for(float j = high; j > low; j--)
            {
                if(numbers[down].getProteinPDV() < pivot)
                {
                    break;
                }
                down--;
            }
            // swap up and down
            if(up < down)
            {
                swap(&numbers[up],&numbers[down]);
            }
        }
        // swap pivot(0 index) and down
        swap(&numbers[low], &numbers[down]);
        // return down
        return down;
    }
    else if(nutrientChoice == 6)
    {
        // pivot is the first element in the vector
        float pivot = numbers[low].getSaturatedFatPDV();
        // up is initialized to 0 index (1st element)
        float up = low;
        // down is initialized to last element in vector
        float down = high;

        // quicksort algorithm. when up passes down, swap pivot and down
        while(up < down)
        {
            // move up until it finds a value > pivot
            for(float j = up; j < high; j++)
            {
                if(numbers[up].getSaturatedFatPDV() > pivot)
                {
                    break;
                }
                up++;
            }
            // move down until it finds a value <= 7
            for(float j = high; j > low; j--)
            {
                if(numbers[down].getSaturatedFatPDV() < pivot)
                {
                    break;
                }
                down--;
            }
            // swap up and down
            if(up < down)
            {
                swap(&numbers[up],&numbers[down]);
            }
        }
        // swap pivot(0 index) and down
        swap(&numbers[low], &numbers[down]);
        // return down
        return down;
    }
    else if(nutrientChoice == 7)
    {
        // pivot is the first element in the vector
        float pivot = numbers[low].getTotalCarbohydratePDV();
        // up is initialized to 0 index (1st element)
        float up = low;
        // down is initialized to last element in vector
        float down = high;

        // quicksort algorithm. when up passes down, swap pivot and down
        while(up < down)
        {
            // move up until it finds a value > pivot
            for(float j = up; j < high; j++)
            {
                if(numbers[up].getTotalCarbohydratePDV() > pivot)
                {
                    break;
                }
                up++;
            }
            // move down until it finds a value <= 7
            for(float j = high; j > low; j--)
            {
                if(numbers[down].getTotalCarbohydratePDV() < pivot)
                {
                    break;
                }
                down--;
            }
            // swap up and down
            if(up < down)
            {
                swap(&numbers[up],&numbers[down]);
            }
        }
        // swap pivot(0 index) and down
        swap(&numbers[low], &numbers[down]);
        // return down
        return down;
    }

}

void swap(Recipe* up, Recipe* down)
{
    // a = b
    // b = a
    Recipe temp = *up; // dereference it
    *up = *down;
    *down = temp;
}

