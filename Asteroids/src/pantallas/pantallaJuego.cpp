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
			actualizarBotones();
			if (!pausa) {
				actualizarNave();
				actualizarDisparos();
				actualizarAsteroides();
				actualizarOleadas();
				actualizarColisiones();
			}
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
			if (fase==salirAMenu) {
				if (!desinicializar) {
					desinicializar = true;
				}
				else {
					estado = menu;
					estaInicializado = false;
					desinicializar = false;
				}
			}
				
		}

		void dibujarJuego() {
			dibujarDisparos();
			dibujarNave();
			dibujarAsteroides();
			dibujarBotones();

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
				inicializarBotones();
				fase = juego;
				pausa = false;
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