#include <iostream>
using namespace std;
class Node{
    int data;
    Node* left,*right;
    public:
        friend class Tree;
        Node(){
            left=NULL;
            right=NULL;
        }
};
class Tree{
    Node* root;
    public:
        Tree(){
            root=NULL;
        }
        Node* insert(Node* root,Node* temp){
            if (root==NULL)
                root = temp;
            else if(temp->data<root->data){
                root->left = temp;
                root=balance(root);
            }
            else{
                root->right = temp;
                root=balance(root);
            }
            return root;
        }
        void insert() {
            char ch = 'Y';  // Ensure correct initialization
            do {
                cout << "Enter data: ";  // Prompt for data input
                int data;  // Use a separate variable to hold input
                cin >> data;
                
                // Initialize Node and set data
                Node* temp = new Node();  // Correct initialization
                temp->data = data;  // Set data
                
                root = insert(root, temp);  // Insert into tree
                
                cout << "Do you want to continue? (Y/N): ";  // Prompt for user choice
                cin >> ch;
            } while (ch == 'Y' || ch == 'y');  // Ensure case-insensitive check
}

        Node* balance(Node* root){
            int bal = diff(root);
            if (bal >1){
                if (diff(root->left) > 0){
                    root=LL_rotation(root);
                }
                else
                    root=LR_rotation(root);
            }
            else if(bal < -1){
                if (diff(root->right) < 0){
                    root=RL_rotation(root);
                }
                else
                    root=RR_rotation(root);
            }
            return root;
        }
        Node* LL_rotation(Node* root){
            Node* temp = root->left;
            root->left = temp->right;
            temp->right = root;
            return temp;
        }
        Node* RR_rotation(Node* root){
            Node* temp = root->right;
            root->right = temp->left;
            temp->left = root;
            return temp;
        }
        Node* RL_rotation(Node* root){
            Node* temp = root->right;
            root->right = LL_rotation(temp);
            return RR_rotation(root);
        }
        Node* LR_rotation(Node* root){
            Node* temp = root->left;
            root->left = RR_rotation(temp);
            return LL_rotation(root);
        }
        int diff(Node *root){
            return height(root->left)-height(root->right);
        }
        int height(Node* root){
            if (root==NULL)
                return 0;
            return 1+max(height(root->left),height(root->right));
        }
        void display(Node* ptr,int level){
            if (ptr!=NULL){
                display(ptr->right, level + 1);
                printf("\n");
                if (ptr == root)
                    cout<<"Root -> ";
                for (int i = 0; i < level && ptr != root; i++)
                    cout<<" ";
                    cout<<ptr->data;
                    display(ptr->left, level + 1);
            }
        }
        void display(){
            display(root, 1);
        }
};
int main(){
    Tree t;
    t.insert();
    t.display();
    return 0;
}