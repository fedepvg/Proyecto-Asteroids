#ifndef OLEADAS_H
#define OLEADAS_H

namespace Juego {
	namespace Oleadas {
		struct Oleadas {
			float duracion;
			int maxAstPosibles;
			bool activa;
		};

		extern const int cantOleadas;
		extern float temporizador;
		extern Oleadas oleada[];
		extern int oleadaActual;
		void inicializarOleadas();
		void actualizarOleadas();
	}
}

#endif