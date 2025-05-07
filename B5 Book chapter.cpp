#include<iostream>
#include<string>
using namespace std;

struct node{
    string label;
    int childcount;
    node* child[10];
};

class booktree{
    node* root;
    
    public:
    booktree(){
        root = nullptr;
    }
    
    void create(){
        root = new node;
        cout<<"Enter the name of Title: ";
        cin.ignore();
        getline(cin,root->label);
        
        cout<<"Enter the number of chapeters in the book : ";
        cin>>root->childcount;
        
        for(int i = 0; i < root->childcount; i++){
            root->child[i] = new node;
            cout<<"Enter the name of chapeter "<< i + 1<<" : ";
            cin.ignore();
            getline(cin,root->child[i]->label);
            
            cout<<"Enter the number of sections in the chapeter : ";
            cin>>root->child[i]->childcount;
            
            for(int j = 0 ; j< root->child[i]->childcount; j++){
                root->child[i]->child[j] = new node;
                cout<<"Enter the name of section "<< j + 1<<" : ";
                cin.ignore();
                getline(cin,root->child[i]->child[j]->label);
                
                cout<<"Enter the number of sub-sectuions in the section : ";
                cin>>root->child[i]->child[j]->childcount;
                
                for(int k = 0; k < root->child[i]->child[j]->childcount; k++){
                    root->child[i]->child[j]->child[k]= new node;
                    cout<<"Enter the name of sub-section "<< k + 1<<" : ";
                    cin.ignore();
                    getline(cin,root->child[i]->child[j]->child[k]->label);
                    
                    root->child[i]->child[j]->child[k]->childcount = 0;
                    
                }
            }
        }
    }
    
    void Display(){
        if(!root){
            cout<<"Book is not created !!!"<<endl;
        }
        else{
            cout<<"--BOOK--"<<endl;
            for(int i = 0 ; i < root->childcount;i++){
                cout<<" chapeter "<< i + 1<< " : "<<root->child[i]->label<<endl;
                for(int j = 0 ; j < root->child[i]->childcount; j++){
                    cout<<" section "<< i + 1<< " : "<<root->child[i]->child[j]->label<<endl;
                    for(int k = 0 ; k < root->child[i]->child[j]->childcount; k++){
                        cout<<" Sub-section "<< i + 1<< " : "<<root->child[i]->child[j]->child[k]->label<<endl;
                    }
                }
            }
            
        }
    }
};
int main(){
    booktree b1;
    int n;
    
    do{
        cout<<"--MENU--"<<endl;
        cout<<"1.create a book"<<endl;
        cout<<"2.Display a book"<<endl;
        cout<<"3.Exit"<<endl;
        
        cout<<"Enter the choice number(1-3) : ";
        cin>>n;
        
        switch(n){
            case 1:
            b1.create();
            break;
            
            case 2:
            b1.Display();
            break;
        }
    }while( n != 3);
    
    return 0;
}
