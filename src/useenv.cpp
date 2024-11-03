#include "../include/useenv.h"
#include <sstream>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <stdexcept>

// Helper function to trim whitespace from both ends of a string
static std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\n\r");
    size_t end = str.find_last_not_of(" \t\n\r");
    return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

// Parse a line and extract key-value pair
void EnvParser::parseLine(const std::string& line) {
    std::string trimmed = trim(line);
    if (trimmed.empty() || trimmed[0] == '#') {
        return;  // Skip empty lines or comments
    }

    size_t equal_pos = trimmed.find('=');
    if (equal_pos == std::string::npos) {
        throw std::runtime_error("Invalid line in .env file: " + line);
    }

    std::string key = trim(trimmed.substr(0, equal_pos));
    std::string value = trim(trimmed.substr(equal_pos + 1));

    // Remove quotes around values if they exist
    if (!value.empty() && value.front() == '"' && value.back() == '"') {
        value = value.substr(1, value.size() - 2);
    }

    env_vars[key] = value;
}

// Load and parse the .env file
void EnvParser::load(const std::string& filepath) {
    std::ifstream env_file(filepath);
    if (!env_file.is_open()) {
        throw std::runtime_error("Could not open .env file: " + filepath);
    }

    std::string line;
    while (std::getline(env_file, line)) {
        parseLine(line);
    }
}

// Constructor: Automatically looks for the .env file
EnvParser::EnvParser() {
    // Define the name of the file to search for
    std::string filepath = ".env";

    // Check if the .env file exists in the current directory
    if (std::filesystem::exists(filepath)) {
        try {
            load(filepath);
        } catch (const std::runtime_error& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    } else {
        std::cerr << "Warning: .env file not found." << std::endl;
    }
}

// Get the value of an environment variable
std::string EnvParser::get(const std::string& key) const {
    auto it = env_vars.find(key);
    if (it != env_vars.end()) {
        return it->second;  // Return the value if found
    }
    throw std::runtime_error("Environment variable not found: " + key);
}