#include "asteroides.h"

#include "raylib.h"

namespace Juego {
	namespace Asteroides {
		static void chequearColisionBordes();
		static void moverAsteroides();
		static void crearAsteroides();
		const int maxAsteroides = 4;
		static const int velocidadAst = 200;
		static int radioAstGrandes = 40;
		static int radioAstMedianos = radioAstGrandes / 2;
		static int radioAstChicos = radioAstMedianos / 2;
		Texture2D tex;

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

		void crearAsteroides() {
			for (int i = 0; i < maxAsteroides; i++)
			{
				do {
					asteroide[i].pos.x = GetRandomValue(0, GetScreenWidth());
					asteroide[i].pos.y = GetRandomValue(0, GetScreenHeight());
				} while (asteroide[i].pos.x<(GetScreenWidth() / 4) * 3 && asteroide[i].pos.x >(GetScreenWidth() / 4) ||
					asteroide[i].pos.y<(GetScreenHeight() / 4) * 3 && asteroide[i].pos.y >(GetScreenHeight() / 4));
				do {
					asteroide[i].velocidad.x = GetRandomValue(-velocidadAst, velocidadAst);
					asteroide[i].velocidad.y = GetRandomValue(-velocidadAst, velocidadAst);
				} while (asteroide[i].velocidad.x == 0 || asteroide[i].velocidad.y == 0 &&
					asteroide[i].velocidad.x<20 && asteroide[i].velocidad.x>-20 &&
					asteroide[i].velocidad.y < 20 && asteroide[i].velocidad.y>-20);

				asteroide[i].radio = radioAstGrandes;
				asteroide[i].activo = true;
				asteroide[i].color = MAROON;
				asteroide[i].textura = tex;
				asteroide[i].escalaYPos = { 0 , 0 , 0 , 0 };
				asteroide[i].spriteFuente = { 0 , 0 , 0 , 0 };
				asteroide[i].origen = { 0, 0 };
			}
		}

		void desinicializarAsteroides() {
			UnloadTexture(tex);
		}

		void moverAsteroides() {
			chequearColisionBordes();
			
			for (int i = 0; i < maxAsteroides; i++)
			{
				if (asteroide[i].activo)
				{
					asteroide[i].pos.x += asteroide[i].velocidad.x*GetFrameTime();
					asteroide[i].pos.y += asteroide[i].velocidad.y*GetFrameTime();
				}
			}
		}

		void inicializarAsteroides() {
			radioAstGrandes = 0.00008f*(float)(GetScreenWidth()*GetScreenHeight());
			radioAstMedianos = radioAstGrandes / 2;
			radioAstChicos = radioAstMedianos / 2;
			tex = LoadTexture("res/asteroideGrande.png");
			crearAsteroides();
			int asteroidesMedActivos = 0;
			int asteroidesChicosActivos = 0;
			int asteroidesDestruidos = 0;
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
					DrawTextureRec(tex, { 0.0f, 0.0f, (float)tex.width, (float)tex.height }, {asteroide[i].pos.x - tex.width / 2,asteroide[i].pos.y - tex.height/2}, WHITE);
				}
			}
		}
	}
}