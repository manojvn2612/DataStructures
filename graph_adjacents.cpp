#include <iostream>
using namespace std;

class gnode {
public:
    int vertex;
    gnode* next;
    friend class graph;
};

class graph 
{
private:
    gnode* head[20];
    int n;

public:
    graph() 
    {
        cout << "Enter the number of vertices: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            head[i] = new gnode();
            head[i]->vertex = i;
            head[i]->next = NULL;
        }
    }

    void create() 
    {
        for (int i = 0; i < n; i++) {
            gnode* temp = head[i];
            char ch;
            do {
                cout << "Do you have any adjacent vertex to be added to " << i << " : ";
                int v;
                cin >> v;
                if (v == i) 
                {
                    cout << "Self loop is not allowed.\n";
                } 
                else 
                {
                    gnode* curr = new gnode();
                    curr->vertex = v;
                    curr->next = NULL;
                    temp->next = curr;
                    temp = temp->next;
                }
                cout << "Do you want to continue (y/n): ";
                cin >> ch;
            } while (ch == 'y' || ch == 'Y');
        }
    }

   

void DFS()
{
    int visited[n];
    for( int i=0 ; i<n; i++)
    visited[i]=0;
    int v;
    cout<<"enter the starting vertex"<<endl;
    cin>>v;
    DFS(v,visited);
}


void DFS(int v,int visited[])
{
    cout<<"the value for vertex currently pointing is :"<<v<<endl;
    visited[v]=1;
    


    gnode *temp =head[v]->next;
    while(temp!=NULL)
    {
        int w=temp->vertex;

        //cout<<w<<endl;
        if(!visited[w])
        DFS(w,visited);
        temp=temp->next;
    }

}
};

int main() {
    graph g;
    g.create();
    g.DFS();
    return 0;
}
