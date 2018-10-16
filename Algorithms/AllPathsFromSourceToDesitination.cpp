#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class Graph {
    public:
        Graph(int n):vertices(n) {
            adj = new vector<int>[n];
        }
    
        void add_edge(int u, int v) {
            adj[u].push_back(v);
            
        }
    
        void print_path_util(int start ,int end,vector<int> & path,bool visited [])
        {
            
            visited[start] = true;
            //cout<<"Visited:"<<start<<"\n";
            path.push_back(start);
            if(start == end)
            {
                size_t count =0;
                for(auto it = path.begin() ; it!=path.end();++it)
                {
                    cout<<*it;
                    if(count != (path.size()-1))
                        cout<<"->";
                    count++;
                }
                cout<<"\n";
            }
            
            else
            {
                
            
                for(auto iter = adj[start].begin(); iter!= adj[start].end();++iter)
                {
                    if(!visited[*iter])
                    {
                        print_path_util(*iter,end,path,visited);
                    }
                }
            }
            visited[start] = false;
            path.pop_back();
        }
    
        void print_path(int start,int end) 
        {
            bool visited [vertices] = {false};
            vector<int> path;
            
            print_path_util(start ,end, path,visited );
            
        }
    private:
    vector<int> * adj;
    int vertices ;
    
};

int main() {
        // Create a graph of size n where each edge weight is 6: 
    Graph g(4); 
    g.add_edge(0, 1); 
    g.add_edge(0, 2); 
    g.add_edge(0, 3); 
    g.add_edge(2, 0); 
    g.add_edge(2, 1); 
    g.add_edge(1, 3); 
  
    int s = 2, d = 3; 
    cout << "Following are all different paths from " << s 
         << " to " << d << endl; 
    g.print_path(s, d); 
    
    return 0;
}
