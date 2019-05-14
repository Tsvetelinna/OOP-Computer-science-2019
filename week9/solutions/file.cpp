
File::File(const char* name, const char* type, const int fileSize)
    : FileSystemObject(name) {

    this->type = copydyn(type);
    this->fileSize = fileSize;
}

File::File(const File& other) : FileSystemObject(other) {
    copy(other);
}

File& File::operator=(const File& other) {
    if (this != &other) {
        erase();
        FileSystemObject::operator=(other);
        copy(other);
    }

    return *this;
}

File::~File() {
    erase();
}

FileSystemObject* File::clone() const {
    return new File(*this);
}

int File::size() const {
    return fileSize;
}


void File::copy(const File& other) {
    type = copydyn(other.type);
    fileSize = other.fileSize;
}

void File::erase() {
    delete[] type;
}
