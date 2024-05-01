#include <bits/stdc++.h>
using namespace std;
class gnode{
	int vertex;
	gnode* next;
	friend class graph;
};
class graph{
	gnode* head[20];
	int n;
	int visited[20];
	int visit[20];
	public:
		graph(){
			cout << "Give the no. of vertices";
			cin >> n;
			for (int i = 0; i < n;i++){
				head[i] = new gnode();
				head[i]->vertex=i;
				}
			cout << "Hello";
		}
		void create(){
			for(int i = 0; i < n ; i++){
				gnode* temp = head[i];
				int v;
				char ch;
				do{
					cout << "Give the next element to"<<i << ":";
					cin >> v;
					if (i==v)
						cout << "No Self Loop"<<endl;
					else{
						if (v == 999)
							continue;
						gnode* curr = new gnode();
						curr->vertex = v;
						temp->next = curr;
						temp = temp->next;
					}
					cout << "Give y/n";
					cin >> ch;
				}while(ch == 'y');
			}
			dfs();
		}
		void dfs(){
			int node;
			cout << "Give the node to start";
			cin >> node;
			for (int i = 0;i<n;i++)
			visited[i] = 0;
			dfs(node);
			bfs(node);
		}
		void dfs(int v){
			int node;
			gnode* temp = head[v]->next;
			visited[v] = 1;
			cout << v << endl;
			while (temp != NULL){
				node = temp->vertex;
				if (!visited[node])
					dfs(node);
				temp = temp->next;
			}
		}
	void bfs(int v)
	{
		queue<int> q;
		q.push(v);
		for (int i = 0; i < n; i++)
		{
			visit[i] = 0;
		}
		while (!q.empty())
		{
			int current = q.front();
			q.pop();
			if (!visit[current])
			{
				cout << current << "\n";
				visit[current] = 1;
				gnode *temp = head[current]->next;
				while (temp != NULL)
				{
					int w = temp->vertex;
					if (!visit[w])
					{
						q.push(w);
					}
					temp = temp->next;
				}
			}
		}
	}
};
int main(){
	graph g;
	g.create();
	
	return 0;
}
/*

PS C:\Users\HP\Downloads> cd "c:\Users\HP\Downloads\" ; if ($?) { g++ Tree_Creation_Traversal.cpp -o Tree_Creation_Traversal } ; if ($?) { .\Tree_Creation_Traversal }
Give the no. of vertices6
HelloGive the next element to0:1
Give y/ny
Give the next element to0:3
Give y/nn
Give the next element to1:2
Give y/nn
Give the next element to2:4
Give y/nn
Give the next element to3:2
Give y/nn
Give the next element to4:999
Give the next element to5:3
Give y/ny
Give the next element to5:4
Give y/nn
Give the node to start0
0
1
2
4
3
BFS
0
1
3
2
4*/