#pragma once
#include <iostream>
#include "wizytowka.h"

class Osoba_fizyczna : public Wizytowka {
	std::string imie;
	std::string nazwisko;
public:
	std::string getTyp() { return typ; }
	int getNumer() { return numer_tel; }
	std::string getImie() { return imie; }
	std::string getNazwisko() { return nazwisko; }
	std::string getNazwa() { return "null"; }
	std::string getMiejscowosc() { return "null"; }
	int setNumer(int numer) { return this->numer_tel = numer; }
	std::string setImie(std::string imie) { return this->imie = imie; }
	std::string setNazwisko(std::string nazwisko) { return this->nazwisko = nazwisko; }
	std::string setNazwa(std::string nazwa) { return "null"; }
	std::string setMiejscowosc(std::string miejscowosc) { return "null"; }

	Osoba_fizyczna(std::string typ, int numer, std::string imie, std::string nazwisko) {
		this->typ = typ;
		this->numer_tel = numer;
		this->imie = imie;
		this->nazwisko = nazwisko;
	}

};