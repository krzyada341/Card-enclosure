#include <iostream>
#include "firma.h"
#include "wizytowka.h"
#include "osoba_fizyczna.h"
#include "baza.h"

int main() {
	bool warunek = true;
	int wybor;
	std::string nazwaPliku, nazwaPliku2;
	Baza baza;

	while (warunek) {
		std::cout << "Mobilny wizytownik. Wybierz opcje, ktora cie interesuje: " << std::endl;
		std::cout << "1. Import bazy danych " << std::endl;
		std::cout << "2. Dodanie wizytowki " << std::endl;
		std::cout << "3. Usuwanie wizytowki " << std::endl;
		std::cout << "4. Modyfikacja wizytowki " << std::endl;
		std::cout << "5. Wyszukaj wizytowek " << std::endl;
		std::cout << "6. Eksport bazy danych " << std::endl;
		std::cout << "7. Wyjscie z programu" << std::endl;
		std::cin >> wybor;

		if (std::cin.fail()) {
			system("pause");
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			wybor = 0;
		}

		system("cls");
		switch (wybor) {
		case 1:
			std::cout << "Wprowadz nazwe wraz z rozszerzeniem pliku z baza danych: " << std::endl;
			std::cin >> nazwaPliku;
			baza.wczytaj(nazwaPliku);
			baza.wyswietl();
			break;
		case 2:
			system("cls");
			baza.dodaj();
			baza.wyswietl();
			break;
		case 3:
			system("cls");
			baza.wyswietl();
			baza.usun();
			baza.wyswietl();
			break;
		case 4:
			system("cls");
			baza.wyswietl();
			baza.modyfikuj();
			baza.wyswietl();
			break;
		case 5:
			system("cls");
			baza.wyszukaj();
			break;
		case 6:
			system("cls");
			std::cout << "Wprowadz nazwe wraz z rozszerzeniem pliku do jakiej chcesz eksportowac aktualna baze: " << std::endl;
			std::cin >> nazwaPliku2;
			baza.eksportuj(nazwaPliku2);
			break;
		case 7:
			warunek = false;
			break;
		default:
			std::cout << "Prosze wybrac poprawna opcje!" << std::endl;
		}
		
	}

	std::cout << "Dziekuje za skorzystanie z programu! " << std::endl;
	return 0;
}