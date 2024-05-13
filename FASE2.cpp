#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <vector>

// Estructura para almacenar la informaci�n de las palabras
struct PalabraInfo {
    std::string traduccion;
    std::string funcionalidad;
};

// Funci�n para cargar el diccionario desde el archivo
std::map<std::string, PalabraInfo> cargarDiccionario(const std::string& archivo) {
    std::map<std::string, PalabraInfo> diccionario;
    std::ifstream archivoEntrada(archivo);
    std::string linea, palabra, traduccion, funcionalidad;

    while (getline(archivoEntrada, linea)) {
        std::istringstream streamLinea(linea);
        getline(streamLinea, palabra, ',');
        getline(streamLinea, traduccion, ',');
        getline(streamLinea, funcionalidad, '\n');
        diccionario[palabra] = {traduccion, funcionalidad};
    }
    archivoEntrada.close();
    return diccionario;
}

// Funci�n para traducir el c�digo
void traducirCodigo(const std::map<std::string, PalabraInfo>& diccionario) {
    std::string linea, palabra, codigoTraducido;
    std::cout << "Ingrese el c�digo C++ (escriba 'fin' para terminar):" << std::endl;
    while (getline(std::cin, linea) && linea != "fin") {
        std::istringstream streamLinea(linea);
        while (streamLinea >> palabra) {
            // Buscar la palabra en el diccionario y traducirla
            auto it = diccionario.find(palabra);
            if (it != diccionario.end()) {
                codigoTraducido += it->second.traduccion + " ";
            } else {
                codigoTraducido += palabra + " ";
            }
        }
        codigoTraducido += "\n";
    }
    std::cout << "C�digo traducido:" << std::endl;
    std::cout << codigoTraducido << std::endl;
}

// Funci�n principal
int main() {
    std::string archivo = "palabras.txt";
    auto diccionario = cargarDiccionario(archivo);
    traducirCodigo(diccionario);
    return 0;
}
