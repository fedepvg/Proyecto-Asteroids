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
		Vector2 puntoDisparo = {0,0};
		static Vector2 puntoBase1 = {0 , 0};
		static Vector2 puntoBase2 = { 0, 0 };
		static int auxVelocidadX = 0;
		static int auxVelocidadY = 0;
		static Rectangle destRec;
		static Rectangle sourceRec;
		static Vector2 origen;
		Vector2 v1;//vector de la pos al punto de disparo
		Vector2 v2;//vector de la pos a la pos del mouse

		Jug crearJugador(){	
			nave.pos.x = (float)GetScreenWidth() / 2;
			nave.pos.y = (float)GetScreenHeight() / 2 - altoNave / 2;
			nave.velocidad = { 0, 0 };
			nave.aceleracion = 0;
			nave.rotacion = 0.0f;
			//nave.collider = { player.position.x + sin(player.rotation*DEG2RAD)*(shipHeight / 2.5f), player.position.y - cos(player.rotation*DEG2RAD)*(shipHeight / 2.5f), 12 };
			nave.color = BLACK;

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
			v1.x = puntoDisparo.x - nave.pos.x;
			v1.y= puntoDisparo.y - nave.pos.y;

			v2.x= GetMouseX() - nave.pos.x;
			v2.y= GetMouseY() - nave.pos.y;
			
			float prodVec;
			float moduloV1;
			float moduloV2;
			float prodMod;
			prodVec = v1.x*v2.x + v1.y*v2.y;
			moduloV1 = sqrt(pow(v1.x, 2) + pow(v1.y, 2));
			moduloV2 = sqrt(pow(v2.x, 2) + pow(v2.y, 2));
			prodMod = moduloV1 * moduloV2;
			nave.rotacion = acos(prodVec/(prodMod));
			nave.rotacion *= RAD2DEG;

			/*nave.rotacion = (acos((prodVec)/
								(sqrt(pow(v1.x,2)+ pow(v1.y, 2)))*(sqrt(pow(v2.x, 2) + pow(v2.y, 2)))));*/
			std::cout << nave.rotacion << std::endl;

			//ROTACION TECLADO---------------------------------------------
			/*if (IsKeyDown(KEY_LEFT)) nave.rotacion -= ANGULO_ROTACION;
			if (IsKeyDown(KEY_RIGHT)) nave.rotacion += ANGULO_ROTACION;*/

			//ROTACION MOUSE--------------------------------------------------
			
		
			//MOVIMIENTO TECLADO-------------------------------------------
			/*if (IsKeyDown(KEY_UP))
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
			destRec.x = nave.pos.x;
			destRec.y = nave.pos.y;*/
		}

		//MOVIMIENTO MOUSE---------------------------------------------------------


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
			moverPuntosNave();
			moverNave();
			chequearColisionBordes();
		}

		void dibujarNave() {
			DrawTriangle(puntoDisparo, puntoBase1, puntoBase2, nave.color);
			DrawTexturePro(nave.textura, sourceRec, destRec, origen ,nave.rotacion, WHITE);
		}

		void inicializarNave() {
			tamanioBaseNave = 0.035f*(float)(GetScreenWidth());
			altoNave = (tamanioBaseNave / 2) / tanf(30 * DEG2RAD);
			nave.textura = LoadTexture("res/nave.png");
			crearJugador();
			destRec = { nave.pos.x, nave.pos.y, (float) nave.textura.width* 2, (float)nave.textura.height * 2 };
			sourceRec= { 0.0f,0.0f, (float)nave.textura.width, (float)nave.textura.height};
			origen = { (float)nave.textura.width,(float)nave.textura.height};
			SetMousePosition(nave.pos);
		}

		void desinicializarNave() {
			UnloadTexture(nave.textura);
		}
	}
}