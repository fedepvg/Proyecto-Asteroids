#include "pantallaCreditos.h"

#include "raylib.h"
#include "juego/juego.h"

namespace Juego {
	namespace Creditos {
		void realizarIngresoCreditos() {

		}

		void actualizarCreditos() {
			if (IsKeyPressed(KEY_M)) {
				estado = menu;
			}
		}
		
		void dibujarCreditos() {
			double tamanioTitulo = (GetScreenHeight()*GetScreenWidth())*0.0190 / 100.0;
			double tamanioSubtitulos = (GetScreenHeight()*GetScreenWidth())*0.0092 / 100.0;
			double tamanioVersion = (GetScreenHeight()*GetScreenWidth())*0.0052 / 100.0;
			char titulo[] = "Creditos";
			char subt1[] = "Hecho con la libreria Raylib";
			char subt2[] = "Programador: Federico van Gelderen";
			char subt3[] = "Sonidos: BFXR";
			char subt4[] = "Musica: Bosca Ceoil, Music Maker";
			char version[] = "PONG v1.0";
			char volver[] = "Pulse M para volver al menu";
			DrawText(titulo, (GetScreenWidth() - MeasureText(titulo, tamanioTitulo)) / 2, 0, tamanioTitulo, DARKGRAY);
			DrawText(subt1, (GetScreenWidth() - MeasureText(subt1, tamanioSubtitulos)) / 2, GetScreenHeight() * 20 / 100, tamanioSubtitulos, DARKGRAY);
			DrawText(subt2, (GetScreenWidth() - MeasureText(subt2, tamanioSubtitulos)) / 2, GetScreenHeight() * 40 / 100 - tamanioSubtitulos, tamanioSubtitulos, DARKGRAY);
			DrawText(subt3, (GetScreenWidth() - MeasureText(subt3, tamanioSubtitulos)) / 2, GetScreenHeight() * 60 / 100 - tamanioSubtitulos, tamanioSubtitulos, DARKGRAY);
			DrawText(subt4, (GetScreenWidth() - MeasureText(subt4, tamanioSubtitulos)) / 2, GetScreenHeight() * 80 / 100 - tamanioSubtitulos, tamanioSubtitulos, DARKGRAY);
			DrawText(version, GetScreenWidth() - MeasureText(version, tamanioVersion), 0 + tamanioVersion, (int)tamanioVersion, DARKGRAY);
			DrawText(volver, (GetScreenWidth() - MeasureText(volver, tamanioSubtitulos)) / 2, GetScreenHeight() - tamanioSubtitulos, tamanioSubtitulos, DARKGRAY);
		}

		
	}
}