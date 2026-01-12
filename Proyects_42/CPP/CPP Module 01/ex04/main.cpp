/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:00:58 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/01/12 12:00:59 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string replaceLine(const std::string &line, const std::string &s1, const std::string &s2)
{
	if (s1.empty())
		return line;

	std::string result;
	size_t pos = 0;
	size_t found = 0;

	while ((found = line.find(s1, pos)) != std::string::npos)
	{
		result.append(line, pos, found - pos);
		result += s2;
		pos = found + s1.length();
	}
	result.append(line, pos);
	return result;
}

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
		outfile << replaceLine(line, s1, s2);
		if (!infile.eof())
			outfile << std::endl;
	}
	return 0;
}
