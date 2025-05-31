#ifndef JOCEEROARE_H
#define JOCEEROARE_H
 
#include <stdexcept>
#include <string>
 
class JocEroare : public std::runtime_error {
public:
    explicit JocEroare(const std::string& mesaj);
};
 
#endif