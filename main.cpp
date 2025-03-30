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

    [[nodiscard]] std::string & get_data_eliberare() {
        return dataEliberare;
    }

    void set_data_eliberare(const std::string &data_eliberare) {
        dataEliberare = data_eliberare;
    }

    [[nodiscard]] std::string & get_data_expirare() {
        return dataExpirare;
    }

    void set_data_expirare(const std::string &data_expirare) {
        dataExpirare = data_expirare;
    }

    [[nodiscard]] std::string & get_emitator() {
        return emitator;
    }

    void set_emitator(const std::string &emitator) {
        this->emitator = emitator;
    }
};


int main() {
    return 0;
}