#ifndef SICT_VALIDATE_H_
#define SICT_VALIDATE_H_
#include <cstring>

namespace sict{
	template <typename T1>
	bool validate(T1 min, T1 max, T1* testValue, int element, bool* result){
		int i;
		int count = 0;
		for (i = 0; i < element; i++){
			result[i] = (testValue[i] >= min && max >= testValue[i]);
			if (result[i]){
				count++;
			}
		}
		return count == element;
	}
	template <>
	bool validate<char>(char min, char max, char* testValue, int element, bool* result){
		int i;
		int count = 0;
		for (i = 0; i < element; i++){
			result[i] = (toupper(testValue[i]) >= min && max >= toupper(testValue[i]));
			if (result[i]){
				count++;
			}
		}
		return count == element;
	}
	template <>
	bool validate<Car>(Car min, Car max, Car* testValue, int element, bool* result){
		int i;
		int count = 0;
		for (i = 0; i < element; i++){
			result[i] = (testValue[i] >= min) && (testValue[i] <= max) && strlen((const char*)testValue[i]) == 6;
			if (result[i]){
				count++;
			}
		}
		return count == element;
		return true;
	}
}
#endif