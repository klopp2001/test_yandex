//Вставьте сюда своё решение из урока «Очередь запросов» темы «Стек, очередь, дек».‎
#pragma once
#include "search_server.h"
#include <deque>

class RequestQueue {
public:
    explicit RequestQueue(const SearchServer& search_server) : search_server_(search_server) {
        // напишите реализацию

    }
    // сделаем "обёртки" для всех методов поиска, чтобы сохранять результаты для нашей статистики
    template <typename DocumentPredicate>
    std::vector<Document> AddFindRequest(const std::string& raw_query, DocumentPredicate document_predicate) {
        std::vector<Document> result = search_server_.FindTopDocuments(raw_query, document_predicate);
        AddToRequests(result.size());
        return result;
    }
    std::vector<Document> AddFindRequest(const std::string& raw_query, DocumentStatus status);
    std::vector<Document> AddFindRequest(const std::string& raw_query);
    int GetNoResultRequests() const;
private:
    struct QueryResult {
        // определите, что должно быть в структуре
        bool is_empty;
    };
    void AddToRequests(size_t  size);
    std::deque<QueryResult> requests_;
    const static int min_in_day_ = 1440;
    // возможно, здесь вам понадобится что-то ещё
    const  SearchServer& search_server_;
};
