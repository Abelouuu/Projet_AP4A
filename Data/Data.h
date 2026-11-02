#ifndef AP4ATP1_DATA_H
#define AP4ATP1_DATA_H

#include <string>
#include <sstream>

class Data {
public:
    virtual ~Data() = default;
    virtual std::string toString() const = 0; 
    
    // Ajout d'une méthode pour copier la donnée polymorphe
    virtual Data* clone() const = 0; 
};

template <typename T>
class SensorData : public Data {
private:
    T value;
    std::string unit;

public:
    SensorData(T val, std::string u) : value(val), unit(u) {}
    T getValue() const { return value; }

    std::string toString() const override {
        std::ostringstream oss;
        if constexpr (std::is_same_v<T, bool>) {
            oss << (value ? "ON" : "OFF");
        } else {
            oss << value;
        }
        return oss.str() + (unit.empty() ? "" : " " + unit);
    }
    
    // Implémentation du clonage qui renvoie une copie exacte de l'objet
    Data* clone() const override {
        return new SensorData<T>(*this);
    }
};

#endif //AP4ATP1_DATA_H