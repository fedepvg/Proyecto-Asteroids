#ifndef ASTEROIDES_H
#define ASTEROIDES_H

#include "raylib.h"

namespace Juego {
	namespace Asteroides {
		struct Asteroides {
			Vector2 pos;
			Vector2 velocidad;
			float radio;
			bool activo;
			Color color;
			Texture2D textura;
			Rectangle posYEscala;
			Rectangle spriteFuente;
			Vector2 origen;
		};

		extern int asteroidesDestruidos;
		extern Asteroides asteroide[];
		void inicializarAsteroides();
		void desinicializarAsteroides();
		void actualizarAsteroides();
		void dibujarAsteroides();
	}
}

#endif