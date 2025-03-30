#include <iostream>
#include <array>

#include <Helper.h>
#include <string>

class Document {
private:
    std::string dataEliberare;
    std::string dataExpirare;
    std::string emitent;
    std::string numar;
    std::string serie;

public:
    // constructor
    Document(const std::string &data_eliberare, const std::string &data_expirare, const std::string &emitent,
             const std::string &numar, const std::string &serie)
        : dataEliberare(data_eliberare),
          dataExpirare(data_expirare),
          emitent(emitent),
          numar(numar),
          serie(serie) {
    }


    // Destructor
    ~Document() {
        std::cout << "Document deleted" << std::endl;
    }

    // Copy constructor and move constructor
    Document(const Document &other)
        : dataEliberare(other.dataEliberare),
          dataExpirare(other.dataExpirare),
          emitent(other.emitent),
          numar(other.numar),
          serie(other.serie) {
    }

    Document(Document &&other) noexcept
        : dataEliberare(std::move(other.dataEliberare)),
          dataExpirare(std::move(other.dataExpirare)),
          emitent(std::move(other.emitent)),
          numar(std::move(other.numar)),
          serie(std::move(other.serie)) {
    }

    Document &operator=(const Document &other) {
        if (this == &other)
            return *this;
        dataEliberare = other.dataEliberare;
        dataExpirare = other.dataExpirare;
        emitent = other.emitent;
        numar = other.numar;
        serie = other.serie;
        return *this;
    }

    Document &operator=(Document &&other) noexcept {
        if (this == &other)
            return *this;
        dataEliberare = std::move(other.dataEliberare);
        dataExpirare = std::move(other.dataExpirare);
        emitent = std::move(other.emitent);
        numar = std::move(other.numar);
        serie = std::move(other.serie);
        return *this;
    }

    [[nodiscard]] const std::string &get_data_eliberare() const {
        return dataEliberare;
    }

    [[nodiscard]] const std::string &get_data_expirare() const {
        return dataExpirare;
    }

    [[nodiscard]] const std::string &get_emitent() const {
        return emitent;
    }

    [[nodiscard]] const std::string &get_numar() const {
        return numar;
    }

    [[nodiscard]] const std::string &get_serie() const {
        return serie;
    }

    friend std::ostream &operator<<(std::ostream &os, const Document &obj) {
        os << "//////////////////////////////////////////////" << '\n';
        os << "Data eliberare: " << obj.get_data_eliberare() << '\n';
        os << "Data expirare: " << obj.get_data_expirare() << '\n';
        os << "Emitent: " << obj.get_emitent() << '\n';
        os << "Numar: " << obj.get_numar() << '\n';
        os << "Serie: " << obj.get_serie() << '\n';
        os << "//////////////////////////////////////////////" << '\n';
        return os;
    }
};


int main() {

    Document doc1("01-01-2023", "01-01-2024", "Emitent1", "123456", "AB");
    std::cout<<doc1;
    return 0;
}
