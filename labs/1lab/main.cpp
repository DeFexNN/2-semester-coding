#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct stek{
  char mark[20];
  char color[20];
  stek* next;
};

stek* top = nullptr;

void add(int l) {
  while (l != 0) {
    stek* temp = new stek;
    cin.ignore(100, '\n');
    cout << "\nenter mark: ";
    cin.getline(temp->mark, sizeof(temp->mark));
    cout << "\nenter color: ";
    cin.getline(temp->color, sizeof(temp->color));
    temp->next = top;
    top = temp;
    l--;
  }
}

void print() {
  stek* temp = top;
  int a = 1;
  while (temp != nullptr) {
    cout << endl << a << ": " << temp->mark << '\t' << temp->color << endl;
    temp = temp->next;
    a++;
  }
}

void PrintToFile(stek *head) {
    ofstream file("test.txt", ios::binary);    
    stek* cur = top;
    while (cur != nullptr) {
        file.write((char*)cur, sizeof(stek));
        cur = cur->next;
    }
    file.close();
}

void ReadFromFile() {
    stek temp;
    ifstream file("test.txt", ios::binary);
    while (top != nullptr) {
        stek* temp_ptr = top;
        top = top->next;
        delete temp_ptr;
    }
    while (file.read((char*)&temp, sizeof(stek))) {
        stek* new_node = new stek;
        strcpy(new_node->mark, temp.mark);
        strcpy(new_node->color, temp.color);
        new_node->next = top;
        top = new_node;
    }
    
    file.close();
}

int main() {
  int x = 0, l = 0;
  do {
    cout << "\n 1 - add, 3 - print 2 - PrintToFile 4 - ReadFromFile\n your choise: ";
    cin >> x;
    switch (x) {
    case 1:
      cout << "\nenter a num of element:";
      cin >> l;
      add(l);
      break;
      case 2:
    PrintToFile(top);
    break;
      case 3:
    print();
    break;
      case 4:
    ReadFromFile();
    break;
    }
  } while (x != 0);
  return 0;
}

