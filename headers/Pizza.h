#pragma once

#include "Includes.h"

class Pizza {
public:
	friend class IPizzaRecipe;
	friend class ItalianPizzaRecipe;
	friend class RussianPizzaRecipe;
	friend class MexicanPizzaRecipe;

	enum FILLING { MEAT, MUSHROOMS, SALAMI };
	enum SPICE { KETCHUP, DILL, CHILI_SAUCE };
	enum HOT_DEGREE { LOW, MID, HIGH };

	Pizza() = default;
	//Pizza(FILLING F, SPICE S, HOT_DEGREE HD) : filling(F), spice(S), hotDegree(HD) {}

	FILLING getFilling() { //need for gtests
		return filling;
	}

	SPICE getSpice() {//need for gtests
		return spice;
	}

	HOT_DEGREE getHotDegree() {//need for gtests
		return hotDegree;
	}

private:
	void setFilling(FILLING f) {
		//std::cout << "Add " << f << " to pizza.\n";
		filling = f;
	}

	void setSpice(SPICE s) {
		//std::cout << "Add " << s << " to pizza.\n";
		spice = s;
	}

	void setHotDegree(HOT_DEGREE hd) {
		//std::cout << "Add " << hd << " to pizza.\n";
		hotDegree = hd;
	}

	FILLING filling;
	SPICE spice;
	HOT_DEGREE hotDegree;
};