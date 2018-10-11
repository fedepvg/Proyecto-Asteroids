#ifndef PANTALLAJUEGO_H
#define PANTALLAJUEGO_H
#include"raylib.h"
namespace Juego {
	namespace PantallaJuego {
		enum fases { inicio, juego, pausa, fin };
		extern fases;
		extern bool pausa;
		void actualizarJuego();
		void dibujarJuego();
		void inicializarPantJuego();
		void desinicializarPantJuego();
	}
}
#endif