#ifndef DEBITO_H
#define DEBITO_H

#include <iostream>
#include <string>
using namespace std;

class Debito: public Cuenta
{
	private:
		int iBono;
		double dPuntos;
	public:
		Debito();
		Debito(int, double, string, int, double);
		void aplicaBono();
		double calculaPagoAnual();
		void deposita(double);
		int getBono();
		double getPuntos();
		void setBono(int);
		void setPuntos(double);
		void toString();
};

Debito::Debito(): Cuenta()
{
	iBono = 0;
	dPuntos = 0;
	cTipoCuenta = 'D';
}

Debito::Debito(int iN, double dB, string sD, int iB, double dP): Cuenta(iN, dB, sD)
{
	iBono = iB;
	dPuntos = dP;
	cTipoCuenta = 'D';
}

void Debito::aplicaBono()
{
	dBalance += (dBalance * 0.01) + dPuntos;
}

double Debito::calculaPagoAnual()
{
	double dPagoAnual;
	this -> aplicaBono();
	dPagoAnual = this -> Cuenta::calculaPagoAnual() - dPuntos;
	dPuntos = 0;
	return dPagoAnual;
}

void Debito::deposita(double dDeposito)
{
	this -> Cuenta::deposita(dDeposito);
	dPuntos += dDeposito / 1000;
}

int Debito::getBono()
{
	return iBono;
}

double Debito::getPuntos()
{
	return dPuntos;
}

void Debito::setBono(int iB)
{
	iBono = iB;
}

void Debito::setPuntos(double dP)
{
	dPuntos = dP;
}

void Debito::toString()
{
	this -> Cuenta::toString();
	cout << "Debito" << endl;
	cout << "Bono: " << iBono << endl;
	cout << "Puntos: " << dPuntos << endl;
}

#endif
