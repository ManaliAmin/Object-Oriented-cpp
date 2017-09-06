#include<iostream>
#include "SuperHero.h"
using namespace std;

SuperHero::SuperHero()
{
	name[0] = '\0';
	strength = 0;
	multStr = 0;

}
SuperHero::SuperHero(const SuperHero& s1){
	strncpy(name, s1.name,20);
	strength = s1.strength;
	multStr = s1.multStr;
}
SuperHero::SuperHero(const char name_[], double str, double mult){
	if (name[0] != '\0' && str >= 0 && mult >= 0){
		strcpy(name, name_);
		strength = str;
		multStr = mult;

	}
	else{
		name[0] = '\0';
		strength = 0;
		multStr = 0;
	}
}
double SuperHero:: getStrength()const{
	double newStr;
	newStr = strength*multStr;
	return newStr;
}
void SuperHero::operator*=(SuperHero& B){
	if (strength < B.strength){
		B.strength += strength;
		strength = 0;
	}
	else{
		strength += B.strength;
		B.strength = 0.0;
	}

}
void SuperHero:: display(std::ostream&)const{
	if (name[0] != '\0'&& strength != 0 && multStr != 0)
		cout << "living superhero! " << name << " - " << strength << endl;
	else
		cout << "deceased superhero!" << endl;

}

SuperHero::~SuperHero()
{
}
