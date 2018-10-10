#include "asteroides.h"

#include "raylib.h"

namespace Juego {
	namespace Asteroides {
		static void chequearColisionBordes();
		static bool chequearPosNuevoAst(int i);
		static bool chequearVelNuevoAst(int i);
		static void moverAsteroides();
		static void crearAsteroides();
		const int maxAsteroides = 4;
		static const int velocidadAst = 200;
		static int radioMaxAst = 8;
		static int radioMinAst = 4;
		static Texture2D spriteAsteroide;
		int asteroidesDestruidos = 0;

		Asteroides asteroide[maxAsteroides];

		void chequearColisionBordes() {
			for (int i = 0; i < maxAsteroides; i++)
			{
				if (asteroide[i].activo)
				{
					if (asteroide[i].pos.x <0 - asteroide[i].radio)
					{
						asteroide[i].pos.x = GetScreenWidth() + asteroide[i].radio;
					}
					else if (asteroide[i].pos.x >  GetScreenWidth() + asteroide[i].radio) {
						asteroide[i].pos.x = -asteroide[i].radio;
					}

					if (asteroide[i].pos.y < 0 - asteroide[i].radio)
					{
						asteroide[i].pos.y = GetScreenHeight() + asteroide[i].radio;
					} 
					else if (asteroide[i].pos.y > GetScreenHeight() + asteroide[i].radio) {
						asteroide[i].pos.y = -asteroide[i].radio;
					}
				}
			}
		}
		
		bool chequearPosNuevoAst(int i) {
			if (asteroide[i].pos.x<(GetScreenWidth() / 4) * 3 && asteroide[i].pos.x >(GetScreenWidth() / 4) ||
				asteroide[i].pos.y<(GetScreenHeight() / 4) * 3 && asteroide[i].pos.y >(GetScreenHeight() / 4)){
				return true;
			}
			return false;
		}

		bool chequearVelNuevoAst(int i) {
			if (asteroide[i].velocidad.x == 0 || asteroide[i].velocidad.y == 0 &&
				asteroide[i].velocidad.x < 20 && asteroide[i].velocidad.x>-20 &&
				asteroide[i].velocidad.y < 20 && asteroide[i].velocidad.y>-20) {
				return true;
			}
			return false;
		}

		void crearAsteroides() {
			for (int i = 0; i < maxAsteroides; i++)
			{
				do {
					asteroide[i].pos.x = GetRandomValue(0, GetScreenWidth());
					asteroide[i].pos.y = GetRandomValue(0, GetScreenHeight());
				} while (chequearPosNuevoAst(i));
				do {
					asteroide[i].velocidad.x = GetRandomValue(-velocidadAst, velocidadAst);
					asteroide[i].velocidad.y = GetRandomValue(-velocidadAst, velocidadAst);
				} while (chequearVelNuevoAst(i));

				asteroide[i].radio =(GetRandomValue(radioMinAst,radioMaxAst)/100000.0f) *(float)(GetScreenWidth()*GetScreenHeight());
				asteroide[i].activo = true;
				asteroide[i].color = MAROON;
				asteroide[i].textura = spriteAsteroide;
				asteroide[i].posYEscala = { asteroide[i].pos.x , asteroide[i].pos.y , asteroide[i].radio*2 , asteroide[i].radio*2 };
				asteroide[i].spriteFuente = { 0.0f , 0.0f , (float)spriteAsteroide.width , (float)spriteAsteroide.height };
				asteroide[i].origen = { asteroide[i].radio , asteroide[i].radio };
			}
		}

		void desinicializarAsteroides() {
			UnloadTexture(spriteAsteroide);
		}

		void moverAsteroides() {
			chequearColisionBordes();
			
			for (int i = 0; i < maxAsteroides; i++)
			{
				if (asteroide[i].activo)
				{
					asteroide[i].pos.x += asteroide[i].velocidad.x*GetFrameTime();
					asteroide[i].pos.y += asteroide[i].velocidad.y*GetFrameTime();
					asteroide[i].posYEscala.x = asteroide[i].pos.x;
					asteroide[i].posYEscala.y = asteroide[i].pos.y;
				}
			}
		}

		void inicializarAsteroides() {
			spriteAsteroide = LoadTexture("res/asteroide.png");
			crearAsteroides();
			asteroidesDestruidos = 0;
		}

		void actualizarAsteroides() {
			moverAsteroides();
			chequearColisionBordes();
		}

		void dibujarAsteroides(){
			for (int i = 0; i < maxAsteroides; i++)
			{
				if (asteroide[i].activo)
				{
					DrawCircle(asteroide[i].pos.x, asteroide[i].pos.y, asteroide[i].radio, asteroide[i].color);
					DrawTexturePro(asteroide[i].textura, asteroide[i].spriteFuente, asteroide[i].posYEscala, asteroide[i].origen,0.0f, WHITE);
				}
			}
		}
	}
}