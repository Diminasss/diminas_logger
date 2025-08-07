#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>


class diminas_logger {
public:
    // Constructor (set filename and logging level)
    explicit diminas_logger(const std::string& log_filename, const std::string& log_level = "INFO");
    ~diminas_logger();

    // Logging
    void log(const std::string& log_string);

    // Set logging level (returns true if successful)
    bool set_level(const std::string& new_log_level);
    // Get current logging level
    int get_level() const;

private:
    int log_level;
    std::string log_filename;
    std::ofstream log_file;
    const std::unordered_map<std::string, int> available_levels = {{"INFO", 1}, {"WARN", 2}, {"ERROR", 3}};
};
