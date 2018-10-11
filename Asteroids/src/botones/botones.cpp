#include "botones.h"

#include "raylib.h"
#include "juego/juego.h"
#include "Pantallas/pantallaJuego.h"
#include "Pantallas/pantallaMenu.h"
#include "Pantallas/pantallaGameOver.h"
#include "Pantallas/pantallaCreditos.h"

namespace Juego {
	namespace Botones {
		static const int cantBotonesMenu = 3;
		static Botones botonMenu[cantBotonesMenu];
		static const int cantBotonesJuego = 2;
		static Botones botonJuego[cantBotonesJuego];
		static const int cantBotonesCreditos = 1;
		static Botones botonCreditos[cantBotonesCreditos];
		static const int cantBotonesGO = 3;
		static Botones botonGO[cantBotonesGO];
		
		static void inicializarBotonesMenu();
		static void actualizarBotonesMenu();
		static void dibujarBotonesMenu();
		static void inicializarBotonesJuego();
		static void actualizarBotonesJuego();
		static void dibujarBotonesJuego();
		static void inicializarBotonesCreditos();
		static void actualizarBotonesCreditos();
		static void dibujarBotonesCreditos();
		static void inicializarBotonesGO();
		static void actualizarBotonesGO();
		static void dibujarBotonesGO();

		//MENU----------------------------------
		void inicializarBotonesMenu() {
			botonMenu[opcJugar].posYTamanio.y = GetScreenHeight()*0.4f;
			botonMenu[opcJugar].opcion = "Jugar";
			botonMenu[opcCreditos].posYTamanio.y = GetScreenHeight()*0.6f;
			botonMenu[opcCreditos].opcion = "Creditos";
			botonMenu[opcSalir].posYTamanio.y = GetScreenHeight()*0.8f;
			botonMenu[opcSalir].opcion = "Salir";

			for (int i = 0; i < cantBotonesMenu; i++) {
				botonMenu[i].posYTamanio.x = GetScreenWidth() *0.3f;
				botonMenu[i].posYTamanio.width = GetScreenWidth() *0.4f;
				botonMenu[i].posYTamanio.height = GetScreenHeight() *0.15f;
				botonMenu[i].estaSeleccionada = false;
				botonMenu[i].centroX = botonMenu[i].posYTamanio.x + botonMenu[i].posYTamanio.width / 2;
				botonMenu[i].centroY = botonMenu[i].posYTamanio.y + botonMenu[i].posYTamanio.height / 2;
			}
		}

		void actualizarBotonesMenu() {
			if (CheckCollisionPointRec(GetMousePosition(), botonMenu[opcJugar].posYTamanio)) {
				botonMenu[opcJugar].estaSeleccionada = true;
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
					estado = partida;
				}
			}
			else {
				botonMenu[opcJugar].estaSeleccionada = false;
			}
			if (CheckCollisionPointRec(GetMousePosition(), botonMenu[opcSalir].posYTamanio)) {
				botonMenu[opcSalir].estaSeleccionada = true;
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
					enJuego = false;
				}
			}
			else {
				botonMenu[opcSalir].estaSeleccionada = false;
			}
			if (CheckCollisionPointRec(GetMousePosition(), botonMenu[opcCreditos].posYTamanio)) {
				botonMenu[opcCreditos].estaSeleccionada = true;
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
					estado = creditos;
				}
			}
			else {
				botonMenu[opcCreditos].estaSeleccionada = false;
			}
		}

		void dibujarBotonesMenu() {
			double tamanioLetras = (GetScreenHeight()*GetScreenWidth())*0.0052 / 100;
			for (int i = 0; i < cantBotonesMenu; i++) {
				if (botonMenu[i].estaSeleccionada) {
					DrawRectangleRec(botonMenu[i].posYTamanio, DARKBLUE);
				}
				else {
					DrawRectangleRec(botonMenu[i].posYTamanio, BLUE);
				}

				DrawText(botonMenu[i].opcion.c_str(), botonMenu[i].centroX - (MeasureText(botonMenu[i].opcion.c_str(), tamanioLetras) / 2), botonMenu[i].centroY, tamanioLetras, BLACK);
			}
		}

		//JUEGO-----------------------------------
		void inicializarBotonesJuego() {

		}

		void actualizarBotonesJuego(){

		}

		void dibujarBotonesJuego() {

		}

		//CREDITOS-------------------------------
		void inicializarBotonesCreditos() {
			botonCreditos[opcVolver].posYTamanio.x = GetScreenWidth() *0.3f;
			botonCreditos[opcVolver].posYTamanio.y = GetScreenHeight() *0.8f;
			botonCreditos[opcVolver].posYTamanio.width = GetScreenWidth() *0.4f;
			botonCreditos[opcVolver].posYTamanio.height = GetScreenHeight() *0.15f;
			botonCreditos[opcVolver].estaSeleccionada = false;
			botonCreditos[opcVolver].centroX = botonCreditos[opcVolver].posYTamanio.x + botonCreditos[opcVolver].posYTamanio.width / 2;
			botonCreditos[opcVolver].centroY = botonCreditos[opcVolver].posYTamanio.y + botonCreditos[opcVolver].posYTamanio.height / 2;
			botonCreditos[opcVolver].opcion = "Volver";
		}

		void actualizarBotonesCreditos() {
			if (CheckCollisionPointRec(GetMousePosition(), botonCreditos[opcVolver].posYTamanio)) {
				botonCreditos[opcVolver].estaSeleccionada = true;
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
					estado = menu;
				}
			}
			else {
				botonCreditos[opcVolver].estaSeleccionada = false;
			}
		}

		void dibujarBotonesCreditos() {
			double tamanioLetras = (GetScreenHeight()*GetScreenWidth())*0.0052 / 100;
			if (botonCreditos[opcVolver].estaSeleccionada) {
				DrawRectangleRec(botonCreditos[opcVolver].posYTamanio, DARKBLUE);
			}
			else {
				DrawRectangleRec(botonCreditos[opcVolver].posYTamanio, BLUE);
			}

			DrawText(botonCreditos[opcVolver].opcion.c_str(), botonCreditos[opcVolver].centroX - (MeasureText(botonCreditos[opcVolver].opcion.c_str(), tamanioLetras) / 2), botonCreditos[opcVolver].centroY, tamanioLetras, BLACK);
		}

		//GAME OVER------------------------------
		void inicializarBotonesGO() {
			botonGO[opcNuevaPartida].posYTamanio.y = GetScreenHeight()*0.4f;
			botonGO[opcNuevaPartida].opcion = "Volver a Jugar";
			botonGO[opcVolverMenu].posYTamanio.y = GetScreenHeight()*0.6f;
			botonGO[opcVolverMenu].opcion = "Volver al Menu";
			botonGO[opcSalirGO].posYTamanio.y = GetScreenHeight()*0.8f;
			botonGO[opcSalirGO].opcion = "Salir";

			for (int i = 0; i < cantBotonesGO; i++) {
				botonGO[i].posYTamanio.x = GetScreenWidth() *0.3f;
				botonGO[i].posYTamanio.width = GetScreenWidth() *0.4f;
				botonGO[i].posYTamanio.height = GetScreenHeight() *0.15f;
				botonGO[i].estaSeleccionada = false;
				botonGO[i].centroX = botonGO[i].posYTamanio.x + botonGO[i].posYTamanio.width / 2;
				botonGO[i].centroY = botonGO[i].posYTamanio.y + botonGO[i].posYTamanio.height / 2;
			}
		}

		void actualizarBotonesGO() {
			if (CheckCollisionPointRec(GetMousePosition(), botonGO[opcNuevaPartida].posYTamanio)) {
				botonGO[opcNuevaPartida].estaSeleccionada = true;
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
					estado = partida;
				}
			}
			else {
				botonGO[opcNuevaPartida].estaSeleccionada = false;
			}
			if (CheckCollisionPointRec(GetMousePosition(), botonGO[opcSalirGO].posYTamanio)) {
				botonGO[opcSalirGO].estaSeleccionada = true;
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
					enJuego = false;
				}
			}
			else {
				botonGO[opcSalirGO].estaSeleccionada = false;
			}
			if (CheckCollisionPointRec(GetMousePosition(), botonGO[opcVolverMenu].posYTamanio)) {
				botonGO[opcVolverMenu].estaSeleccionada = true;
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
					estado = menu;
				}
			}
			else {
				botonGO[opcVolverMenu].estaSeleccionada = false;
			}
		}

		void dibujarBotonesGO() {
			double tamanioLetras = (GetScreenHeight()*GetScreenWidth())*0.0052 / 100;
			for (int i = 0; i < cantBotonesGO; i++) {
				if (botonGO[i].estaSeleccionada) {
					DrawRectangleRec(botonGO[i].posYTamanio, DARKBLUE);
				}
				else {
					DrawRectangleRec(botonGO[i].posYTamanio, BLUE);
				}

				DrawText(botonGO[i].opcion.c_str(), botonGO[i].centroX - (MeasureText(botonGO[i].opcion.c_str(), tamanioLetras) / 2), botonGO[i].centroY, tamanioLetras, BLACK);
			}
		}

		void inicializarBotones() {
			switch (estado) {
			case menu:
				inicializarBotonesMenu();
				break;
			case partida:
				inicializarBotonesJuego();
				break;
			case gameOver:
				inicializarBotonesGO();
				break;
			case creditos:
				inicializarBotonesCreditos();
				break;
			default:break;
			}
		}

		void actualizarBotones() {
			switch (estado) {
			case menu:
				actualizarBotonesMenu();
				break;
			case partida:
				actualizarBotonesJuego();
				break;
			case gameOver:
				actualizarBotonesGO();
				break;
			case creditos:
				actualizarBotonesCreditos();
				break;
			default:break;
			}
		}

		void dibujarBotones() {
			switch (estado) {
			case menu:
				dibujarBotonesMenu();
				break;
			case partida:
				dibujarBotonesJuego();
				break;
			case gameOver:
				dibujarBotonesGO();
				break;
			case creditos:
				dibujarBotonesCreditos();
				break;
			default:break;
			}
		}
	}
}