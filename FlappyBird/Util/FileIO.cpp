#include "FlappyBird/Util/FileIO.h"
#include "FlappyBird/Util/Logger.h"

#include <fstream>
#include <sstream>
#include <iostream>

namespace FlappyBird
{
	std::string FileIO::ReadFileContent(const std::string& filepath)
	{
		std::ifstream stream(filepath);
		if (stream.fail())
			FLAPPYBIRD_LOG_CRITICAL("FileIO Failed to Open({})", filepath);

		std::stringstream ss;
		std::string line;
		while (std::getline(stream, line))
			ss << line << "\n";

		stream.close();
		return ss.str();
	}

	void FileIO::WriteFileContent(const std::string& filepath, const std::string& data)
	{
		std::ofstream fout(filepath);
		fout << data.c_str();
	}
}
