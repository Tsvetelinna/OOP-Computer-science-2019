
FileSystemObject::FileSystemObject(const char* name) {
    this->name = copydyn(name);
}

FileSystemObject::FileSystemObject(const FileSystemObject& other) {
    copy(other);
}

FileSystemObject& FileSystemObject::operator=(const FileSystemObject& other) {
    if (this != &other) {
        erase();
        copy(other);
    }

    return *this;
}

FileSystemObject::~FileSystemObject() {
    erase();
}


void FileSystemObject::copy(const FileSystemObject& other) {
    name = copydyn(other.name);
}

void FileSystemObject::erase() {
    delete[] name;
}
