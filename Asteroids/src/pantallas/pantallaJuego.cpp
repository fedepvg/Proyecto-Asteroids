#include "pantallaJuego.h"

#include "raylib.h"
#include "Juego/juego.h"
#include "objetos/nave.h"
#include "objetos/asteroides.h"
#include "objetos/disparo.h"
#include "colisiones/colisiones.h"
#include "oleadas/oleadas.h"
#include "botones/botones.h"

namespace Juego {
	namespace PantallaJuego {
		using namespace Asteroides;
		using namespace Nave;
		using namespace Disparo;
		using namespace Colisiones;
		using namespace Oleadas;
		using namespace Botones;

		using namespace Juego;
		static bool estaInicializado = false;
		fases fase = inicio;
		static bool desinicializar = false;
		static int opcionElegida = 0;
		bool pausa = false;

		static bool jugadorPerdio();

		bool jugadorPerdio() {
			if (nave.perdio||nave.gano){
				return true;
			}
			else {
				return false;
			}	
		}

		void actualizarJuego() {
			if (!pausa) {
				actualizarNave();
				actualizarDisparos();
				actualizarAsteroides();
				actualizarOleadas();
				actualizarColisiones();
				if (jugadorPerdio()) {
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
		}

		void dibujarJuego() {
			dibujarDisparos();
			dibujarNave();
			dibujarAsteroides();

			const double tamanioLetras = (GetScreenHeight()*GetScreenWidth())*0.0042 / 100;

			DrawText(FormatText("%f", temporizador),0+tamanioLetras,0+tamanioLetras,tamanioLetras,DARKGRAY);
			DrawText(FormatText("%i", oleadaActual+1), GetScreenWidth() / 2, 0 + tamanioLetras, tamanioLetras, DARKGRAY);
		}

		void inicializarPantJuego() {
			if (!estaInicializado||fase==inicio) {
				inicializarNave();
				inicializarAsteroides();
				inicializarOleadas();
				inicializarDisparos();
				fase = juego;
			}
			estaInicializado = true;
		}

		void desinicializarPantJuego() {
			if (desinicializar) {
				desinicializarNave();
				desinicializarAsteroides();
			}
		}
	}
}