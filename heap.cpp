#include <iostream>
using namespace std;
class heap{
    int n,arr[INT_MAX],j=0;
    void add(){
        cout << "Enter element to be added : ";
        int element;
        cin >> element;
        arr[j]=element;
        insert(arr,j+1);
        j++;
    }
    void insert(int arr[100],int k){
        int temp1;
        int i = k;
        int temp = arr[k-1];
        while(i > 1 && arr[(i/2)-1] < temp){
            temp1 = arr[(i/2)-1];
            arr[i-1] = temp1;
            i = i/2;
        }
        arr[i-1] = temp;
    }
    void adjust(int arr[100],int k,int n){
        
    }
    int deleteh(int arr[100]){
        int x = arr[0];
        arr[0] = arr[n-1];

    }
};
int main(){
    int x;
    cin >> x;
    return 0;
}