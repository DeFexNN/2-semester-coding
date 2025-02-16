#include <iostream>
#include <ostream>
#include <cstring>

using namespace std;

struct note{
    char name[20];
    char surname[20];
    char telephone[20];
    int  bday[3];
    note*next;
    note*prev;
};

note* EnterNotes(note* head){
        if(head==nullptr){
            note*temp=new note;
            cout <<endl<< "Enter strcut specs"<<endl;
            cout << "Enter name: "<<endl;cin.getline(temp->name,sizeof(temp->name));
            cout << "Enter surname: "<<endl;cin.getline(temp->surname,sizeof(temp->surname));
            cout << "Enter telephone: "<<endl;cin.getline(temp->telephone,sizeof(temp->telephone));
            cout << "Enter bday(3): "<<endl;for(int i = 0;i<3;i++)cin>>temp->bday[i];
            return temp;
        }else{
            while(head->next!=nullptr){
                head=head->next;
            }
            note*temp=new note;
            cout <<endl<< "Enter strcut specs"<<endl;
            cout << "Enter name: "<<endl;cin.getline(temp->name,sizeof(temp->name));
            cout << "Enter surname: "<<endl;cin.getline(temp->surname,sizeof(temp->surname));
            cout << "Enter telephone: "<<endl;cin.getline(temp->telephone,sizeof(temp->telephone));
            cout << "Enter bday(3): "<<endl;for(int i = 0;i<3;i++)cin>>temp->bday[i];
            head->next=temp;
            temp->prev=head;
            return temp;
        }
}
void PrintNotes(note*head){
    while(head!=nullptr){
        cout << "Name: "<<head->name<<endl;
        cout << "Surname: "<<head->surname<<endl;
        cout << "Telephone: "<<head->telephone<<endl;
        cout << "Bday: "<<head->bday[0]<<"/"<<head->bday[1]<<"/"<<head->bday[2]<<endl;
        head=head->next;
    }
}





int main (){
    note *head=nullptr;
    head = EnterNotes(head); // Передаємо адресу i-го елемента
    PrintNotes(head);
    return 0;
}
