#include<iostream>
using namespace std;

class treenode{
	char data;
	treenode *left;
	treenode *right;
	friend class tree;
};
class stack{
	int top;
	treenode* data[30];
	public:
		stack(){
			top = -1;
		}
		void push(treenode* temp){
			top++;
			data[top] = temp;
		}
		treenode* pop(){
			return data[top--];
			
		}
		int empty(){
			if (top == -1)
				return 1;
			return 0;
		}
		friend class tree;
};
class tree{
	treenode *root;
	stack s;
	public:

		tree(){
		    root=NULL;
		}

		void create_r(){
		   root = new treenode();
		   cout<<"Enter Data To Be Put In Root"<<endl;
		   cin>>root->data;
		   root->left = root->right = NULL;
		   create_r(root);
		}
		void create_nr() {
			if (root != NULL) {
				cout << "Tree already has a root. Cannot create a new tree." << endl;
				return;
			}

			root = new treenode();
			cout << "Enter Data To Be Put In Root" << endl;
			cin >> root->data;
			root->left = root->right = NULL;

			stack<treenode*> s;
			s.push(root);

			while (!s.empty()) {
				treenode* current = s.top();
				s.pop();

				char ch;
				cout << "Do You Want To Attach Node on Left (Y/N) ";
				cin >> ch;

				if (ch == 'Y') {
					treenode* newNode = new treenode();
					cout << "Enter Data To Be Put In Left Child: ";
					cin >> newNode->data;
					newNode->left = newNode->right = NULL;
					current->left = newNode;
					s.push(newNode);
				}

				cout << "Do You Want To Attach Node on Right (Y/N) ";
				cin >> ch;

				if (ch == 'Y') {
					treenode* newNode = new treenode();
					cout << "Enter Data To Be Put In Right Child: ";
					cin >> newNode->data;
					newNode->left = newNode->right = NULL;
					current->right = newNode;
					s.push(newNode);
				}
			}
		}
		void create_r(treenode* root){
		    char ch;
		    treenode *ptr;
		    cout<<"Do You Want To Attach Node on Left (Y/N) "<<endl;
		    cin>>ch;
		    if(ch == 'Y'){
		      ptr = new treenode();
		      cin>> ptr->data;
		      ptr->left = ptr->right = NULL;
		      root->left = ptr;
		      create_r(ptr);
		    }
		    cout<<"Do You Want To Attach Node on Right (Y/N) "<<endl;
		    cin>>ch;
		    if(ch == 'Y'){
		      ptr = new treenode();
		      cin>> ptr->data;
		      ptr->left = ptr->right = NULL;
		      root->right= ptr;
		      create_r(ptr);
		    }

		}
		void display(){
			
			cout << "Post Order Traversal" << endl;
			cout << "Recursive"<<endl;
			post_order_r(root);
			
		}
		void pre_order_r(treenode* root){
			if (root == NULL)
				return;
			cout << root->data << "\t";
			pre_order_r(root->left);
			pre_order_r(root->right);
			
		}
		void in_order_r(treenode* root){
			if (root == NULL)
				return;
			in_order_r(root->left);
			cout << root->data << "\t";
			in_order_r(root->right);
		}
		void post_order_r(treenode* root){
			if (root == NULL)
				return;
			post_order_r(root->left);
			post_order_r(root->right);
			cout << root->data << "\t";
		}
		void pre_order_nr(){
			treenode* temp;
			temp = root;
			while(1){
				
				while(temp != NULL){
					s.push(temp);
					treenode* x;
					x = s.pop();
					
					temp = temp->left;
				}
				if (s.empty())
					break;
				
				temp = temp->right;
			} 
		}
		void in_order_nr(){
			treenode* temp;
			temp = root;
			while(1){
				while(temp != NULL){
					s.push(temp);
					temp = temp->left;
				}
				if (s.empty())
					break;
				treenode* x;
				x = s.pop();
				cout << x->data;
				temp = temp->right;
			} 
		}
		void post_order_nr(){
			treenode* temp = root;
			while(1){
				while (temp != NULL){
					if (temp->right != NULL)
						s.push(temp->right);
					s.push(temp);
					temp = temp->left;
				}
				temp = s.pop();
				if (temp->right && s.data[s.top] == temp->right){
					s.pop();
					s.push(temp);
					temp = temp->right;
				}
				else
				{
					cout << temp->data;
					temp = NULL;
				}
				
			}
		}
};



int main()
{
tree bt;
bt.create_nr();
//bt.create_r();
bt.display();
return 0;
}

//2nd part
#include <iostream>

using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to create a binary tree non-recursively
void create_nr(Node*& root) {
    if (root == nullptr) {
        root = new Node(0); // Dummy root to start the tree
        cout << "Enter data for root node: ";
        cin >> root->data;
    }

    char choice;
    do {
        Node* temp = root;
        int flag = 0;
        Node* curr = new Node(0); // Dummy node for accepting data

        cout << "Enter data for new node: ";
        cin >> curr->data;

        while (flag == 0) {
            cout << "Add as left child (l) or right child (r) of " << temp->data << ": ";
            cin >> choice;

            if (choice == 'l') {
                if (temp->left == nullptr) {
                    temp->left = curr;
                    flag = 1;
                }
                temp = temp->left;
            } else if (choice == 'r') {
                if (temp->right == nullptr) {
                    temp->right = curr;
                    flag = 1;
                }
                temp = temp->right;
            }
        }

        cout << "Do you want to continue adding nodes? (y/n): ";
        cin >> choice;

    } while (choice == 'y');
}

int main() {
    Node* root = nullptr;
    create_nr(root);

    // Displaying the created binary tree
    // Display function can be implemented using various tree traversal techniques

    return 0;
}
