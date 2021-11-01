#pragma once
#include "dummy.h"

void dummyTest() {
	Dummy a;
	*a.num = 4;
	Dummy b{a};
	Dummy c;
	c = a;
	cout << "a: " << *a.num << endl;
	cout << "b: " << *b.num << endl;
	cout << "c: " << *c.num << endl;
	*b.num = 3;
	*c.num = 5;
	cout << "a: " << *a.num << endl;
	cout << "b: " << *b.num << endl;
	cout << "c: " << *c.num << endl; //skrives ut 4,4,4,5,5,5, hvorfor feilmeld?

	cin.get(); // For å hindre at vinduet lukkes
	
}
Dummy::Dummy(const Dummy &other) : num{ nullptr } {
    this->num = new int{};
    *num = other.get(); //kopierer verdier fra other til this
}
Dummy &Dummy::operator=(Dummy rhs) {

    swap(num, rhs.num); //swapper pekere
    return *this;
}