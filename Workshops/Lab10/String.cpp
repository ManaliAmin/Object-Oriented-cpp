#include <cstring>
#include <iostream>
#include "String.h"

using namespace std;

namespace ict{
	//private functions
	void String::deallocate(){
		delete[] m_data;
		m_data = nullptr;
		m_memSize = 0;
	}
	void String::allocate(int memsize){
		deallocate();
		m_data = new char[m_memSize = memsize];
		//initialize first element
		m_data[0] = '\0';

	}

	void String::init(const char* str, int memsize){
		m_data = nullptr;
		m_len = strlen(str);
		if (memsize < m_len + 1){
			memsize = m_len + 1;
		}
		allocate(memsize);
		strcpy(m_data, str);
		m_data[m_len + 1] = '\0';
	}

	//constructors and destructors
	String::String(){
		m_data = nullptr;
		m_memSize = 0;
		m_len = 0;
	}
	String::String(const char* str, int memsize){
		init(str, memsize);
	}
	String::~String(){
		delete[] m_data;
	}

	//copy and assignment operators
	String::String(const String& other){
		//*this = other;
		init(other.m_data, other.m_memSize);
	}
	String& String::operator=(const String& other){
		if (this != &other){
			init(other.m_data, other.m_memSize);
		}
		return *this;
	}

	//public member functions
	void String::resize(int newsize){
		int i;
		char* temp;
		temp = nullptr;
		temp = new char[newsize];
		temp[0] = '\0';          //initialize first element
		if (m_data){
			for (i = 0; (i < newsize - 1 && m_data[i] != '\0'); i++){
				temp[i] = m_data[i];
			}
			temp[i] = '\0';
		}
		allocate(newsize);
		if (temp[0] != '\0'){      //nothing to copy
			strcpy(m_data, temp);
		}
		m_len = strlen(m_data);
	}

	int String::getLength()const{
		return m_len;
	}

	int String::getMemSize()const{
		return m_memSize;
	}


	//IO member functions
	istream& String::read(istream& istr){
		char c;
		int i = 0;
		for (i = 0; (c = istr.get() != '\n'); i++){
			if (i == m_memSize - 1){
				m_len = i;
				resize(m_memSize + ExpansionSize);
			}
			m_data[i] = c;
		}
		m_data[m_len = i] = 0;
		return istr;
	}

	// operator overloads
	String& String::operator+=(const char* str){
		int strLength = strlen(str);
		if (m_memSize < (m_len + strLength + 1)){
			resize(strLength + m_len + 1);
		}
		strcat(m_data, str);
		m_len = strlen(m_data);
		return *this;
	}

	String& String::operator+=(String& str){
		*this += str.m_data;
		return *this;
	}

	String String::operator+(const String& str)const{
		String temp;
		temp.allocate(500);
		temp += this->m_data;
		temp += " ";
		temp += str.m_data;
		temp.m_len = strlen(temp.m_data + 1);
		return temp;
	}

	String& String::operator++(){     //pre-fix operator
		char temp[500];
		strcpy(temp, " ");
		strcat(temp, m_data);
		strcpy(m_data, temp);
		m_len = strlen(m_data);
		return *this;
	}

	String String::operator++(int){    //post-fix operator
		String temp = *this;
		temp += " ";
		return *this;
	}

	char& String::operator[](int index){
		if (index > m_memSize - 1){
			resize(index + ExpansionSize);
		}
		return m_data[index];
	}
	String::operator int()const{
		return strlen(m_data);
	}

	String::operator const char *()const{
		return m_data;
	}

	ostream& String::display(ostream& ostr) const{
		if (m_data != nullptr){
			ostr << m_data;
		}
		return ostr;
	}


	//IO Non-member opertors
	ostream& operator<<(ostream& ostr, const String& s){
		return s.display(ostr);

	}
	istream& operator>>(istream& istr, String &s){
		return s.read(istr);
	}

}