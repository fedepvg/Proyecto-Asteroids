#include "asteroides.h"

#include "raylib.h"

namespace Juego {
	namespace Asteroides {
		static void chequearColisionBordes();
		static void moverAsteroides();
		static void crearAsteroides();
		const int maxAstGrandes = 4;
		const int maxAstMedianos = maxAstGrandes*2;
		const int maxAstChicos = maxAstMedianos*2;
		static const int velocidadAst = 200;
		static int radioAstGrandes = 40;
		static int radioAstMedianos = radioAstGrandes / 2;
		static int radioAstChicos = radioAstMedianos / 2;

		Asteroides asteroideGrande[maxAstGrandes];
		Asteroides asteroideMediano[maxAstMedianos];
		Asteroides asteroideChico[maxAstChicos];

		void chequearColisionBordes() {
			for (int i = 0; i < maxAstGrandes; i++)
			{
				if (asteroideGrande[i].activar)
				{
					if (asteroideGrande[i].posicion.x <0 - asteroideGrande[i].radio)
					{
						asteroideGrande[i].posicion.x = GetScreenWidth() + asteroideGrande[i].radio;
					}
					else if (asteroideGrande[i].posicion.x >  GetScreenWidth() + asteroideGrande[i].radio) {
						asteroideGrande[i].posicion.x = -asteroideGrande[i].radio;
					}

					if (asteroideGrande[i].posicion.y < 0 - asteroideGrande[i].radio)
					{
						asteroideGrande[i].posicion.y = GetScreenHeight() + asteroideGrande[i].radio;
					} 
					else if (asteroideGrande[i].posicion.y > GetScreenHeight() + asteroideGrande[i].radio) {
						asteroideGrande[i].posicion.y = -asteroideGrande[i].radio;
					}
				}
			}
			for (int i = 0; i < maxAstMedianos; i++)
			{
				if (asteroideMediano[i].activar)
				{
					if (asteroideMediano[i].posicion.x <= 0 - asteroideMediano[i].radio)
					{
						asteroideMediano[i].posicion.x = GetScreenWidth() + asteroideGrande[i].radio;
					}
					else if (asteroideMediano[i].posicion.x >= GetScreenWidth() + asteroideMediano[i].radio) {
						asteroideMediano[i].posicion.x = - asteroideMediano[i].radio;
					}

					if (asteroideMediano[i].posicion.y <= 0 - asteroideMediano[i].radio)
					{
						asteroideMediano[i].posicion.y = GetScreenHeight() + asteroideGrande[i].radio;
					}
					else if (asteroideMediano[i].posicion.y >= GetScreenHeight()) {
						asteroideMediano[i].posicion.y =  - asteroideMediano[i].radio;
					}
				}
			}
			for (int i = 0; i < maxAstChicos; i++)
			{
				if (asteroideChico[i].activar)
				{
					if (asteroideChico[i].posicion.x <= 0 - asteroideChico[i].radio)
					{
						asteroideChico[i].posicion.x = GetScreenWidth() + asteroideChico[i].radio;
					} 
					else if (asteroideChico[i].posicion.x >= GetScreenWidth() + asteroideChico[i].radio){
						asteroideChico[i].posicion.x = -asteroideChico[i].radio;
					}

					if (asteroideChico[i].posicion.y <=0 - asteroideChico[i].radio)
					{
						asteroideChico[i].posicion.y = GetScreenHeight() + asteroideChico[i].radio;
					} 
					else if (asteroideChico[i].posicion.y >= GetScreenHeight() + asteroideChico[i].radio) {
						asteroideChico[i].posicion.y = -asteroideChico[i].radio;
					}
				}
			}
		}

		void crearAsteroides() {
			for (int i = 0; i < maxAstGrandes; i++)
			{
				do {
					asteroideGrande[i].posicion.x = GetRandomValue(0,GetScreenWidth());
					asteroideGrande[i].posicion.y = GetRandomValue(0, GetScreenHeight());
				} while (asteroideGrande[i].posicion.x<(GetScreenWidth()/4)*3 && asteroideGrande[i].posicion.x > (GetScreenWidth() / 4) * 2 &&
						asteroideGrande[i].posicion.y<(GetScreenHeight() / 4) * 3 && asteroideGrande[i].posicion.y >(GetScreenHeight() / 4) * 2);
				do {
					asteroideGrande[i].velocidad.x =  GetRandomValue(-velocidadAst,velocidadAst);
					asteroideGrande[i].velocidad.y = GetRandomValue(-velocidadAst, velocidadAst);
				} while (asteroideGrande[i].velocidad.x == 0 || asteroideGrande[i].velocidad.y == 0);
				
				asteroideGrande[i].radio = radioAstGrandes;
				asteroideGrande[i].activar = true;
				asteroideGrande[i].color=MAROON;
				asteroideGrande[i].textura = LoadTexture("res/asteroideGrande.png");
			}

			for (int i = 0; i < maxAstMedianos; i++)
			{
				asteroideMediano[i].posicion = { 0,0 };
				asteroideMediano[i].velocidad = { 0,0 };
				asteroideMediano[i].radio = radioAstMedianos;
				asteroideMediano[i].activar = false;
				asteroideMediano[i].color = RAYWHITE;
				asteroideMediano[i].textura = LoadTexture("res/asteroideMed.png");
			}

			for (int i = 0; i < maxAstChicos; i++)
			{
				asteroideChico[i].posicion = { 0,0 };
				asteroideChico[i].velocidad = { 0,0 };
				asteroideChico[i].radio = radioAstChicos;
				asteroideChico[i].activar = false;
				asteroideChico[i].color = RAYWHITE;
				asteroideChico[i].textura = LoadTexture("res/asteroideChico.png");
			}
		}

		void desinicializarAsteroides() {
			for (int i = 0; i < maxAstGrandes; i++)
			{
				UnloadTexture(asteroideGrande[i].textura);
			}

			for (int i = 0; i < maxAstMedianos; i++)
			{
				UnloadTexture(asteroideMediano[i].textura);
			}

			for (int i = 0; i < maxAstChicos; i++)
			{
				UnloadTexture(asteroideChico[i].textura);
			}
		}

		void moverAsteroides() {
			chequearColisionBordes();
			
			for (int i = 0; i < maxAstGrandes; i++)
			{
				if (asteroideGrande[i].activar)
				{
					asteroideGrande[i].posicion.x += asteroideGrande[i].velocidad.x*GetFrameTime();
					asteroideGrande[i].posicion.y += asteroideGrande[i].velocidad.y*GetFrameTime();
				}
			}
			for (int i = 0; i < maxAstMedianos; i++)
			{
				if (asteroideMediano[i].activar)
				{
					asteroideMediano[i].posicion.x += asteroideMediano[i].velocidad.x*GetFrameTime();
					asteroideMediano[i].posicion.y += asteroideMediano[i].velocidad.y*GetFrameTime();
				}
			}
			for (int i = 0; i < maxAstChicos; i++)
			{
				if (asteroideChico[i].activar)
				{
					asteroideChico[i].posicion.x += asteroideChico[i].velocidad.x*GetFrameTime();
					asteroideChico[i].posicion.y += asteroideChico[i].velocidad.y*GetFrameTime();
				}
			}
		}

		void inicializarAsteroides() {
			radioAstGrandes = 0.00008f*(float)(GetScreenWidth()*GetScreenHeight());
			radioAstMedianos = radioAstGrandes / 2;
			radioAstChicos = radioAstMedianos / 2;
			crearAsteroides();
		}

		void actualizarAsteroides() {
			moverAsteroides();
			chequearColisionBordes();
		}

		void dibujarAsteroides(){
			for (int i = 0; i < maxAstGrandes; i++)
			{
				if (asteroideGrande[i].activar)
				{
					DrawCircle(asteroideGrande[i].posicion.x, asteroideGrande[i].posicion.y,asteroideGrande[i].radio,asteroideGrande[i].color);
				}
			}
			for (int i = 0; i < maxAstMedianos; i++)
			{
				if (asteroideMediano[i].activar)
				{
					DrawCircle(asteroideMediano[i].posicion.x, asteroideMediano[i].posicion.y, asteroideMediano[i].radio, asteroideMediano[i].color);
				}
			}
			for (int i = 0; i < maxAstChicos; i++)
			{
				if (asteroideChico[i].activar)
				{
					DrawCircle(asteroideChico[i].posicion.x, asteroideChico[i].posicion.y, asteroideChico[i].radio, asteroideChico[i].color);
				}
			}
		}
	}
}