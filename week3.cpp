#include <iostream>

using namespace std;

int slabs[3][3] = {{55, 65, 75}, {120, 150, 170}, {210, 230, 240}};

int main()
{
    cout << "My student ID is XY12345678" << endl;
    int choice;
    while (true)
    {
        cout << "Enter your choice" << endl;
        cout << "Press 1 to display bill of slab 1 and slab 2." << endl;
        cout << "Press 2 to display bill of slab 3." << endl;
        cout << "Press any other key to exit." << endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Bill for slab 1 is" << endl;
            for (int i = 0; i < 3; i++)
            {
                cout << slabs[0][i] * 10 << "\t";
            }
            cout << endl
                 << "Bill for slab 2 is" << endl;
            for (int i = 0; i < 3; i++)
            {
                cout << slabs[1][i] * 15 << "\t";
            }
            cout << endl;
        }
        else if (choice == 2)
        {
            cout << "Bill for slab 3 is" << endl;
            for (int i = 0; i < 3; i++)
            {
                cout << slabs[2][i] * 20 << "\t";
            }
            cout << endl;
        }
        else
        {
            break;
        }
    }

    return 0;
}