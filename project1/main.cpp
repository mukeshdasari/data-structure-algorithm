#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<string>
#include<algorithm>
#include "mergeSort.cpp"
#include "heapSort.cpp"
#include "insertionSort.cpp"
#include "quickSort.cpp"

int main(int argc, char* argv[]){
    int inputSize = std::stoi(argv[1]); //Taking input size of vector
    std::vector<int> inputVec1(inputSize,0);
    std::vector<int> inputVec2;
    std::vector<int> inputVec3;
    std::vector<int> inputVec4;
    std::vector<int> inputVec5;
    std::srand(std::time(0));
    std::generate(inputVec1.begin(),inputVec1.end(),std::rand); //Generating vector with random numbers of size inputSize

    //Can be used to sort input vector in descending order to demonstrate sorting the descending sorted vector
    // std::sort(std::begin(inputVec1), std::end(inputVec1), std::greater<>());
    
    //Can be used to sort input vector in descending order to demonstrate sorting the  sorted vector
    // std::sort(std::begin(inputVec1), std::end(inputVec1));

    for(int k=0;k<inputVec1.size();k++){
        inputVec2.push_back(inputVec1[k]);
        inputVec3.push_back(inputVec1[k]);
        inputVec4.push_back(inputVec1[k]);
        inputVec5.push_back(inputVec1[k]);
    }

    std::chrono::system_clock::time_point stMergeSort = std::chrono::system_clock::now(); //Mark starting time of merge sort
    std::vector<int> result1 = mergeSort(inputVec1); //Sorting vector using merge sort
    std::chrono::system_clock::time_point etMergeSort = std::chrono::system_clock::now(); //Mark ending time of merge sort

    std::chrono::system_clock::time_point stHeapSort = std::chrono::system_clock::now(); //Mark starting time of heap sort
    std::vector<int> result2 = heapSort(inputVec2); //Sorting vector using heap sort
    std::chrono::system_clock::time_point etHeapSort = std::chrono::system_clock::now(); //Mark ending time of heap sort

    std::chrono::system_clock::time_point stInsertionSort = std::chrono::system_clock::now(); //Mark starting time of insertion sort
    std::vector<int> result3 = insertionSort(inputVec3); //Sorting vector using inserion sort
    std::chrono::system_clock::time_point etInsertionSort = std::chrono::system_clock::now(); //Mark ending time of insertion sort

    std::chrono::system_clock::time_point stInPlaceQuickSort = std::chrono::system_clock::now(); //Mark starting time of in-place quick sort
    std::vector<int> result4 = inPlaceQuickSort(inputVec4,0,inputVec4.size()-1); //Sorting vector using in-place quick sort
    std::chrono::system_clock::time_point etInPlaceQuickSort = std::chrono::system_clock::now(); //Mark ending time of in-place quick sort

    std::chrono::system_clock::time_point stModifiedQuickSort = std::chrono::system_clock::now(); //Mark starting time of modified quick sort
    std::vector<int> result5 = modifiedQuickSort(inputVec5); //Sorting vector using modified quick sort
    std::chrono::system_clock::time_point etModifiedQuickSort = std::chrono::system_clock::now(); //Mark ending time of modified quick sort

    //Calculating running time of each sorting algorithm in ms
    std::chrono::duration<double, std::milli> rtMergeSort = etMergeSort - stMergeSort;
    std::chrono::duration<double, std::milli> rtHeapSort = etHeapSort - stHeapSort;
    std::chrono::duration<double, std::milli> rtInsertionSort = etInsertionSort - stInsertionSort;
    std::chrono::duration<double, std::milli> rtInPlaceQuickSort = etInPlaceQuickSort - stInPlaceQuickSort;
    std::chrono::duration<double, std::milli> rtModifiedQuickSort = etModifiedQuickSort - stModifiedQuickSort;

    //Can be used to check if each sorting algorithms yeilds the same output (sorted vector)
    // for(int i=0;i<result1.size();i++){
    //     std::cout << result1[i] << " ";
    //     std::cout << result2[i] << " ";
    //     std::cout << result3[i] << " ";
    //     std::cout << result4[i] << " ";
    //     std::cout << result5[i] << " "<<(result1[i]==result2[i] &&result2[i]==result3[i] &&result3[i]==result4[i]&&result4[i]==result5[i]) << std::endl;
    // }
    
    //Printing time taken by each sorting algorithm in ms 
    std::cout << "InputSize of Vector : " << inputSize << std::endl; 
    std::cout << "MergeSort : " << rtMergeSort.count() << std::endl;
    std::cout << "HeapSort : " << rtHeapSort.count() << std::endl;
    std::cout << "InsertionSort : " << rtInsertionSort.count() << std::endl;
    std::cout << "InPlaceQuickSort : " << rtInPlaceQuickSort.count() << std::endl;
    std::cout << "ModifiedQuickSort : " << rtModifiedQuickSort.count() << std::endl;
    
    //End of program
    return 0;
}