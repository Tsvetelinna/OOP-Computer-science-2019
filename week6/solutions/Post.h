#ifndef POST_H
#define POST_H

#include "Message.h"

const int POST_DEFAULT_CAPACITY = 1000;
const char* POST_DEFAULT_OUT_FILE_NAME = "test/test.txt";

class Post {
private:
    Message* messages;
    size_t size;
    size_t capacity;
    std::ofstream outputFile;

    void writeToFile(const Message& m);

    Message deleteMessage(int pos);

    Post(const Post& other);
    Post& operator=(const Post& other);

public:

    Post(size_t maxSize = POST_DEFAULT_CAPACITY, const char* fileName = POST_DEFAULT_OUT_FILE_NAME);
    ~Post();

    void send(const Message& m);
    Message receive(const Person& receiver);
    bool hasMessage(const Person& receiver) const;
};

#include "Post.cpp"

#endif // POST_H