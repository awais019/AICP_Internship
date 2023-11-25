#include <iostream>
#include <cmath>
using namespace std;

class Hexagon
{
private:
    int sideLength;

public:
    Hexagon()
    {
        sideLength = 7;
    }
    double calcArea()
    {
        return (3 * sqrt(3) * sideLength * sideLength) / 2;
    }
    int calcPerimeter()
    {
        return 6 * sideLength;
    }
    int calcAngleSum()
    {
        return 120 * 6;
    }
    void display()
    {
        cout << "Area of hexagon is: " << calcArea() << endl;
        cout << "Perimeter of hexagon is: " << calcPerimeter() << endl;
        cout << "Sum of angles of hexagon is: " << calcAngleSum() << endl;
    }
};

class Square
{
private:
    int sideLength;

public:
    Square()
    {
        sideLength = 7;
    }
    double calcArea()
    {
        return sideLength * sideLength;
    }
    int calcPerimeter()
    {
        return 4 * sideLength;
    }
    void display()
    {
        cout << "Area of square is: " << calcArea() << endl;
        cout << "Perimeter of square is: " << calcPerimeter() << endl;
    }
};

void displayMenu()
{
    cout << "Enter 1 to calculate area, perimeter and sum of angles of hexagon" << endl;
    cout << "Enter 2 to calculate area and perimeter of square" << endl;
    cout << "Press any other key to exit" << endl;
}

int main()
{
    Hexagon hexagon;
    Square square;
    do
    {
        int choice;
        displayMenu();
        cin >> choice;
        if (choice == 1)
        {
            hexagon.display();
        }
        else if (choice == 2)
        {
            square.display();
        }
        else
        {
            break;
        }
    } while (true);
}