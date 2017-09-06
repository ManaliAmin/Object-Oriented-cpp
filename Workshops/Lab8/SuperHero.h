#pragma once
#ifndef _SUPERHERO_H
#define SUPERHERO_H
#include "Hero.h"

class SuperHero :public Hero
{
	char name[21];
	double strength;
	double multStr;
public:
	SuperHero();
	SuperHero(const SuperHero& s1);
	SuperHero(const char name[], double str, double mult);
	double getStrength()const;
	void operator*=(SuperHero&);
	void display(std::ostream&)const;
	~SuperHero();
};
#endif

