#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>
#include <iostream>

class Document {
private:
    std::string dataEliberare;
    std::string dataExpirare;
    std::string emitent;
    std::string numar;
    std::string serie;

public:
    Document(const std::string &data_eliberare, const std::string &data_expirare, const std::string &emitent,
             const std::string &numar, const std::string &serie);

    Document(const std::string &data_eliberare, const std::string &data_expirare, const std::string &emitent,
             const std::string &numar);

    Document(const std::string &data_eliberare, const std::string &data_expirare, const std::string &emitent);

    Document(const Document &other);
    Document(Document &&other) noexcept;

    Document &operator=(const Document &other);
    Document &operator=(Document &&other) noexcept;

    [[nodiscard]] const std::string &get_data_eliberare() const;
    [[nodiscard]] const std::string &get_data_expirare() const;
    [[nodiscard]] const std::string &get_emitent() const;
    [[nodiscard]] const std::string &get_numar() const;
    [[nodiscard]] const std::string &get_serie() const;

    friend std::ostream &operator<<(std::ostream &os, const Document &obj);
};

#endif // DOCUMENT_H
