#ifndef SICT_DRIVER_H_
#define SICT_DRIVER_H_
#include"Car.h"

namespace sict
{
	class Driver :public Car
	{
	private:
		char name_[31];
		Car& car_;
	public:
		Driver(const char* name, Car& theCar);
		void drive();
		void stop();
		void showStatus();
	};
}
#endif