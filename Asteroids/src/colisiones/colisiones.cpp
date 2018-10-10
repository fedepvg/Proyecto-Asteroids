#include "colisiones.h"

#include "objetos/asteroides.h"
#include "objetos/disparo.h"
#include "objetos/nave.h"

namespace Juego {
	namespace Colisiones {
		using namespace Asteroides;
		using namespace Nave;
		using namespace Disparo;
		int asteroidesChicosActivos;
		int asteroidesDestruidos;
		int asteroidesMedActivos;

		void actualizarColisiones() {
			//Nave con asteroides------------------------------
			for (int i = 0; i < maxAsteroides; i++)	{
				if (CheckCollisionCircles(nave.pos, nave.escalaYPos.width / 2, asteroide[i].pos, asteroide[i].radio)) {
					nave.perdio = true;
					break;
				}
			}

			//Asteroides con disparos----------------------------
			for (int i = 0; i < maxAsteroides; i++) {
				for (int j = 0; j < cantMaxDisparos; j++)
				{
					if (disparo[j].activo&&asteroide[i].activo) {
						if (CheckCollisionCircles(disparo[j].pos, disparo[j].radio, asteroide[i].pos, asteroide[i].radio)) {
							asteroidesDestruidos++;
							disparo[j].activo = false;
							asteroide[i].activo = false;
							break;
						}
					}
				}	
			}
		}
	}
}