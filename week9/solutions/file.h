#pragma once

class File : public FileSystemObject {
public:
    File(const char* name = "N/A", const char* type = "", const int fileSize = 0);

    File(const File& other);

    File& operator=(const File& other);

    ~File();

    virtual FileSystemObject* clone() const;

    virtual int size() const;

protected:
    char* type;
    int fileSize;

private:
    void copy(const File& other);

    void erase();
};

#include "file.cpp"