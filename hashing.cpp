#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student {
private:
    int id;
    string name;
    // Provide accessors if necessary
public:
    friend class Hashing;
};

class Hashing {
private:
    int max;
    Student s;
public:
    Hashing(int maxSize) {
        max = maxSize;
        s.id = -1;
        s.name = "--";
    }

    void insert(int key, const string& name) {
        cout << "Inserting " << name << " at keyed " << key << endl;
        
        fstream file("data.txt", ios::in | ios::out | ios::binary);
        
        int loc = key % max;
        file.seekg(loc * sizeof(Student), ios::beg);
        
        file.read((char*)&s, sizeof(Student));
        
        if (s.id == -1) {
            
            s.id = key;
            cout << "Insertied " << name << " at keyed " << key << endl;
            s.name = name;
            cout << "Insertied " << name << " at keyed " << key << endl;
            file.seekp(loc * sizeof(Student), ios::beg);
            file.write(reinterpret_cast<char*>(&s), sizeof(Student));
            cout << "Inserted " << name << " at key " << key << endl;
        } else {
            cout << "Collision detected at key " << key << endl;
        }

        file.close();
    }
};

int main() {
    int maxSize;
    cout << "Enter max size of file: ";
    cin >> maxSize;

    // Initialize Hashing object with given size
    Hashing h(maxSize);

    for (int i = 0; i < 5; ++i) {
        string name;
        cout << "Enter name: ";
        cin >> name;
        cout << name;
        h.insert(i + 1, name);
    }

    return 0;
}