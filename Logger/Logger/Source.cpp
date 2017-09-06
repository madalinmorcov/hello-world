#include <iostream>
#include "ILog.h"
#include <string.h>

void main()
{
	Logging LoggIt;

	Timer x;

	x.start();



	x.stop();

	LoggIt.Log(ErrorType::ERROR, "ya man " + std::to_string(x.getTime()));

}