#include <iostream>
#include <vector>

void quickSort(std::vector<float> numbers, float low, float high);
float split(std::vector<float> numbers, float low, float high);
void swap(float* up, float* down);

int main()
{

    // make a vector of floats to test with 
    std::vector<float> numVector; 
    numVector.push_back(3); 
    numVector.push_back(6); 
    numVector.push_back(2); 
    numVector.push_back(7); 
    numVector.push_back(9); 
    numVector.push_back(4); 
    numVector.push_back(1); 
    numVector.push_back(5); 

    float n = numVector.size();
    quickSort(numVector, 0, n-1);

    // print out the vector after
    for(int i = 0; i < numVector.size(); i++)
    {
        std::cout << numVector.at(i) << std::endl;
    }

    return 0; 
}


// cited from Sorting Lecture, slide 121 and 122 
void quickSort(std::vector<float> numbers, float low, float high)
{
    // need pivot, up and down pointers
    if(low < high)
    {
        // pivot is the first element, but it gets swapped with the down pointer
        float pivot = split(numbers, low, high);
        // sort the numbers below the pivot
        quickSort(numbers, low, pivot - 1); 
        // sort the numbers above the pivot
        quickSort(numbers, pivot + 1, high);
        
    }
    
}

float split(std::vector<float> numbers, float low, float high)
{
    // pivot is the first element in the vector
    float pivot = numbers[low];
    // up is initialized to 0 index (1st element)
    float up = low; 
    // down is initialized to last element in vector
    float down = high; 

    // quicksort algorithm. when up passes down, swap pivot and down
    while(up < down)
    {
        // move up until it finds a value > pivot 
        while(up < high)
        {
            if(numbers[up] > pivot)
            {
                break;
            }
            up++;
        }
        // move down until it finds a value <= 7
        while(low < high)
        {
            if(numbers[down] < pivot)
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

void swap(float* up, float* down)
{
    // a = b 
    // b = a 
    float temp = *up; // dereference it 
    *up = *down; 
    *down = temp;
}