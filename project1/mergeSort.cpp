#include<vector>

// Divide and conquer algorithm
std::vector<int> merge(std::vector<int> leftVec, std::vector<int> rightVec){
    std::vector<int> sortedVec;
    int i=0, j=0;
    while(leftVec.size()>0 && rightVec.size()>0){
        if(leftVec[0]<rightVec[0]){
            sortedVec.push_back(leftVec[0]);
            leftVec.erase(leftVec.begin());
        } else{
            sortedVec.push_back(rightVec[0]);
            rightVec.erase(rightVec.begin());
        }
    }
    while(i<leftVec.size()){
        sortedVec.push_back(leftVec[i]);
        i++;
    }
    while(j<rightVec.size()){
        sortedVec.push_back(rightVec[j]);
        j++;
    }
    return sortedVec;
}

//Merge sort algorithm
std::vector<int> mergeSort(std::vector<int> vec){
    int vecLength = vec.size();
    if (vecLength == 1) return vec;
    std::vector<int> leftVec, rightVec;
    for(int i=0;i<vecLength/2;i++){
        leftVec.push_back(vec[i]);
    }
    for(int j=vecLength/2;j<vecLength;j++){
        rightVec.push_back(vec[j]);
    }
    leftVec = mergeSort(leftVec);
    rightVec = mergeSort(rightVec);
    return merge(leftVec, rightVec);
}