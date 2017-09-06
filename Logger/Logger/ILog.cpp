#include "ILog.h"
#include <iostream>
#include <chrono>

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

	/*for (int i = 0; true;i++)
	{
		char *x;
		x = new char[i];
	}*/

	logOutput <<" ["<<type<<"] "<< message;

	std::cout << std::endl << " " << logOutput.str() << std::endl;
}

void Timer::start()
{
	_start = std::chrono::system_clock::now();
}

double Timer::getTime()
{
	return _diff.count();
}

void Timer::stop()
{
	_end = std::chrono::system_clock::now();
	_diff = _end - _start;
}

void TimerWrapper::startTimer(const std::string& timerName)
{
	if (_timers.find(timerName) == _timers.end())
	{
		_timers.emplace(timerName, new Timer);
		_timers[timerName]->start();
	}
	else
		std::cout << "Vezi ca e deja adaugat timeru asta. Sal" << std::endl;
}

std::string TimerWrapper::stopTimer(const std::string& timerName)
{
	_timers[timerName]->stop();
	auto time = std::to_string(_timers[timerName]->getTime());
	_timers.erase(timerName);
	return time;
}
