#include <iostream>
using namespace std;
struct Node{
    string name;
    Node* next;
};
Node* last = NULL;
//Add Employee
void addEmployee(string name){
    Node* newNode = new Node();
    newNode->name = name;
    if(last == NULL){
        last = newNode;
        newNode->next = newNode;
    }
    else{
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }

    cout<<"Added successfully\n";
}

//Search Employee
void searchEmployee(string name){
    if(last == NULL){
        cout<<"List empty\n";
        return;
    }
    Node* temp = last->next;
    do{
        if(temp->name == name){
            cout<<"Found successfully\n";
            return;
        }
        temp = temp->next;
    }while(temp != last->next);
    cout<<"Employee not found\n";
}
//Deleting Employee
void deleteEmployee(string name){
    if(last == NULL){
        cout<<"List empty\n";
        return;
    }
    Node *curr = last->next, *prev = last;
    do{
        if(curr->name == name){
            //Only one node
            if(curr == last && curr->next == last)
                last = NULL;
            else{
                prev->next = curr->next;
                if(curr == last)
                    last = prev;
            }

            delete curr;

            cout<<"Deleted successfully\n";
            return;
        }
        prev = curr;
        curr = curr->next;
    }while(curr != last->next);
    cout<<"Employee not found\n";
}
//Updating Employee
void updateEmployee(string oldName, string newName){

    if(last == NULL){
        cout<<"List empty\n";
        return;
    }
    Node* temp = last->next;
    do{
        if(temp->name == oldName){
            temp->name = newName;
            cout<<"Updated successfully\n";
            return;
        }
        temp = temp->next;

    }while(temp != last->next);
    cout<<"Employee not found\n";
}
//displaying the List
void display(){
    if(last == NULL){
        cout<<"List empty\n";
        return;
    }
    Node* temp = last->next;
    do{
        cout<<temp->name<<" ";
        temp = temp->next;
    }while(temp != last->next);
    cout<<endl;
}
int main(){
    cout<<"---Adding Employees---\n";
    addEmployee("Touseef");
    addEmployee("Duaa");
    addEmployee("Mirha");
    addEmployee("Babar");
    cout<<"\nEmployees List:\n";
    display();
    cout<<"\nSearch Employee (Touseef):\n";
    searchEmployee("Touseef");
    cout<<"\nUpdate Employee (Mirha -> Fatima):\n";
    updateEmployee("Mirha","Fatima");
    display();

    cout<<"\nDelete Employee (Babar):\n";
    deleteEmployee("Babar");
    display();
    return 0;
}