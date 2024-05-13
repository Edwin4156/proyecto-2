#include <iostream>
#include <fstream>
#include <map>
#include <string>

// Estructura para almacenar la información de las palabras
struct PalabraInfo {
    std::string traduccion;
    std::string funcionalidad;
};

// Función para agregar una palabra al archivo
void agregarPalabra(std::map<std::string, PalabraInfo>& diccionario, const std::string& archivo) {
    std::string palabra, traduccion, funcionalidad;
    std::cout << "Ingrese Palabra: ";
    std::cin >> palabra;
    std::cout << "Ingrese Traducción: ";
    std::cin.ignore(); // Ignora el '\n' que queda en el buffer
    std::getline(std::cin, traduccion);
    std::cout << "Ingrese Funcionalidad: ";
    std::getline(std::cin, funcionalidad);

    // Agregar la información al diccionario
    diccionario[palabra] = {traduccion, funcionalidad};

    // Escribir la información en el archivo
    std::ofstream archivoSalida(archivo, std::ios::app); // Abre el archivo en modo append
    if (archivoSalida.is_open()) {
        archivoSalida << palabra << "," << traduccion << "," << funcionalidad << std::endl;
        archivoSalida.close();
    } else {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
    }
}

// Función principal
int main() {
    std::map<std::string, PalabraInfo> diccionario;
    std::string archivo = "palabras.txt";

    // Agregar palabras al archivo
    agregarPalabra(diccionario, archivo);

    // Aquí puedes implementar las funciones para Leer, Actualizar y Borrar

    return 0;
}
