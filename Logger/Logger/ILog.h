#pragma once
#include <fstream>
#include <iostream>
#include <ctime>

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
	ILog();
	virtual void Log(const std::string& message) = 0;
	~ILog();
};

class Logging : public ILog
{
	void Log(const std::string& message) override;
private:
	std::ofstream logOutput;
	time_t m_timer;
};
