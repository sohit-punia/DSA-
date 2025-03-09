#include<iostream>
using namespace std;


// 2. Introduction to Objects and OOP 
class Car {  // Class (Blueprint)
    public:
        string brand;
        int speed;
    
        void show() {
            cout << "Brand: " << brand << ", Speed: " << speed << endl;
        }
    };
    int main() {
        Car c1;  // Creating an object
        c1.brand = "Toyota";
        c1.speed = 120;
        c1.show();  // Output: Brand: Toyota, Speed: 120
    }
    

    // 3. Encapsulation (Data Hiding)
    //Encapsulation means hiding data inside a class and controlling access 🔹 We use private and public access specifiers.
    class Student {
        private:
            int rollNumber;  // Private variable (cannot be accessed directly)
        public:
            void setRoll(int r) { rollNumber = r; }  // Public method to set value
            int getRoll() { return rollNumber; }     // Public method to get value
        };
        int main() {
            Student s;
            s.setRoll(101);
            cout << s.getRoll();  // Output: 101
        }
// The variable rollNumber cannot be accessed directly, only through functions.

// 4. Polymorphism (Many Forms)
/*
Polymorphism means one thing behaves in multiple ways.
There are two types:

  1:- Compile-time Polymorphism (Method Overloading & Operator Overloading)
  2:- Run-time Polymorphism (Method Overriding)
*/

//✅ Example of Function Overloading:-
class Math {
    public:
        int add(int a, int b) { return a + b; } // Adding two integers
        double add(double a, double b) { return a + b; } // Adding two decimals
    };
    int main() {
        Math obj;
        cout << obj.add(5, 10);  // Output: 15
        cout << obj.add(2.5, 3.5);  // Output: 6.0
    }

    //✅ Example of Overriding (Run-time Polymorphism):

    class Parent {
        public:
            virtual void show() { cout << "Parent class" << endl; }
        };
        class Child : public Parent {
        public:
            void show() { cout << "Child class" << endl; }  // Overriding method
        };
        int main() {
            Parent* p;
            Child c;
            p = &c;
            p->show();  // Output: Child class
        }
      