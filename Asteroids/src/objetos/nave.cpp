#include "nave.h"

#include <cmath>
#include <iostream>

#include "raylib.h"
#include "pantallas/pantallaJuego.h"

namespace Juego {
	namespace Nave {
#define ANGULO_ROTACION  300 * GetFrameTime();

		static void moverNave();
		static void moverPuntosNave();
		static void chequearColisionBordes();
		Jug nave;
		static float altoNave;
		static float tamanioBaseNave;
		static const float velocidadBase = 50.0f;
		static const float aceleracionBase = 7.0f;
		static const int cantMaxDisparos = 10;
		Vector2 puntoDisparo = { 0,0 };
		static Vector2 puntoBase1 = {0, 0};
		static Vector2 puntoBase2 = { 0, 0 };
		static int auxVelocidadX = 0;
		static int auxVelocidadY = 0;

		Jug crearJugador(){	
			nave.pos.x = (float)GetScreenWidth() / 2;
			nave.pos.y = (float)GetScreenHeight() / 2 - altoNave / 2;
			nave.velocidad = { 0, 0 };
			nave.aceleracion = 0;
			nave.rotacion = 0;
			//nave.collider = { player.position.x + sin(player.rotation*DEG2RAD)*(shipHeight / 2.5f), player.position.y - cos(player.rotation*DEG2RAD)*(shipHeight / 2.5f), 12 };
			nave.color = WHITE;

			return nave;
		}
		
		void chequearColisionBordes() {
			//Colision con bordes
			if (nave.pos.x <= 0) {
				nave.pos.x = GetScreenWidth();
			}
			else if (nave.pos.x >= GetScreenWidth()) {
				nave.pos.x = 0;
			}

			if (nave.pos.y <= 0) {
				nave.pos.y = GetScreenHeight();
			}
			else if (nave.pos.y >= GetScreenHeight()) {
				nave.pos.y = 0;
			}
		}

		void moverNave() {

			//ROTACION---------------------------------------------
			if (IsKeyDown(KEY_LEFT)) nave.rotacion -= ANGULO_ROTACION;
			if (IsKeyDown(KEY_RIGHT)) nave.rotacion += ANGULO_ROTACION;

		
			//MOVIMIENTO--------------------------------------------
			if (IsKeyDown(KEY_UP))
			{
				if (!IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_RIGHT)) {
					nave.velocidad.x = sin(nave.rotacion*DEG2RAD)*velocidadBase;
					nave.velocidad.y = cos(nave.rotacion*DEG2RAD)*velocidadBase;

					auxVelocidadX = nave.velocidad.x;
					auxVelocidadY = nave.velocidad.y;

					nave.velocidad.x *= GetFrameTime();
					nave.velocidad.y *= GetFrameTime();

					if (nave.aceleracion < 10.0f) nave.aceleracion += aceleracionBase *GetFrameTime();
				}
				else {
					nave.velocidad.x = auxVelocidadX*GetFrameTime();
					nave.velocidad.y = auxVelocidadY*GetFrameTime();
					
					if (nave.aceleracion > 0) nave.aceleracion -= aceleracionBase *GetFrameTime();
					else if (nave.aceleracion < 0) nave.aceleracion = 0;
				}
			}
			else
			{
				if (nave.aceleracion > 0) nave.aceleracion -= aceleracionBase *GetFrameTime();
				else if (nave.aceleracion < 0) nave.aceleracion = 0;
			}

			nave.pos.x += (nave.velocidad.x*nave.aceleracion);
			nave.pos.y -= (nave.velocidad.y*nave.aceleracion);
		}

		void moverPuntosNave() {
			// La rotación se calcula como dos circunferencias: una para el punto superior con radio=altura y otra para las bases con radio=base/2
			// Los -90 y +90 son porque la rotación 0 esta corrida -90 en un punto y +90 en el otro
			// Punto de una circunferencia===>	X=posX del centro + sen(ang)*radio
			//									Y=posY del centro + sen(ang)*radio
			//Los cosenos se restan porque el plano es al reves de lo tradicional, es decir, con la y creciente hacia abajo
			puntoDisparo = { nave.pos.x + sinf(nave.rotacion*DEG2RAD)*(altoNave), nave.pos.y - cosf(nave.rotacion*DEG2RAD)*(altoNave) };
			puntoBase1 = { nave.pos.x + sinf((nave.rotacion-135.0)*DEG2RAD)*(tamanioBaseNave/2 ), nave.pos.y - cosf((nave.rotacion-135.0)*DEG2RAD)*(tamanioBaseNave/2) };
			puntoBase2 = { nave.pos.x + sinf((nave.rotacion+135.0)*DEG2RAD)*(tamanioBaseNave/2 ), nave.pos.y - cosf((nave.rotacion+135.0)*DEG2RAD)*(tamanioBaseNave/2) };

		}

		void actualizarNave() {
			moverNave();
			moverPuntosNave();
			chequearColisionBordes();
		}

		void dibujarNave() {
			DrawTriangle(puntoDisparo, puntoBase1, puntoBase2, nave.color);
		}

		void inicializarJug() {
			tamanioBaseNave = 0.035f*(float)(GetScreenWidth());
			altoNave = (tamanioBaseNave / 2) / tanf(30 * DEG2RAD);

			crearJugador();
		}
	}
}