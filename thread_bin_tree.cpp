#include <iostream>
using namespace std;
class tbtnode {
    char data;
    bool rbit;
    bool lbit;
    tbtnode *left;
    tbtnode *right;
    tbtnode(){
        lbit = rbit = false;
    }
    friend class tbt;
};
class tbt {
    tbtnode *head;
    public:
    tbt() {
        head = new tbtnode();
        head->rbit = head->lbit = true;
        head->left = head->right = head;
    }
    void create(){
        tbtnode *root = new tbtnode();
        cout << "Give root data";
        cin >> root->data;
        head->lbit = 1;
        head->left = root;
        root->right = head;
        root->left = head;
        char g;
        
        do {
            tbtnode *temp = root;
            tbtnode *newnode = new tbtnode();
            bool flag = false;
            
            while (flag == false)
            {
                char ch;
                cout << "Give left or right";
                cin >> ch;
                cout << "Give data";
                cin >> newnode->data;
                if (ch == 'l')
                {
                    if (temp->lbit == 0)
                    {
                        newnode->right = temp;
                        newnode->left = temp->left;
                        temp->left = newnode;
                        temp->lbit = 1;
                        flag = true;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
                if (ch == 'r'){
                    if (temp->rbit == 0)
                    {
                        newnode->left = temp;
                        newnode->right = temp->right;
                        temp->right = newnode;
                        temp->rbit = 1;
                        flag = true;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
                cout << "Continue with";
                cin >> g;
                }
            }while (g == 'y');
        
    }
    void inorder(){
        tbtnode *temp = head;
        while(1){
            temp = inordersucc(temp);
            if(temp == head) break;
            cout << temp->data;
        }
    }

    tbtnode* inordersucc(tbtnode* temp){
        tbtnode *x = temp->right;
        if (temp->rbit== 1){
            while (x->lbit==1)
            {
                x = x->left;
            }}
        return x;   
    }
    void preorder(){
        tbtnode* temp = head->left;
        while(temp!= head){
            cout << temp->data;
            while(temp->lbit != 0){
                temp = temp->left;
                cout << temp->data;

            }
            while(temp->rbit == 0){
                temp = temp->right;
            }
            temp = temp->right;
        }
    }
};

int main(){
    tbt t;
    t.create();
    t.inorder();
    t.preorder();
    return 0;
}