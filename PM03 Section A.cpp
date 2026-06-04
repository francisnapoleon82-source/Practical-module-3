#include <iostream>
#include <string>
using namespace std;

// PA0101, PA0102: Create a class with properties
class Shape {
protected:
    double width, height;
public:
    // PA0105, PA0112: Constructor to initialize
    Shape(double w, double h) : width(w), height(h) {}

    // PA0103: Set values
    void setDimensions(double w, double h) {
        width = w;
        height = h;
    }

    // Virtual function for PA0108: Overriding
    virtual double area() {
        return 0;
    }
};

// PA0101: Parent class
class Rectangle : public Shape {
public:
    Rectangle(double w, double h) : Shape(w, h) {}

    // PA0107: Calculate area
    double area() override {
        return width * height;
    }
};

// PA0101: Child class with unique property
class Book {
private:
    string title;
    string author;
    int pages;
    int speed; // PA0111: State variable
public:
    // PA0105: Constructor
    Book(string t, string a, int p, int s=0) : title(t), author(a), pages(p), speed(s) {}

    void display() {
        cout << "Book: " << title << " by " << author << ", Pages: " << pages << ", Speed: " << speed << endl;
    }
};

int main() {
    // PA0109: Create C++ class and objects
    Rectangle rect(10, 5);
    cout << "Rectangle area: " << rect.area() << endl;

    // PA0110: Book class and three instances
    Book b1("C++ Basics", "Kagiso", 200);
    Book b2("OOP Concepts", "Smith", 300, 20);
    Book b3("Advanced C++", "Lee", 400);

    b1.display();
    b2.display();
    b3.display();

    // PA0104: Reuse class
    rect.setDimensions(7, 3);
    cout << "Reused Rectangle area: " << rect.area() << endl;

    // PA0106: 'with' keyword equivalent in C++ is direct object reference
    // (C++ does not have 'with'; instead, we use object.method or object.property)
    cout << "Accessing rect area directly: " << rect.area() << endl;

    return 0;
}
