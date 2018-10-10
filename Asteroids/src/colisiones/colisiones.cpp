#include "colisiones.h"

#include "objetos/asteroides.h"
#include "objetos/disparo.h"
#include "objetos/nave.h"

namespace Juego {
	namespace Colisiones {
		using namespace Asteroides;
		using namespace Nave;
		using namespace Disparo;

		void actualizarColisiones() {
			//Nave con asteroides------------------------------
			for (int i = 0; i < maxAstGrandes; i++)	{
				if (CheckCollisionCircles(nave.pos, nave.escalaYPos.width / 2, asteroideGrande[i].pos, asteroideGrande[i].radio)) {
					nave.perdio = true;
					break;
				}
			}
			
			for (int i = 0; i < maxAstMedianos; i++) {
				if (CheckCollisionCircles(nave.pos, nave.escalaYPos.width / 2, asteroideMediano[i].pos, asteroideMediano[i].radio)) {
					nave.perdio = true;
					break;
				}
			}

			for (int i = 0; i < maxAstChicos; i++) {
				if (CheckCollisionCircles(nave.pos, nave.escalaYPos.width / 2, asteroideChico[i].pos, asteroideChico[i].radio)) {
					nave.perdio = true;
					break;
				}
			}

			//Asteroides con disparos----------------------------
			for (int i = 0; i < maxAstGrandes; i++) {
				for (int j = 0; j < cantMaxDisparos; j++)
				{
					if (CheckCollisionCircles(disparo[j].pos, disparo[j].radio, asteroideGrande[i].pos, asteroideGrande[i].radio)) {
						
						break;
					}
				}	
			}

			for (int i = 0; i < maxAstMedianos; i++) {
				for (int j = 0; j < cantMaxDisparos; j++) {
					if (CheckCollisionCircles(disparo[j].pos, disparo[j].radio, asteroideMediano[i].pos, asteroideMediano[i].radio)) {
						
						break;
					}
				}	
			}

			for (int i = 0; i < maxAstChicos; i++) {
				for (int j = 0; j < cantMaxDisparos; j++) {
					if (CheckCollisionCircles(disparo[j].pos, disparo[j].radio, asteroideChico[i].pos, asteroideChico[i].radio)) {
						
						break;
					}
				}
			}
		}
	}
}