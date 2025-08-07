#include "diminas_logger.h"


diminas_logger::diminas_logger(const std::string& log_filename, const std::string& log_level) {

    // Check .log in filename
    if (log_filename.find(".log") != std::string::npos) {
        this->log_filename = log_filename;
    } else {
        this->log_filename = "diminas_log.log";
    }

    // Check available log levels
    if (available_levels.find(log_level) != available_levels.end()) {
        this->log_level = available_levels.at(log_level);
    } else {
        this->log_level = 1; // INFO
    }

    // Open log file
    this->log_file.open(log_filename, std::ios::out);


    std::cout << "Logger initialized, file: " << this->log_filename << ", level: " << this->log_level << std::endl;
    this->log_file << "Logger initialized, file: " << this->log_filename << ", level: " << this->log_level << std::endl;
}

diminas_logger::~diminas_logger() {
    if (this->log_file.is_open()){
        this->log_file.close();
    }
}

bool diminas_logger::set_level(const std::string& new_log_level) {
    if (this->available_levels.find(new_log_level) != this->available_levels.end()) {
        this->log_level = available_levels.at(new_log_level);
        return true;
    } else {
        return false;
    }
}

int diminas_logger::get_level() const {
    return this->log_level;
}

void diminas_logger::log(const std::string& log_string) {
    this->log_file.clear();
    this->log_file.seekp(0, std::ios::end);
    this->log_file << log_string << std::endl;
}
