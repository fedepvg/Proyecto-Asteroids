#include "nave.h"

#include <cmath>
#include <iostream>

#include "raylib.h"
#include "pantallas/pantallaJuego.h"

namespace Juego {
	namespace Nave {
#define ANGULO_ROTACION  300 * GetFrameTime();

		void calcuarAngRotacion();
		void moverNave();
		void chequearColisionBordes();
		Jug nave;
		static float altoNave;
		static float tamanioBaseNave;
		static const float velocidadBase = 30.0f;
		static const float aceleracionBase = 2.5f;
		static const int cantMaxDisparos = 10;
		Vector2 puntoDisparo = {0,0};
		static Vector2 puntoBase1 = {0 , 0};
		static Vector2 puntoBase2 = { 0, 0 };
		static int auxVelocidadX = 0;
		static int auxVelocidadY = 0;
		static Rectangle destRec;
		static Rectangle sourceRec;
		static Vector2 origen;
		static Vector2 v1;		//vector de la nave.pos al x=0 y=nave.pos
		static Vector2 v2;		//vector de la nave.pos a la pos del mouse
		static float prodVec;
		static float moduloV1;
		static float moduloV2;
		static float prodMod;
			

		Jug crearJugador(){	
			nave.pos.x = (float)GetScreenWidth() / 2;
			nave.pos.y = (float)GetScreenHeight() / 2 - altoNave / 2;
			nave.velocidad = { 0, 0 };
			nave.aceleracion = 0;
			nave.rotacion = 0.0f;
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
				nave.pos.y = 0+5;
			}
		}

		void calcuarAngRotacion() {
			v1.x = nave.pos.x - nave.pos.x;
			v1.y = 0.0f - nave.pos.y;

			v2.x = GetMouseX() - nave.pos.x;
			v2.y = GetMouseY() - nave.pos.y;

			prodVec = v1.x*v2.x + v1.y*v2.y;
			moduloV1 = sqrt(pow(v1.x, 2) + pow(v1.y, 2));
			moduloV2 = sqrt(pow(v2.x, 2) + pow(v2.y, 2));
			prodMod = moduloV1 * moduloV2;
			nave.rotacion = acos(prodVec / (prodMod));

			nave.rotacion *= RAD2DEG;

			if (GetMouseX() < nave.pos.x) {
				nave.rotacion = 360 - nave.rotacion;
			}
		}

		void moverNave() {
			//ROTACION MOUSE--------------------------------------------------
			calcuarAngRotacion();	
			
			std::cout << nave.rotacion << std::endl;			
		
			//MOVIMIENTO TECLADO-------------------------------------------
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
			float a = (GetScreenWidth()*GetScreenHeight())*0.01/100;
			if (moduloV2 < a) {
				if (moduloV2 <= 1) {
					nave.aceleracion = 0;
				}
				else {
					if (nave.aceleracion > 0) {
						nave.aceleracion -= aceleracionBase * GetFrameTime();
					}
					else {
						nave.aceleracion = 0;
					}
				}
			}
			
			nave.pos.x += (nave.velocidad.x * nave.aceleracion);
			nave.pos.y -= (nave.velocidad.y * nave.aceleracion);
			destRec.x = nave.pos.x;
			destRec.y = nave.pos.y;
		}

		//MOVIMIENTO MOUSE---------------------------------------------------------


		void actualizarNave() {
			moverNave();
			chequearColisionBordes();
		}

		void dibujarNave() {
			//DrawTriangle(puntoDisparo, puntoBase1, puntoBase2, nave.color);
			DrawTexturePro(nave.textura, sourceRec, destRec, origen ,nave.rotacion, WHITE);
		}

		void inicializarNave() {
			tamanioBaseNave = 0.035f*(float)(GetScreenWidth());
			altoNave = (tamanioBaseNave / 2) / tanf(30 * DEG2RAD);
			nave.textura = LoadTexture("res/nave.png");
			crearJugador();
			destRec = { nave.pos.x, nave.pos.y, (float)nave.textura.width * 2, (float)nave.textura.height * 2 };
			sourceRec = { 0.0f,0.0f, (float)nave.textura.width, (float)nave.textura.height };
			origen = { (float)nave.textura.width,(float)nave.textura.height };
			SetMousePosition({nave.pos.x , nave.pos.y });
		}

		void desinicializarNave() {
			UnloadTexture(nave.textura);
		}
	}
}