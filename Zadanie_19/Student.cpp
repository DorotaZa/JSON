#include "Student.hpp"


Student::Student()
{
}

Student::Student(std::string name, std::string lastName, int age) : _name(name), _lastName(lastName), _age(age) {}


void Student::setName(std::string name)
{
	_name = name;
}

void Student::setLastName(std::string lastName)
{
	_lastName = lastName;
}

void Student::setAge(int age)
{
	_age = age;
}

std::string Student::getName() const
{
	return _name;
}

std::string Student::getLastName() const
{
	return _lastName;
}

int Student::getAge() const
{
	return _age;
}

void to_json(json& j, const Student& s) //to sie nazywa konstruktorem/ lista inicjalizujaca(?)
{
	j = json{ {"name", s.getName()}, {"lastname", s.getLastName()}, {"age", s.getAge()} };
}

void from_json(const json& j, Student& s)
{
	//j.at("name").get_to(p.name);
	//j.at("address").get_to(p.address);
	//j.at("age").get_to(p.age);

	//nie mozemy napisac tej funkcji dokladnie tak jak wyzej, poniewaz pracujemy na klasie i polach prywatnych ktore musimy uzyskac, a get_to przyjmuje referencje na zmienna; pobiera wartosc do zmiennej;
	//metody "obejscia":

	//z uzyciem zmiennej
	std::string name;
	j.at("name").get_to(name);
	s.setName(name);

	//szykiem przestawnym
	s.setLastName(j["lastName"]); 
	s.setAge(j["age"].get<int>());

}
