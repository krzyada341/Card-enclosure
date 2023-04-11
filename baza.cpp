#pragma once
#include <iostream>
#include <list>
#include <fstream>
#include <memory>
#include <cctype>
#include <algorithm>
#include "baza.h"

void Baza::wczytaj(const std::string& nazwaPliku) {
	int numer;
	std::string typ, wartosc1, wartosc2;
	std::ifstream plik(nazwaPliku);
	try {
		if (!plik) throw nazwaPliku;
	}
	catch (std::string& nazwa) {
		std::cerr << "Nie znaleziono takiego pliku! " << std::endl;
	}
	while (plik >> typ >> numer >> wartosc1 >> wartosc2) {
		if(typ == "osoba")
			bazaWizytowek.push_back(std::shared_ptr<Osoba_fizyczna>(new Osoba_fizyczna(typ, numer, wartosc1, wartosc2)));
		if(typ == "firma")
			bazaWizytowek.push_back(std::shared_ptr<Firma>(new Firma(typ, numer, wartosc1, wartosc2)));
	}
}

void Baza::wyswietl() {
	int id = 0;
	for (auto const& i : bazaWizytowek) {
		if(i->getTyp() == "osoba")
			std::cout << "ID:" << id << " Numer telefonu: " << i->getNumer() << " Imie: " << i->getImie() << " Nazwisko: " << i->getNazwisko() << std::endl;
		if (i->getTyp() == "firma")
			std::cout << "ID:" << id << " Numer telefonu: " << i->getNumer() << " Nazwa: " << i->getNazwa() << " Miejscowosc: " << i->getMiejscowosc() << std::endl;
		id++;
	}
}

void Baza::dodaj() {
	int wybor, numer;
	std::string imie, nazwisko, nazwa, miejscowosc;
	std::string osoba = "osoba";
	std::string firma = "firma";

	std::cout << "Jaki typ wizytowki chcesz dodac? " << std::endl << "1. Osoba fizyczna " << std::endl << "2. Firma" << std::endl;
	std::cin >> wybor;

	if (std::cin.fail()) {
		system("pause");
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		wybor = 0;
	}

	switch (wybor) {
	case 1:
		std::cout << "Wpisz kolejno potrzebne wartosci: NumerTelefonu Imie Nazwisko :" << std::endl;
		std::cin >> numer >> imie >> nazwisko;

		if (std::cin.fail()) {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.clear();
			std::cout << "Numer telefonu sklada sie tylko z liczb" << std::endl;
			break;
		}
		else if (numer <= 999999999 && numer > 99999999) {
			bazaWizytowek.push_back(std::shared_ptr<Osoba_fizyczna>(new Osoba_fizyczna(osoba, numer, imie, nazwisko)));
			break;
		}
		else {
			std::cout << "Numer telefonu sklada sie z 9 cyfr!" << std::endl;
			break;
		}

	case 2:
		std::cout << "Wpisz kolejno potrzebne wartosci: NumerTelefonu Nazwa Miejscowosc :" << std::endl;
		std::cin >> numer >> nazwa >> miejscowosc;

		if (std::cin.fail()) {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.clear();
			std::cout << "Numer telefonu sklada sie tylko z liczb" << std::endl;
			break;
		}
		else if (numer <= 999999999 && numer > 99999999) {
			bazaWizytowek.push_back(std::shared_ptr<Firma>(new Firma(firma, numer, nazwa, miejscowosc)));;
			break;
		}
		else {
			std::cout << "Numer telefonu sklada sie z 9 cyfr!" << std::endl;
			break;
		}
	}
}

void Baza::eksportuj(const std::string& nazwaPliku) {
	std::ofstream plik(nazwaPliku);
	for (auto const& i : bazaWizytowek) {
		if (i->getTyp() == "osoba")
			plik << i->getTyp() << " " << i->getNumer() << " " << i->getImie() << " " << i->getNazwisko() << std::endl;
		if (i->getTyp() == "firma")
			plik << i->getTyp() << " " << i->getNumer() << " " << i->getNazwa() << " " << i->getMiejscowosc() << std::endl;
	}
	plik.close();
}

void Baza::usun() {
	if (bazaWizytowek.empty()) {
		std::cout << "Nie ma tu czego usuwac, baza jest pusta ! " << std::endl;
	}
	else {
		int idElementu;
		std::cout << "Podaj id wiersza do usuniecia: " << std::endl;
		std::cin >> idElementu;
		if (idElementu >= bazaWizytowek.size()) {
			std::cout << "Nie ma takiego indeksu" << std::endl;
		}
		else {
			std::list<std::shared_ptr<Wizytowka>>::iterator it = bazaWizytowek.begin();
			advance(it, idElementu);
			bazaWizytowek.erase(it);
		}
	}
}

void Baza::modyfikuj() {
	if (bazaWizytowek.empty()) {
		std::cout << "Nie ma tu czego modyfikowac, baza jest pusta ! " << std::endl;
	}
	else {
		int idElementu, numer;
		std::string wybor, imie, nazwisko, nazwa, miejscowosc;
		auto it = bazaWizytowek.begin();
		std::cout << "Podaj id wiersza do zmodyfikowania oraz nazwe wartosci do zmodyfikowania" << std::endl;
		std::cin >> idElementu >> wybor;
		std::transform(wybor.begin(), wybor.end(), wybor.begin(), ::tolower);

		if (idElementu >= bazaWizytowek.size()) {
			std::cout << "Nie ma takiego indeksu" << std::endl;
		}
		else {
			advance(it, idElementu);
			if (wybor == "numer") {
				std::cout << "Podaj nowy numer telefonu:" << std::endl;
				std::cin >> numer;

				if (std::cin.fail()) {
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cin.clear();
					std::cout << "Numer telefonu sklada sie tylko z liczb" << std::endl;
				}
				else if (numer <= 999999999 && numer > 99999999) {
					(*it)->setNumer(numer);
				}
				else {
					std::cout << "Numer telefonu sklada sie z 9 cyfr!" << std::endl;
				}
			}

			else if ((*it)->getTyp() == "osoba") {
				if (wybor == "imie") {
					std::cout << "Podaj nowe imie:" << std::endl;
					std::cin >> imie;
					(*it)->setImie(imie);
				}

				else if (wybor == "nazwisko") {
					std::cout << "Podaj nowe nazwisko:" << std::endl;
					std::cin >> nazwisko;
					(*it)->setNazwisko(nazwisko);
				}
				else std::cout << "Dla takiego ID podana wartosc nie istnieje!" << std::endl;
			}

			else if ((*it)->getTyp() == "firma") {
				if (wybor == "nazwa") {
					std::cout << "Podaj nowa nazwe:" << std::endl;
					std::cin >> nazwa;
					(*it)->setNazwa(nazwa);
				}

				else if (wybor == "miejscowosc") {
					std::cout << "Podaj nowa miejscowosc:" << std::endl;
					std::cin >> miejscowosc;
					(*it)->setMiejscowosc(miejscowosc);
				}
				else std::cout << "Dla takiego ID podana wartosc nie istnieje!" << std::endl;
			}
		}
	}
}

void Baza::wyszukaj() {
	int numer;
	int id = 0;
	std::string wybor, imie, nazwisko, nazwa, miejscowosc;
	std::cout << "Wpisz po ktorej wartosci wyszukac: " << std::endl;
	std::cin >> wybor;
	std::transform(wybor.begin(), wybor.end(), wybor.begin(), ::tolower);
	if (wybor == "numer") {
		std::cout << "Wpisz dla jakiego numeru telefonu wyszukac wartosci: " << std::endl;
		std::cin >> numer;
		for (auto const& i : bazaWizytowek) {
			if (i->getTyp() == "osoba" && i->getNumer() == numer)
				std::cout << "ID:" << id << " Numer telefonu: " << i->getNumer() << " Imie: " << i->getImie() << " Nazwisko: " << i->getNazwisko() << std::endl;
			if (i->getTyp() == "firma" && i->getNumer() == numer)
				std::cout << "ID:" << id << " Numer telefonu: " << i->getNumer() << " Nazwa: " << i->getNazwa() << " Miejscowosc: " << i->getMiejscowosc() << std::endl;
			id++;
		}
	}
	if (wybor == "imie") {
		std::cout << "Wpisz dla jakiego imienia wyszukac wartosci: " << std::endl;
		std::cin >> imie;
		for (auto const& i : bazaWizytowek) {
			if (i->getTyp() == "osoba" && i->getImie() == imie)
				std::cout << "ID:" << id << " Numer telefonu: " << i->getNumer() << " Imie: " << i->getImie() << " Nazwisko: " << i->getNazwisko() << std::endl;
			if (i->getTyp() == "firma" && i->getImie() == imie)
				std::cout << "ID:" << id << " Numer telefonu: " << i->getNumer() << " Nazwa: " << i->getNazwa() << " Miejscowosc: " << i->getMiejscowosc() << std::endl;
			id++;
		}
	}
	if (wybor == "nazwisko") {
		std::cout << "Wpisz dla jakiego nazwiska wyszukac wartosci: " << std::endl;
		std::cin >> nazwisko;
		for (auto const& i : bazaWizytowek) {
			if (i->getTyp() == "osoba" && i->getNazwisko() == nazwisko)
				std::cout << "ID:" << id << " Numer telefonu: " << i->getNumer() << " Imie: " << i->getImie() << " Nazwisko: " << i->getNazwisko() << std::endl;
			if (i->getTyp() == "firma" && i->getNazwisko() == nazwisko)
				std::cout << "ID:" << id << " Numer telefonu: " << i->getNumer() << " Nazwa: " << i->getNazwa() << " Miejscowosc: " << i->getMiejscowosc() << std::endl;
			id++;
		}
	}
	if (wybor == "nazwa") {
		std::cout << "Wpisz dla jakiej nazwy wyszukac wartosci: " << std::endl;
		std::cin >> nazwa;
		for (auto const& i : bazaWizytowek) {
			if (i->getTyp() == "osoba" && i->getNazwa() == nazwa)
				std::cout << "ID:" << id << " Numer telefonu: " << i->getNumer() << " Imie: " << i->getImie() << " Nazwisko: " << i->getNazwisko() << std::endl;
			if (i->getTyp() == "firma" && i->getNazwa() == nazwa)
				std::cout << "ID:" << id << " Numer telefonu: " << i->getNumer() << " Nazwa: " << i->getNazwa() << " Miejscowosc: " << i->getMiejscowosc() << std::endl;
			id++;
		}
	}
	if (wybor == "miejscowosc") {
		std::cout << "Wpisz dla jakiej miejscowosci wyszukac wartosci: " << std::endl;
		std::cin >> miejscowosc;
		for (auto const& i : bazaWizytowek) {
			if (i->getTyp() == "osoba" && i->getMiejscowosc() == miejscowosc)
				std::cout << "ID:" << id << " Numer telefonu: " << i->getNumer() << " Imie: " << i->getImie() << " Nazwisko: " << i->getNazwisko() << std::endl;
			if (i->getTyp() == "firma" && i->getMiejscowosc() == miejscowosc)
				std::cout << "ID:" << id << " Numer telefonu: " << i->getNumer() << " Nazwa: " << i->getNazwa() << " Miejscowosc: " << i->getMiejscowosc() << std::endl;
			id++;
		}
	}

	
}