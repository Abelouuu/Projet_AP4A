//
// Created by abel6 on 11/2/2026.
//

#ifndef AP4ATP1_DATA_H
#define AP4ATP1_DATA_H

#include <string>
#include <sstream>

// Interface générique
class Data {
public:
    virtual ~Data() = default;

    // Oblige les classes filles à fournir une représentation textuelle
    virtual std::string toString() const = 0;
};

// Classe template pour gérer n'importe quel type de donnée (float, bool, int, etc.)
template <typename T>
class SensorData : public Data {
private:
    T value;
    std::string unit;

public:
    // Constructeur
    SensorData(T val, std::string u) : value(val), unit(u) {}

    // Getter pour récupérer la valeur mathématique si le serveur veut faire des calculs
    T getValue() const { return value; }

    // Implémentation polymorphe de l'affichage
    std::string toString() const override {
        std::ostringstream oss;
        // Formatage pour les booléens (pour la lumière)
        if constexpr (std::is_same_v<T, bool>) {
            oss << (value ? "ON" : "OFF");
        } else {
            oss << value;
        }
        return oss.str() + (unit.empty() ? "" : " " + unit);
    }
};

#endif //AP4ATP1_DATA_H
