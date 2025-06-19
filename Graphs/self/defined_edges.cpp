#include <iostream>
using namespace std;

class AdjacencyMatrix {
    private:
    int nodes;  //number of nodes
    int **adj;  // pointer to 2d array (matrix)

    public:
    AdjacencyMatrix(int nodes){
        this->nodes = nodes;
        adj = new int* [nodes];

        for (int i = 0; i < nodes; i++){
          adj[i] = new int[nodes];
          for (int j = 0; j < nodes; j++){
           adj[i][j] = 0;
          }
          
        }
        display();
    }

    void add_edge(int origin,int destin){
        if(origin>nodes || destin > nodes || origin <=0 || destin <=0) {
            cout << "Invalid edge"<<endl;
            return;
        }
        adj[origin-1][destin-1]=1;
    }

    void delete_edge(int origin,int destin){
        if(origin>nodes || destin > nodes || origin <=0 || destin <=0) {
            cout << "Invalid edge"<<endl;
            return;
        }
        adj[origin-1][destin-1] = 0;
    }

    void display() {
        int i,j;
        for ( i = 0; i < nodes; i++)
        {
           for ( j = 0; j < nodes; j++)
           {
          cout<<adj[i][j]<<" ";
          cout<<endl;
           }
           
        }
        
    }

};

int main(){
	int nodes, max_edges,edges, origin, destin;
            cout<<"Enter number of nodes: ";
           cin>>nodes; 
           cout<<"Enter number of egdes: ";
           cin>>edges;
           if(edges>(nodes*nodes)){
           cout<<"invalid number of edges"<<endl;
           return 0;
           }
          AdjacencyMatrix am(nodes);
        	for (int i = 0; i < edges; i++){
    	cout<<"Edges number :"<<i+1<<endl;
    	cout<<"Enter edge (-1 -1 to exit): "<<endl;
    	cout<<"Enter Origin and destination vertices : "<<endl;
    	cin>>origin>>destin;	 
    	if(origin == -1 || destin == -1)
        	break;
    	am.add_edge(origin, destin);
	}
	am.display();

am.delete_edge(1,2);
am.delete_edge(2,2);
cout<<"After deleting two edges"<<endl;
am.display();
	return 0;
}
