#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <fstream>
#include <string>


class File
{
public:
	File();
	File(std::string& filename);
	~File();
	bool CreateAFile(std::string filename);
	bool WriteToFile(std::string writing);
	bool ReadFile(const std::string filename);	// perhaps an int param for line num?
	bool CloseFile();
	std::string GetLine(int lineNum);

private:
	std::fstream* m_openFile;
	std::string m_fileString;
};


#endif