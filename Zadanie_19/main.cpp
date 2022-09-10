// Zadanie_19

//Utwórz vector<Students>. Wypełnij go kilkoma obiektami, a następnie zapisz go do pliku students.json.
//Zapisany plik powinien zawierać mniej więcej takie dane :
//{
//    "Students": [
//    {"firstName":"Sean", "lastName" : "Brown"},
//    { "firstName":"Drake", "lastName" : "Williams" },
//    { "firstName":"Tom", "lastName" : "Miller" },
//    { "firstName":"Peter", "lastName" : "Jonson" }
//    ]
//}
//Następnie:
//Wczytaj plik students.json do listy, a następnie wypisz na konsolę dane wszystkich studentów.
//
//Uwaga : https ://github.com/nlohmann/json#basic-usage

#include <iostream>
#include "json/json.hpp"
#include "Student.hpp"
#include <vector>
#include <list>
#include <algorithm>
#include <fstream>

using json = nlohmann::json;


int main()

{
    std::vector <Student> students;
    students.push_back(Student("Sean", "Brown", 42));
    students.emplace_back("Drake", "Williams", 38);
    students.emplace_back("Tom", "Miller", 38);
    students.emplace_back("Peter", "Jonson", 27);

    //OFSTREAM
    json j;
    j["Students"] = students;
    std::ofstream o("students.json");
    o << std::setw(4) << j;


    //IFSTREAM
    
    std::ifstream i("students.json");
    json js = json::parse(i);

    std::list<Student> listOfStudents;

    //wczytanie danych do listy

    for (auto& element : js["Students"])
    {
        listOfStudents.push_back(element.get<Student>()); //dziala, bo mamy funkcje from_json  //get.<Student>()- upewniamy sie o zwracamy typ
    }

    std::for_each(listOfStudents.begin(), listOfStudents.end(), [](const Student& s) {
        std::cout << "Name: " << s.getName() << "; LastName: " << s.getLastName() << "Age: " << s.getAge() << std::endl; });

}
