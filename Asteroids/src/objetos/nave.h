#ifndef NAVE_H
#define NAVE_H

#include "raylib.h"

namespace Juego {
	namespace Nave {
		struct Jug {
			Vector2 pos;
			Vector2 velocidad;
			Vector2 aceleracion;
			float rotacion;
			Color color;
			Texture2D textura;
			Rectangle posYEscala;
			Rectangle spriteFuente;
			Vector2 origen;
			bool perdio;
			bool gano;
		};

		extern Jug nave;
		extern Vector2 puntoDisparo;
		Jug crearJugador();
		void actualizarNave();
		void dibujarNave();
		void inicializarNave();
		void desinicializarNave();
	}
}

#endif