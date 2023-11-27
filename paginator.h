//Вставьте сюда своё решение из урока «‎Очередь запросов».‎
#pragma once
#include <ostream>
template <typename Iterator>
class IteratorRange {
public:
    IteratorRange(Iterator begin, Iterator end) : begin_(begin), end_(end) {

    }
    Iterator begin()const {
        return begin_;
    }
    Iterator end()const {
        return end_;
    }
    auto size() const {
        return distance(begin, end);
    }
private:
    Iterator begin_;
    Iterator end_;
};
template<typename Iterator>
std::ostream& operator <<  (std::ostream& os, const IteratorRange<Iterator>& iterator) {
    auto begin = iterator.begin();
    auto end = iterator.end();
    while (begin != end) {
        os << *begin;
        begin++;
    }
    return os;
}
template <typename Iterator>
class Paginator {
public:
    // тело класса
    Paginator(Iterator begin, Iterator end, size_t page_size) {
        while (begin != end) {
            int counter = page_size;
            const Iterator it_range_begin = begin;
            while (counter != 0) {
                counter--;
                begin++;
                if (begin == end)
                    break;
            }
            const Iterator it_range_end = begin;
            const IteratorRange iter_range(it_range_begin, it_range_end);
            iterators_.push_back(iter_range);
        }
    }
    auto begin() const { return iterators_.begin(); }
    auto end()const { return iterators_.end(); }
    auto size() const { return iterators_.size(); }
private:
    vector <IteratorRange<Iterator>> iterators_;
};

template <typename Container>
auto Paginate(const Container& c, size_t page_size) {



    return Paginator(begin(c), end(c), page_size);
}