#include<iostream>
#include<vector>

//Heapify algorithm
void heapify(std::vector<int>& minHeapVec, int lastNode){
    int i = 1;
    while(i < lastNode){
        if((2*i+1) <= lastNode){
            int currentNode = minHeapVec[i];
            int leftNode = minHeapVec[2*i];
            int rightNode = minHeapVec[(2*i)+1];
            if(currentNode<leftNode && currentNode<rightNode) return;
            else if(leftNode<=rightNode && currentNode>leftNode){
                    int temp = minHeapVec[2*i];
                    minHeapVec[2*i] = minHeapVec[i];
                    minHeapVec[i] = temp;
                    i = 2*i;
            } else if(rightNode<leftNode && currentNode>rightNode){
                int temp = minHeapVec[(2*i)+1];
                minHeapVec[(2*i)+1] = minHeapVec[i];
                minHeapVec[i] = temp;
                i = (2*i)+1;
            } 
        } else if(2*i <= lastNode && minHeapVec[i]>minHeapVec[2*i]){
            int temp = minHeapVec[2*i];
            minHeapVec[2*i] = minHeapVec[i];
            minHeapVec[i] = temp;
            i = 2*i;
        } else{
            return;
        }        
    }
}

//Heap sort algorithm
std::vector<int> heapSort(std::vector<int> vec){
    std::vector<int> minHeapVec;
    minHeapVec.push_back(0);
    minHeapVec.push_back(vec[0]);
    for(int i=1; i<vec.size();i++){
        minHeapVec.push_back(vec[i]);
        int lastNode = i+1;
        while(lastNode>0 && minHeapVec[lastNode]<minHeapVec[lastNode/2]){
            int temp = minHeapVec[lastNode];
            minHeapVec[lastNode] = minHeapVec[lastNode/2];
            minHeapVec[lastNode/2] = temp; 
            lastNode = lastNode/2;
        }
    }

    for(int j=0;j<minHeapVec.size()-1;j++){
        vec[j]=minHeapVec[1];
        minHeapVec[1] = minHeapVec[minHeapVec.size()-j-1];
        heapify(minHeapVec,minHeapVec.size()-j-2);
    }
    return vec;
}

