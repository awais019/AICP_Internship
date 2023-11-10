#include <iostream>
#include <vector>

using namespace std;

struct Item
{
    string code;
    string description;
    double price;

    Item() {}

    Item(string code, string description, double price)
    {
        this->code = code;
        this->description = description;
        this->price = price;
    }
};

struct Category
{
    string name;
    vector<Item> items;

    Category(string name, vector<Item> items)
    {
        this->name = name;
        this->items = items;
    }
};

vector<Category> categories = {
    Category("Case", {
                         Item("A1", "Compact", 75.00),
                         Item("A2", "Tower", 150.00),
                     }),
    Category("RAM", {
                        Item("B1", "8 GB", 79.99),
                        Item("B2", "16 GB", 149.99),
                        Item("B3", "32 GB", 299.99),
                    }),
    Category("Main Hard Disk Drive", {
                                         Item("C1", "1 TB HDD", 49.99),
                                         Item("C2", "2 TB HDD", 89.99),
                                         Item("C3", "4 TB HDD", 129.99),
                                     }),
    Category("Solid State Drive", {
                                      Item("D1", "240 GB SSD", 59.99),
                                      Item("D2", "480 GB SSD", 119.99),
                                  }),
    Category("Optical Drive", {
                                  Item("F1", "DVD/Blu-Ray Player", 50.0),
                                  Item("F2", "DVD/Blu-Ray Re-writer", 100.0),
                              }),
    Category("Operating System", {
                                     Item("G1", "Standard Vision", 100.0),
                                     Item("G2", "Professional Vision", 175.0),
                                 })

};

void display()
{
    cout << "Category \t\t\t"
         << "Code \t"
         << "Description \t"
         << "Price \t" << endl;

    for (int i = 0; i < categories.size(); i++)
    {
        cout << categories[i].name;
        for (int j = 0; j < categories[i].items.size(); j++)
        {
            cout << "\t\t\t\t" << categories[i].items[j].code << "\t" << categories[i].items[j].description << "\t\t" << categories[i].items[j].price << endl;
        }
    }
}

bool isValidCode(string categoryName, string code)
{
    for (int i = 0; i < categories.size(); i++)
    {
        if (categories[i].name == categoryName)
        {
            for (int j = 0; j < categories[i].items.size(); j++)
            {
                if (categories[i].items[j].code == code)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

Item findItem(string code)
{
    for (int i = 0; i < categories.size(); i++)
    {
        for (int j = 0; j < categories[i].items.size(); j++)
        {
            if (categories[i].items[j].code == code)
            {
                return categories[i].items[j];
            }
        }
    }
    return Item();
}

int main()
{
    display();

    double basicPrice = 200.0;

    string caseCode;
    string ramCode;
    string mainHDDCode;

    Item selectedCase;
    Item selectedRAM;
    Item selectedMainHDD;

    while (true)
    {
        cout << "Enter code for case: ";
        cin >> caseCode;

        if (!isValidCode("Case", caseCode))
        {
            cout << "Invalid code for case. Please try again." << endl;
            continue;
        }
        else
        {
            selectedCase = findItem(caseCode);
            break;
        }
    };

    while (true)
    {
        cout << "Enter code for RAM: ";
        cin >> ramCode;

        if (!isValidCode("RAM", ramCode))
        {
            cout << "Invalid code for RAM. Please try again." << endl;
            continue;
        }
        else
        {
            selectedRAM = findItem(ramCode);
            break;
        }
    }

    while (true)
    {
        cout << "Enter code for main hard disk drive: ";
        cin >> mainHDDCode;

        if (!isValidCode("Main Hard Disk Drive", mainHDDCode))
        {
            cout << "Invalid code for main hard disk drive. Please try again." << endl;
            continue;
        }
        else
        {
            selectedMainHDD = findItem(mainHDDCode);
            break;
        }
    }

    double totalPrice = basicPrice + selectedCase.price + selectedRAM.price + selectedMainHDD.price;

    cout << "Choosen items: " << endl;
    cout << "Case: " << selectedCase.description << endl;
    cout << "RAM: " << selectedRAM.description << endl;
    cout << "Main Hard Disk Drive: " << selectedMainHDD.description << endl;
    cout << "Total price: $" << totalPrice << endl;

    char moreItems;
    vector<Item> additionalItems;
    cout << "Do you want to add additional items? (y/n): ";
    cin >> moreItems;

    while (moreItems == 'y')
    {
        string categoryName;
        string code;

        cout << "Enter category name: ";
        cin.ignore();
        getline(cin, categoryName);

        cout << "Enter code: ";
        cin >> code;

        if (!isValidCode(categoryName, code))
        {
            cout << "Invalid code. Please try again." << endl;
            continue;
        }
        else
        {
            Item item = findItem(code);
            additionalItems.push_back(item);
        }

        cout << "Do you want to add additional items? (y/n): ";
        cin >> moreItems;
    }

    double additionalItemsPrice = 0.0;

    for (int i = 0; i < additionalItems.size(); i++)
    {
        additionalItemsPrice += additionalItems[i].price;
    }

    totalPrice += additionalItemsPrice;

    cout << "Additional items: " << endl;
    for (int i = 0; i < additionalItems.size(); i++)
    {
        cout << additionalItems[i].description << endl;
    }

    cout << "Total price: $" << totalPrice << endl;

    double savedMoney = 0.0;

    if (additionalItems.size() == 1)
    {
        savedMoney = totalPrice * 0.05;
        totalPrice -= savedMoney;
    }
    else if (additionalItems.size() >= 2)
    {
        savedMoney = totalPrice * 0.1;
        totalPrice -= savedMoney;
    }

    cout << "You saved $" << savedMoney << endl;
    cout << "Total price after discount: $" << totalPrice << endl;

    return 0;
}