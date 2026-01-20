#include<bits/stdc++.h>
using namespace std;

//simple association example
class Student {
public:
    void attendClass() {
        cout << "Student attending class\n";
    }
};

class Teacher {
public:
    void teach(Student& s) {   // uses Student
        cout << "Teacher teaching\n";
        s.attendClass();
    }
};



// aggregation example 
class Player {
public:
    string name;
    Player(string name) : name(name) {}
};

class Team {
private:
    vector<Player*> players;   // weak ownership

public:
    void addPlayer(Player* p) {
        players.push_back(p);
    }
};

/*
🧠 Key Points
✔ Team does NOT create Player
✔ Player can belong to multiple teams
✔ Team does NOT delete Player
*/

//composition

class A {
public:
    void method1() {
        cout << "Method1 of class A called" << endl;
    }
};

class B {
private:
    A* a;   // B has a  A (composition)

public:
    B() {
        a = new A();   // B creates A → ownership
    }

    void method2() {
        cout << "Method2 of class B called" << endl;
    }

    // exposing A's functionality via B
    A* getA() {
        return a;
    }

    ~B() {
        delete a;     // lifecycle managed by B
    }
};

int main() {
    B* b = new B();

    b->method2();            // b -> method2()
    b->getA()->method1();    // b -> a -> method1()

    delete b;
    return 0;
}
