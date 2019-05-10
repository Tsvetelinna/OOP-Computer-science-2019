#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Duck {
private:
    int height;
    int weight;
    string color;
public:
    Duck() {}

    Duck(int height, int weight, const string &color)
            : height(height), weight(weight), color(color) {}

    virtual ~Duck() {}

    virtual void quack() = 0;

    virtual void read(istream& is) {
        is >> height >> weight;
        is.ignore(1, '\n');
        getline(is, color);
    }

    virtual void write(ostream& os) const {
        os << height << endl;
        os << weight << endl;
        os << color << endl;
    }

    friend ostream& operator<<(ostream& os, const Duck& duck) {
        duck.write(os);
        return os;
    }

    friend istream& operator>>(istream& is, Duck& duck) {
        duck.read(is);
        return is;
    }
};

class RubberDuck : public Duck {
private:
    bool canDebug;
    int elasticity;
public:

    RubberDuck() {}

    RubberDuck(int height, int weight, const string &color, bool canDebug, int elasticity)
            : Duck(height, weight, color), canDebug(canDebug), elasticity(elasticity) {}

    void quack() {
        cout << "Pipipi" << endl;
    }

    void read(istream &is) {
        Duck::read(is);

        is >> canDebug >> elasticity;
    }

    void write(ostream &os) const {

        Duck::write(os);

        os << canDebug << endl << elasticity << endl;
    }
};

class RealDuck : public Duck {
private:
    int age;
    string name;
public:

    RealDuck() {}

    RealDuck(int height, int weight, const string &color, int age, const string &name)
            : Duck(height, weight, color), age(age), name(name) {}

    void quack() {
        cout << "quack" << endl;
    }

    void read(istream &is) {
        Duck::read(is);

        is >> age;
        is.ignore(1, '\n');
        getline(is, name);
    }

    void write(ostream &os) const {

        Duck::write(os);

        os << age << endl << name << endl;
    }
};

class PlasticDuck : public Duck {
private:
    int parts;
public:

    PlasticDuck() {}

    PlasticDuck(int height, int weight, const string &color, int parts)
            : Duck(height, weight, color), parts(parts) {}

    void quack() {
        cout << "__no_sound__" << endl;
    }

    void read(istream &is) {
        Duck::read(is);

        is >> parts;
    }

    void write(ostream &os) const {

        Duck::write(os);

        os << parts << endl;
    }
};

class DuckFactory {
public:
    static Duck* createDuck(const string& duckType) {
        if (duckType == "RubberDuck") {
            return new RubberDuck;
        }
        else if (duckType == "RealDuck") {
            return new RealDuck;
        }
        else if (duckType == "PlasticDuck") {
            return new PlasticDuck;
        }
        else {
            cerr << "DuckFactory: Wrong Duck type" << endl;
            exit(-1);
        }
    }
};

class Lake {
private:
    vector<Duck*> ducks;
public:

    void read(istream &is) {

        while (!is.eof()) {
            // reed duckType in loop in order to skip empty lines
            string duckType;
            do {
                getline(is, duckType);
            } while(duckType.empty());

            Duck *duck = DuckFactory::createDuck(duckType);
            is >> *duck;

            ducks.push_back(duck);
        }
    }

    void write(ostream &os) const {
        for (Duck* duck : ducks) {
            os << *duck << endl;
        }
    }

    void quackAll() const {
        for (Duck* duck : ducks) {
            duck->quack();
        }
    }
};

int main() {

    ifstream is("in.txt");

    Duck *ducks[] = {new RubberDuck, new RubberDuck, new RealDuck, new PlasticDuck};

    for (int i = 0; i < 4; i++) {
        is >> *ducks[i];
    }

    for (int i = 0; i < 4; i++) {
        cout << *ducks[i] << endl;
    }

    for (int i = 0; i < 4; i++) {
        ducks[i]->quack();
    }

    ifstream lakeInFile("in_lake.txt");
    Lake lake;
    lake.read(lakeInFile);
    lake.write(cout);
    lake.quackAll();

    return 0;
}