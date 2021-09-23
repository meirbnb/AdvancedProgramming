#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Person{
private:
	string name;
	int age;
	int luck;

public:
	Person(string newName="Unknown", int newAge=0, int newLuck=-1) : name( newName ), age( newAge ), luck( newLuck ){}

	/*	Setters & Getters	*/
	void setName(string name){
		this->name = name;
	}
	string getName(){
		return this->name;
	}
	
	void setAge(int age){
		this->age = age;
	}
	int getAge(){
		return this->age;
	}
	
	void setLuck(int luck){
		this->luck = luck;
	} 
	int getLuck(){
		return this->luck;
	}

};

void changeLuck(Person &A, Person &B);

const int N = 5; // number of instances

int main(){
	srand(time(0));  // generating random numbers based on time

	vector<Person>people(1 + N);
	people[1] = Person("Meirbek", 19, rand());
	people[2] = Person("Madiar", 29, rand());
	people[3] = Person("Manarbek", 30, rand());
	people[4] = Person("Alibek", 20, rand());
	people[5] = Person("Arman", 21, rand());

	string luckiestPerson;
	int maxLuck = 0;
	for (Person person : people)
		if (maxLuck < person.getLuck())
			luckiestPerson = person.getName(), maxLuck = person.getLuck();
	cout << luckiestPerson << " is the luckiest person with the luck coefficient = " << maxLuck << "\n\n";
	
	cout << "Before using changeLuck(Person A, Person B):\n";
	cout << people[3].getName() << "'s luck = " << people[3].getLuck() << '\n';
	cout << people[4].getName() << "'s luck = " << people[4].getLuck() << "\n\n";

	changeLuck(people[3], people[4]);

	cout << "After using changeLuck(Person A, Person B):\n";
	cout << people[3].getName() << "'s luck = " << people[3].getLuck() << '\n';
	cout << people[4].getName() << "'s luck = " << people[4].getLuck() << "\n\n";
	
	/*	Storing Person objects inside an allocated heap memory	*/
	cout << "New heap memory:\n";
	Person *humans = new Person[N];
	*(humans + 0) = Person("Arman", 21, rand());
	*(humans + 1) = Person("Meirbek", 19, rand());
	*(humans + 2) = Person("Manarbek", 30, rand());
	*(humans + 3) = Person("Madiar", 29, rand());
	*(humans + 4) = Person("Alibek", 20, rand());
	
	for (; humans->getAge(); ++humans)
		cout << humans->getName() << " is " << humans->getAge() << " old and has a luck of " << humans->getLuck() << '\n';

	delete humans; // releases the memory
	
	cout << humans->getName() << endl; // this line does not ouput anything since the memory humans gets freed;
	return 0;
}

void changeLuck(Person &A, Person &B){
	int luckAB = A.getLuck() + B.getLuck();
	A.setLuck(luckAB - A.getLuck());
	B.setLuck(luckAB - A.getLuck());
}
