#include <iostream>
#include <iomanip>

using namespace std;
const int SIZE = 3;

class Chair {
private:
    int legs;
    double * prices;
public:
    // constructors
    Chair() {
        const int MIN = 10000, MAX = 99999;
        legs = (rand()%2+3);
        for (int i = 0; i < SIZE; i++)
            prices[i] = (rand() % (MAX-MIN+1) + MIN) / (double) 100;
    }
    // setters and getters
    int getLegs(){ return legs; }
    
    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: " ;
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }
};

int main() {
    cout << fixed << setprecision(2);

    //creating pointer to first chair object
    Chair *chairPtr = new Chair;
    chairPtr->print();

    //creating dynamic chair object with constructor
    Chair *livingChair = new Chair(3);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    //creating dynamic array of chair objects
    Chair *collection = new Chair[SIZE];
   
    for (int i = 0; i < SIZE; i++)
        collection[i].print();
    
    return 0;
}