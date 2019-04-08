#include <cstring>
#include <iostream>
#include <cassert>
#include <fstream>
#include "Message.h"

void Message::readFromFile(const char* fileName) {

    std::ifstream inFile;
    inFile.open(fileName, std::ios_base::in);

    if (inFile.is_open()) {
        // get length of file:
        inFile.seekg(0, std::ios::end);
        int length = inFile.tellg();
        inFile.seekg(0, std::ios::beg);

        // allocate memory:
        delete[] this->text;
        this->text = new char[length + 1];

        // read data as a block:
        inFile.read(text, length);

        inFile.close();
    }
    else {
        std::cerr << "Message::readFromFile(const char* fileName) => can't open file\n";
    }
}

Message::Message() {
    this->text = copydyn("");
    this->date = copydyn("");
}

Message::Message(const char* fileName, const Person& sender, 
        const Person& receiver, const char* date) 
    : sender(sender), receiver(receiver) {

    this->text = copydyn("");
    this->readFromFile(fileName);

    assert(strlen(date) == 10);
    this->date = copydyn(date);
}

Message::Message(const Message& other) {
    copy(other);
}

Message& Message::operator=(const Message& other) {
    if (this != &other) {
        erase();
        copy(other);
    }

    return *this;
}

Message::~Message() {
    erase();
}

bool Message::operator==(const Message& other) const {
    return this->sender == other.sender &&
        this->receiver == other.receiver &&
        strcmp(this->date, other.date) == 0 &&
        strcmp(this->text, other.text) == 0;
}

bool Message::operator!=(const Message& other) const {
    return !operator==(other);
}

void Message::print() const {
    std::cout << "===================" << this->date << "===================\n";
    std::cout << "Sender: " << this->sender.getName() << std::endl;
    std::cout << "Receiver: " << this->receiver.getName() << std::endl;
    std::cout << "================================================\n";
    std::cout << this->text << std::endl;
    std::cout << "================================================\n";
}

const char* Message::getText() const {
    return this->text;
}

const char* Message::getDate() const {
    return this->date;
}

Person Message::getReceiver() const {
    return this->receiver;
}

Person Message::getSender() const {
    return this->sender;
}

void Message::setText(const char* text) {
    delete[] this->text;
    this->text = copydyn(text);
}

void Message::setDate(const char* date) {
    delete[] this->date;
    this->date = copydyn(date);
}

void Message::setReceiver(const Person& receiver) {
    this->receiver = receiver;
}

void Message::setSender(const Person& sender) {
    this->sender = sender;
}