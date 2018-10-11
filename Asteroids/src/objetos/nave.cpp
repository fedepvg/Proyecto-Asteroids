#include "nave.h"

#include <cmath>

#include "raylib.h"
#include "pantallas/pantallaJuego.h"

namespace Juego {
	namespace Nave {

		void calcuarAngRotacion();
		void moverNave();
		void chequearColisionBordes();
		Jug nave;
		static float altoNave;
		static float tamanioBaseNave;
		static const float aceleracionBase = 100.0f;
		static const float velocidadMax = 200.0f;
		static Vector2 vecReferncia;		//vector de la nave.pos al x=0 y=nave.pos
		static Vector2 vecDireccion;		//vector de la nave.pos a la pos del mouse
		static float prodVec;
		static float moduloV1;
		static float moduloV2;
		static float prodMod;	

		Jug crearJugador(){	
			nave.pos.x = (float)GetScreenWidth() / 2;
			nave.pos.y = (float)GetScreenHeight() / 2 - altoNave / 2;
			nave.velocidad.x = 0.0f;
			nave.velocidad.y= 0.0f;
			nave.aceleracion.x = 0;
			nave.aceleracion.y = 0;
			nave.rotacion = 0.0f;
			nave.color = BLACK;
			nave.textura = LoadTexture("res/nave.png");
			nave.posYEscala = { nave.pos.x, nave.pos.y, (float)nave.textura.width * 2, (float)nave.textura.height * 2 };
			nave.spriteFuente = { 0.0f,0.0f, (float)nave.textura.width, (float)nave.textura.height };
			nave.origen = { (float)nave.textura.width,(float)nave.textura.height };
			nave.perdio = false;
			nave.gano = false;

			return nave;
		}
		
		void chequearColisionBordes() {
			//Colision con bordes
			if (nave.pos.x <= 0) {
				nave.pos.x = GetScreenWidth();
			}else if (nave.pos.x >= GetScreenWidth()) {
				nave.pos.x = 0;
			}

			if (nave.pos.y <= 0) {
				nave.pos.y = GetScreenHeight();
			}else if (nave.pos.y >= GetScreenHeight()) {
				nave.pos.y = 0+5;
			}
		}

		void calcuarAngRotacion() {
			vecReferncia.x = nave.pos.x - nave.pos.x;
			vecReferncia.y = 0.0f - nave.pos.y;

			vecDireccion.x = GetMouseX() - nave.pos.x;
			vecDireccion.y = GetMouseY() - nave.pos.y;

			prodVec = vecReferncia.x*vecDireccion.x + vecReferncia.y*vecDireccion.y;
			moduloV1 = sqrt(pow(vecReferncia.x, 2) + pow(vecReferncia.y, 2));
			moduloV2 = sqrt(pow(vecDireccion.x, 2) + pow(vecDireccion.y, 2));
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

			//MOVIMIENTO MOUSE-------------------------------------------
			if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) {
				nave.aceleracion.x += sin(nave.rotacion*DEG2RAD)*(aceleracionBase*GetFrameTime());
				nave.aceleracion.y += cos(nave.rotacion*DEG2RAD)*(aceleracionBase*GetFrameTime());
				nave.aceleracion.x *= GetFrameTime();
				nave.aceleracion.y *= GetFrameTime();
			}
			else {
				nave.aceleracion = { 0.0f,0.0f };
			}

			nave.velocidad.x += nave.aceleracion.x;
			nave.velocidad.y += nave.aceleracion.y;
			
			if (nave.velocidad.x >= velocidadMax*GetFrameTime()) {
				nave.velocidad.x = velocidadMax*GetFrameTime();
			}else if (nave.velocidad.x <= -velocidadMax * GetFrameTime()) {
				nave.velocidad.x = -velocidadMax * GetFrameTime();
			}
			if(nave.velocidad.y>=velocidadMax*GetFrameTime()){
				nave.velocidad.y = velocidadMax * GetFrameTime();
			}else if (nave.velocidad.y <= -velocidadMax * GetFrameTime()) {
				nave.velocidad.y = -velocidadMax * GetFrameTime();
			}

			nave.pos.x += nave.velocidad.x;
			nave.pos.y -= nave.velocidad.y;
			nave.posYEscala.x = nave.pos.x;
			nave.posYEscala.y = nave.pos.y;
		}

		void actualizarNave() {
			moverNave();
			chequearColisionBordes();
		}

		void dibujarNave() {
			if (!PantallaJuego::pausa) {
				DrawTexturePro(nave.textura, nave.spriteFuente, nave.posYEscala, nave.origen, nave.rotacion, WHITE);
			}else {
				DrawTexturePro(nave.textura, nave.spriteFuente, nave.posYEscala, nave.origen, nave.rotacion, LIGHTGRAY);
			}
			
		}

		void inicializarNave() {
			crearJugador();
		}

		void desinicializarNave() {
			UnloadTexture(nave.textura);
		}
	}
}