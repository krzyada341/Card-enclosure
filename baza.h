#pragma once
#include <iostream>
#include <list>
#include <memory>
#include "firma.h"
#include "wizytowka.h"
#include "osoba_fizyczna.h"

class Baza {
	std::list<std::shared_ptr<Wizytowka>> bazaWizytowek;
public:
	void wczytaj(const std::string& nazwaPliku);
	void wyswietl();
	void dodaj();
	void eksportuj(const std::string& nazwaPliku);
	void usun();
	void modyfikuj();
	void wyszukaj();
};
