#include "Hero.h"
#include<iostream>
using namespace std;
Hero::Hero(){
	name_[21] = '\0';
	strength = 0;
}
Hero::Hero(char name[], double str){
	strcpy(name_, name);
	if (str > 0)
		strength = str;
	else
		str = 0.0;
}
bool Hero::isEmpty()const{
	if (name_[0] == '\0' && strength == 0){
		return true;
	}
	else
		return false;
}
double Hero::getStrength()const{
	if (!(strength == 0)){
		return strength;
	}
	else
		return 0.0;
}
void Hero::display(std::ostream&os)const{
	if (!(isEmpty()))
		os << name_ << " - " << strength << endl;

}
void Hero:: operator-=(double str){
	if (str < strength){

		strength -= str;
	}
	else{
		strength = 0.0;
	}
}
void Hero:: operator+=(double str){
	strength += str;
}
bool operator<(const Hero& str1, const Hero& str2){
	bool comp;
	comp = (str1.getStrength() < str2.getStrength());
	return comp;

}



