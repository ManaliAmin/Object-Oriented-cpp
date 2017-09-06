#include "Car.h"

namespace sict
{
	void Car::speed(int value)
	{
		if (value > maxSpeed_)
			value = maxSpeed_;
		if (value < 0)
			value = 0;
		speed_ = value;

	}
	int Car::maxSpeed() const
	{
		return maxSpeed_;
	}

	int Car::speed() const
	{
		return speed_;
	}
	Car::Car(int maxSpeed)
	{
		maxSpeed_ = maxSpeed;
		speed_ = 0;
	}
	void Car::accelerate()
	{
		accelerate();
	}
	void Car::brake()
	{
		brake();
	}
	std::ostream & Car::display(std::ostream & cout) const
	{
		display(cout);
		return cout;
	}
	std::ostream & operator<<(std::ostream & cout, const Car & P)
	{
		P.display(cout);
		return cout;
	}
}