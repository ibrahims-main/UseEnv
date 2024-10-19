#ifndef ENV_PARSER_H
#define ENV_PARSER_H

#include <unordered_map>
#include <string>
#include <fstream>
#include <stdexcept>
#include <iostream>

class EnvParser {
    private:
        std::unordered_map<std::string, std::string> env_vars;

        void parseLine(const std::string& line);
        void load(const std::string& filepath);  // Loads a specific file

    public:
        EnvParser();  // Constructor automatically searches for the .env file
        std::string get(const std::string& key) const;  // Get value without default
};

#endif // ENV_PARSER_H