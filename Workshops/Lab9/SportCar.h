#ifndef SICT_SPORTCAR_H_
#define SICT_SPORTCAR_H_
#include"Car.h"
namespace sict
{
	// complete the declaration of the class
	class SportCar :public Car
	{
	private:
		// private members go here
		int noOfPassengers_;

	public:
		// public members go here
		SportCar();
		SportCar(int maxSpeed, int nop);

		void accelerate();
		void brake();
		// pure virtual members from base class go here
		std::ostream& display(std::ostream& ostr) const;
	};
}
#endif