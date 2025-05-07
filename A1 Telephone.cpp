#include<iostream>
#include<string>
using namespace std;

const int Table_size = 10;

struct client {
	string name;
	long long telephone;
};

struct node {
	client data;
	node* next;
};

class linear {
	client table[Table_size];
	bool occupied[Table_size];

public:
	linear() {
		for (int i = 0; i < Table_size; i++) {
			occupied[i] = false;
		}
	}

	int hashfunction(long long tele) {
		return tele % Table_size;
	}

	void Insert(long long tele, string name) {
		int index = hashfunction(tele);
		int start = index;

		while (occupied[index]) {
			index = (index + 1) % Table_size;
			if (start == index) {
				cout << "Table is full !!!" << endl;
				return;
			}
		}
		table[index].name = name;
		table[index].telephone = tele;
		occupied[index] = true;
		cout << "Successfully inserted (Linear) !!!" << endl;
	}
	
	int Search(long long tele){
	    int index = hashfunction(tele);
	    int start = index;
	    int comparision = 0;
	    
	    if(occupied[index]){
	        comparision ++;
	        if(table[index].telephone == tele){
	            cout<<"The search telephone user is found !!!"<<endl;
	            return comparision;
	        }
	        index = index + 1;
	    }
	    else {
	        cout<<"The search elephone was not found in databse !!!"<<endl;
	    }
	    
	}

	void Display() {
		cout << "--Linear Hash Table--" << endl;
		for (int i = 0; i < Table_size; i++) {
			if (occupied[i]) {
				cout << "[" << i << "] " << table[i].name << " -> " << table[i].telephone << endl;
			}
			else {
				cout << "[" << i << "] EMPTY" << endl;
			}
		}
	}
};

class chaining {
	node* table[Table_size];

public:
	chaining() {
		for (int i = 0; i < Table_size; i++) {
			table[i] = NULL;
		}
	}

	int hashfunction(long long tele) {
		return tele % Table_size;
	}

	void Insert(long long tele, string name) {
		int index = hashfunction(tele);
		node* newnode = new node;
		newnode->data.name = name;
		newnode->data.telephone = tele;
		newnode->next = table[index];
		table[index] = newnode;
		cout << "Successfully inserted (Chaining) !!!" << endl;
	}
	
	int Search(long long tele){
	    int index = hashfunction(tele);
	    node* temp = table[index];
	    int comparision = 0;
	    
	    while(temp){
	        comparision ++;
	        if(table[index]->data.telephone == tele){
	            cout<<"The search user is found !!!"<<endl;
	            return comparision;
	        }
	        else{
	            temp = temp->next;
	        }
	    }
	    
	}


	void Display() {
	    cout<<"---Chaining Table---"<<endl;
		for(int i = 0 ; i < Table_size ; i++) {
			cout<<"["<<i<<"]";
			node * temp = table[i];
			while(temp) {
				cout<<"->"<<temp->data.name<<"->"<<temp->data.telephone<<endl;
				temp = temp -> next;
			}

			cout<<"\n";

		}
 	}
};


	int main() {
		linear l1;
		chaining c1;
		int choice;
		string name;
		long long tele;

		do {
			cout << "--MENU--" << endl;
			cout << "1.Insert" << endl;
			cout << "2.Search" << endl;
			cout << "3.Display" << endl;
			cout << "4.Exit" << endl;
			cout << "Enter the choice(1-4) : ";
			cin >> choice;

			switch (choice) {
			case 1:
				cout << "Enter the name : ";
				cin >> name;
				cout << "Enter the telephone: ";
				cin >> tele;

				l1.Insert(tele, name);
				c1.Insert(tele, name);

				break;
				
			case 2:
			    cout<<"Enter the search telephone : ";
			    cin>>tele;
			    l1.Search(tele);
			    c1.Search(tele);
			    break;

			case 3:
				l1.Display();
				c1.Display();
				break;
			}

		} while (choice != 4);

		return 0;
	}

	
