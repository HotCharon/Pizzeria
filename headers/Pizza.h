#include "Includes.h"

class Pizza {
public:
	enum FILLING { MEAT, MUSHROOMS, SALAMI };
	enum SPICE { KETCHUP, DILL, SHILI_SAUCE };
	enum HOT_DEGREE { LOW, MID, HIGH };

	void setFilling(FILLING f) {
		std::cout << "Add " << f << " to pizza.\n";
		filling = f;
	}

	void setSpice(SPICE s) {
		std::cout << "Add " << s << " to pizza.\n";
		spice = s;
	}

	void setHotDegree(HOT_DEGREE hd) {
		std::cout << "Add " << hd << " to pizza.\n";
		hotDegree = hd;
	}

	FILLING filling;
	SPICE spice;
	HOT_DEGREE hotDegree;
};