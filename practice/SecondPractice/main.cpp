#include <iostream>
using namespace std;

class train{
    char pos1[20];
    int num;
    char time[10];
    public:
    train(){
        cout << "Enter the position of the train: ";
        cin >> pos1;
        cout << "Enter the number of the train: ";
        cin >> num;
        cout << "Enter the time of the train: ";
        cin >> time;
    }
    void print(){
        cout << "Train number: " << num << endl;
        cout << "Train position: " << pos1 << endl;
        cout << "Train time: " << time << endl;
    }
    void change(){
        cout << "Enter the new position of the train: ";
        cin >> pos1;
        cout << "Enter the new number of the train: ";
        cin >> num;
        cout << "Enter the new time of the train: ";
        cin >> time;
    }
};
int main(){
    train t1;
    t1.print();
    t1.change();
    t1.print();
}