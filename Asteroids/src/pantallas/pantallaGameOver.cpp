#include "pantallaGameOver.h"

#include "raylib.h"
#include "Juego/juego.h"
#include "objetos/nave.h"

namespace Juego {
	namespace GameOver {
		void actualizarGO() {
			if (IsKeyPressed(KEY_M)) {
				estado = menu;
			}
			if (IsKeyPressed(KEY_ENTER)) {
				estado = partida;
			}
		}

		void dibujarGO() {
			double tamanioTitulo = (GetScreenHeight()*GetScreenWidth())*0.011 / 100;
			double tamanioSub = (GetScreenHeight()*GetScreenWidth())*0.0055 / 100;
			char ganador[] = "GANADOR: JUGADOR ";
			char subt1[] = "Ganó";
			char subt2[] = "Perdió";
			
			if (Nave::nave.gano) {
				DrawText(subt1, GetScreenWidth() / 9, (GetScreenHeight() / 3) * 2, tamanioSub, DARKGRAY);
			}else {
				DrawText(subt2, GetScreenWidth() / 9, (GetScreenHeight() / 12) * 10, tamanioSub, DARKGRAY);
			}
			
			
		}

	}
}