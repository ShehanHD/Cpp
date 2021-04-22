//
// Created by sheha_xp3yxp0 on 22/04/2021.
//

#include "Student.h"

Student::Student(std::string name, std::string surname, std::string email) : name(name), surname(surname), email(email) {
    this->id = uuid(20);
    this->name = name;
    this->surname = surname;
    this->email = email;
}

Student::Student(std::string id, std::string name, std::string surname, std::string email) : id(std::move(id)), name(std::move(name)), surname(std::move(surname)), email(std::move(email)) {
    this->id = id;
    this->name = name;
    this->surname = surname;
    this->email = email;
}

std::string Student::uuid(const int len) {
    time(NULL);
    std::string newId;
    static const char alphanum[] ="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    srand((rand())  * getpid());

    newId.reserve(len);

    for (int i = 0; i < len; ++i)
        newId += alphanum[rand() % (sizeof(alphanum) - 1)];

    return newId;
}

const std::string &Student::getId() const {
    return id;
}

void Student::setId(const std::string &id) {
    Student::id = id;
}

const std::string &Student::getName() const {
    return name;
}

void Student::setName(const std::string &name) {
    Student::name = name;
}

const std::string &Student::getSurname() const {
    return surname;
}

void Student::setSurname(const std::string &surname) {
    Student::surname = surname;
}

const std::string &Student::getEmail() const {
    return email;
}

void Student::setEmail(const std::string &email) {
    Student::email = email;
}

std::ostream &operator<<(std::ostream &os, Student &student) {
    os << "id: " << student.id << " name: " << student.name << " surname: " << student.surname << " email: "
       << student.email;
    return os;
}
