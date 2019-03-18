#ifndef PERSON_H
#define PERSON_H

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

    friend ostream& operator<<(ostream& os, const Person& person) {
        os << person.name << " " << person.age << " " << person.hasDrivingLicense;
        return os;
    }

    ~Person(){

        erase();
    }
};


#endif //PERSON_H
