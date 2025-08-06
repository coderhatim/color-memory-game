#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <conio.h>
//////////////////////////////////////////
using namespace std::this_thread;
void display_colour(int color);
void insertColor(struct node*& head, int color);
void add(node*& head);
void singleplayer();
int randomize_color();
int getColorAt(struct node* head, int index);
bool out= false; 
int score=0;
bool hard=false;
///////////////////////////////////////////
using namespace std;
struct node {
    int colour;
    node* next;
};
///////////////////////////////////////////
void insertColor(node*& head, int color) {
    // Create a new node and store the color in it
    node* newNode = new node;
    newNode->colour = color;
    newNode->next = nullptr;

    // If list is empty, make head point to newNode
    if (head == nullptr) {
        head = newNode;
    }
    else {
        // Otherwise, go to the last node and attach newNode
        node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
///////////////////////////////////////////
int randomize_color(){
	int random;
	if(hard){
		random = rand() % 7 + 1; 
	}
	else{
		random = rand() % 4 + 1; 	
	}
    
    return random;
}
///////////////////////////////////////////

void add(node*& head){
   

    int randomColor = randomize_color();  
    insertColor(head, randomColor);
    display_colour(randomColor);  
}
///////////////////////////////////////////
int getColorAt(node* head, int index) {
    int count = 0;
    node* temp = head;

    while (temp != nullptr) {
        if (count == index) {
            return temp->colour;
        }
        count++;
        temp = temp->next;
    }

    return -1; // If index is out of range
}
///////////////////////////////////////////
void display_colour(int color) {
    	if(hard){
    		switch (color) {
        case 1: cout << "\U0001F534"; break;
        case 2: cout << "\U0001F7E2"; break;
        case 3: cout << "\U0001F535"; break;
        case 4: cout << "\U0001F7E1"; break;
        case 5: cout << "\U0001F7E3"; break;
        case 6: cout << "\U0001F7E0"; break;
        case 7: cout << "\u26AA"; break;
        default: cout << "\u2757\n"; break;}
    }
    else{
    	switch (color) {
    	case 1: cout << "\U0001F534"; break;
        case 2: cout << "\U0001F7E2"; break;
        case 3: cout << "\U0001F535"; break;
        case 4: cout << "\U0001F7E1"; break;
        default: cout << "\u2757\n"; break;
	}
    }
    
}
///////////////////////////////////////////
void singleplayer() {
    cout << "Game started\n";
    sleep_for(std::chrono::seconds(2));
    system("cls");
    node* head = nullptr;  
    int index = 0;         
    out = false;          

    while (out == false) {
    	system("cls");
        cout << "        ";
        add(head);
        if(hard){
        	sleep_for(std::chrono::milliseconds(600));	
		}
		else{
			sleep_for(std::chrono::seconds(2));
		}
        
        system("cls"); 
        cout<<"score : "<<score<<endl;
        cout << "Enter the full colour sequence (as numbers):\n";
        if(hard==false){
        cout << "1)\U0001F534  2)\U0001F7E2  3)\U0001F535  4)\U0001F7E1 \n";}
        else{
	        cout << "1)\U0001F534  2)\U0001F7E2  3)\U0001F535  4)\U0001F7E1  5)\U0001F7E3  6)\U0001F7E0  7)\u26AA\n";}
        for (int i = 0; i <= index; i++) {
            int n;
            cin >> n;
            if (n == getColorAt(head, i)) {
                cout << "Correct!\n";
            } else {
            	cout<<"wrong!"<<endl;
            	sleep_for(std::chrono::seconds(2));
            	system("cls");
                cout << "Game Over.\n";
                cout<<"score : "<<score<<endl;
                for(int j=0; j<=index; j++){
                	display_colour(getColorAt(head,j));
                	//cout<<"\u26AB";
                	cout<<" ";
				}
				cout<<"- the sequence";
				cout<<endl;
				for(int j=0; j<i; j++){
					//cout<<"\u26AB\u26AB";
					cout<<"   ";
					
				}
				display_colour(n);
				cout<<" - mistake";
				cout<<endl;
                out = true;
                break;
            }
        }
        index++;
        score++;
    }
    int x;
    cout<<"press any to exit."<<endl;
    //cin>>x;
    _getch();
    system("cls");
    return;
}
///////////////////////////////////////////
void deffi(){
 cout<<"1) normal \n";
 cout<<"2) hard\n";
 cout<<"3) exit\n";
 int x;
 cin>>x;
 if(x==1){
 	hard=false;
 	system("cls");
 	singleplayer();
 	
 }
 else if(x==2){
 	hard=true;
 	system("cls");
 	singleplayer();
 	
 }
 else{
 	system("cls");
 	return;
 }
 return;
}
int main() {
    srand(time(0));
    system("chcp 65001");
    system("cls");
    while(true){
    cout<<"1) play\n";
    cout<<"2) Exit\n";
    int choice;
    cin >> choice;
    if (choice == 1) {
        //cout << "You chose a 1 player game.\n";
        score=0;
        system("cls");
        deffi();  
    } else if (choice == 2) {
        cout << "Exiting the game.\n";
        break;
    } else {
        cout << "Invalid choice. Please try again.\n";
    }
	}
    return 0;
}
