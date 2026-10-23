/*
 * Задание 37. Подсчитать русские буквы «а» и «А» в строке UTF-8.
 * Ввод: одна строка, сохранённая в UTF-8.
 * Вывод: количество кодовых точек U+0430 и U+0410.
 * Пример: Мама мыла раму -> 4.
 */
#include <cstdint>
#include <iostream>
#include <string>

bool nextCodePoint(const std::string& text, std::size_t& index,
                   std::uint32_t& code_point) {
    if (index >= text.size()) return false;
    const unsigned char lead = static_cast<unsigned char>(text[index]);
    std::size_t length;
    if (lead <= 0x7F) {
        length = 1;
        code_point = lead;
    } else if (lead >= 0xC2 && lead <= 0xDF) {
        length = 2;
        code_point = lead & 0x1F;
    } else if (lead >= 0xE0 && lead <= 0xEF) {
        length = 3;
        code_point = lead & 0x0F;
    } else if (lead >= 0xF0 && lead <= 0xF4) {
        length = 4;
        code_point = lead & 0x07;
    } else {
        return false;
    }
    if (index + length > text.size()) return false;
    for (std::size_t offset = 1; offset < length; ++offset) {
        const unsigned char byte = static_cast<unsigned char>(text[index + offset]);
        if ((byte & 0xC0) != 0x80) return false;
        code_point = (code_point << 6) | (byte & 0x3F);
    }
    index += length;
    return true;
}

int main() {
    std::string text;
    if (!std::getline(std::cin, text)) {
        std::cerr << "Error\n";
        return 1;
    }
    int count = 0;
    for (std::size_t index = 0; index < text.size();) {
        std::uint32_t code_point;
        if (!nextCodePoint(text, index, code_point)) {
            std::cerr << "Error\n";
            return 1;
        }
        if (code_point == 0x0430 || code_point == 0x0410) ++count;
    }
    std::cout << count << '\n';
    return 0;
}
