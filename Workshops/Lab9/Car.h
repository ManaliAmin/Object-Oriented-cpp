#ifndef SICT_CAR_H_
#define SICT_CAR_H_
#include"Vehicle.h"
namespace sict
{
	// complete the declaration of the class
	class Car :public Vehicle
	{
	private:
		// private members go here
		int speed_;
		int maxSpeed_;
	protected:
		// protected members go here
		void speed(int value);
		int maxSpeed() const;
	public:
		// public members go here
		int speed() const;
		Car(int maxSpeed = 100);
		virtual void accelerate();
		virtual void brake();
		virtual std::ostream& display(std::ostream&) const;

	};
	std::ostream& operator<<(std::ostream &, const Car &);

}

#endif