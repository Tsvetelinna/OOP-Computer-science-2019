#ifndef MESSAGE_H
#define MESSAGE_H

#include "Person.h"

char* copydyn(const char*);

class Message {
private:
    char* text;
    char* date;
    Person sender;
    Person receiver;

    void copy(const Message& other) {
        this->text = copydyn(other.text);
        this->date = copydyn(other.date);
        this->sender = other.sender;
        this->receiver = other.receiver;
    }

    void erase() {
        delete[] this->text;
        delete[] this->date;
    }

    void readFromFile(const char* fileName);

public:
    Message();

    Message(const char* fileName, const Person& sender, 
            const Person& receiver, const char* date);

    Message(const Message& other);

    Message& operator=(const Message& other);

    ~Message();

    bool operator==(const Message& other) const;
    bool operator!=(const Message& other) const;

    void print() const;

    const char* getText() const;
    const char* getDate() const;
    Person getReceiver() const;
    Person getSender() const;

    void setText(const char* text);
    void setDate(const char* date);
    void setReceiver(const Person& receiver);
    void setSender(const Person& sender);
};

#include "Message.cpp"

#endif // MESSAGE_H