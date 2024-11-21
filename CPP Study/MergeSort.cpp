#include <iostream>
#include <vector>

void mergeSort(std::vector<int>& array){
    if(array.size() <= 1){
        return;
    }
    
    int midPoint = array.size() / 2;
    std::vector<int> leftPart(array.begin(), array.begin() + midPoint);
    std::vector<int> rightPart(array.begin() + midPoint, array.end());
    
    mergeSort(leftPart);
    mergeSort(rightPart);
    
    int leftIndex = 0, rightIndex = 0, sortedIndex = 0;
    
    while(leftIndex < leftPart.size() && rightIndex < rightPart.size()){
        if(leftPart[leftIndex] < rightPart[rightIndex]){
            array[sortedIndex] = leftPart[leftIndex];
            leftIndex++;
        } else if (rightPart[rightIndex] < leftPart[leftIndex]){
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

int main(){
    std::vector<int> numbers = {4, 10, 6, 14, 2, 1, 8, 5};
    
    mergeSort(numbers);
    
    for(int i : numbers)
        std::cout << i << " ";
    
    return 0;
}