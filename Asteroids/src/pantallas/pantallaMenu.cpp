#include "pantallaMenu.h"

#include "raylib.h"
#include "Juego/juego.h"

namespace Juego {
	namespace Menu {
		static bool estaInicializado = false;
		static bool desinicializar = false;
		Music musica;
		static int opcionElegida = 0;

		void inicializarMenu() {
			estaInicializado = true;
		}

		void realizarIngresoMenu() {

		}

		void actualizarMenu() {

			if (IsKeyPressed(KEY_ENTER) || opcionElegida == KEY_ENTER) {
				if (!desinicializar) {
					desinicializar = true;
					opcionElegida = KEY_ENTER;
				}
				else {
					estado = partida;
					estaInicializado = false;
					desinicializar = false;
					opcionElegida = 0;
				}
			}
			if (IsKeyPressed(KEY_Q) || opcionElegida == KEY_Q) {
				if (!desinicializar) {
					desinicializar = true;
					opcionElegida = KEY_Q;
				}
				else {
					enJuego = false;
					estaInicializado = false;
					desinicializar = false;
					opcionElegida = 0;
				}
			}
			if (IsKeyPressed(KEY_C) || opcionElegida == KEY_C) {
				if (!desinicializar) {
					desinicializar = true;
					opcionElegida = KEY_C;
				}
				else {
					estado = creditos;
					estaInicializado = false;
					desinicializar = false;
					opcionElegida = 0;
				}
			}
		}

		void dibujarMenu() {
			double tamanioTitulo = (GetScreenHeight()*GetScreenWidth())*0.0190 / 100;
			double tamanioSubtitulos = (GetScreenHeight()*GetScreenWidth())*0.0052 / 100;
			double tamanioVersion = (GetScreenHeight()*GetScreenWidth())*0.0042 / 100.0;
			char titulo[] = "Asteroids";
			char subt1[] = "Para empezar, presione Enter";
			char subt2[] = "Para ver los creditos, presione C";
			char subt3[] = "Para salir, presione Q";
			char version[] = "Asteroids v0.2";
			DrawText(titulo, (GetScreenWidth() - MeasureText(titulo, tamanioTitulo)) / 2, (GetScreenHeight() - tamanioTitulo) / 2, tamanioTitulo, DARKGRAY);
			DrawText(subt1, 0 + tamanioSubtitulos, GetScreenHeight() - tamanioSubtitulos * 3, tamanioSubtitulos, DARKGRAY);
			DrawText(subt2, 0 + tamanioSubtitulos, GetScreenHeight() - tamanioSubtitulos * 2, tamanioSubtitulos, DARKGRAY);
			DrawText(subt3, 0 + tamanioSubtitulos, GetScreenHeight() - tamanioSubtitulos, tamanioSubtitulos, DARKGRAY);
			DrawText(version, GetScreenWidth() - MeasureText(version, tamanioVersion), 0 + tamanioVersion, (int)tamanioVersion, DARKGRAY);
		}

		void desinicializarMenu() {
			
		}
	}
}