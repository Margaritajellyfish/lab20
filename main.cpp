#include <iostream>
#include <iomanip>
#include<ctime>

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
        srand(time(0) + rand());
        legs = (rand()%2+3);
        prices = new double[SIZE];
        for (int i = 0; i < SIZE; i++)
            prices[i] = (rand() % (MAX-MIN+1) + MIN) / (double) 100;
    }
    Chair(int l, double p[SIZE]) {
        legs = l;
        prices = new double[SIZE];
        for (int i = 0; i < SIZE; i++) {
            prices[i] = p[i];
        }
    }
    ~Chair() {
        delete[] prices;
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
    double livingPrices[SIZE] = { 525.25, 434.34, 252.52 };
    Chair* livingChair = new Chair(3, livingPrices);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    //creating dynamic array of chair objects
    Chair *collection = new Chair[SIZE];
   
    for (int i = 0; i < SIZE; i++)
        collection[i].print();
    
    delete[] collection;
    collection = nullptr;
    return 0;
}