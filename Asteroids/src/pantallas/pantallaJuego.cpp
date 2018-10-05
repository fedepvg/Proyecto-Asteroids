#include "pantallaJuego.h"

#include "raylib.h"
#include "Juego/juego.h"
#include "objetos/nave.h"
#include "objetos/asteroides.h"
#include "objetos/disparo.h"

namespace Juego {
	namespace PantallaJuego {
		using namespace Asteroides;
		using namespace Nave;
		using namespace Disparo;

		static void chequearColisiones();
		static bool chequearResultado();

		using namespace Juego;
		static bool estaInicializado = false;
		fases fase = inicio;
		static bool desinicializar = false;
		static int opcionElegida = 0;


		void chequearColisiones() {
			
		}

		bool chequearResultado() {

			return false;
		}

		void realizarIngresoPantJuego() {

		}

		void actualizarJuego() {
			actualizarNave();
			actualizarDisparos();
			actualizarAsteroides();
			chequearColisiones();
			if (chequearResultado()) {
				if (!desinicializar) {
					desinicializar = true;
				}
				else {
					fase = fin;
					estado = gameOver;
					estaInicializado = false;
					desinicializar = false;
				}
			}
			if (IsKeyPressed(KEY_M) || opcionElegida == KEY_M) {
				if (!desinicializar) {
					desinicializar = true;
					opcionElegida = KEY_M;
				}
				else {
					estado = menu;
					estaInicializado = false;
					desinicializar = false;
					opcionElegida = 0;
				}
			}
		}

		void dibujarJuego() {
			dibujarNave();
			dibujarAsteroides();
			dibujarDisparos();
			
			char instrucciones[] = "El Jugador se mueve con las flechas";
			char menu[] = "Pulse M para volver al menu";

			const double tamanioLetras = (GetScreenHeight()*GetScreenWidth())*0.0037 / 100;
			DrawText(instrucciones, 0 + tamanioLetras, GetScreenHeight() - tamanioLetras, tamanioLetras, DARKGRAY);
			DrawText(menu, GetScreenWidth() - MeasureText(menu, tamanioLetras), GetScreenHeight() - tamanioLetras, tamanioLetras, DARKGRAY);
		}

		void inicializarPantJuego() {
			if (!estaInicializado) {
				inicializarNave();
				inicializarAsteroides();
				inicializarDisparos();
				fase = inicio;
			}
			estaInicializado = true;
		}

		void desinicializarPantJuego() {
			if (desinicializar) {
				desinicializarNave();
			}
		}
	}
}