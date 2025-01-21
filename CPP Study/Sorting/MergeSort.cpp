#include <iostream>
#include <vector>
#include <random>

void mergeSort(std::vector<int>& array){
    if(array.size() <= 1)
        return;
        
    int midpoint = array.size() / 2;
    std::vector<int> leftPart(array.begin(), array.begin() + midpoint);
    std::vector<int> rightPart(array.begin() + midpoint, array.end());
    
    mergeSort(leftPart);
    mergeSort(rightPart);
    
    int leftIndex = 0, rightIndex = 0, sortedIndex = 0;
    
    while(leftIndex < leftPart.size() && rightIndex < rightPart.size()){
        if(leftPart[leftIndex] < rightPart[rightIndex]){
            array[sortedIndex] = leftPart[leftIndex];
            leftIndex++;
        }
        else{
            array[sortedIndex] = rightPart[rightIndex];
            rightIndex++;
        }
        sortedIndex++;
    }
    
    while(leftIndex < leftPart.size()){
        array[sortedIndex] = leftPart[leftIndex];
        leftIndex++;
        sortedIndex++;
    }
    
    while(rightIndex < rightPart.size()){
        array[sortedIndex] = rightPart[rightIndex];
        rightIndex++;
        sortedIndex++;
    }
}

int main()
{
    
    // modern random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1,100);
    
    std::vector<int> array;
    for(int i = 0; i < 20; i++)
        array.push_back(distr(gen));
        
    printf("Original Vector:\t");
    for(int i : array)
        std::cout << i << " ";
        
    mergeSort(array);
    printf("\nSorted Vector:\t\t");
    for(int i : array)
        std::cout << i << " ";

    return 0;
}