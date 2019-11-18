#include "Cuenta.h"
#include "Credito.h"
#include "Debito.h"

#include <iostream>
#include <string>
using namespace std;

int main()
{
	Cuenta *listaCuentas[20];
	Credito *credito;
	Debito *debito;
	int iContadorCuentas = 0, iNoCuenta, iInteres, iBono, iX;
	char cOpcion, cTipoCuenta;
	double dBalance, dLimite, dPuntos, dCantidad;
	string sDueno;
	bool bExiste;

	do
	{
		cout << "****** MENU ********" << endl;
		cout << "a) Agrega cuenta" << endl;
		cout << "b) Desplegar datos de cuenta dado su NoCuenta" << endl;
		cout << "c) Depositar en cuenta dado su NoCuenta" << endl;
		cout << "d) Retirar de cuenta dado su NoCuenta" << endl;
		cout << "e) Calcular pago anual ddado su NoCuenta" << endl;
		cout << "f) Aplicar bonus / Aplicar incremento limite dado su NoCuenta" << endl;
		cout << "g) Terminar" << endl;
		cout << "Opcion: ";
		cin >> cOpcion;

		switch (cOpcion)
		{
			case 'a': // Agrega cuenta
			case 'A':
				cout << "Tipo de cuenta (A, C, D): ";
				cin >> cTipoCuenta;
				cout << "Numero de cuenta: ";
				cin >> iNoCuenta;
				cout << "Dueno: ";
				cin >> sDueno;
				cout << "Balance: ";
				cin >> dBalance;

				if (cTipoCuenta == 'a' || cTipoCuenta == 'A')
				{
					listaCuentas[iContadorCuentas] = new Cuenta(iNoCuenta, dBalance, sDueno);
					// listaCuentas[0] -> toString();
				}
				else if (cTipoCuenta == 'c' || cTipoCuenta == 'C')
				{
					cout << "Interes: ";
					cin >> iInteres;
					cout << "Limite de credito: ";
					cin >> dLimite;

					listaCuentas[iContadorCuentas] = new Credito(iNoCuenta, dBalance, sDueno, iInteres, dLimite);
					// listaCuentas[0] -> toString();
				}
				else if (cTipoCuenta == 'd' || cTipoCuenta == 'D')
				{
					cout << "Bono: ";
					cin >> iBono;
					cout << "dPuntos: ";
					cin >> dPuntos;

					listaCuentas[iContadorCuentas] = new Debito(iNoCuenta, dBalance, sDueno, iBono, dPuntos);
					// listaCuentas[0] -> toString();
				}

				// Falta validar los inputs del usuario

				iContadorCuentas++;
				break;

			case 'b': // Desplegar datos de cuenta dado su NoCuenta
			case 'B':
				cout << "NoCuenta: ";
				cin >> iNoCuenta;

				bExiste = false;
				for (iX = 0; iX < iContadorCuentas && !bExiste; iX++)
				{
					if (listaCuentas[iX] -> getNoCuenta() == iNoCuenta)
					{
						listaCuentas[iX] -> toString();
						bExiste = true;
					}
				}

				if (!bExiste)
				{
					cout << "Ese numero de cuenta no existe aun!" << endl;
				}

				break;

			case 'c': // Depositar en cuenta dado su NoCuenta
			case 'C':
				cout << "NoCuenta: ";
				cin >> iNoCuenta;
				cout << "Cantidad a depositar: ";
				cin >> dCantidad;

				bExiste = false;
				for (iX = 0; iX < iContadorCuentas && !bExiste; iX++)
				{
					if (listaCuentas[iX] -> getNoCuenta() == iNoCuenta)
					{
						cTipoCuenta = listaCuentas[iX] -> getTipoCuenta();
						if (cTipoCuenta == 'A')
						{
							listaCuentas[iX] -> deposita(dCantidad);
						}
						else if (cTipoCuenta == 'C')
						{
							credito = (Credito *)listaCuentas[iX];
							credito -> deposita(dCantidad);
						}
						else
						{
							debito = (Debito *)listaCuentas[iX];
							debito -> deposita(dCantidad);
						}

						bExiste = true;
					}
				}

				if (!bExiste)
				{
					cout << "Ese numero de cuenta no existe aun!" << endl;
				}

				break;

			case 'd': // Retirar de cuenta dado su NoCuenta
			case 'D':
				cout << "NoCuenta: ";
				cin >> iNoCuenta;
				cout << "Cantidad a retirar: ";
				cin >> dCantidad;
				break;

			case 'e': // Calcular pago anual ddado su NoCuenta
			case 'E':

				break;

			case 'f': // Aplicar bonus / Aplicar incremento limite dado su NoCuenta
			case 'F':

				break;

			case 'g': // Terminar
			case 'G':
				break;

			default:

				break;
		}
	}
	while (cOpcion != 'g' && cOpcion != 'G');

	return 0;
}