#ifndef CREDITO_H
#define CREDITO_H

#include <iostream>
#include <string>
using namespace std;

class Credito: public Cuenta
{
	private:
		int iInteres;
		double dLimite;
	public:
		Credito();
		Credito(int, double, string, int, double);
		double aplicaInteres();
		double calculaPagoAnual();
		void deposita(double);
		int getInteres();
		double getLimite();
		double incrementaCredito(int);
		bool retira(double);
		void setInteres(int);
		void setLimite(double);
		void toString();
};

Credito::Credito(): Cuenta()
{
	iInteres = 5;
	dLimite = 5000;
	cTipoCuenta = 'C';
}

Credito::Credito(int iN, double dB, string sD, int iI, double dL): Cuenta(iN, dB, sD)
{
	iInteres = iI;
	dLimite = dL;
	cTipoCuenta = 'C';
}

double Credito::aplicaInteres()
{
	return dBalance * iInteres * (dLimite / 100 * 0.04);
}

double Credito::calculaPagoAnual()
{
	return this -> Cuenta::calculaPagoAnual() + aplicaInteres();
}

void Credito::deposita(double dDeposito)
{
	dBalance -= dDeposito;
}

int Credito::getInteres()
{
	return iInteres;
}

double Credito::getLimite()
{
	return dLimite;
}

double Credito::incrementaCredito(int iPorcentaje)
{
	return dLimite * (1 + iPorcentaje / 100.0);
}

bool Credito::retira(double dRetiro)
{
	if (dLimite >= dBalance + dRetiro)
	{
		dBalance += dRetiro;
		return true;
	}
	else
	{
		return false;
	}
}

void Credito::setInteres(int iI)
{
	iInteres = iI;
}

void Credito::setLimite(double dL)
{
	dLimite = dL;
}

void Credito::toString()
{
	this -> Cuenta::toString();
	cout << "Credito" << endl;
	cout << "Interes: " << iInteres << endl;
	cout << "Limite: " << dLimite << endl;
}

#endif
