#include "nave.h"

#include "pantallas/pantallaJuego.h"

namespace Juego {
	namespace Nave {
		Jug nave;
		float tamanioXJug = 0;
		float tamanioYJug = 0;
		float velocidadJug = 0;
		float rotacion = 0;

		Jug crearJugador(int numJug) {
			if (numJug != 1) {
				nave.pos = { 0 + tamanioXJug, ((float)GetScreenHeight() - tamanioYJug) / 2 };
			}
			else {
				nave.pos = { (float)GetScreenWidth() - 2 * tamanioXJug, ((float)GetScreenHeight() - tamanioYJug) / 2 };
			}

			nave.tamanio = { tamanioXJug, tamanioYJug };

			return nave;
		}

		void moverNave() {
			if (IsKeyDown(KEY_UP)) nave.pos.y -= velocidadJug * GetFrameTime();
			if ((nave.pos.y) <= 0) nave.pos.y = 0;
			if (IsKeyDown(KEY_DOWN)) nave.pos.y += velocidadJug * GetFrameTime();
			if ((nave.pos.y + nave.tamanio.y) >= GetScreenHeight()) nave.pos.y = GetScreenHeight() - nave.tamanio.y;

			if (IsKeyDown(KEY_LEFT)) rotacion -= 150 *GetFrameTime();
			if (IsKeyDown(KEY_RIGHT)) rotacion += 150*GetFrameTime();
		}

		void dibujarNave() {
			DrawPoly({ 50,50}, 3, 20, rotacion, WHITE);
			//DrawRectangleV(nave.pos, nave.tamanio, WHITE);
		}

		void inicializarJug() {
			tamanioXJug = (float)(GetScreenWidth()*2.0 / 100.0);
			tamanioYJug = (float)(GetScreenHeight()*15.0 / 100.0);
			velocidadJug = (float)(GetScreenHeight() * 80.0 / 100.0);

			for (int i = 0; i < cantJug; i++) {
				crearJugador(i);
			}
			PantallaJuego::fase = PantallaJuego::inicio;
		}
	}
}