#include <iostream>
#include <array>

#include <Helper.h>
#include <string>

class Document {
    std::string dataEliberare;
    std::string dataExpirare;
    std::string emitator;

public:
    Document(const std::string &data_eliberare, const std::string &data_expirare, const std::string &emitator)
        : dataEliberare(data_eliberare),
          dataExpirare(data_expirare),
          emitator(emitator) {
    }

    [[nodiscard]] std::string data_eliberare() const {
        return dataEliberare;
    }

    [[nodiscard]] std::string data_expirare() const {
        return dataExpirare;
    }

    [[nodiscard]] std::string emitator1() const {
        return emitator;
    }
};


int main() {
    return 0;
}