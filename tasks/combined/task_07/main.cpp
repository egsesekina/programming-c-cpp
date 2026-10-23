/*
 * Задание 7. Подсчитать число Unicode-символов в корректной строке UTF-8.
 * Ввод: одна строка UTF-8.
 * Вывод: количество кодовых точек, а не байтов.
 * Пример: Привет мир -> 10.
 */
#include <iostream>
#include <string>

bool utf8Length(const std::string& text, std::size_t& count) {
    count = 0;
    for (std::size_t i = 0; i < text.size();) {
        const unsigned char lead = static_cast<unsigned char>(text[i]);
        std::size_t length = 0;
        if (lead <= 0x7F) length = 1;
        else if (lead >= 0xC2 && lead <= 0xDF) length = 2;
        else if (lead >= 0xE0 && lead <= 0xEF) length = 3;
        else if (lead >= 0xF0 && lead <= 0xF4) length = 4;
        else return false;

        if (i + length > text.size()) return false;
        for (std::size_t j = 1; j < length; ++j) {
            const unsigned char byte = static_cast<unsigned char>(text[i + j]);
            if ((byte & 0xC0) != 0x80) return false;
        }
        i += length;
        ++count;
    }
    return true;
}

int main() {
    std::string text;
    if (!std::getline(std::cin, text)) {
        std::cerr << "Error\n";
        return 1;
    }
    std::size_t count;
    if (!utf8Length(text, count)) {
        std::cerr << "Error\n";
        return 1;
    }
    std::cout << count << '\n';
    return 0;
}
