#include <iostream>
#include <string>
#include "../../Logger/ILog.h"
#include "../../Logger/ILog.cpp"

class Printer
{
public:
	virtual void execute() = 0;
	Logging _manage;
	TimerWrapper _rapper;
};

class RealSubject : public Printer
{
public:
	RealSubject(std::string string) : str(string) {};
	void execute() override
	{
		std::cout << str;
		_manage.Log(ErrorType::INFO, "RealSubject => execute()  -  OK");
	}
	~RealSubject() = default;
private:
	std::string str;
};

class ProxySubject : public Printer
{
private:
	RealSubject *real;
	std::string _trueOne;
public:
	ProxySubject(std::string str): _trueOne(str)
	{
		real = new RealSubject(_trueOne.substr(16));
	}
	void execute () override
	{
		std::string strWork = _trueOne;
		size_t start = strWork.find_first_of(' ');
		start = strWork.find_first_of(' ',start+1);
		size_t end = strWork.size();
		strWork = strWork.erase(start,end);

		std::cout << strWork << " ";

		real->execute();

	}
	RealSubject* operator -> (){
		std::string timerName = "timer1";
		_rapper.startTimer(timerName);
		_rapper.startTimer("otherTimer");

		std::string strWork = _trueOne;
		size_t start = strWork.find_first_of(' ');
		start = strWork.find_first_of(' ', start + 1);
		start = strWork.find_first_of(' ', start + 1);
		size_t end = strWork.size();

		_manage.Log(ErrorType::INFO, _rapper.stopTimer("otherTimer") + " : RealSubject => execute()  -  OK");

		strWork = strWork.erase(start, end);                         ////       not sexy
		start = strWork.find_first_of(' ');
		end = strWork.find_first_of(' ', start + 1);

		strWork = strWork.erase(start, end-3);

		std::cout << strWork << " ";

		
		_manage.Log(ErrorType::INFO, _rapper.stopTimer(timerName)+ " : RealSubject => execute()  -  OK");


		return real;
	}
	~ProxySubject()
	{
		delete real;
	}
};

void main()
{
	ProxySubject obj("the quick brown fox jumped over the dog");
	obj->execute();
	std::cout << std::endl;
	obj.execute();
	std::cout << std::endl;
}

//
//#include <iostream>
//#include <string>
//
//class Printer
//{
//public:
//	virtual auto execute() -> void = 0;
//};
//
//class RealPrinter : public Printer
//{
//private:
//	std::string str;
//public:
//	RealPrinter(std::string str)
//	{
//		this->str = str;
//	}
//	virtual auto execute() -> void
//	{
//		std::cout << str << std::endl;
//	}
//};
//
//class ProxyPrinter : public Printer
//{
//private:
//	std::string str;
//	size_t commonStringPos = 0;
//	RealPrinter *rp = nullptr;
//public:
//	ProxyPrinter(std::string str)
//	{
//		this->str = str;
//		for (auto word = 0; word < 3; ++word)
//			commonStringPos = str.find(' ', commonStringPos);
//		rp = new RealPrinter(str.substr(commonStringPos, str.length));
//	}
//
//	virtual auto execute() -> void
//	{
//		size_t wordStart = str.find_first_of(' ');
//		size_t wordEnd = str.find_first_of(' ', wordStart + 1);
//		std::string temp = str;
//		temp.erase(wordStart, wordEnd);
//		std::cout << temp;
//		rp->execute();
//	}
//
//	Printer* operator->()
//	{
//		size_t wordStart = str.find_first_of(' ');
//		size_t wordEnd = str.find_first_of(' ', wordStart + 1);
//		std::string temp = str;
//		temp.erase(wordStart, wordEnd);
//		std::cout << temp;
//		return rp;
//	}
//
//	~ProxyPrinter()
//	{
//		delete rp;
//	}
//};
//
//auto main() -> int
//{
//	ProxyPrinter obj(std::string("the quick brown fox jumped over the dog"));
//	obj->execute();
//	obj.execute();
//	return 0;
//}