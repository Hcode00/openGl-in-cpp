#pragma once
#include <string>
#include <iostream>

#define LOG(x) std::cout << x << std::endl

class Log
{
public:
	const enum logLevel {
	  LevelError,
	  LevelWarning,
	  LevelInfo
	};

private:
	int p_level = LevelInfo;
	static int m_no_errors;
	static int m_no_warnings;
	static int m_no_infos;

public:
	Log(logLevel LogLevel)
	{
		p_level = LogLevel;
	}
	Log()
	{
		p_level = LevelInfo;
	}

	static void getCount()
	{
		std::string errors = "\033[31m" + std::to_string(m_no_errors) + " E" + "\033[0m";
		std::string warnings = "\033[33m" + std::to_string(m_no_warnings) + " W" + "\033[0m";
		std::string infos = "\033[36m" + std::to_string(m_no_infos) + " I" + "\033[0m";
		std::cout << "[ " + errors + " - " + warnings + " - " + infos + " ]\n";
	}

	void Error(std::string Message) const
	{
		m_no_errors++;
		if (p_level >= LevelError)
		{
			std::cout << "\033[31m[Error]: " << Message << "\033[0m" << std::endl;
		}

	}
	void Warn(std::string Message) const
	{
		m_no_warnings++;
		if (p_level >= LevelWarning)
		{
			std::cout << "\033[33m[WARNING]: " << Message << "\033[0m" << std::endl;
		}
	}
	void Info(std::string Message) const
	{
		m_no_infos++;
			if (p_level == LevelInfo)
		{
			std::cout << "\033[36m[INFO]: " << Message << "\033[0m" << std::endl;
		}

	}
	void Error(std::string Message, std::string Message2) const
	{
		m_no_errors++;
		if (p_level >= LevelError)
		{
			std::cout << "\033[31m[Error]: " << Message << Message2 << "\033[0m" << std::endl;
		}

	}
	void Warn(std::string Message, std::string Message2) const
	{
		m_no_warnings++;
		if (p_level >= LevelWarning)
		{
			std::cout << "\033[33m[WARNING]: " << Message << Message2 << "\033[0m" << std::endl;
		}
	}
	void Info(std::string Message, std::string Message2) const
	{
		m_no_infos++;
		if (p_level == LevelInfo)
		{
			std::cout << "\033[36m[INFO]: " << Message << Message2 << "\033[0m" << std::endl;
		}

	}
void Error(std::string Message, const unsigned char* Message2) const
	{
		m_no_errors++;
		if (p_level >= LevelError)
		{
			std::cout << "\033[31m[Error]: " << Message << Message2 << "\033[0m" << std::endl;
		}

	}
	void Warn(std::string Message, const unsigned char* Message2) const
	{
		m_no_warnings++;
		if (p_level >= LevelWarning)
		{
			std::cout << "\033[33m[WARNING]: " << Message << Message2 << "\033[0m" << std::endl;
		}
	}
	void Info(std::string Message, const unsigned char* Message2) const
	{
		m_no_infos++;
		if (p_level == LevelInfo)
		{
			std::cout << "\033[36m[INFO]: " << Message << Message2 << "\033[0m" << std::endl;
		}

	}
	void Error(std::string Message, const char* Message2) const
	{
		m_no_errors++;
		if (p_level >= LevelError)
		{
			std::cout << "\033[31m[Error]: " << Message << Message2 << "\033[0m" << std::endl;
		}

	}
	void Warn(std::string Message, const char* Message2) const
	{
		m_no_warnings++;
		if (p_level >= LevelWarning)
		{
			std::cout << "\033[33m[WARNING]: " << Message << Message2 << "\033[0m" << std::endl;
		}
	}
	void Info(std::string Message, const char* Message2) const
	{
		m_no_infos++;
		if (p_level == LevelInfo)
		{
			std::cout << "\033[36m[INFO]: " << Message << Message2 << "\033[0m" << std::endl;
		}

	}

};
int	Log::m_no_errors;
int	Log::m_no_warnings;
int	Log::m_no_infos;

