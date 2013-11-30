#ifndef BANK_H
#define BANK_H

#include <string>
#include "Account.h"

using namespace std;

class Bank {
	private:
		// data member goes here
		// interest rate
		
		// account list
		
	public:
		// constructors, destructors
		
		// setters, getters
		
		// implement these methods
		void create(string name, double balance);
		void deposit(string name, double value);
		void withdraw(string name, double value);
};

#endif
