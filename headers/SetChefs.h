#pragma once

#include "Includes.h"
#include "Pizza.h"
#include "Drinks.h"
#include "Recipes.h"

class SetChef { //it's abstract factory
public:
	virtual Pizza* CreatePizza() = 0;
	virtual Drink* CreateDrink() = 0;
};

class ItalianSetChef : public SetChef {
public:
	virtual Pizza* CreatePizza() {
		Pizza* pizza = new Pizza;

		
	}

private:
	
};

class RussianSetChef : public SetChef {

};

class MexicanSetChef : public SetChef {

};