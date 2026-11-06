#ifndef AP4ATP1_DATA_H
#define AP4ATP1_DATA_H

#include <string>
#include <sstream>
#include <iostream>

// Classe de base abstraite permettant au serveur et aux capteurs de manipuler
// des données de types différents via un pointeur polymorphe Data*
class Data {
public:
    virtual ~Data() = default;
    virtual std::string toString() const = 0;

    // Ajout d'une méthode virtuelle pure pour copier la donnée
    virtual Data* clone() const = 0;

    // Méthode virtuelle permettant de vérifier les seuils critiques à la réception
    virtual void checkAlert(const std::string& type) const {}
};

// Classe template dérivée pour encapsuler la valeur brute (bool, float...) et son unité
template <typename T>
class SensorData : public Data {
private:
    T value;
    std::string unit;

public:
    SensorData(T val, std::string u) : value(val), unit(u) {}
    T getValue() const { return value; }

    // Conversion de la mesure en chaîne de caractères pour l'affichage et les logs
    std::string toString() const override {
        std::ostringstream oss;
        // Si le type T est un bool, on affiche ON/OFF au lieu de 1/0
        if constexpr (std::is_same_v<T, bool>) {
            if (value) {
                oss << "ON";
            } else {
                oss << "OFF";
            }
        } else {
            oss << value;
        }
        return oss.str() + (unit.empty() ? "" : " " + unit);
    }

    // Implémentation du clonage qui renvoie une copie dynamique exacte de l'objet
    Data* clone() const override {
        return new SensorData<T>(*this);
    }

    // Analyse active de la mesure pour déclencher une alerte si un seuil est dépassé
    void checkAlert(const std::string& type) const override {
        // Si c'est un float (température ou son)
        if constexpr (std::is_same_v<T, float>) {
            if (type == "Temperature" && (value < 15.0f || value > 25.0f)) {
                std::cout << "[ALERTE] Temperature anormale : " << value << " C" << std::endl;
            }
            else if (type == "Sound" && value > 52.0f) {
                std::cout << "[ALERTE] Niveau sonore eleve : " << value << " Db" << std::endl;
            }
        }
    }
};

#endif //AP4ATP1_DATA_H