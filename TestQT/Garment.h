#ifndef GARMENT_H
#define GARMENT_H

#include <string>

class Garment
{
public:
    Garment(int id, double weight, std::string material, std::string color);
    void SetDryer(bool dryer);
    void SetSteamer(bool steamer);
    void SetCentrifuge(bool centrifuge);
    bool GetDryer();
    bool GetSteamer();
    bool GetCentrifuge();
    int GetCustomerId();
    double GetWeight();
   // Color GetColor();
  //  Material GetMaterial();




private:
    int id;
    enum Material{Cotton, Wool, Satin, Nylon, Linen, Silk, Polyester };
    enum Color{Black, White, Colored};
    double weight;
    bool dryer;
    bool steamer;
    bool centrifuge;
    int customerId;
};

#endif // GARMENT_H
