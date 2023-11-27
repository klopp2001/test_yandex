#include "read_input_functions.h"
//Вставьте сюда своё решение из урока «Очередь запросов» темы «Стек, очередь, дек».‎
std::string ReadLine() {
    std::string s;
    std::getline(std::cin, s);
    return s;
}

int ReadLineWithNumber() {
    int result;
    std::cin >> result;
    ReadLine();
    return result;
}


