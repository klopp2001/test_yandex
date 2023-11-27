#include "document.h"

//Вставьте сюда своё решение из урока «Очередь запросов» темы «Стек, очередь, дек».‎

Document::Document(int id, double relevance, int rating)
    : id(id)
    , relevance(relevance)
    , rating(rating) {
}
std::ostream& operator<< (std::ostream& os, const Document& document) {
    return os << "{ document_id = " << document.id << ", relevance = " << document.relevance << ", rating = " << document.rating << " }";
}