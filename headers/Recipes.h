#pragma once

#include "Includes.h"
#include "Pizza.h"
#include <memory>

class IPizzaRecipe { //builder
public:
	virtual void BuildFilling() = 0;
	virtual void BuildSpice() = 0;
	virtual void BuildHotDegree() = 0;

	void CreatePizza() {
		m_pizza.reset(new Pizza);
	}

	std::shared_ptr<Pizza> GetPizza() {
		return m_pizza;
	}

protected:
	std::shared_ptr<Pizza> m_pizza;
};

class ItalianPizzaRecipe : public IPizzaRecipe {
public:
	void BuildFilling() {
		m_pizza->setFilling(Pizza::MEAT);
	}

	void BuildSpice() {
		m_pizza->setSpice(Pizza::KETCHUP);
	}

	void BuildHotDegree() {
		m_pizza->setHotDegree(Pizza::MID);
	}
};

class RussianPizzaRecipe : public IPizzaRecipe {
public:
	void BuildFilling() {
		m_pizza->setFilling(Pizza::MUSHROOMS);
	}

	void BuildSpice() {
		m_pizza->setSpice(Pizza::DILL);
	}

	void BuildHotDegree() {
		m_pizza->setHotDegree(Pizza::LOW);
	}
};

class MexicanPizzaRecipe : public IPizzaRecipe {
public:
	void BuildFilling() {
		m_pizza->setFilling(Pizza::SALAMI);
	}

	void BuildSpice() {
		m_pizza->setSpice(Pizza::CHILI_SAUCE);
	}

	void BuildHotDegree() {
		m_pizza->setHotDegree(Pizza::HIGH);
	}
};