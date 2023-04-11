#pragma once

class Wizytowka {
protected:
	int numer_tel;
	std::string typ;
public:
	virtual std::string getTyp() = 0;
	virtual int getNumer() = 0;
	virtual std::string getImie() = 0;
	virtual std::string getNazwisko() = 0;
	virtual std::string getNazwa() = 0;
	virtual std::string getMiejscowosc() = 0;
	virtual int setNumer(int numer) = 0;
	virtual std::string setImie(std::string imie) = 0;
	virtual std::string setNazwisko(std::string nazwisko) = 0;
	virtual std::string setNazwa(std::string nazwa) = 0;
	virtual std::string setMiejscowosc(std::string miejscowosc) = 0;
};