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

public:
	Log(logLevel LogLevel)
	{
		p_level = LogLevel;
	}
	Log()
	{
		p_level = LevelInfo;
	}


	void Error(std::string Message) const
	{
		if (p_level >= LevelError)
		{
			std::cout << "\033[31m[Error]: " << Message << "\033[0m" << std::endl;
		}

	}
	void Warn(std::string Message) const
	{
		if (p_level >= LevelWarning)
		{
			std::cout << "\033[33m[WARNING]: " << Message << "\033[0m" << std::endl;
		}
	}
	void Info(std::string Message) const
	{
			if (p_level == LevelInfo)
		{
			std::cout << "\033[36m[INFO]: " << Message << "\033[0m" << std::endl;
		}

	}
	void Error(unsigned char Message) const
	{
		if (p_level >= LevelError)
		{
			std::cout << "\033[31m[Error]: " << Message << "\033[0m" << std::endl;
		}

	}
	void Warn(unsigned char Message) const
	{
		if (p_level >= LevelWarning)
		{
			std::cout << "\033[33m[WARNING]: " << Message << "\033[0m" << std::endl;
		}
	}
	void Info(unsigned char Message) const
	{
		if (p_level == LevelInfo)
		{
			std::cout << "\033[36m[INFO]: " << Message << "\033[0m" << std::endl;
		}

	}
	void Error(unsigned int Message) const
	{
		if (p_level >= LevelError)
		{
			std::cout << "\033[31m[Error]: " << Message << "\033[0m" << std::endl;
		}

	}
	void Warn(unsigned int Message) const
	{
		if (p_level >= LevelWarning)
		{
			std::cout << "\033[33m[WARNING]: " << Message << "\033[0m" << std::endl;
		}
	}
	void Info(unsigned int Message) const
	{
		if (p_level == LevelInfo)
		{
			std::cout << "\033[36m[INFO]: " << Message << "\033[0m" << std::endl;
		}

	}
	void Error(int Message) const
	{
		if (p_level >= LevelError)
		{
			std::cout << "\033[31m[Error]: " << Message << "\033[0m" << std::endl;
		}

	}
	void Warn(int Message) const
	{
		if (p_level >= LevelWarning)
		{
			std::cout << "\033[33m[WARNING]: " << Message << "\033[0m" << std::endl;
		}
	}
	void Info(int Message) const
	{
		if (p_level == LevelInfo)
		{
			std::cout << "\033[36m[INFO]: " << Message << "\033[0m" << std::endl;
		}

	}
	void Error(float Message) const
	{
		if (p_level >= LevelError)
		{
			std::cout << "\033[31m[Error]: " << Message << "\033[0m" << std::endl;
		}

	}
	void Warn(float Message) const
	{
		if (p_level >= LevelWarning)
		{
			std::cout << "\033[33m[WARNING]: " << Message << "\033[0m" << std::endl;
		}
	}
	void Info(float Message) const
	{
		if (p_level == LevelInfo)
		{
			std::cout << "\033[36m[INFO]: " << Message << "\033[0m" << std::endl;
		}

	}
	void Error(const unsigned char* Message) const
	{
		if (p_level >= LevelError)
		{
			std::cout << "\033[31m[Error]: " << Message << "\033[0m" << std::endl;
		}

	}
	void Warn(const unsigned char* Message) const
	{
		if (p_level >= LevelWarning)
		{
			std::cout << "\033[33m[WARNING]: " << Message << "\033[0m" << std::endl;
		}
	}
	void Info(const unsigned char* Message) const
	{
		if (p_level == LevelInfo)
		{
			std::cout << "\033[36m[INFO]: " << Message << "\033[0m" << std::endl;
		}

	}
	void GLError(const unsigned int Message) const
	{
		if (p_level >= LevelError)
		{
			std::cout << "\033[31m[OpenGL Error]: " << Message << "\033[0m" << std::endl;
		}

	}
	void sGLError(const int err,const char* function,const char* file,int line) const
	{
		if (p_level >= LevelError)
		{
			std::cout << "\033[31m[OpenGL Error]: in (" << file << "): " << "at line :" << line << " " << function << " Error Code -> " << err << "\033[0m" << std::endl;
		}

	}
	void GLWarn(const unsigned int Message) const
	{
		if (p_level >= LevelWarning)
		{
			std::cout << "\033[33m[OpenGL WARNING]: " << Message << "\033[0m" << std::endl;
		}
	}
	void GLInfo(const unsigned int Message) const
	{
		if (p_level == LevelInfo)
		{
			std::cout << "\033[36m[OpenGL INFO]: " << Message << "\033[0m" << std::endl;
		}

	}

	void Error(std::string Message, std::string Message2) const
	{
		if (p_level >= LevelError)
		{
			std::cout << "\033[31m[Error]: " << Message << Message2 << "\033[0m" << std::endl;
		}

	}
	void Warn(std::string Message, std::string Message2) const
	{
		if (p_level >= LevelWarning)
		{
			std::cout << "\033[33m[WARNING]: " << Message << Message2 << "\033[0m" << std::endl;
		}
	}
	void Info(std::string Message, std::string Message2) const
	{
		if (p_level == LevelInfo)
		{
			std::cout << "\033[36m[INFO]: " << Message << Message2 << "\033[0m" << std::endl;
		}

	}
void Error(std::string Message, const unsigned char* Message2) const
	{
		if (p_level >= LevelError)
		{
			std::cout << "\033[31m[Error]: " << Message << Message2 << "\033[0m" << std::endl;
		}

	}
	void Warn(std::string Message, const unsigned char* Message2) const
	{
		if (p_level >= LevelWarning)
		{
			std::cout << "\033[33m[WARNING]: " << Message << Message2 << "\033[0m" << std::endl;
		}
	}
	void Info(std::string Message, const unsigned char* Message2) const
	{
		if (p_level == LevelInfo)
		{
			std::cout << "\033[36m[INFO]: " << Message << Message2 << "\033[0m" << std::endl;
		}

	}
	void Error(std::string Message, const char* Message2) const
	{
		if (p_level >= LevelError)
		{
			std::cout << "\033[31m[Error]: " << Message << Message2 << "\033[0m" << std::endl;
		}

	}
	void Warn(std::string Message, const char* Message2) const
	{
		if (p_level >= LevelWarning)
		{
			std::cout << "\033[33m[WARNING]: " << Message << Message2 << "\033[0m" << std::endl;
		}
	}
	void Info(std::string Message, const char* Message2) const
	{
		if (p_level == LevelInfo)
		{
			std::cout << "\033[36m[INFO]: " << Message << Message2 << "\033[0m" << std::endl;
		}

	}

};

