#ifndef ASTEROIDES_H
#define ASTEROIDES_H

#include "raylib.h"

namespace Juego {
	namespace Asteroides {
		struct Asteroides {
			Vector2 posicion;
			Vector2 velocidad;
			float radio;
			bool activar;
			Color color;
		};

		extern const int maxAstGrandes;
		extern const int maxAstMedianos;
		extern const int maxAstChicos;
		extern Asteroides asteroideGrande[];
		extern Asteroides asteroideMediano[];
		extern Asteroides asteroideChico[];
		void inicializarAsteroides();
		void actualizarAsteroides();
		void dibujarAsteroides();
	}
}

#endif