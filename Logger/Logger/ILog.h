#pragma once
#include <fstream>
#include <iostream>
#include <ctime>
#include <sstream>

enum class ErrorType
{
	FATAL,
	ERROR,
	WARNING,
	INFO,
	DEBUG,
	ENUMEND
};

class ILog
{
public:
	ILog() = default;
	//virtual void Log(const std::string& message) = 0;
	~ILog() = default;
};

class Logging : public ILog
{
public:
	void Log(ErrorType ID,const std::string& message);
private:
	std::stringstream logOutput;
	time_t m_timer;
};
