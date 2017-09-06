#pragma once
#include <ctime>
#include <fstream>
#include "../../Logger/ILog.h"

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

