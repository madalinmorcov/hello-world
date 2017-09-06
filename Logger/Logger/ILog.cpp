#include "ILog.h"
#include <iostream>
#include <sstream>

void Logging::Log(ErrorType ID,const std::string& message)
{

	m_timer = time(0);
	struct tm * now = new tm;
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

	std::string type;

	switch (ID)
	{
	case ErrorType::ERROR:
		type = "ERROR";
		break;
	case ErrorType::WARNING:
		type = "WARNING";
		break;
	case ErrorType::INFO:
		type = "INFO";
		break;
	case ErrorType::DEBUG:
		type = "DEBUG";
		break;
	case ErrorType::FATAL:
		type = "FATAL";
		break;

	}

	logOutput <<"["<<type<<"]"<< message;

	std::cout << " " << logOutput.str() << std::endl;

}
