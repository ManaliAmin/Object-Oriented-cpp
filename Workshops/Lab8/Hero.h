#ifndef _HERO_H
#define HERO_H
#include<iostream>
class Hero{
	char name_[21];
	double strength;
public:
	Hero();
	Hero(char* name, double str);
	bool isEmpty()const;
	double getStrength()const;
	void display(std::ostream&)const;
	void operator-=(double str);
	void operator+=(double str);
};
bool operator<(const Hero&, const Hero&);
#endif