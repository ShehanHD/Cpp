//
// Created by sheha_xp3yxp0 on 22/04/2021.
//

#ifndef REFRESH_STUDENT_H
#define REFRESH_STUDENT_H
#include <iostream>
#include <ctime>
#include <unistd.h>
class Student{
private:
    std::string id;
    std::string name;
    std::string surname;
    std::string email;
    std::string uuid(int len);

public:
    Student(std::string name, std::string surname, std::string email);

    Student(std::string id, std::string name, std::string surname, std::string email);

    const std::string &getId() const;

    void setId(const std::string &id);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getSurname() const;

    void setSurname(const std::string &surname);

    const std::string &getEmail() const;

    void setEmail(const std::string &email);

    friend std::ostream &operator<<(std::ostream &os, Student &student);
};

#endif //REFRESH_STUDENT_H
