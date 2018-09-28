#ifndef NAVE_H
#define NAVE_H

#include "raylib.h"

namespace Juego {
	namespace Nave {
		/*struct Jug {
			Vector2 pos;
			Vector2 tamanio;
		};*/

		struct Jug {
			Vector2 pos;
			Vector2 velocidad;
			float aceleracion;
			float rotacion;
			//Vector3 collider;
			Color color;
		};

		const int cantJug = 2;
		extern float tamanioXJug;
		extern float tamanioYJug;
		extern Jug nave;
		extern Jug crearJugador/*(int numJug)*/;
		extern void moverNave();
		extern void dibujarNave();
		extern void inicializarJug();
	}
}

#endif