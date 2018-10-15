#include "oleadas.h"

#include "raylib.h"
#include "objetos/asteroides.h"
#include "objetos/nave.h"

namespace Juego {
	namespace Oleadas {
		using namespace Asteroides;
		using namespace Nave;

		static const int asteroidesPorOleada = 4;
		const int cantOleadas = 10;
		float temporizador;
		bool nuevaOleada=false;
		Oleadas oleada[cantOleadas];
		int oleadaActual;
		static float multiplicadorDeVelocidad = 1.1f;
		static void inicializarNuevaOleada();

		void inicializarOleadas() {
			
			for (int i = 0; i < cantOleadas; i++){
				if (i == 0) {
					oleada[i].maxAstPosibles = asteroidesPorOleada;
					oleada[i].activa = true;
					oleada[i].duracion = 2.0f;
				}else {
					oleada[i].maxAstPosibles = oleada[i-1].maxAstPosibles + asteroidesPorOleada;
					oleada[i].activa = false;
					oleada[i].duracion = oleada[i - 1].duracion + 0.5f;
				}
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
				asteroide[i].velocidad.x *= multiplicadorDeVelocidad;
				asteroide[i].velocidad.y *= multiplicadorDeVelocidad;
			}
		}

		void actualizarOleadas() {
			if (nuevaOleada) {
				inicializarNuevaOleada();
			}

			if (asteroidesDestruidos == oleada[oleadaActual].maxAstPosibles && oleadaActual==cantOleadas-1) {
				nave.gano = true;
			}else {
				if (oleadaActual != cantOleadas - 1) {
					temporizador -= GetFrameTime();
					if (temporizador <= 0 || asteroidesDestruidos == oleada[oleadaActual].maxAstPosibles) {
						if (oleadaActual < cantOleadas - 1) {
							oleadaActual++;
							nuevaOleada = true;
							multiplicadorDeVelocidad += 0.1f;
						}
					}
				}else {
					temporizador = 0.0f;
				}
			}
		}
	}
}