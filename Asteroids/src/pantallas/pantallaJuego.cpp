#include "pantallaJuego.h"

#include "raylib.h"
#include "Juego/juego.h"
#include "objetos/nave.h"
#include "objetos/asteroides.h"
#include "objetos/disparo.h"
#include "colisiones/colisiones.h"
#include "oleadas/oleadas.h"

namespace Juego {
	namespace PantallaJuego {
		using namespace Asteroides;
		using namespace Nave;
		using namespace Disparo;
		using namespace Colisiones;
		using namespace Oleadas;

		static bool jugadorPerdio();

		using namespace Juego;
		static bool estaInicializado = false;
		fases fase = inicio;
		static bool desinicializar = false;
		static int opcionElegida = 0;

		bool jugadorPerdio() {
			if (nave.perdio||nave.gano){
				return true;
			}
			else {
				return false;
			}	
		}

		void actualizarJuego() {
			actualizarNave();
			actualizarDisparos();
			actualizarAsteroides();
			actualizarOleadas();
			actualizarColisiones();
			if (jugadorPerdio()) {
				if (!desinicializar) {
					desinicializar = true;
				}else {
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
				}else {
					estado = menu;
					estaInicializado = false;
					desinicializar = false;
					opcionElegida = 0;
				}
			}
		}

		void dibujarJuego() {
			dibujarDisparos();
			dibujarNave();
			dibujarAsteroides();
			
			char instrucciones[] = "El Jugador se mueve con el click derecho del mouse y dispara con el izquierdo";
			char menu[] = "Pulse M para volver al menu";

			const double tamanioLetras = (GetScreenHeight()*GetScreenWidth())*0.0037 / 100;
			DrawText(instrucciones, 0 + tamanioLetras, GetScreenHeight() - tamanioLetras, tamanioLetras, DARKGRAY);
			DrawText(menu, GetScreenWidth() - MeasureText(menu, tamanioLetras), GetScreenHeight() - tamanioLetras, tamanioLetras, DARKGRAY);
			DrawText(FormatText("%f", temporizador),0+tamanioLetras,0+tamanioLetras,tamanioLetras,DARKGRAY);
		}

		void inicializarPantJuego() {
			if (!estaInicializado) {
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