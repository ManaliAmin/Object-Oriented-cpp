#include <iostream>
#include "SportCar.h"
#include "PickupTruck.h"
#include "Driver.h"

using namespace std;
using namespace sict;

int main()
{
	SportCar tesla(240, 2);
	PickupTruck ford;
	Driver john("John", tesla);
	Driver kim("Kim", ford);
	cout << tesla << endl;
	cout << ford << endl;

	ford.load("Bricks", 3500);
	john.drive();
	kim.drive();
	john.stop();
	kim.stop();
	cout << tesla << endl;
	cout << ford << endl;

	return 0;
}