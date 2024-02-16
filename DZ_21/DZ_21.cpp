#include <iostream>
#include <experimental/filesystem>
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

namespace fs = std::experimental::filesystem::v1;

int main() 
{
    setlocale(0, "");
    try {
        fs::path directory_path = "E:/ШАГ/C++ OOP"; // Укажите путь к директории
        uintmax_t total_size = 0;

        for (const auto& entry : fs::recursive_directory_iterator(directory_path)) {
            if (fs::is_regular_file(entry)) {
                total_size += fs::file_size(entry);
            }
        }

        std::cout << "Объем, занимаемый директорией: " << total_size << " байт" << std::endl;
    }
    catch (const fs::filesystem_error& ex) {
        std::cerr << "Ошибка при обработке файловой системы: " << ex.what() << std::endl;
    }

    return 0;
}
