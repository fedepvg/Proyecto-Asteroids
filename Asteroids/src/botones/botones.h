#ifndef BOTONES_H
#define BOTONES_H

#include <string>

#include "raylib.h"

namespace Juego {
	namespace Botones {
		enum opcionesMenu { opcJugar, opcCreditos, opcSalir };
		enum opcionesJuego { opcPausa, opcSilenciar};
		enum opcionesGO { opcVolverMenu, opcNuevaPartida, opcSalirGO };
		enum opcionesCreditos {opcVolver};
		struct Botones {
			Rectangle posYTamanio;
			bool estaSeleccionada;
			std::string opcion;
			float centroX;
			float centroY;
		};

		void inicializarBotones();
		void actualizarBotones();
		void dibujarBotones();
	}
}

#endif