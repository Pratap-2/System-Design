#include <bits/stdc++.h>
using namespace std;

/* ---------- Interfaces ---------- */

class Flyable {
public:
    virtual void fly() = 0;
    virtual ~Flyable() {}
};

class Quackable {
public:
    virtual void quack() = 0;
    virtual ~Quackable() {}
};

/* ---------- Base Duck ---------- */

class Duck {
public:
    virtual void display() = 0;

    void swim() {
        cout << "All ducks can swim\n";
    }

    virtual ~Duck() {}
};

/* ---------- Concrete Ducks ---------- */

class MallardDuck : public Duck, public Flyable, public Quackable {
public:
    void display() override {
        cout << "I am a Mallard Duck\n";
    }

    void fly() override {
        cout << "Mallard flying\n";
    }

    void quack() override {
        cout << "Mallard quacking\n";
    }
};

class RedheadDuck : public Duck, public Flyable, public Quackable {
public:
    void display() override {
        cout << "I am a Redhead Duck\n";
    }

    void fly() override {
        cout << "Redhead flying\n";
    }

    void quack() override {
        cout << "Redhead quacking\n";
    }
};

class RubberDuck : public Duck, public Quackable {
public:
    void display() override {
        cout << "I am a Rubber Duck\n";
    }

    void quack() override {
        cout << "Squeak!\n";
    }
};

class DecoyDuck : public Duck {
public:
    void display() override {
        cout << "I am a Decoy Duck\n";
    }
};

/*(Interfaces solve who can do what, but not how it’s done.
 When behavior varies and evolves, interfaces alone cause duplication and rigidity.)*/

/* ---------- Main ---------- */

int main() {

    vector<Duck*> ducks = {
        new MallardDuck(),
        new RedheadDuck(),
        new RubberDuck(),
        new DecoyDuck()
    };

    for (Duck* d : ducks) {
        d->display();
        d->swim();

        // check if duck can fly
        Flyable* f = dynamic_cast<Flyable*>(d);
        if (f) {
            f->fly();
        }

        // check if duck can quack
        Quackable* q = dynamic_cast<Quackable*>(d);
        if (q) {
            q->quack();
        }

        cout << "-------------------\n";
    }

    for (Duck* d : ducks) delete d;
}
/* (✅ Why dynamic_cast is safe

✔ Checks object type at runtime
✔ Works only with polymorphic classes (virtual functions)
✔ Returns nullptr if cast is invalid

🧠 Mental Model (exam-friendly)

dynamic_cast asks the object:
“Do you really support this interface?”)
*/

