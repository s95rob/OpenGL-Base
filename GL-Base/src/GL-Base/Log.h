#pragma once
#include <iostream>
#include <string>

#define LOG_COLOR_ERROR "\033]31m"
#define LOG_COLOR_NORMAL "\033]2m"

class Log {
public:
	static void Write(const std::string& message) {
		std::cout << message << '\n';
	}

	static void Error(const std::string& message) {
		std::cout << "[ ERROR ] " << message << '\n';
	}
};