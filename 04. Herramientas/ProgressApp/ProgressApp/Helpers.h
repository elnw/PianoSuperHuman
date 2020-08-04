#pragma once
#include <iostream>
#include <fstream>
#include <sys/stat.h>

using namespace std;

class CHelpers {
public:
	static void CrearArchivo(string nombre) {
		fstream archivo;
		archivo.open(nombre, ios::out);

		if (!archivo) {
			throw exception("No se pudo crear el archivo...");
		}

		archivo.close();
	}

	static void LeerArchivoProgreso(string nombre, int &cantidadMental, int &cantidadFisico, int &cantidadEmocional) {
		fstream archivo;
		archivo.open(nombre, ios::in);
		if (archivo.peek() == '\0')return;
		archivo >> cantidadMental >> cantidadFisico >> cantidadEmocional;
		archivo.close();
	}

	static void EscribirArchivoProgreso(string nombre, int cantidadMental, int cantidadFisico, int cantidadEmocional) {
		fstream archivo;
		archivo.open(nombre, ios::out);
		archivo << cantidadMental << " " << cantidadFisico << " " << cantidadEmocional;
		archivo.close();
	}

	static bool VerificarExistenciaArchivo(string nombre) {
		struct stat buffer;
		return (stat(nombre.c_str(), &buffer) == 0);
	}

};

