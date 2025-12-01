#include<iostream>
#include<list>
#include<set>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> dist(vector<vector<int>> &graph, int source, int edges){
    
    // now first of all create a adjacency list so that we can ...
    // use unordered map to map int type to a list type 
    unordered_map <int, list<pair<int,int>>> adj;

    // now iterate through a loop so that list can be created
    for (int i=0; i<edges; i++){  // NOTE THAT: edges ko hi traverse krna pdega kyuki wo hi connection set krenge bcoz no. of vertices and edges can be different
        int u = graph[i][0];  // the root node
        int v = graph[i][1];  // the final node
        int w = graph[i][2];  // distance between them

        adj[u].push_back({v,w});
        adj[v].push_back({u,w}); 
    }

    for (auto& node : adj){
        int u = node.first;
        cout << u << " -> ";

        for (auto& neighbour : node.second){
            int v = neighbour.first;
            int weight = neighbour.second;
            cout << "(" << v << ", " << weight << ") ";
        }
        cout << endl;
    }
    // now our adjacency list is created successfully , successfully tried and tested now jump to the main part of the program

    // make a array for distances
    // also take a set of ({distance,node}) so that we can extrace the lowest distance every time

    vector<int> dist(10,INT_MAX); // NOTE: in this we have to take number of vertices
    set<pair<int,int>> st;

    dist[source] = 0;
    st.insert({0,source});

    // now go inside the main loop 
    while(!st.empty()){

        auto top = *(st.begin());
        st.erase(st.begin());

        int nodeDistance = top.first; // the distance covered till now to that node
        int topNode = top.second;  // the node we are looking to

        for (auto &neighbour : adj[topNode]){
            int adjNode = neighbour.first;  // the adjacent node from the root node
            int edgeWeight = neighbour.second;  // the distance from the root node to neighbour node
            
            if (nodeDistance + edgeWeight < dist[adjNode]){

                auto oldRecord = st.find({dist[adjNode], adjNode});
                if (oldRecord != st.end()){
                    st.erase(oldRecord);
                }

                dist[adjNode] = nodeDistance + edgeWeight;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}

int main(){
    // create a vector<vector<int>> to store the bi-directional graph i made

    vector<vector<int>> graph;
    graph.push_back({0,1,25});
    graph.push_back({0,6,15});
    graph.push_back({0,3,20});
    graph.push_back({1,2,20});
    graph.push_back({6,7,10});
    graph.push_back({3,4,13});
    graph.push_back({3,8,12});
    graph.push_back({4,5,14});
    graph.push_back({8,9,11});
    graph.push_back({7,9,5});

    // now our graph is created that we have to pass to our function
    // let's declare it's source 
    int source = 0;
    int edges = 10;

    // now create a function which will take this input and tell us the least distance to every vertex
    vector<int> result = dist(graph,source,edges);

    cout << endl;

    for (int i=0; i<result.size(); i++){
        cout << "distance for node " << i << " is " << result[i] << " ";
        cout << endl;
    }

    cout << endl;
}