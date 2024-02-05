#pragma once
#include <iostream>

class Zbior
{
	size_t m_liczbaElementow = 0;
	double* m_elementy = nullptr;
	double m_dolnaGranica = 0;
	double m_gornaGranica = 0;
	void alokuj(int);
	void zwolnij();
public:
	Zbior() {};

	Zbior(size_t liczElem, double dGran, double gGran);


	//przenoszenie
	Zbior(Zbior&& element);

	Zbior& operator=(Zbior&& element) = delete;

	//kopiowanie
	Zbior(const Zbior& element) = delete;

	Zbior& operator=(const Zbior& element) {
		if (this != &element) {
			bool roznyRozmiar = this->m_liczbaElementow != element.m_liczbaElementow;
			if (this->m_elementy != nullptr && roznyRozmiar) {
				zwolnij();
			}
			if (element.m_elementy != nullptr) {
				if (roznyRozmiar) {
					alokuj(element.m_liczbaElementow);
				}

				for (int i = 0; i < element.m_liczbaElementow; i++) {
					this->m_elementy[i] = element.m_elementy[i];
				}
			}
			this->m_liczbaElementow = element.m_liczbaElementow;
		}
		return *this;
	}

	void showDane();

	double srednia();

	~Zbior() { zwolnij(); }
};

class Funktor
{
private:

	Zbior m_zbior_testowy;

public:
	Funktor(const Funktor& element) {}


	Funktor(Zbior& element) {
		m_zbior_testowy = element;
	}

	bool operator()(Zbior& element) {
		double sredniaFunktora = m_zbior_testowy.srednia();
		double srednia = element.srednia();

		if (srednia < (srednia + 0.1) && srednia >(srednia - 0.1)) {
			return true;
		}
		else {
			return false;
		}
	}
};