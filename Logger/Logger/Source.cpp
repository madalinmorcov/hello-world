#include <iostream>
#include "ILog.h"
#include <string.h>

void main()
{
	Logging LoggIt;

	LoggIt.Log(ErrorType::ERROR, "again man");
}