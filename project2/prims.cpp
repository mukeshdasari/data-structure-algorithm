#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include<bits/stdc++.h>


int extractMinimumDistance(std::vector<int> vertexKeyVec, std::vector<bool> vertexVisitVec){
    int minimumDistance = INT_MAX, index;
    for(int i=0; i<vertexKeyVec.size(); i++){
        if (vertexVisitVec[i] == false && vertexKeyVec[i] < minimumDistance){
            minimumDistance = vertexKeyVec[i];
            index = i; 
        }
    }
    return index;
}

void prims(std::vector<std::vector<int>> graph, int vertex, int source){
    std::vector<int> vertexParentVec(vertex);
    std::vector<bool> vertexVisitVec;
    std::vector<int> vertexKeyVec;
    
    //initialiazing all vertex distance with max and vertex set to false
    for(int i=0; i<vertex; i++){
        vertexKeyVec.push_back(INT_MAX);
        vertexVisitVec.push_back(false);
    }
 
    vertexKeyVec[source] = 0;
    vertexParentVec[source] = -1;

    for(int j=0; j<vertex-1; j++){
        int index = extractMinimumDistance(vertexKeyVec, vertexVisitVec);
        vertexVisitVec[j] = true;

        for (int k = 0; k < vertex; k++){
            if ( vertexVisitVec[k] == false  && graph[index][k] && graph[index][k] < vertexKeyVec[k]){
                vertexParentVec[k] = index;
                vertexKeyVec[k] = graph[index][k];
            } 
        }
    }
    int mst = 0;
    for (int l = 1; l < vertex; l++){
        char start = 65 + vertexParentVec[l];
        char end = 65 +  l;
        std::cout<<"Edge : "<<start<<" -> "<<end<<" \t"<<"Weight : "<<graph[l][vertexParentVec[l]] << std::endl;
        mst += graph[l][vertexParentVec[l]];
    }
    std::cout<<"MST Cost : "<<mst<<std::endl;

}

int main(){
    std::cout<<"\n************************************************\n";
    std::cout << "\t\tPRIM'S ALGORITHM" << std::endl;
    std::cout<<"************************************************\n";
    for(int i=0;i<4;i++){
        int startVertexFlag = false;
        std::string vertexStr, edgeStr, graphTypeStr;
        
        std::vector<std::string> inputStringVec;
        std::string line;
        std::ifstream inputFile("./input_sources/Prim_graph"+std::to_string(i+1)+".txt");

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
            
            // std::cout<< static_cast<int>(startVertex[0] - 'A') << static_cast<int>(endVertex[0] - 'A') << stoi(weight) << std::endl;
            graph[static_cast<int>(startVertex[0] - 'A')][static_cast<int>(endVertex[0] - 'A')] = stoi(weight);
            if(graphTypeStr[0] == 'U') graph[static_cast<int>(endVertex[0] - 'A')][static_cast<int>(startVertex[0] - 'A')] = stoi(weight);
        }
        int source = startVertexFlag ? static_cast<int>(inputStringVec[inputStringVec.size()-1][0] - 'A') >= 0 ? static_cast<int>(inputStringVec[inputStringVec.size()-1][0] - 'A') : 0 : 0;
        std::cout << "Graph " << i+1 << std::endl;
        std::cout << "Vertex : " << vertex << "\tEdge : " << edge << std::endl;
        std::chrono::system_clock::time_point startTime = std::chrono::system_clock::now();
        prims(graph, vertex, source);   
        std::chrono::system_clock::time_point endtime = std::chrono::system_clock::now();
        std::chrono::duration<double, std::milli> difference = endtime - startTime;
        std::cout << "Time(ms) : " << difference.count() << std::endl;
        std::cout<<"************************************************\n";
    }
    std::cout<<"************************************************\n";


    return 0;
}