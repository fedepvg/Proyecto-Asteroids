#ifndef OLEADAS_H
#define OLEADAS_H

namespace Juego {
	namespace Oleadas {
		struct Oleadas {
			float duracion;
			int maxAstPosibles;
			bool activa;
		};

		#define cantOleadas 10
		extern float temporizador;
		extern Oleadas oleada[];
		extern int oleadaActual;
		void inicializarOleadas();
		void actualizarOleadas();
	}
}

#endif