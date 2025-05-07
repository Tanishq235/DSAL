#include<iostream>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

class bst{
    public:
    node* root;
    bst(){
        root=NULL;
    }

    void create(node*& root){
        int total,data;
        cout<<"Enter the total numbers of elements";
        cin>>total;
        for(int i=0;i < total;i++){
            cout<<"enter number"<<i+1<<":";
            cin>>data;
            insert(root,data);
        }
    }
    void insert(node*& root,int data){
        if(root==NULL){
            root= new node;
            root->data=data;
            root->right=NULL;
            root->left=NULL;
        }
        else if(data<root->data){
            insert(root->left,data);
        }
        else if(data>root->data){
            insert(root->right,data);
        }
    }
    int findmax(node* root){
        if(root==NULL){
            cout<<"Tree is empty"<<endl;
            return -1;
        }
        while(root->right!=NULL){
            root=root->right;
        }
        cout<<"Maximum value:"<<root->data<<endl;
        return root->data;
    }
    int findmin(node* root){
        if(root==NULL){
            cout<<"Tree is empty"<<endl;
            return -1;
        }
        while(root->left!=NULL){
            root=root->left;
        }
        cout<<"Minimum value:"<<root->data<<endl;
        return root->data;
}
    void search(node* root,int value ){
        while(root!=NULL){
            if(root->data==value){
                cout<<"value"<<value<<"Found in the tree"<<endl;
                return;
            }
            else if(value<root->data){
                root==root->right;
            }
            else {
                root=root->right;
            }
        }
        cout<<"value"<<value<<"Not found in the tree"<<endl;
    }
    void mirror(node*&root){
        if (root==NULL){
            return;
        }
        node* temp=root->left;
        root->left=root->right;
        root->right=temp;
        mirror(root->left);
        mirror(root->right);
    }
    int height(node* root){
        if (root==NULL){
            return 0;
        }
        int h1=height(root->left);
        int hr=height(root->right);
        return max(h1,hr) +1;

    }
    void display(node*root){
        if(root==NULL){
            display(root->left);
            cout<<root->data<<" ";
            display(root->right);

        }
    }
};
int main(){
    bst B;
    int data;
    int value;
    int choice;
do{
        cout<<"\n--MENU--"<<endl;
        cout<<"1.Create Bst "<<endl;
        cout<<"2.Insert node "<<endl;
        cout<<"3.Find Maximum"<<endl;
        cout<<"4.Find Minimum"<<endl;
        cout<<"5.Display bst"<<endl;
        cout<<"6.Search value"<<endl;
        cout<<"7.Mirror bst"<<endl;
        cout<<"8.Find height"<<endl;
        cout<<"9.Exit"<<endl;
        cout<<"Enter the choice: ";
        cin>>choice;

        switch(choice){
            case 1:
              B.create(B.root);
              break;
            case 2:
              cout<<"Enter the number to inserted";
              cin>>data;
              B.insert(B.root,data);
              break;
            case 3:
              B.findmax(B.root);
              break;
            case 4:
              B.findmin(B.root);
              break;
            case 5:
              cout<<"BST (Inorder)";
              B.display(B.root);
              cout<<endl;
              break;
            case 6:
              cout<<"enter the value to be searched";
              cin>>value;
              B.search(B.root,value);
              break;
            case 7:
              B.mirror(B.root);
              cout<<"BST mirrored";
              B.display(B.root);
              cout<<endl;
              break;
            case 8:
              cout<<"Height of BST :"<<B.height(B.root)<<endl;
              break;
            case 9:
              cout<<"--End--"<<endl;
              break;
            default:
              cout<<"Invalid choice. Please enter the valid option "<<endl;
        }
    }
    while(choice!=9);
    return 0;

}
