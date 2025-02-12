#include <cstdio>
#include <cstring>
#include <iostream>
#include <ostream>
using namespace std;

// Глобальна змінна (поки що не використовується в логіці списку)
int i = 0;

// Структура Node представляє вузол однонапрямленого списку.
// Кожен вузол містить:
// - Показник на наступний вузол (next)
// - Ціле число (hyinya) як дані вузла.
struct Alphabet {
    Alphabet* next;
    char letters[20];
    char znaki[10];
    int let_num;
    int znak_num;
};
// Функція Add_Single_Node додає новий вузол до кінця списку.
// Якщо список порожній (head == nullptr), новий вузол стає головою списку і вводяться дані користувача.
// Якщо список не порожній, функція проходить через вузли, поки не дійде до останнього, і додає новий вузол після нього.
// Повертається (можливо змінена) голова списку.
Alphabet* Add_Nodes(Alphabet* head,int num) {
    for(;num!=0;num--){
    i++;
    Alphabet *t1, *t2;
    t1 = new Alphabet();       // Створення нового вузла у динамічній пам'яті.
    t1->next = nullptr;    // Ініціалізація поля next як nullptr, бо це новий вузол без наступника.
    cout << "\nCreating node...("<<i<<")\n";
    if (head==nullptr) {
        // Якщо список порожній, тоді:
        head = t1;       // Новий вузол стає головою списку.
        // Зчитування значення для нового вузла від користувача:
        (void)getchar(); 
        cout<<"Enter value for first node:\nEnter letters: ";cin.getline(head->letters,sizeof(head->letters));
        cout <<"Enter znaki: ";cin.getline(head->znaki,sizeof(head->znaki));
        head->let_num=strlen(head->letters);
        head->znak_num=strlen(head->znaki);
    } else {
        // Якщо список не порожній, тоді проходимо по вузлах до кінця.
        t2 = head;       // Починаємо з голови списку.
        while (t2->next != nullptr)
            t2 = t2->next;   // Перехід до наступного вузла, поки не знайдемо останній.
          cout<<"Enter value for ("<<i<<") node: \nEnter letters: ";
          cin.getline(t1->letters,sizeof(t1->letters));cout<<"Enter znaki: ";
          cin.getline(t1->znaki,sizeof(t1->letters));
          t1->let_num=strlen(t1->letters);
          t1->znak_num=strlen(t1->znaki);
          // Зчитування значення для нового вузла від користувача:
        // Додаємо новий вузол в кінець списку:
        t2->next = t1;
    }
    
    // Повідомлення, що вузол створено:
    cout << "Node created!";
    }
    return head;      // Повертаємо оновлену голову списку.
}

// Функція List_Single_Node проходить через всі вузли списку і виводить дані, що зберігаються в кожному з них.
// Параметр head - вказівник на початок списку.
void List_Single_Node(Alphabet* head) {
    int num=i;
    if(i!=0){
        cout << "\nList of ("<<num<<") nodes:\n";
        while (head != nullptr) {
        cout<<'('<<num<<')'<<" Node:"<<endl <<"Letters: "<< head->letters <<"("<<head->let_num<<")"<<endl<<"Znaki: "<<head->znaki<<"("<<head->znak_num<<")"<<endl;
        num--;
        head = head->next;
        }
    }else cout << "\nList is empty\n";
    cout << "Press enter to continue:";
    system("read \n");
    (void)getchar();
}

void Delete_Last_Element(Alphabet* head){
    Alphabet* next_el=nullptr;
    while(head!=nullptr){
        cout << "\ndeleting node("<<i<<")";i--;
        next_el = head->next;
        delete(head);
        if(head->next!=nullptr)head=next_el;
    }
    head=nullptr;
    (void)getchar();
}
int Func3(Alphabet* head,int num){
    int count=0;
    if(i!=0){
        while (head != nullptr) {
        if(num==strlen(head->letters))count++;cout<<endl<<"NUM IS:"<<count<<endl<<"LETTERS IS:"<<head->letters<<endl<<"head is: "<<head <<"ANOTHER HEAD IS: "<< head->next; 
        cout<<'('<<num<<')'<<" Node:"<<endl <<"Letters: "<< head->letters <<"("<<head->let_num<<")"<<endl<<"Znaki: "<<head->znaki<<"("<<head->znak_num<<")"<<endl;
        head = head->next;
        }
    }else cout << "\nList is empty\n";
    cout << "Press enter to continue:";
    (void)getchar();
    return count;
}

Alphabet* Sort_List_1(Alphabet* head) {
    if (!head && !head->next) return head;
    bool swapped;
    do {
        swapped = false;
        Alphabet dummy;
        dummy.next = head;
        Alphabet* prev = &dummy;
        while (prev->next && prev->next->next) {
            Alphabet* first = prev->next;
            Alphabet* second = first->next;
            if (prev->next->let_num < prev->next->next->let_num) {
                first->next = second->next;
                second->next = first;
                prev->next = second;
                swapped = true;
            } else {
                prev = prev->next;
            }
        }
        head = dummy.next;
    } while (swapped);
    (void)getchar();
    return head;
}

Alphabet* Add_Node_After(Alphabet* head,int num){;
    Alphabet* t1=new Alphabet();
    cin.getline(t1->letters,sizeof(t1->letters));
    cin.getline(t1->znaki,sizeof(t1->letters));
    t1->let_num=strlen(t1->letters);
    t1->znak_num=strlen(t1->znaki);
    t1->next=nullptr;

    if(head==nullptr){
        head=t1;
        return head;//якщо список пустий то елемент стає головою
    }
    if(num==1){
        t1->next=head;//якщо елемент після якого вставляємо перший то він стає головою
        head=t1;//інакше вставляємо після елемента з номером num
        return head;
    }
    Alphabet* cur=head;
    for(int i=1;i<num&&cur->next!=nullptr;i++)
        cur=cur->next;
    if(cur->next==nullptr){
        t1->next=cur->next;
        cur->next=t1;
        return head;
    }
    system("read \n");
    return head;
}

Alphabet* Ret_Last_Head(Alphabet* head){
    int a=0;
    while(a!=1){
        head=head->next;
        a++;
    }
    return head;
}
Alphabet* Ret_Last_Real_Head(Alphabet* head){
    return head->next;
}
void Add_Nodess(Alphabet* head,int num) {
    for(;num!=0;num--){
    i++;
    Alphabet *t1, *t2;
    t1 = new Alphabet();       // Створення нового вузла у динамічній пам'яті.
    t1->next = nullptr;    // Ініціалізація поля next як nullptr, бо це новий вузол без наступника.
    cout << "\nCreating node...("<<i<<")\n";
        t2 = head;       // Починаємо з голови списку.
        while (t2->next != nullptr)
            t2 = t2->next;   // Перехід до наступного вузла, поки не знайдемо останній.
          cout<<"Enter value for ("<<i<<") node: \nEnter letters: ";
          cin.getline(t1->letters,sizeof(t1->letters));cout<<"Enter znaki: ";
          cin.getline(t1->znaki,sizeof(t1->letters));
          t1->let_num=strlen(t1->letters);
          t1->znak_num=strlen(t1->znaki);
          // Зчитування значення для нового вузла від користувача:
        // Додаємо новий вузол в кінець списку:
        t2->next = t1;    
    // Повідомлення, що вузол створено:
    cout << "Node created!";
    }      // Повертаємо оновлену голову списку.
}


int main () {
    Alphabet* head=nullptr;
    int choice=999,num=0;

    while(choice!=0){
        cout << "Enter your choice:"<<endl<<"1)Create List with (n) elements"<<endl<<"2)Print all nodes from list"<<endl<<"3)Function 3(1 arg) arg==strlen(entered)"<<endl<<"4)Sort structures"<<endl<<"5)Add new element after (n)"<<endl<<"6)Save to file"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter number of adding elements: ";
                cin>>num;
                (void)getchar();
                head = Add_Nodes(head,num);
                break;
            case 2:
                List_Single_Node(head);
                break;
            case 3:
                cin>>num;
                getchar();
                cout << "Number of elements with "<<num<<" characters: "<<Func3(head,num);
                break;
            case 4:
                cout << "Sorting started..."<<endl;
                head = Sort_List_1(head); // update head with the new head pointer
                break;
            case 5:
                cout<<"enter number of element to paste info after this el: ";
                cin>>num;
                (void)getchar();
                Add_Node_After(head,num);
                break;
            case 6:
                cout << "Deleting element";
                head = Ret_Last_Head(head);
                cout<< "Deleted first element";
                break;
            case 7:
                head = Ret_Last_Real_Head(head);
                break;
            case 8:
                cin>>num;
                Add_Nodess(head,num);
        }
    }
}

