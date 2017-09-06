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
	virtual void Log(const std::string& message)=0;
	~ILog();
	
private:
	std::ofstream logOutput;
	time_t m_timer;
	

};

m_timer = time(0);
	struct tm * now= new tm;
	localtime_s(now, &m_timer);
	logOutput << now->tm_mday << '/'
		<< (now->tm_mon + 1) << '/'
		<< (now->tm_year + 1900) << " "
		<< now->tm_hour << ":";
	if (now->tm_min < 10)
		logOutput << '0' << now->tm_min << ":";
	else
		logOutput << now->tm_min << ":";
	if (now->tm_sec < 10)
		logOutput << '0' << now->tm_sec;
	else
		logOutput << now->tm_sec;

	logOutput << message;
