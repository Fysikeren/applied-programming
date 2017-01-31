#include "FileNotOpenException.hpp"

FileNotOpenException::FileNotOpenException(std::string prob) : Exception("Test", prob) {}