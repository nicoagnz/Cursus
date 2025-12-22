#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./sed <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::ifstream infile(filename.c_str());
	if (!infile)
	{
		std::cerr << "Error: could not open input file." << std::endl;
		return 1;
	}

	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile)
	{
		std::cerr << "Error: could not create output file." << std::endl;
		return 1;
	}

	std::string line;
	while (std::getline(infile, line))
	{
		outfile << line;
		if (!infile.eof())
			outfile << std::endl;
	}
	return 0;
}
