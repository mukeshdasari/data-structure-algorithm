#include <vector>
#include <random>
//In place partition
std::vector<int> inPlacePartition(std::vector<int> &vec, int left, int right, int pivote){
    int pivoteValue = vec[pivote];
    int i = 0, j = vec.size() - 1;
    while (i <= j){
        if (vec[i] <= vec[pivote])
            i++;
        if (vec[j] > vec[pivote])
            j--;
        if (vec[i] > vec[pivote] && vec[j] < vec[pivote]){
            int temp = vec[i];
            vec[i] = vec[j];
            vec[j] = temp;
            i++;
            j--;
        }
    }
    int pTemp = vec[pivote];
    vec[pivote] = vec[j];
    vec[j] = pTemp;
    std::vector<int> result;
    result.push_back(i);
    result.push_back(j);
    return result;
}

//In place quick sort algorithm
std::vector<int> inPlaceQuickSort(std::vector<int> &vec, int left, int right){
    if (left >= right)
        return vec;
    int pivoteIndex = left + std::rand() % (left + (right - left));
    std::vector<int> values = inPlacePartition(vec, left, right, left);
    int i = values[0], j = values[1];
    inPlaceQuickSort(vec, left, i - 1);
    inPlaceQuickSort(vec, j + 1, right);
    return vec;
}

//Modified quick sort uses insertion sort for array size less than 10
void quickInsertionSort(std::vector<int> &vec, int left, int right)
{
    int i;
    for (int j = left; j <= right; j++){
        i = j - 1;
        int key = vec[j];
        while (i >= 0 && key < vec[i]){
            vec[i + 1] = vec[i];
            i--;
        }
        vec[i + 1] = key;
    }
    return;
}

//Modified quick sort main algorithm
void medianQuickSort(std::vector<int> &vec, int left, int right){
    if(left+10 <= right){
        int center = (left+right)/2;
        int pivote;
        int temp;
        if (vec[center] < vec[left] && vec[center] < vec[right]){
            temp = vec[left];
            vec[left] = vec[center];
            if (vec[left] < vec[right])
                vec[center] = temp;
            if (vec[left] > vec[right]){
                vec[center] = vec[right];
                vec[right] = temp;
            }
        }
        if (vec[center] > vec[left] && vec[center] > vec[right]){
            temp = vec[right];
            vec[right] = vec[center];
            if (vec[left] < vec[right])
                vec[center] = temp;
            if (vec[left] > vec[right]){
                vec[center] = vec[left];
                vec[left] = temp;
            }
        }
        pivote = vec[center];

        int i,j;
        for(i=left, j=right-2;;){
            while(vec[i]<pivote) i++;
            while(vec[j]>pivote) j--;
            if(i<j){
                int temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
            } else{
                break;
            }
        }
        int swap = vec[i];
        vec[i] = vec[right-1];
        vec[right-1] = swap;

        medianQuickSort(vec, left ,i - 1);
        medianQuickSort(vec, i, right);
        return;
    } 
    else{
        quickInsertionSort(vec, left, right);
        return;
    }
}

std::vector<int> modifiedQuickSort(std::vector<int> &vec){
    std::vector<int> sortedVec;
    medianQuickSort(vec,  0, vec.size() - 1);
    return vec;
}