#include "Document.h"

Document::Document(const std::string &data_eliberare, const std::string &data_expirare, const std::string &emitent,
                   const std::string &numar, const std::string &serie)
    : dataEliberare(data_eliberare),
      dataExpirare(data_expirare),
      emitent(emitent),
      numar(numar),
      serie(serie) {
}

Document::Document(const std::string &data_eliberare, const std::string &data_expirare, const std::string &emitent,
                   const std::string &numar)
    : dataEliberare(data_eliberare),
      dataExpirare(data_expirare),
      emitent(emitent),
      numar(numar) {
}

Document::Document(const std::string &data_eliberare, const std::string &data_expirare, const std::string &emitent)
    : dataEliberare(data_eliberare),
      dataExpirare(data_expirare),
      emitent(emitent) {
}

Document::Document(const Document &other)
    : dataEliberare(other.dataEliberare),
      dataExpirare(other.dataExpirare),
      emitent(other.emitent),
      numar(other.numar),
      serie(other.serie) {
}

Document::Document(Document &&other) noexcept
    : dataEliberare(std::move(other.dataEliberare)),
      dataExpirare(std::move(other.dataExpirare)),
      emitent(std::move(other.emitent)),
      numar(std::move(other.numar)),
      serie(std::move(other.serie)) {
}

Document &Document::operator=(const Document &other) {
    if (this == &other)
        return *this;
    dataEliberare = other.dataEliberare;
    dataExpirare = other.dataExpirare;
    emitent = other.emitent;
    numar = other.numar;
    serie = other.serie;
    return *this;
}

Document &Document::operator=(Document &&other) noexcept {
    if (this == &other)
        return *this;
    dataEliberare = std::move(other.dataEliberare);
    dataExpirare = std::move(other.dataExpirare);
    emitent = std::move(other.emitent);
    numar = std::move(other.numar);
    serie = std::move(other.serie);
    return *this;
}

const std::string &Document::get_data_eliberare() const {
    return dataEliberare;
}

const std::string &Document::get_data_expirare() const {
    return dataExpirare;
}

const std::string &Document::get_emitent() const {
    return emitent;
}

const std::string &Document::get_numar() const {
    return numar;
}

const std::string &Document::get_serie() const {
    return serie;
}

std::ostream &operator<<(std::ostream &os, const Document &obj) {
    os << "Data eliberare: " << obj.dataEliberare << '\n';
    os << "Data expirare: " << obj.dataExpirare << '\n';
    os << "Emitent: " << obj.emitent << '\n';
    if (!obj.numar.empty())
        os << "Numar: " << obj.numar << '\n';
    if (!obj.serie.empty())
        os << "Serie: " << obj.serie << '\n';
    return os;
}
