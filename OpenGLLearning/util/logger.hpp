#pragma once
#include <iostream>

enum logLevel {
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	FATAL
};

class Logger {
public:
		
	Logger(logLevel);
	~Logger();
	void log(logLevel, const char*);
private:
	int currentFilterLevel;
	const char* lvlName[5] = { "DEBUG", "INFO", "WARNING", "ERROR", "FATAL" };
};
	
Logger::Logger(logLevel filter) {
	this->currentFilterLevel = filter;
}

void Logger::log(logLevel level, const char* message) {
	if (level >= this->currentFilterLevel) {
		std::cout << "[" << this->lvlName[level] << "] " << message << "\n";
	}
}
