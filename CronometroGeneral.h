#pragma once
#include <ctime>
#include <iostream>
#include <chrono>
#include <thread>
#include <string>

typedef std::chrono::high_resolution_clock::time_point T_P;// hice esto para no tener que teclar "std::chrono::high_resolution_clock::time_point" mill veces .
//------------------------------------------//
using std::chrono::high_resolution_clock;

class Cronometro
{
public:
	Cronometro();// constructor por defecto 
	
	// Este constructor te deja elejir cual medida de timepo se presenta las medidas .
	Cronometro(std::string Indicador);
	
	~Cronometro();// destructor por defecto 
public:
	void ComenzarMedirTiempo();
	void FinalizarMedirTiempo();
	void ElegirMedidaTiempo(std::string Indicador);
public:
	T_P M_Inicio;
	T_P M_Fin;

	// Esta variable determina cuanto timepo a transcurrido desde que iniciamos el cronometro .
	std::chrono::duration<double>  M_ResultadoPorDefecto;

	std::chrono::milliseconds M_miliSegundos;//<= la variable que indica los milisegundos 
    std::chrono::microseconds M_microSegundos;//<= la variable que indica los microsegundos.
	std::chrono::seconds M_Segundos;//<= la variable que indica los segundos.

private:
	void PrintResultado();
	enum Banderas// estos enums son para indicar las medicion de tiempo que va presentar el objeto.
	{
		AUTO = -1,
		Defecto = 0,// Es indica al objecto lo que hace por defecto . 
		Microsegundos = 1,// Indica al objecto que va a sacar el timepo en Macrosegundos  
		Milisegundos = 2,// Indica al objecto que va a sacar el tiempo en Milisegundos 
		Segundo = 3// Indica al objecto que va a sacar el tiempo en Segundos .
	};

	Banderas M_TipoTiempo = Defecto;
};

