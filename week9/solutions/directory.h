#pragma once

const int MAX_FSObjects = 256;


class Directory : public FileSystemObject {
public:
    Directory(const char* name = "N/A");

    Directory(const Directory& other);

    Directory& operator=(const Directory& other);

    ~Directory();

    void addObject(FileSystemObject* object);

    virtual FileSystemObject* clone() const;

    virtual int size() const;;

protected:
    int objectsCount;
    FileSystemObject *objects[MAX_FSObjects];

private:
    void copy(const Directory& other);

    void erase();
};

#include "directory.cpp"