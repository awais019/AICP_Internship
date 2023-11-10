#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum Direction
{
    UP,
    DOWN
};

class Train
{
public:
    int noOfCoaches;
    string time;
    Direction direction;
    int seatsPerCoach;
    int ticketsBooked;
    int totalPassengers = 0;
    int totalMoney = 0;

    Train(int noOfCoaches, string time, Direction direction)
        : noOfCoaches(noOfCoaches), time(time), direction(direction), seatsPerCoach(80), ticketsBooked(0) {}

    int availableSeats() const
    {
        return noOfCoaches * seatsPerCoach - ticketsBooked;
    }
};

vector<Train> trains = {
    Train(6, "09:00", UP),
    Train(6, "10:00", DOWN),
    Train(6, "11:00", UP),
    Train(6, "12:00", DOWN),
    Train(6, "13:00", UP),
    Train(6, "14:00", DOWN),
    Train(6, "15:00", UP),
    Train(8, "16:00", DOWN),
};

void display()
{
    for (const auto &train : trains)
    {
        // closed should be displayed as "CLOSED" if the train is full
        if (train.availableSeats() == 0)
        {
            cout << "Train " << &train - &trains[0] << ": " << train.time << " " << (train.direction == UP ? "UP" : "DOWN") << " CLOSED" << endl;
            continue;
        }
        cout << "Train " << &train - &trains[0] << ": " << train.time << " " << (train.direction == UP ? "UP" : "DOWN") << " " << train.availableSeats() << endl;
    }
}

void purchaseTickets(int trainIndex, int passengers, int returnTrainIndex)
{
    if (trains[trainIndex].availableSeats() < passengers || trains[returnTrainIndex].availableSeats() < passengers)
    {
        cout << "Not enough seats available." << endl;
        return;
    }

    int pricePerTicket = 50;
    int total = pricePerTicket * passengers;

    if (passengers >= 10)
    {
        total -= (passengers / 10) * pricePerTicket;
    }

    trains[trainIndex].totalPassengers += passengers;
    trains[trainIndex].totalMoney += total / 2;
    trains[returnTrainIndex].totalPassengers += passengers;
    trains[returnTrainIndex].totalMoney += total / 2;

    trains[trainIndex].ticketsBooked += passengers;
    trains[returnTrainIndex].ticketsBooked += passengers;

    cout << "Total price: $" << total << endl;
    display();
}

void displayTotals()
{
    int totalPassengers = 0;
    int totalMoney = 0;
    int maxPassengers = 0;
    int maxPassengersTrainIndex = 0;

    for (int i = 0; i < trains.size(); i++)
    {
        const auto &train = trains[i];
        cout << "Train " << i << ": " << train.totalPassengers << " passengers, $" << train.totalMoney << endl;
        totalPassengers += train.totalPassengers;
        totalMoney += train.totalMoney;
        if (train.totalPassengers > maxPassengers)
        {
            maxPassengers = train.totalPassengers;
            maxPassengersTrainIndex = i;
        }
    }

    cout << "Total passengers: " << totalPassengers << endl;
    cout << "Total money: $" << totalMoney << endl;
    cout << "Train with most passengers: " << maxPassengersTrainIndex << endl;
}

int main()
{
    display();

    char purchaseMore = 'y';
    while (purchaseMore == 'y' || purchaseMore == 'Y')
    {
        int trainIndex, passengers, returnTrainIndex;
        cout << "Enter train index: ";
        cin >> trainIndex;
        cout << "Enter number of passengers: ";
        cin >> passengers;
        cout << "Enter return train index: ";
        cin >> returnTrainIndex;

        purchaseTickets(trainIndex, passengers, returnTrainIndex);

        cout << "Purchase more tickets? (y/n): ";
        cin >> purchaseMore;
    }

    displayTotals();
    return 0;
}