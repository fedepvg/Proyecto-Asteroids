#include "pantallaGameOver.h"

#include "raylib.h"
#include "Juego/juego.h"

namespace Juego {
	namespace GameOver {
		void realizarIngresoGO() {

		}

		void actualizarGO() {
			if (IsKeyPressed(KEY_M)) {
				estado = menu;
			}
			if (IsKeyPressed(KEY_ENTER)) {
				estado = partida;
			}
		}

		void dibujarGO() {
			/*double tamanioTitulo = (GetScreenHeight()*GetScreenWidth())*0.011 / 100;
			double tamanioSub = (GetScreenHeight()*GetScreenWidth())*0.0055 / 100;
			char ganador[] = "GANADOR: JUGADOR ";
			char subt1[] = "Para volver al menu, presione M";
			char subt2[] = "Para volver a jugar, presione Enter";

			DrawText(FormatText("GANADOR: JUGADOR %i", PantallaJuego::jugGanador), (GetScreenWidth() - MeasureText(ganador, tamanioTitulo)) / 2, (GetScreenHeight() - tamanioTitulo) / 2, tamanioTitulo, DARKGRAY);
			DrawText(subt1, GetScreenWidth() / 9, (GetScreenHeight() / 3) * 2, tamanioSub, DARKGRAY);
			DrawText(subt2, GetScreenWidth() / 9, (GetScreenHeight() / 12) * 10, tamanioSub, DARKGRAY);*/
		}

	}
}