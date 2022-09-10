// JSON


#include <iostream>
#include <fstream>
#include "json/json.hpp"
using json = nlohmann::json; //include namespace'u


int main()
{

    json j;
    j["name"] = "Dorota";
    j["lastName"] = "Zak";
    j["list"] = { 1,0,2 };
    j["job"]["freelance"] = "arch";
    j["job"]["regular"] = "barista";

    std::ofstream file("me.json");
    file << std::setw(4) << j << std::endl; //setw(4) - formatuje plik za pomoca whitespaces; default 4- zapewnia optymalna czytelnosc, ale mozna zmienic numer dowolnie wg uznania; wyrownuje dlugosc linii do zadanej ilosci whitespaces

}

