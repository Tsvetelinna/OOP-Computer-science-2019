#include <cassert>

Directory::Directory(const char* name) : FileSystemObject(name) {
    this->objectsCount = 0;
}

Directory::Directory(const Directory& other) : FileSystemObject(other) {
    copy(other);
}

Directory& Directory::operator=(const Directory& other) {
    if (this != &other) {
        erase();
        FileSystemObject::operator=(other);
        copy(other);
    }

    return *this;
}

Directory::~Directory() {
    erase();
}

void Directory::addObject(FileSystemObject* object) {

    assert(objectsCount < MAX_FSObjects - 1);
    objects[objectsCount++] = object->clone();
}

FileSystemObject* Directory::clone() const {
    return new Directory(*this);
}

int Directory::size() const {
    int dirSize = 0;

    for (int i = 0; i < objectsCount; i++) {
        dirSize += objects[i]->size();
    }

    return dirSize;
}

void Directory::copy(const Directory& other) {
    objectsCount = other.objectsCount;

    for (int i = 0; i < objectsCount; i++) {
        objects[i] = other.objects[i]->clone();
    }
}

void Directory::erase() {
    for (int i = 0; i < objectsCount; i++) {
        delete objects[i];
    }
}
