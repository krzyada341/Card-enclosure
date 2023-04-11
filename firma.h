#pragma once
#include <iostream>
#include "wizytowka.h"

class Firma : public Wizytowka {
	std::string nazwa;
	std::string miejscowosc;
public:
	std::string getTyp() { return typ; }
	int getNumer() {return numer_tel; }
	std::string getNazwa() { return nazwa; }
	std::string getMiejscowosc() { return miejscowosc; }
	std::string getImie() { return "null"; }
	std::string getNazwisko() { return "null"; }
	int setNumer(int numer) { return this->numer_tel = numer; }
	std::string setNazwa(std::string nazwa) { return this->nazwa = nazwa; }
	std::string setMiejscowosc(std::string miejscowosc) { return this->miejscowosc = miejscowosc; }
	std::string setImie(std::string imie) { return "null"; }
	virtual std::string setNazwisko(std::string nazwisko) { return "null"; }

	Firma(std::string typ, int numer, std::string nazwa, std::string miejscowosc) {
		this->typ = typ;
		this->numer_tel = numer;
		this->nazwa = nazwa;
		this->miejscowosc = miejscowosc;
	}
	
};