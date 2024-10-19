# UseEnv

A simple C++ library for parsing `.env` files, allowing you to easily manage environtment variables

## Features

- Automatically searches for a `.env` file in the current directory.
- Simple API to retrieve environtment variable values.

## Installation

### Prerequisites

Make sure you have the following installed on your system

- A C++ compiler (e.g., `g++` or `clang++`)
- CMake (optional, if you want to use CMake for building)
- A text editor or IDE (e.g., Visual Studio Code, Code::Blocks, or any other IDE)

### Clone the Repository

To use this library, clone the repository to your local machine using the following command

```bash
git clone https://github.com/ibrahims-main/UseEnv.git
```

## Build Instructions

- Copy the Files: You can include the library in your own project by copying the `include/useenv.h` and `env/useenv.cpp` files into your project directory.

- Create a `.env` File: In the same directory as your project, create a .env file and define your environment

## Compiling With Env

You can compile your code with .env like this

```bash
g++ -o my_program main.cpp env/useenv.cpp -std=c++17
```

## Usage 

### Create a `.env` File
Create a `.env` file in the same directory as your executable or in your project root. Add your environment variables in the following format:

```makefile
DATABASE_HOST=localhost
DATABASE_USER=root
DATABASE_PASSWORD=secret
```

### Example Code
Here’s a simple example of how to use the `EnvParser` library in your project:

```c++
#include <iostream>
#include "include/useenv.h"

int main() {
    EnvParser env; // Automatically searches for the .env file

    try {

        std::string db_host = env.get("DATABASE_HOST");
        std::string db_port = env.get("DATABASE_PORT");
        std::string debug = env.get("DEBUG");

        std::cout << "Database host: " << db_host << std::endl;
        std::cout << "Database port: " << db_port << std::endl;
        std::cout << "Debug mode: " << (debug == "true" ? "On" : "Off") << std::endl;

    } catch(const std::runtime_error& e) {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
```

## License

This project is licensed under the [MIT License](LICENSE) - see the [LICENSE](LICENSE) file for details.

## Contributing

Contributions are welcome! Please feel free to submit issues or pull requests.

Have fun using this easy library :)