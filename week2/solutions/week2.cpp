#include <iostream>
#include <cstring>
using namespace std;

char* copyDyn(const char* str){
	
	char* res = new char[strlen(str) + 1];
	strcpy(res, str);

	return res;
}

class Person{
	private:
		char* name;
		int age;
		bool hasDrivingLicense;

		void copy(const Person& p){

			this->name = copyDyn(p.name);
			this->age = p.age;
			this->hasDrivingLicense = p.hasDrivingLicense;
		}

		void erase(){

			if(this->name != NULL){
				delete[] name;
			}
		}

	public:
		Person(){
			this->name = copyDyn("");
			this->age = 0;
			this->hasDrivingLicense = false;
		}

		Person(const char* name, const int age, const bool hasLicense){

			this->name = copyDyn(name);
			this->age = age;
			this->hasDrivingLicense = hasLicense;
		}

		Person(const Person& p){

			copy(p);
		}

		Person& operator=(const Person& other){

			if(&other != this){

				erase();
				copy(other);
			}

			return *this;
		}

		bool operator==(const Person& other) const {
			return strcmp(name, other.name) == 0 && age == other.age && 
				hasDrivingLicense == other.hasDrivingLicense;
		}

		char* getName() const{

			return this->name;
		}

		int getAge() const{

			return this->age;
		}

		bool getDrivingLicense () const{

			return this->hasDrivingLicense;
		}

		void setName(const char* name){

			delete[] this->name;
			this->name = copyDyn(name);
		}

		void setAge(const int age){

			this->age = age;
		}

		void setDrivingLicense(const bool hasDrivingLicense){

			this->hasDrivingLicense = hasDrivingLicense;
		}

		void print(){

			cout << "Name: " << this->name << endl;
			cout << "Age: " << this->age << endl;
			cout << "Driving License: " << boolalpha << this->hasDrivingLicense << endl;
		}

		~Person(){

			erase();
		}
};

class Car{
private:
	char* model;
	char* number;
	char* color;
	Person owner;

	void copy(const Car& car){

		this->model = copyDyn(car.model);
		this->number = copyDyn(car.number);
		this->color = copyDyn(car.color);
		this->owner = car.owner;
	}

	void erase(){

		if(this->model) {
			delete[] model;
		}

		if(this->number) {
			delete[] number;
		}

		if(this->color) {
			delete[] color;
		}
	}

public:
	Car():owner(){

		this->model = copyDyn("");
		this->color = copyDyn("");
		this->number = copyDyn("");
	}

	Car(const char* model, const char* number, const char* color, const Person person) : owner(person) {

		this->model = copyDyn(model);
		this->number = copyDyn(number);
		this->color = copyDyn(color);	
	}
	

	Car(const Car& c){

		copy(c);
	}

	Car& operator=(const Car& other){

		if(&other != this){

			erase();
			copy(other);
		}

		return *this;
	}

	~Car(){

		erase();
	}

	char* getModel() const{

		return this->model;
	}

	char* getNumber() const{

		return this->number;
	}

	char* getColor() const{

		return this->color;
	}

	Person getOwner() const{

		return this->owner;
	}

	void setModel(const char* model){

		delete[] this->model;
		this->model = copyDyn(model);
	}

	void setNumber(const char* number){

		delete[] this->number;
		this->number = copyDyn(number);
	}

	void setColor(const char* color){

		delete[] this->color;
		this->color = copyDyn(color);
	}

	bool hasOwnerDrivingLicense(){

		return this->owner.getDrivingLicense();
	}

	void print(){

		cout << "Model: " << this->model << endl;
		cout << "Number: " << this->number << endl;
		cout << "Color: " << this->color << endl;
		cout << "OWNER " << endl;
		this->owner.print();
	}

};


class Parking{

private:
	Car* cars;
	int capacity;
	int size;
	char* name;
	Person owner;

	void copy(const Parking& p){

		this->capacity = p.capacity;
		this->size = p.size;

		cars = new Car[capacity];

		for (int i = 0; i < size; ++i)
		{
			this->cars[i] = p.cars[i];
		}

		this->name = copyDyn(p.name);
		this->owner = p.owner;
	}

	void erase(){
		delete[] cars;
		delete[] name;
	}

	void resize(){

		this->capacity *= 2;
		Car* temp = cars;
		cars = new Car[capacity];

		for(int i = 0; i < size; i++){

			cars[i] = temp[i];
		}

		delete[] temp;
	}

public:
	Parking(){

		this->size = 0;
		this->capacity = 8;
		this->cars = new Car[capacity];
		this->name = copyDyn("");
	}

	Parking(const Parking& p){

		copy(p);
	}

	Parking& operator=(const Parking& other){

		if(&other != this){

			erase();
			copy(other);
		}

		return *this;
	}

	~Parking(){

		erase();
	}

	int getSize() const{

		return this->size;
	}

	void setSize(const int size){
	
		this->size = size;
	}

	char* getName() const {
		return this->name;
	}

	void* setName(const char* name) {
		delete[] this->name;
		this->name = copyDyn(name);
	}

	Person getOwner() const {
		return this->owner;
	}

	void setOwner(const Person& person) {
		this->owner = person;
	}


	void addCar(const Car& car){

		if (size >= capacity){

			resize();
		}

		this->cars[size] = car;
		size++;
	}

	void remove(){

		cars[size - 1] = Car();
		size--;
	}

	void print(){

		for(int i = 0; i < size; i++){

			cout << "Car " << i << endl;
			this->cars[i].print();
		}
	}

	Person findOwner(const char* carNumber) {
		for (int i = 0; i < size; i++) {
			if (strcmp(cars[i].getNumber(), carNumber) == 0) {
				return cars[i].getOwner();
			}
		}

		return Person();
	}

	void printAllCarsOfOwner(const Person& owner) {
		for (int i = 0; i < size; i++) {
			if (cars[i].getOwner() == owner) {
				cars[i].print();
			}
		}
	}
};

void testPerson() {
	Person person1("Gosho", 21, true), person2 = Person("Pesho", 18, false), 
		person3("Vladi", 23, true);

	Person person4 = person1;

	person1.print();
	person2.print();
	person3.print();
	person4.print();
}

void testCar() {
	Person person("Todor", 30, true);

	Car car1("golf", "CA8888KK", "blue", Person("Pesho", 22, true));
	Car car2("ford", "CA1234KK", "silver", Person("Gosho", 20, true));
	Car car3("fiat", "CA1111AA", "white", Person("Vlado", 18, false));
	Car car4("shkoda", "BT1111AA", "white", person);

	car1.print();
	car2.print();
	car3.print();
	car4.print();
}

void testParking() {
	Person person("Todor", 30, true);

	Car car1("golf", "CA8888KK", "blue", Person("Pesho", 22, true));
	Car car2("ford", "CA1234KK", "silver", Person("Gosho", 20, true));
	Car car3("fiat", "CA1111AA", "white", Person("Vlado", 18, false));
	Car car4("shkoda", "BT1111AA", "white", person);
	Car car5("seat", "CA4321KK", "black", person);

	Parking parking;
	parking.print();

	parking.addCar(car1);
	parking.addCar(car2);
	parking.addCar(car3);
	parking.addCar(car4);
	parking.addCar(car5);

	parking.printAllCarsOfOwner(person);
	parking.findOwner("CA1111AA").print();
	parking.findOwner("esdsad").print();
}

int main (){
	

	return 0;
}