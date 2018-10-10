#include "disparo.h"

#include <cmath>

#include "raylib.h"
#include "nave.h"

namespace Juego {
	namespace Disparo {
		using namespace Nave;

		static void crearDisparos();
		static void disparar();
		static void chequearColisionBordes();
		static void moverDisparos();
		static const float velocidadDisparo = 750;
		int radioDisparo = 0;
		const int cantMaxDisparos=4;
		Balas disparo[cantMaxDisparos];

		void crearDisparos() {
			for (int i = 0; i < cantMaxDisparos; i++)
			{
				disparo[i].pos = {0, 0};
				disparo[i].velocidad = {0,0};
				disparo[i].radio=2;
				disparo[i].rotacion=0.0f;
				disparo[i].activado=false;
				disparo[i].color=BLACK;
			}
		}

		void inicializarDisparos() {
			radioDisparo = 0.000008*((float)GetScreenWidth()*GetScreenHeight());
			crearDisparos();
		}

		void actualizarDisparos(){
			disparar();
			moverDisparos();
			chequearColisionBordes();
		}

		void disparar() {
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				for (int i = 0; i < cantMaxDisparos; i++)
				{
					if (!disparo[i].activado) {
						disparo[i].pos = nave.pos;
						disparo[i].activado = true;
						disparo[i].velocidad.x =sin(nave.rotacion*DEG2RAD)*velocidadDisparo;
						disparo[i].velocidad.y =cos(nave.rotacion*DEG2RAD)*velocidadDisparo;
						disparo[i].rotacion = nave.rotacion;
						break;
					}
				}
			}
		}

		void chequearColisionBordes() {
			for (int i = 0; i < cantMaxDisparos; i++)
			{
				if (disparo[i].activado) {
					if (disparo[i].pos.x < 0)
					{
						disparo[i].activado = false;
					}
					else if (disparo[i].pos.x > GetScreenWidth()) {
						disparo[i].activado = false;
					}

					if (disparo[i].pos.y < 0)
					{
						disparo[i].activado = false;
					}
					else if (disparo[i].pos.y > GetScreenHeight()) {
						disparo[i].activado = false;
					}
				}
			}
		}

		void moverDisparos() {
			for (int i = 0; i < cantMaxDisparos; i++)
			{
				if (disparo[i].activado) {
					disparo[i].pos.x += disparo[i].velocidad.x*GetFrameTime();
					disparo[i].pos.y -= disparo[i].velocidad.y*GetFrameTime();
				}
			}
		}

		void dibujarDisparos() {
			for (int i = 0; i < cantMaxDisparos; i++)
			{
				if (disparo[i].activado) {
					DrawCircle(disparo[i].pos.x, disparo[i].pos.y,disparo[i].radio,disparo[i].color);
				}
			}
		}
	}
}