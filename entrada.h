#pragma once
#include <iostream>
#include <sstream>
#include <string>

inline bool lerInteiro(int& valor) {
    std::string linha;
    while (std::getline(std::cin, linha)) {
        std::istringstream entrada(linha);
        int numero;
        if ((entrada >> numero) && (entrada >> std::ws).eof()) {
            valor = numero;
            return true;
        }
        std::cout << "Digite um numero inteiro valido." << std::endl;
    }
    return false;
}

inline bool lerTexto(std::string& texto, std::size_t limite) {
    if (!std::getline(std::cin, texto)) return false;
    if (texto.find_first_not_of(" \t\r") == std::string::npos ||
        texto.size() > limite || texto.find('\0') != std::string::npos) {
        std::cout << "Texto invalido. Use de 1 a " << limite << " bytes." << std::endl;
        return false;
    }
    return true;
}
