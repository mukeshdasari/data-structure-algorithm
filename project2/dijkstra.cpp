#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<bits/stdc++.h>

int extractMinimumDistance(std::vector<int> vertexDistance, std::vector<bool> vertexSet){
    int minimumDistance = INT_MAX, index;
    for(int i=0; i<vertexDistance.size();i++){
        if(vertexSet[i] == false && vertexDistance[i] <= minimumDistance){
            minimumDistance = vertexDistance[i];
            index = i;
        }
    }
    return index;
}

void printShortesPath(std::vector<int> vertexParent, int index){
    if (vertexParent[index] == - 1)
        return;
  
    printShortesPath(vertexParent, vertexParent[index]);
    
    char ver = 65 + index; // Ascii values for pritning A,B,C..
    std::cout<< " -> " << ver;
}

void dijkstra(std::vector<std::vector<int>> graph, int vertex, int source){
    std::vector<int> vertexDistance;
    std::vector<int> vertexParent(vertex);
    std::vector<bool> vertexSet;

    //initialiazing all vertex distance with max and vertex set to false
    for(int i=0; i<vertex; i++){
        vertexDistance.push_back(INT_MAX);
        vertexSet.push_back(false);
    }

    vertexDistance[source] = 0;
    vertexParent[source] = -1;

    for(int j=0; j<vertex; j++){
        int index = extractMinimumDistance(vertexDistance, vertexSet);
        vertexSet[index] = true;
        
        for(int k=0; k<vertex; k++){
            if(vertexDistance[index] != INT_MAX && graph[index][k] && !vertexSet[k] && vertexDistance[index] + graph[index][k] < vertexDistance[k]){
                vertexDistance[k] = vertexDistance[index] + graph[index][k];
                vertexParent[k] = index;
            }
        }
    }


    char sourceChar = 65 + source;
	for(int l = 1; l<vertex; l++){
        std::cout<< "Shortest Distance : " << vertexDistance[l] << "\t\t Path : ";
        std::cout<< sourceChar;
        printShortesPath(vertexParent, l);
		std::cout<<std::endl;
	}
}

int main(){
    std::cout<<"\n************************************************\n";
    std::cout << "\t\tDIJKSTRA'S ALGORITHM" << std::endl;
    std::cout<<"************************************************\n";
    for(int i=0;i<4;i++){
        int startVertexFlag = false;
        std::string vertexStr, edgeStr, graphTypeStr;
        
        std::vector<std::string> inputStringVec;
        std::string line;
        std::ifstream inputFile("./input_sources/Dijkstra_graph"+std::to_string(i+1)+".txt");

        //Reading linew and insetind in the vector of string 
        while (getline(inputFile, line, '\n')) {
            inputStringVec.push_back(line);
        }

        //Getting the vertex, edge and type of graph
        std::istringstream iss(inputStringVec[0]);
        iss >> vertexStr >> edgeStr >> graphTypeStr;

        int vertex = stoi(vertexStr);
        int edge = stoi(edgeStr);


        //Creating the matrix Graph of size vertex * vertex
        std::vector<std::vector<int>> graph(vertex, std::vector<int>(vertex));
        
        for (int i=1; i<inputStringVec.size();i++){
            std::string startVertex, endVertex, weight;
            std::istringstream strs(inputStringVec[i]);
            strs >> startVertex >> endVertex >> weight;
            if(strs.fail()){
                startVertexFlag = true;
                continue;
            }
            
            graph[static_cast<int>(startVertex[0] - 'A')][static_cast<int>(endVertex[0] - 'A')] = stoi(weight);
            if(graphTypeStr[0] == 'U') graph[static_cast<int>(endVertex[0] - 'A')][static_cast<int>(startVertex[0] - 'A')] = stoi(weight);
        }
        int source = startVertexFlag ? static_cast<int>(inputStringVec[inputStringVec.size()-1][0] - 'A') : 0;
        std::cout << "Graph " << i+1 << std::endl;
        std::cout << "Vertex : " << vertex << "\tEdge : " << edge << std::endl;
        std::chrono::system_clock::time_point startTime = std::chrono::system_clock::now();
        dijkstra(graph, stoi(vertexStr), source);  
        std::chrono::system_clock::time_point endtime = std::chrono::system_clock::now();
        std::chrono::duration<double, std::milli> difference = endtime - startTime;
        std::cout << "Time(ms) : " << difference.count() << std::endl; 
        std::cout<<"************************************************\n";
    }
    std::cout<<"************************************************\n\n\n";

    return 0;
}