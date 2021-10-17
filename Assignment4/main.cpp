#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Course{
private:
	string name;
	int number;
	string lecturer;
public:
	Course(string name, string lecturer){
		this->name = name;
		this->lecturer = lecturer;
	}
	void setName(string name){
		this->name = name;
	}
	string getName(){
		return name;
	}
	void setNumber(int number){
		this->number = number;
	}
	int getNumber(){
		return number;
	}
	void setLecturer(string lecturer){
		this->lecturer = lecturer;
	}
	string getLecturer(){
		return lecturer;
	}
};

class ACM{
private:
	string topic;
	map<string, string>location;
	int number;
public:
	void setTopic(string topic){
		this->topic = topic;
	}
	string getTopic(){
		return topic;
	}
	void setLocation(string city, string address){
		location[city] = address;
	}
	string getLocationByCity(string city){
		return location[city];
	}
	void setNumber(int number){
		this->number = number;
	}
	int getNumber(){
		return number;
	}
};


class IEEE{
private:
	string name;
	string location;
	set<string>topics;	
public:
	void setName(string name){
		this->name = name;
	}	
	string getName(){
		return name;
	}
	void setLocation(string location){
		this->location = location;
	}
	string getLocation(){
		return location;
	}
	void addTopic(string topic){
		topics.insert(topic);
	}
	string getTopics(){
		stringstream ss;
		for (string topic : topics)
			ss << topic;
		return ss.str();
	}
};

class Student{
private:
	string name;
	int id;
	int age;
	vector<Course>courses;
	ACM acm;
	IEEE ieee;
public:
	void setName(string name){
		this->name = name;
	}
	string getName(){
		return name;
	}
	void setId(int id){
		this->id = id;
	}
	int getId(){
		return id;
	}
	void setAge(int age){
		this->age = age;
	}
	int getAge(){
		return age;
	}
	void setACM(ACM acm){
		this->acm = acm;
	}
	void setIEEE(IEEE ieee){
		this->ieee = ieee;
	}
	ACM getACM(){
		return acm;
	}
	IEEE getIEEE(){
		return ieee;
	}
	void addCourse(Course course){
		courses.push_back(course);
	}
	string getCourse(){
		stringstream ss;
		for (int i=0; i<courses.size(); i++){
			if (i > 0) ss << "\t\t\t\t\t\t\t";
			ss << courses[i].getName() << '\n';
		}
		return ss.str();
	}
};


istream & operator >> (istream &cin, Student &stud){
	cout << "Enter student info:\n";
	string name;
	int id, age;
	cout << "Name: ";
	getline(cin, name);
	cout << "ID: ";
	cin >> id;
	cout << "Age: ";
	cin >> age;
	int N;
	cout << "Number of courses: ";
	cin >> N;
	while(N-->0){
		string cname, lecturer;
		cout << "Course name: ";
		cin >> cname;
		cout << "Lecturer: ";
		cin >> lecturer;
		stud.addCourse(Course(cname, lecturer));
	}
	string activityType;
	cout << "Activity name: ";
	cin >> activityType;
	if (activityType == "ACM"){
		string topic, city, address;
		int num;
		cout << "Topic: ";
		cin >> topic;
		cout << "City: ";
		cin >> city;
		cout << "Address: ";
		cin >> address;
		ACM activity = ACM();
		activity.setTopic(topic);
		activity.setLocation(city, address);
		activity.setNumber(num);
		stud.setACM(activity);
	} else if (activityType == "IEEE"){
		IEEE activity = IEEE();
		string confName, location;
		int K;
		cout << "Conference name: ";
		cin >> confName;
		activity.setName(confName);
		cout << "Location: ";
		cin >> location;
		activity.setLocation(location);
		cout << "Number of topics: ";
		cin >> K;
		while(K--){
			string theme;
			cout << "Topic: ";
			cin >> theme;
			activity.addTopic(theme);
		}
		stud.setIEEE(activity);
	}
	stud.setName(name);
	stud.setId(id);
	stud.setAge(age);
	cout << endl;
	cin.ignore();
	return cin;
}

ostream & operator << (ostream &cout, Student &stud){
	cout << stud.getName() << "\t" << stud.getId() << '\t' << stud.getAge() << '\t' << (stud.getACM().getTopic().empty() ? "IEEE" : "ACM") << "\t\t" << stud.getCourse() << "\t\t\n";
	return cout;
}

int main(){
	Student student1 = Student();
	Student student2 = Student();
/*	Student student3 = Student();
	Student student4 = Student();
	Student student5 = Student();
	Student student6 = Student();
*/
	cin >> student1 >> student2;
	cout << "Name\t\t\tID\tAge\tActivities\tCourses\n-------------------------------------------------------------------\n";
	cout << student1 << student2;
	return 0;
}
