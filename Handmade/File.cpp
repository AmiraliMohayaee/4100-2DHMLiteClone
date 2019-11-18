#include "File.h"


File::File(std::string& filename)
{
	// Indicating a file is being created intended
	// to take in strings
	m_openFile->open(filename, std::ios::out | std::ios::binary);
}

File::~File()
{
	CloseFile();	// Incase the user forgets to deallocate
	delete m_openFile;
}

// Called incase the overloaded constructed is not called
bool File::CreateAFile(std::string filename)
{
	m_openFile->open(filename, std::ios::out | std::ios::binary);

	if (m_openFile->fail())
	{
		std::cout << "File Could not be found" << std::endl;
		return false;
	}

	return true;
}

bool File::WriteToFile(std::string writing)
{
	m_fileString = writing;

	if (!m_openFile->is_open())
	{
		std::cout << "Could not write to file. Possible wrong path or "
			<< "format." << std::endl;
		return false;
	}

	*m_openFile << m_fileString;

	return true;
}


bool File::CloseFile()
{
	if (!m_openFile->is_open())
	{
		std::cout << "Failed to access File." << std::endl;
		return false;
	}

	m_openFile->close();

	return true;
}

std::string File::GetLine(int lineNum)
{
	if (m_fileString.empty())
	{
		std::cout << "Cannot Find line on File." << std::endl;
	}
	else
	{
		return m_fileString;
	}
}


bool File::ReadFile(const std::string filename)
{
	m_openFile->open(filename, std::ios::in |
		std::ios::out);

	// Opens existing file
	if (m_openFile->is_open())
	{
		std::cout << "File Successfully opened" << std::endl;
		char str;

		while (m_openFile->get(str))
		{
			std::cout << str;
		}
		std::cout << std::endl;

		return true;
	}
	else
	{
		std::cout << "File Read Error. Enter correct path." << std::endl;
		return false;
	}
}
