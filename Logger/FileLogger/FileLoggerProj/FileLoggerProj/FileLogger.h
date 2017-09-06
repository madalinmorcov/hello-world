#pragma once
#include "../Logger/ILog.h"
#include <ctime>
#include <fstream>

class FileLogger : public ILog
{
public:
	FileLogger();
	void Log(const std::string& message);
	~FileLogger();

private:
	std::ofstream logOutput;
	time_t m_timer;
};

