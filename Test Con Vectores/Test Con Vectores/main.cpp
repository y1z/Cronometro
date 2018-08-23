#include <iostream>
#include <vector>
#include <algorithm>
#include"CronometroGeneral.h"
using std::vector;
Cronometro cronometro;

// lo que hace esta funcion es 
// temporarmente deter el programa 
void ExtraEspacio(int CantidadDeEspacio) {
	std::string Espacio;
	for (int i = 0; i < CantidadDeEspacio; ++i) 
	{
		Espacio += "\n";
	}

	std::cout << Espacio;
}

void Stop() 
{
	std::cin.ignore();
	std::cin.get();
}

void VectorPushBack(long CantidadDeElementos)
{
	std::cout << "aqui se esta midiendo Cuanto tiempo se trada un vector en hacer \n [push_back]  a 10000000 variable de tamaño de un int SIN resize \n .";

	vector<int> VectorDeints;
	cronometro.ComenzarMedirTiempo();
	for(long i=0; i < CantidadDeElementos; ++i)
	{
		VectorDeints.push_back(i);
	
	}
	cronometro.FinalizarMedirTiempo();

	ExtraEspacio(5);
}

void VectorPushBackSize(long CantidadDeElementos) {

	std::cout << "aqui se esta midiendo Cuanto tiempo se trada en un vector en hacer \n [push_back] 10000000 variable de tamaño de un int CON resize \n .";


	vector<int> VectorDeints;


	cronometro.ComenzarMedirTiempo();
	VectorDeints.resize(CantidadDeElementos);
	for (long i = 0; i < CantidadDeElementos; ++i)
	{
		VectorDeints.push_back(i);

	}
	cronometro.FinalizarMedirTiempo();
	ExtraEspacio(5);
}

void VectorEmplaceBack(long CantidadDeElementos) {

	std::cout << "aqui se esta midiendo Cuanto tiempo se trada en un vector en hacer \n [emplace_back] a 10000000 variable de tamaño de un int SIN resize \n  .";

	vector<int> VectorDeints;
	cronometro.ComenzarMedirTiempo();
	for (long i= 0; i < CantidadDeElementos; ++i)
	{
		VectorDeints.emplace_back(i);

	}
	cronometro.FinalizarMedirTiempo();
	ExtraEspacio(5);
}

void VectorEmplaceBackSize(long CantidadDeElementos) {
	std::cout << "aqui se esta midiendo Cuanto tiempo se trada en un vector en hacer \n [emplace_back] 10000000 variable de tamaño de un int CON resize \n .";

	vector<int> VectorDeints;
	cronometro.ComenzarMedirTiempo();
	VectorDeints.resize(CantidadDeElementos);
	for (long i = 0; i < CantidadDeElementos; ++i)
	{
		VectorDeints.emplace_back(i);

	}
	cronometro.FinalizarMedirTiempo();
	ExtraEspacio(5);


}


int main() {
	const long DiezMillones = 10000000;


	VectorPushBack(DiezMillones);
	VectorPushBackSize(DiezMillones);
	VectorEmplaceBack(DiezMillones);
	VectorEmplaceBackSize(DiezMillones);

	Stop();

	return 0;
}