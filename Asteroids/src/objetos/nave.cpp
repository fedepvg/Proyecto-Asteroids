#include "nave.h"

#include "pantallas/pantallaJuego.h"

namespace Juego {
	namespace Nave {
		Jug nave;
		float tamanioXJug = 0;
		float tamanioYJug = 0;
		float velocidadJug = 0;
		float rotacion = 0;

		Jug crearJugador(/*int numJug*/) {
			
			nave.pos = { GetScreenWidth()/2, GetScreenHeight()/2 };

			return nave;
		}

		void moverNave() {
			if (IsKeyDown(KEY_UP)) nave.pos.y -= velocidadJug * GetFrameTime();
			if (IsKeyDown(KEY_DOWN)) nave.pos.y += velocidadJug * GetFrameTime();

			if (IsKeyDown(KEY_LEFT)) rotacion -= 150 *GetFrameTime();
			if (IsKeyDown(KEY_RIGHT)) rotacion += 150*GetFrameTime();
		}

		void dibujarNave() {

			//DrawPoly({ 50,50}, 3, 20, rotacion, WHITE);
			//DrawRectangleV(nave.pos, nave.tamanio, WHITE);
		}

		void inicializarJug() {
			tamanioXJug = (float)(GetScreenWidth()*2.0 / 100.0);
			tamanioYJug = (float)(GetScreenHeight()*15.0 / 100.0);
			velocidadJug = (float)(GetScreenHeight() * 80.0 / 100.0);

			crearJugador();
			
			PantallaJuego::fase = PantallaJuego::inicio;
		}
	}
}