#ifndef NAVE_H
#define NAVE_H

#include "raylib.h"

namespace Juego {
	namespace Nave {
		struct Jug {
			Vector2 pos;
			Vector2 velocidad;
			float aceleracion;
			float rotacion;
			//Vector3 collider;
			Color color;
		};

		extern Jug nave;
		extern Vector2 puntoDisparo;
		Jug crearJugador();
		void actualizarNave();
		void dibujarNave();
		void inicializarJug();
	}
}

#endif