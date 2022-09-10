#pragma once
#include <string>
#include "json/json.hpp"

using json = nlohmann::json;

class Student
{
public:
	Student();
	Student(std::string name, std::string lastName, int age);

	void setName(std::string name);
	void setLastName(std::string lastName);
	void setAge(int age);

	std::string getName()const;
	std::string getLastName()const;
	int getAge()const;

private:
	std::string _name;
	std::string _lastName;
	int _age = 0;
};

//tutaj defaultowo umieszczamy te funckje; wynika t z dokumentacji jsona
void to_json(json& j, const Student& s);
void from_json(const json& j, Student& s);
