#include <iostream>
#include <unordered_set>
#include <string>

class Animal {
public:
	Animal(std::string name = "None", std::string specie = "None", std::string color = "None", std::string gender = "None", std::string age = "None") :
		name(name),
		specie(specie),
		color(color),
		gender(gender),
		age(age) {}

	void showInfo() const {
		std::cout << name << std::endl;
		std::cout << "\tage:\t\t" << age << std::endl;
		std::cout << "\tgender:\t\t" << gender << std::endl;
		std::cout << "\tspecie:\t\t" << specie << std::endl;
		std::cout << "\tcolor:\t\t" << color << std::endl << std::endl;
	}
	
	struct AnimalHasher
	{
		std::size_t operator()(const Animal& a) const
		{
			return std::hash<std::string>{} (a.name)
				^ std::hash<std::string>{} (a.specie)
				^ std::hash<std::string>{} (a.color)
				^ std::hash<std::string>{} (a.gender)
				^ std::hash<std::string>{} (a.age);
		}
	};

	std::string getName() const {
		return name;
	}
	std::string getSpecie() const {
		return specie;
	}
	std::string getColor() const {
		return color;
	}
	std::string getGender() const {
		return gender;
	}
	std::string getAge() const {
		return age;
	}
	friend bool operator ==(const Animal& a1, const Animal& a2);
private:
	std::string name;
	std::string specie;
	std::string color;
	std::string gender;
	std::string age;
};

bool operator ==(const Animal& a1, const Animal& a2) {
	return a1.name == a2.name &&
		a1.specie == a2.specie &&
		a1.color == a2.color &&
		a1.gender == a2.gender &&
		a1.age == a2.age;
}

class Zoo {
public:
	void addAnimal(Animal animal) {
		if (!animals.count(animal)) {
			animals.insert(animal);
			std::cout << "Successfully added" << std::endl << std::endl;
		}
		else {
			std::cout << "Already have one" << std::endl << std::endl;
		}
	}
	void showAllAnimalsInfo() const{
		if (animals.empty()) {
			std::cout << "Don't have anyone here" << std::endl << std::endl;;
		}
		for (auto& elem : animals) {
			elem.showInfo();
		}
	}
	void searchByName(std::string name) const {
		for (auto& elem : animals) {
			if (name == elem.getName()) {
				elem.showInfo();
			}
		}
	}
	void searchByGender(std::string gender) const {
		for (auto& elem : animals) {
			if (gender == elem.getGender()) {
				elem.showInfo();
			}
		}
	}
	void searchBySpecie(std::string specie) const {
		for (auto& elem : animals) {
			if (specie == elem.getSpecie()) {
				elem.showInfo();
			}
		}
	}
	void searchByColor(std::string color) const {
		for (auto& elem : animals) {
			if (color == elem.getColor()) {
				elem.showInfo();
			}
		}
	}
	void searchByAge(std::string age) const {
		for (auto& elem : animals) {
			if (age == elem.getAge()) {
				elem.showInfo();
			}
		}
	}
private:
	std::unordered_set<Animal, Animal::AnimalHasher> animals;
};

int main() {
	Zoo zoo;
	Animal A{"Rob", "Dog", "Boy", "White", "12"};
	Animal B{"Lana", "Cat", "Girl", "Black", "12"};
	Animal C{"Lana", "Cat", "Girl", "Black", "12"};
	zoo.addAnimal(A);
	zoo.addAnimal(B);
	zoo.addAnimal(C);

	std::string input;


	while (true) {
		std::cout << "Enter the command, use \"help\" to see all the commands" << std::endl << ">>> ";
		std::cin >> input;
		std::cout << std::endl;
		if (input == "help") {
			std::cout << std::endl << "-------------------" << std::endl;
			std::cout << "show_all" << std::endl;
			std::cout << "add_new_animal" << std::endl;
			std::cout << "search_by_name" << std::endl;
			std::cout << "search_by_specie" << std::endl;
			std::cout << "search_by_gender" << std::endl;
			std::cout << "search_by_color" << std::endl;
			std::cout << "search_by_age" << std::endl;
			std::cout << "-------------------" << std::endl << std::endl;
		}
		else if (input == "show_all") {
			zoo.showAllAnimalsInfo();
		}
		else if (input == "add_new_animal") {
			std::string name;
			std::string specie;
			std::string color;
			std::string gender;
			std::string age;
			std::cout << "Enter the name: ";
			std::cin >> name;
			std::cout << "Enter the specie: ";
			std::cin >> specie;
			std::cout << "Enter the color: ";
			std::cin >> color;
			std::cout << "Enter the gender: ";
			std::cin >> gender;
			std::cout << "Enter the age: ";
			std::cin >> age;
			Animal new_animal { name, specie, color, gender, age };
			zoo.addAnimal(new_animal);
		}
		else if (input == "search_by_name") {
			std::string name;
			std::cout << "Enter the name: ";
			std::cin >> name;
			zoo.searchByName(name);
		}
		else if (input == "search_by_specie") {
			std::string specie;
			std::cout << "Enter the specie: ";
			std::cin >> specie;
			zoo.searchBySpecie(specie);
		}
		else if (input == "search_by_color") {
			std::string color;
			std::cout << "Enter the color: ";
			std::cin >> color;
			zoo.searchByColor(color);
		}
		else if (input == "search_by_gender") {
			std::string gender;
			std::cout << "Enter the gender: ";
			std::cin >> gender;
			zoo.searchByGender(gender);
		}
		else if (input == "search_by_age") {
			std::string age;
			std::cout << "Enter the age: ";
			std::cin >> age;
			zoo.searchByAge(age);
		}
		else {
			std::cout << "Don't have such command" << std::endl << std::endl;
		}
	}
	return 0;
}