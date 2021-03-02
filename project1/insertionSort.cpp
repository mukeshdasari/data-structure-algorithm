#include<vector>

//Insertion sort algorithm
std::vector<int> insertionSort(std::vector<int> vec){
    int i;
    for(int j=1;j<vec.size();j++){
        i = j-1;
        int key = vec[j];
        while(i>=0 && key<vec[i]){
            vec[i+1] = vec[i];
            i--;
        }
        vec[i+1] = key;
    }
    return vec;
}