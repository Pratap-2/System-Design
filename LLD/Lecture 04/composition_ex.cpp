#include <iostream>
using namespace std;

class Engine {
public:
    Engine() {
        cout << "Engine created\n";
    }

    void start() {
        cout << "Engine started\n";
    }

    ~Engine() {
        cout << "Engine destroyed\n";
    }
};

class Car {
private:
    Engine engine;   // Composition: object inside object

public:
    Car() {
        cout << "Car created\n";
    }

    void drive() {
        engine.start();
        cout << "Car is moving\n";
    }

    ~Car() {
        cout << "Car destroyed\n";
    }
};

int main() {
    Car car;
    car.drive();
    return 0;
}

/*
6️⃣ Composition Using Dynamic Allocation (Advanced)
Sometimes composition uses unique ownership
*/

#include <memory>

class Engine {
public:
    void start() {
        cout << "Engine started\n";
    }
};

class Car {
private:
    unique_ptr<Engine> engine; // exclusive ownership

public:
    Car() {
        engine = make_unique<Engine>();
    }

    void drive() {
        engine->start();
        cout << "Car moving\n";
    }
};

int main() {
    Car car;
    car.drive();
    return 0;
}


/*📌 This is still composition because:
Car owns Engine
No one else can share it
Engine dies with Car

7️⃣ When to Use Composition in LLD?

Use Composition when:
✔ Object is mandatory
✔ Object is not reusable independently
✔ Strong ownership is required
✔ Clear lifecycle dependency exists

Common Interview Examples

House → Room
Library → BookCopy
Order → OrderItem
Human → Heart

8️⃣ Interview Questions & Answers

❓ Q1: Is composition better than inheritance?
✅ Answer:
Composition is preferred when behavior can change dynamically and we want to avoid tight coupling caused by inheritance.

❓ Q2: How do you identify composition in requirements?
✅ Answer:
If an object cannot logically exist without its parent and parent controls its lifecycle, it is composition.

❓ Q3: Can composition exist with pointers?
✅ Answer:
Yes, if ownership is clearly defined (e.g., unique_ptr), it is still composition.

9️⃣ One-Line Summary (MEMORIZE)
Composition = strong has-a + ownership + lifecycle dependency

*/
