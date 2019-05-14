#pragma once
#include <cstring>

char* copydyn(const char* str) {
    char* res = new char[strlen(str) + 1];
    strcpy(res, str);
    return res;
}


class FileSystemObject {
public:
    FileSystemObject(const char* name = "N/A");

    FileSystemObject(const FileSystemObject& other);

    FileSystemObject& operator=(const FileSystemObject& other);

    virtual ~FileSystemObject();

    virtual int size() const = 0;

    virtual FileSystemObject* clone() const = 0;

protected:
    char* name;

private:
    void copy(const FileSystemObject& other);

    void erase();
};

#include "fso.cpp"