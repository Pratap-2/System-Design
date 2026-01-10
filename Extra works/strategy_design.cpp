#include <bits/stdc++.h>
using namespace std;

/* ---------- Strategy Interfaces ---------- */

class FlyBehavior {
public:
    virtual void fly() = 0;
    virtual ~FlyBehavior() {}
};

class QuackBehavior {
public:
    virtual void quack() = 0;
    virtual ~QuackBehavior() {}
};

/* ---------- Concrete Fly Strategies ---------- */

class FlyWithWings : public FlyBehavior {
public:
    void fly() override {
        cout << "Flying with wings\n";
    }
};

class FlyNoWay : public FlyBehavior {
public:
    void fly() override {
        cout << "I can't fly\n";
    }
};

class FlyWithRocket : public FlyBehavior {
public:
    void fly() override {
        cout << "Flying with rocket power 🚀\n";
    }
};

/* ---------- Concrete Quack Strategies ---------- */

class NormalQuack : public QuackBehavior {
public:
    void quack() override {
        cout << "Quack!\n";
    }
};

class Squeak : public QuackBehavior {
public:
    void quack() override {
        cout << "Squeak!\n";
    }
};

class MuteQuack : public QuackBehavior {
public:
    void quack() override {
        cout << "<< Silence >>\n";
    }
};

/* ---------- Duck Base Class (Context) ---------- */

class Duck {
protected:
    FlyBehavior* flyBehavior;
    QuackBehavior* quackBehavior;

public:
    Duck(FlyBehavior* fb, QuackBehavior* qb)
        : flyBehavior(fb), quackBehavior(qb) {}

    virtual void display() = 0;

    void performFly() {
        flyBehavior->fly();
    }

    void performQuack() {
        quackBehavior->quack();
    }

    void setFlyBehavior(FlyBehavior* fb) {
        flyBehavior = fb;
    }

    void setQuackBehavior(QuackBehavior* qb) {
        quackBehavior = qb;
    }

    void swim() {
        cout << "All ducks can swim\n";
    }

    virtual ~Duck() {
        cout<<"Destructor called :)"<<endl;
    }
};

/* ---------- Concrete Ducks ---------- */

class MallardDuck : public Duck {
public:
    MallardDuck()
        : Duck(new FlyWithWings(), new NormalQuack()) {}

    void display() override {
        cout << "I am a Mallard Duck\n";
    }
};

class RubberDuck : public Duck {
public:
    RubberDuck()
        : Duck(new FlyNoWay(), new Squeak()) {}

    void display() override {
        cout << "I am a Rubber Duck\n";
    }
};

class DecoyDuck : public Duck {
public:
    DecoyDuck()
        : Duck(new FlyNoWay(), new MuteQuack()) {}

    void display() override {
        cout << "I am a Decoy Duck\n";
    }
};

/* ---------- Main ---------- */

int main() {

    Duck* mallard = new MallardDuck();
    mallard->display();
    mallard->performFly();
    mallard->performQuack();

    cout << "---- Power upgrade ----\n";

    mallard->setFlyBehavior(new FlyWithRocket());
    mallard->performFly();

    cout << "\n";

    Duck* rubber = new RubberDuck();
    rubber->display();
    rubber->performFly();
    rubber->performQuack();

    delete mallard;
    delete rubber;
}
