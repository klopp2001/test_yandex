#pragma once
#include "request_queue.h"

std::vector<Document> RequestQueue::AddFindRequest(const std::string& raw_query, DocumentStatus status)
{
    std::vector<Document> result = search_server_.FindTopDocuments(raw_query, status);
    AddToRequests(result.size());
    return result;
}

std::vector<Document> RequestQueue::AddFindRequest(const std::string& raw_query)
{
    std::vector<Document> result = search_server_.FindTopDocuments(raw_query);
    AddToRequests(result.size());
    return result;
}

int RequestQueue::GetNoResultRequests() const
{
    int count = 0;
    for (auto tmp : requests_) {
        if (!tmp.is_empty)
            count++;
    }
    return count;
}

void RequestQueue::AddToRequests(size_t size)
{
    QueryResult query;
    if (size > 0) {
        query = { true };
    }
    else
    {
        query = { false };
    }
    int requests_current_size = requests_.size();
    if (requests_current_size == min_in_day_) {
        requests_.pop_back();
        requests_.push_front(query);
    }
    else {
        requests_.push_front(query);
    }
}
