#include "juego.h"

#include "raylib.h"
#include "Pantallas/pantallaJuego.h"
#include"Pantallas/pantallaMenu.h"
#include"Pantallas/pantallaGameOver.h"
#include "Pantallas/pantallaCreditos.h"

namespace Juego {
	static void inicializarJuego();
	//static void inicializarPantallas();
	static void actualizar();
	static void dibujar();
	//static void desinicializarPantallas();
	static void desinicializarJuego();

	using namespace PantallaJuego;
	estados estado = menu;
	int anchoPantalla = 900;
	int altoPantalla = 600;
	bool enJuego = true;

	void inicializarJuego() {
		InitWindow(anchoPantalla, altoPantalla, "Asteroids");
		InitAudioDevice();
	}

	/*void inicializarPantallas() {
		switch (estado) {
		case menu:
			Menu::inicializarMenu();
			break;
		case partida:
			inicializarPantJuego();
			break;
		default:break;
		}
	}*/

	/*void realizarIngreso() {
		switch (estado) {
		case menu:
			Menu::realizarIngresoMenu();
			break;
		case partida:
			realizarIngresoPantJuego();
			break;
		case gameOver:
			GameOver::realizarIngresoGO();
			break;
		case creditos:
			Creditos::realizarIngresoCreditos();
			break;
		default:break;
		}
	}*/

	void actualizar() {
		switch (estado) {
		case menu:
			Menu::actualizarMenu();
			break;
		case partida:
			actualizarJuego();
			break;
		case gameOver:
			GameOver::actualizarGO();
			break;
		case creditos:
			Creditos::actualizarCreditos();
			break;
		default:break;
		}
	}

	void dibujar() {
		BeginDrawing();

		ClearBackground(BLACK);

		switch (estado) {
		case menu:
			Menu::dibujarMenu();
			break;
		case partida:
			dibujarJuego();
			break;
		case gameOver:
			GameOver::dibujarGO();
			break;
		case creditos:
			Creditos::dibujarCreditos();
			break;
		default:break;
		}
		EndDrawing();
	}

	/*void desinicializarPantallas() {
		switch (estado) {
		case menu:
			Menu::desinicializarMenu();
			break;
		case partida:
			desinicializarPantJuego();
			break;
		default:break;
		}
	}*/

	void desinicializarJuego() {
		CloseAudioDevice();
		CloseWindow();
	}

	void ejecutar() {

		inicializarJuego();

		while (enJuego) {
			//inicializarPantallas();
			actualizar();
			dibujar();
			//desinicializarPantallas();
		}

		desinicializarJuego();
	}
}