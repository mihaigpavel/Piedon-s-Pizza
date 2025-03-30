#include <string>

class Document {
private:
    std::string dataEliberare;
    std::string dataExpirare;
    std::string emitent;
    std::string numar;
    std::string serie;

public:
    Document(const std::string &data_eliberare, const std::string &data_expirare, const std::string &emitent,
        const std::string &numar, const std::string &serie)
        : dataEliberare(data_eliberare),
          dataExpirare(data_expirare),
          emitent(emitent),
          numar(numar),
          serie(serie) {
    }


};


int main() {
    return 0;
}
