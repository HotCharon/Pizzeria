#pragma once

#include "Includes.h"

class Drink {
public:
	virtual ~Drink() {};
};

class Wine : public Drink {
public:
	virtual ~Wine() {}
};

class Kvass : public Drink {
public:
	virtual ~Kvass() {}
};

class Mescal : public Drink {
public:
	virtual ~Mescal() {}
};