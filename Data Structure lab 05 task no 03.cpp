#include <iostream>
using namespace std;
struct Player
 {
    string name;
    int score;
    Player*next;
    Player*prev;
};
Player* head=NULL;
//Insert in sorted order
void addPlayer(string name,int score)
 {
    Player*newNode=new Player();
    newNode->name=name;
    newNode->score=score;
    if(head == NULL)
	{
        newNode->next = newNode->prev = NULL;
        head=newNode;
        return;
    }
    Player*temp=head;
    while(temp!=NULL && temp->score < score)
        temp=temp->next;
    if(temp==head)
	{
        newNode->next=head;
        newNode->prev=NULL;
        head->prev=newNode;
        head=newNode;
    }
    else if(temp==NULL)
	{
        Player*last=head;
        while(last->next!=NULL)
            last=last->next;
        last->next=newNode;
        newNode->prev=last;
        newNode->next=NULL;
    }
    else{
        newNode->next=temp;
        newNode->prev=temp->prev;
        temp->prev->next=newNode;
        temp->prev=newNode;
    }
}

// Delete player by name
void deletePlayer(string name)
{
    Player*temp=head;
    while(temp!=NULL&&temp->name!=name)
        temp = temp->next;
    if(temp==NULL)
	{
        cout<<"Player not found\n";
        return;
    }
    if(temp==head)
	{
        head=head->next;
        if(head!=NULL)
            head->prev = NULL;
    }

    else{
        temp->prev->next=temp->next;
        if(temp->next !=NULL)
            temp->next->prev=temp->prev;
    }
    delete temp;
}
// Display all players
void display(){
    Player* temp=head;
    while(temp != NULL)
	{
        cout<<temp->name<<"  "<<temp->score<<endl;
        temp=temp->next;
    }
}
//Players with same score
void sameScore(int s)
{
    Player*temp=head;
    while(temp!=NULL)
	{
        if(temp->score== s)
            cout<<temp->name<<" "<<temp->score<<endl;
        temp =temp->next;
    }
}
//Lowest score
void lowestScore(){
    if(head == NULL) return;
    Player* temp = head;
    cout<<"Lowest Score Player: "<<temp->name<<" "<<temp->score<<endl;
}

// Display backward from a player
void displayBackward(string name){

    Player* temp=head;
    while(temp!=NULL && temp->name != name)
        temp = temp->next;
    if(temp ==NULL){
        cout<<"Player not found\n";
        return;
    }
    temp=temp->prev;
    while(temp!= NULL)
	{
        cout<<temp->name<<" "<<temp->score<<endl;
        temp=temp->prev;
    }
}
int main()
{
    int choice;
    string name;
    int score;
    do{
        cout<<"\n1 Add Player";
        cout<<"\n2 Delete Player";
        cout<<"\n3 Display All Players";
        cout<<"\n4 Lowest Score Player";
        cout<<"\n5 Players With Same Score";
        cout<<"\n6 Display Backward From Player";
        cout<<"\n0 Exit\n";
        cin>>choice;
        switch(choice){
        case 1:
            cout<<"Enter Name: ";
            cin>>name;
            cout<<"Enter Score: ";
            cin>>score;
            addPlayer(name,score);
            break;
        case 2:
            cout<<"Enter player name to delete: ";
            cin>>name;

            deletePlayer(name);
            break;
        case 3:
            display();
            break;
       case 4:
            lowestScore();
            break;
        case 5:
            cout<<"Enter score: ";
            cin>>score;
            sameScore(score);
            break;
        case 6:
            cout<<"Enter player name: ";
            cin>>name;
            displayBackward(name);
            break;
        }
    }while(choice!=0);
}