#include <bits/stdc++.h>
using namespace std;
class gnode {
    private:
        int vertex;
        gnode* next;
        friend class graph;
};

class graph {
    private:
        gnode* head[10];
        int n;
    public:
        cout << "Enter No. of Vertices: ";
        cin >> n;
        for (int i = 0 ;i < n;i++){
            head[i] = new gnode();
            head[i]->vertex = i;
            head[i]->next = NULL;
        }
        void create_graph(){
            cout << ""
        }
};