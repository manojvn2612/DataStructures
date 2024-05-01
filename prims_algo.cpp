#include <iostream>
#include <limits>
using namespace std;

class graph{
    int cost[10][10];
    int cities;
public:
    graph(){
        cities = 0;
        cout << "Give no. of cities: ";
        cin >> cities;
        for (int i = 0; i < cities; i++)
            for(int j = 0; j < cities; j++)
                cost[i][j] = 999;
    }

    void create(){
        bool choice;

        for (int i = 0; i < cities; i++){
            for(int j = i+1; j < cities; j++) {
                cout << "Do you want to enter cost matrix from city " << i << " to " << j << "? (1/0): ";
                cin >> choice;
                if (choice == true) {
                    cout << "Give cost matrix between " << i << " and " << j << ": ";
                    cin >> cost[i][j];
                    cost[j][i] = cost[i][j];
                } else {
                    cost[i][j] = cost[j][i] = 999;
                }
            }
        }
    }

    void display(){
        cout << "Cost Matrix" << endl;
        for(int i = 0; i < cities; i++){
            cout << "\n";
            for (int j = 0; j < cities; j++)
                cout << cost[i][j] << " ";
        }
        cout << endl;
    }

    int prims(int start_v){
        int nearest[10];
        int j,mincost=0;
        int t[10][2];
        for (int i= 0 ; i < cities; i++)
            nearest[i] = -1;
        for (int i = 0; i < cities; i++){
            if (i != start_v)
                nearest[i] = start_v;
        }
        int r = 0;
        for (int i = 1; i < cities ; i++){
            int min = 999;
            for (int k = 0 ; k < cities;k++){
                if (nearest[k] != -1 && cost[k][nearest[k]] < min){
                    j = k; 
                    min = cost[k][nearest[k]];
                }
            }
            t[r][0] = j;
            t[r][1]= nearest[j];
            r +=1;
            mincost += cost[j][nearest[j]];
            nearest[j]=-1;
            for (int k = 0 ; k < cities;k++){
                if (nearest[k]!=-1 && cost[k][nearest[k]]>cost[k][j])
                nearest[k]=j;
            }
        }
        return mincost;
    }
    void print(){
        int mincost = prims(1);
        cout << "Minimum Cost is " << mincost << endl;
    }
};

int main(){
    graph g;
    g.create();
    g.display();
    g.print();

    return 0;
}
