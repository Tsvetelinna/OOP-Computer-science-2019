#include <iostream>
#include <fstream>
#include <cstring>
#include "Person.h"
#include "Message.h"
#include "Post.h"

char* copydyn(const char* str) {
    char* res = new char[strlen(str) + 1];
    strcpy(res, str);
    return res;
}

int main() {

    Post post;
    Person sender("Bobi", "0000000001");
    Person receiver("Tsveti", "0000000002");

    post.send(Message("test/file1.txt", sender, receiver, "2019-04-02"));
    post.send(Message("test/file2.txt", sender, receiver, "2019-04-03"));
    post.send(Message("test/file3.txt", sender, receiver, "2019-04-04"));

    while (post.hasMessage(receiver)) {
        Message message = post.receive(receiver);
        message.print();
        std::cout << std::endl;
    }

    return 0;
}