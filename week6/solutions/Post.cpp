#include "Post.h"
#include "Message.h"

void Post::writeToFile(const Message& m) {

    outputFile << m.getDate() << " "
               << m.getSender().getName() << " "
               << m.getReceiver().getName() << std::endl;
}

Message Post::deleteMessage(int pos) {
    Message message = messages[pos];
    
    for (int i = pos; i < size - 1; i++) {
        messages[i] = messages[i + 1];
    }
    messages[size - 1] = Message();
    size--;

    return message;
}

Post::Post(size_t maxSize, const char* fileName) {

    this->capacity = maxSize;
    this->messages = new Message[capacity];
    this->size = 0;

    this->outputFile.open(fileName);
}

void Post::send(const Message& m) {

    assert(this->size + 1 < this->capacity);

    this->messages[this->size++] = m;

    this->writeToFile(m);
}

Message Post::receive(const Person& receiver) {

    for(int i = 0; i < size; i++) {

        if(messages[i].getReceiver() == receiver) {

            return deleteMessage(i);     
        }
    }

    return Message();
}

bool Post::hasMessage(const Person& receiver) const {

    for(int i = 0; i < size; i++) {
        if(messages[i].getReceiver() == receiver) {
            return true;
        }
    }

    return false;
}

Post::~Post() {
    delete[] messages;
}