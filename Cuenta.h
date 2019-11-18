#ifndef CUENTA_H
#define CUENTA_H

#include <iostream>
#include <string>
using namespace std;

class Cuenta
{
	protected:
		int iNoCuenta;
		double dBalance;
		string sDueno;
		char cTipoCuenta;
	public:
		Cuenta();
		Cuenta(int, double, string);
		double calculaPagoAnual();
		void deposita(double);
		double getBalance();
		string getDueno();
		char getTipoCuenta();
		int getNoCuenta();
		bool retira(double);
		void setBalance(double);
		void setDueno(string);
		void setNoCuenta(int);
		virtual void toString();
};

Cuenta::Cuenta()
{
	iNoCuenta = -1;
	dBalance = 0;
	sDueno = "N/A";
	cTipoCuenta = 'A';
}

Cuenta::Cuenta(int iN, double dB, string sD)
{
	iNoCuenta = iN;
	dBalance = dB;
	sDueno = sD;
	cTipoCuenta = 'A';
}

double Cuenta::calculaPagoAnual()
{
	double dPagoAnual = 2500;
	switch (cTipoCuenta)
	{
		case 'A':
			dPagoAnual += 1500;
			break;
		case 'C':
			dPagoAnual += 1000;
			break;
		case 'D':
			dPagoAnual += 500;
			break;
	}
	return dPagoAnual;
}

void Cuenta::deposita(double dDeposito)
{
	dBalance += dDeposito;
}

double Cuenta::getBalance()
{
	return dBalance;
}

string Cuenta::getDueno()
{
	return sDueno;
}

char Cuenta::getTipoCuenta()
{
	return cTipoCuenta;
}

int Cuenta::getNoCuenta()
{
	return iNoCuenta;
}

bool Cuenta::retira(double dRetiro)
{
	if (dBalance >= dRetiro)
	{
		dBalance -= dRetiro;
		return true;
	}
	else
	{
		return false;
	}
}

void Cuenta::setBalance(double dB)
{
	dBalance = dB;
}

void Cuenta::setDueno(string sD)
{
	sDueno = sD;
}

void Cuenta::setNoCuenta(int iN)
{
	iNoCuenta = iN;
}

void Cuenta::toString()
{
	cout << "Cuenta" << endl;
	cout << "NoCuenta: " << iNoCuenta << endl;
	cout << "Balance: " << dBalance << endl;
	cout << "Dueno: " << sDueno << endl;
	cout << "TipoCuenta: " << cTipoCuenta << endl;
}

#endif
