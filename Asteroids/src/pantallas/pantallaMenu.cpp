#include "pantallaMenu.h"

#include <string>

#include "raylib.h"
#include "Juego/juego.h"

namespace Juego {
	namespace Menu {
		static enum opciones{opcJugar,opcCreditos,opcSalir};
		static struct Botones {
			Rectangle posYTamanio;
			bool estaSeleccionada;
			std::string opcion;
			float centroX;
			float centroY;
		};
		static bool estaInicializado = false;
		static const int cantBotones = 3;
		static Botones boton[cantBotones];
		static void inicializarBotones();
		static void actualizarBotones();
		static void dibujarBotones();

		void inicializarBotones() {
			boton[opcJugar].posYTamanio.y = GetScreenHeight()*0.4;
			boton[opcJugar].opcion = "Jugar";
			boton[opcCreditos].posYTamanio.y = GetScreenHeight()*0.6;
			boton[opcCreditos].opcion = "Creditos";
			boton[opcSalir].posYTamanio.y = GetScreenHeight()*0.8;
			boton[opcSalir].opcion = "Salir";
			
			for (int i = 0; i < cantBotones; i++) {
				boton[i].posYTamanio.x = GetScreenWidth() *0.3;
				boton[i].posYTamanio.width = GetScreenWidth() *0.4;
				boton[i].posYTamanio.height = GetScreenHeight() *0.15;
				boton[i].estaSeleccionada = false;
				boton[i].centroX = boton[i].posYTamanio.x + boton[i].posYTamanio.width / 2;
				boton[i].centroY= boton[i].posYTamanio.y + boton[i].posYTamanio.height / 2;
			}
		}

		void inicializarMenu() {
			if(!estaInicializado)
			inicializarBotones();
			estaInicializado = true;
		}

		void actualizarBotones(){
			if (CheckCollisionPointRec(GetMousePosition(), boton[opcJugar].posYTamanio)) {
				boton[opcJugar].estaSeleccionada = true;
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
					estado = partida;
					estaInicializado = false;
				}
			}else {
				boton[opcJugar].estaSeleccionada = false;
			}
			if (CheckCollisionPointRec(GetMousePosition(), boton[opcSalir].posYTamanio)) {
				boton[opcSalir].estaSeleccionada = true;
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
					enJuego = false;
					estaInicializado = false;
				}	
			}
			else {
				boton[opcSalir].estaSeleccionada = false;
			}
			if (CheckCollisionPointRec(GetMousePosition(), boton[opcCreditos].posYTamanio)) {
				boton[opcCreditos].estaSeleccionada = true;
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
					estado = creditos;
					estaInicializado = false;
				}
			}
			else {
				boton[opcCreditos].estaSeleccionada = false;
			}
		}

		void actualizarMenu() {
			actualizarBotones();
		}

		void dibujarBotones() {
			double tamanioLetras = (GetScreenHeight()*GetScreenWidth())*0.0052 / 100;
			for (int i = 0; i < cantBotones; i++) {
				if (boton[i].estaSeleccionada) {
					DrawRectangleRec(boton[i].posYTamanio, DARKBLUE);
				}else {
					DrawRectangleRec(boton[i].posYTamanio, BLUE);
				}
				
				DrawText(boton[i].opcion.c_str(), boton[i].centroX - (MeasureText(boton[i].opcion.c_str(),tamanioLetras)/2), boton[i].centroY, tamanioLetras, BLACK);
			}


		}

		void dibujarMenu() {	
			double tamanioTitulo = (GetScreenHeight()*GetScreenWidth())*0.0190 / 100;
			double tamanioVersion = (GetScreenHeight()*GetScreenWidth())*0.0042 / 100.0;
			char titulo[] = "Asteroids";
			char version[] = "Asteroids v0.3";
			dibujarBotones();
			DrawText(titulo, (GetScreenWidth() - MeasureText(titulo, tamanioTitulo)) / 2, GetScreenHeight()*0.1f, tamanioTitulo, DARKGRAY);
			DrawText(version, GetScreenWidth() - MeasureText(version, tamanioVersion), 0 + tamanioVersion, (int)tamanioVersion, DARKGRAY);
		}
	}
}