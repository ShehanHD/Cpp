#ifndef IOFILE_H
#define IOFILE_H

#include <iostream>

class IOFile {
private:
    std::string toUPPER(std::string);
    std::string filterSTR(std::string);
    bool exists(const char *);
    int h(char);
    void PDFtoTXT(char *);


public:
    void setPDF(char *);
    void setTXT(char *);
    void setManual();
};

#endif // IOFILE_H
