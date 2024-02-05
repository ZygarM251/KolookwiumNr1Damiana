#include "Nag³ówek.h"
#include <iostream>
#include <new>
#include <random>

using namespace std;

void Zbior::alokuj(int n)
{
	if (n > 0)
	{
		m_elementy = new(std::nothrow) double[n];
		m_liczbaElementow = n;
	}
}

void Zbior::zwolnij()
{
	if (m_elementy != nullptr)
	{
		delete[] m_elementy;
		m_elementy = nullptr;
	}
}

Zbior::Zbior(size_t liczElem, double dGran, double gGran)
{
	alokuj(liczElem);
	std::uniform_real_distribution<double> zakres(dGran, gGran);
	std::random_device generator;
	for (int elem = 0; elem < liczElem; elem++)
		m_elementy[elem] = zakres(generator);
}


Zbior::Zbior(Zbior&& element)
	:m_liczbaElementow(element.m_liczbaElementow), m_dolnaGranica(element.m_dolnaGranica), m_gornaGranica(element.m_gornaGranica)
{
	this->m_elementy = element.m_elementy;
	element.m_elementy = nullptr;
}

void Zbior::showDane()
{
	for (int i = 0; i < m_liczbaElementow; i++) {
		cout << m_elementy[i] << " ";
	}
}

double Zbior::srednia() {
	double srednia = 0.0;
	for (int i = 0; i < m_liczbaElementow; i++) {
		srednia += m_elementy[i];
	}

	srednia = srednia / m_liczbaElementow;

	return srednia;
}