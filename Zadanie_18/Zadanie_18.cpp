// Zadanie_18

//Utwórz jason z podanego stringa :
//
//{
//    "company":{
//        "employee":{
//            "name":"Stefan",
//                "payroll" : {
//                "salary":1500,
//                    "bonus" : 800
//            }
//        }
//    }
//}
//
//Następnie wypisz sumę wynagrodzenia wraz z bonusem dla Stefana

#include <iostream>
#include "json/json.hpp"

using json = nlohmann::json;

int main()
{

    std::string str(R"({
        "company":{
            "employee":{
                "name":"Stefan",
                    "payroll" : {
                    "salary":1500,
                        "bonus" : 800
                }
            }
        }
    })");


    json js = json::parse(str);

    //w jsonie podajemy cala sciezke,zeby dobrac sie do danych!!!
    std::cout << js["company"]["employee"] << std::endl; //wszystko sie wyswietli

    json employee = js["company"]["employee"];
    std::string empName = employee["name"];
    std::cout << empName << std::endl;

    int salary = employee["payroll"]["salary"];
    int bonus = employee["payroll"]["bonus"];

    int sum = salary + bonus;

    std::cout << "Stefan earned " << sum << "." << std::endl;

}