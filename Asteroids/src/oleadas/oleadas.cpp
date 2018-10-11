#include "oleadas.h"

#include "raylib.h"
#include "objetos/asteroides.h"
#include "objetos/nave.h"

namespace Juego {
	namespace Oleadas {
		using namespace Asteroides;
		using namespace Nave;

		const int cantOleadas = 10;
		float temporizador;
		bool nuevaOleada=false;
		Oleadas oleada[cantOleadas];
		int oleadaActual;
		static void inicializarNuevaOleada();

		void inicializarOleadas() {
			
			for (int i = 0; i < cantOleadas; i++){
				if (i == 0) {
					oleada[i].maxAstPosibles = 4;
					oleada[i].activa = true;
					oleada[i].duracion = 2.0f;
				}else {
					oleada[i].maxAstPosibles = oleada[i-1].maxAstPosibles + 4;
					oleada[i].activa = false;
					oleada[i].duracion = oleada[i - 1].duracion + 0.5f;
				}
			}
			for (int i = 0; i < oleada[oleadaActual].maxAstPosibles; i++) {
				asteroide[i].activo = true;
			}
			temporizador =oleada[0].duracion;
			nuevaOleada = false;
			oleadaActual = 0;
		}

		void inicializarNuevaOleada() {
			nuevaOleada = false;
			temporizador = oleada[oleadaActual].duracion;

			for (int i = oleada[oleadaActual - 1].maxAstPosibles; i < oleada[oleadaActual].maxAstPosibles; i++){
				asteroide[i].activo = true;
			}
		}

		void actualizarOleadas() {
			if (nuevaOleada) {
				inicializarNuevaOleada();
			}

			if (asteroidesDestruidos == oleada[oleadaActual].maxAstPosibles) {
				nave.gano = true;
			}else {
				temporizador -= GetFrameTime();
				if (temporizador <= 0) {
					if (oleadaActual < cantOleadas - 1) {
						oleadaActual++;
						nuevaOleada = true;
					}
				}
			}
		}
	}
}