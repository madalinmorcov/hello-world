#pragma once
#include <fstream>
#include <iostream>
#include <ctime>
#include <sstream>
#include <chrono>
#include <unordered_map>

//#define LOG_API _declspec(dllexport)

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
	virtual void Log(ErrorType ID,const std::string& message) = 0;
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

class Timer
{
public:
	void start();
	double getTime();
	void stop();
private:
	std::chrono::time_point<std::chrono::system_clock> _start;
	std::chrono::time_point<std::chrono::system_clock> _end;
	std::chrono::duration<double> _diff;
};
class TimerWrapper
{
public:
	void startTimer(const std::string& timerName);
	std::string stopTimer(const std::string& timerName);
private:
	std::unordered_map<std::string, Timer*> _timers;
};