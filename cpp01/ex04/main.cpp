/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:39:17 by htharrau          #+#    #+#             */
/*   Updated: 2025/06/09 15:21:55 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Create a program that takes three parameters in the following order: a file-
name and two strings, s1 and s2.
It must open the file <filename> and copy its content into a new file
<filename>.replace, replacing every occurrence of s1 with s2.
Using C file manipulation functions is forbidden and will be considered cheating.
All the member functions of the class std::string are allowed, except replace.
Use them wisely!
Of course, handle unexpected inputs and errors. You must create and turn in your
own tests to ensure that your program works as expected.  */

/*******************************************************************************
File Stream Classes
- std::ifstream: For reading from files.
- std::ofstream: For writing to files.
- std::fstream: For both reading and writing.

Opening Files: use the constructor or .open():
- std::ifstream inputFile("input.txt");
- std::ofstream outputFile;
- outputFile.open("output.txt");
Always check if the file opened successfully:
if (!inputFile.is_open()) { std::cerr << "Failed to open file." << std::endl; }

Reading from Files
- Use std::getline() to read lines:
std::string line;
while (std::getline(inputFile, line)) {     // process line      }
- or use inputFile >> variable; to read word by word

Writing to Files: Use the insertion operator <<:
- outputFile << "Hello, file!" << std::endl;
- You can write variables, strings, etc.

Closing Files
- Always close files when done: inputFile.close(); outputFile.close();
- Files are closed automatically when the stream object is destroyed, but
closing them explicitly is best practice.

File Modes. In order to open a file with a stream object, use its member
function open: open (filename, mode);. The modes:
- std::ios::in Open for input operations.
- std::ios::out Open for output operations.
- std::ios::binary	Open in binary mode.
- std::ios::ate	Set the initial position at the end of the file.If this flag is not set, the initial
position is the beginning of the file.
- std::ios::app	All output operations are performed at the end of the file, appending the content to
the current content of the file.
- std::ios::trunc	If the file is opened for output operations and it already existed, its
previous content is deleted and replaced by the new one. All these flags can be combined using the
bitwise operator OR (|). Default mode: ofstream, ifstream and fstream have a default mode if flag is
missing
- ofstream:	ios::out
- ifstream:	ios::in
- fstream:	ios::in | ios::out

Error Handling
- Always check if a file stream is open before reading/writing.
- You can check with .is_open() or simply test the stream in a boolean context:
if (!inputFile) { // error  }

********************************************/

#include <fstream>
#include <iostream>
#include <string>

#define ERROR 1
#define GLAMOROUS 0

std::string& replaceString(std::string& line, const std::string& s1, const std::string& s2);

int main(int argc, char** argv) {
    if (argc != 4) {
        std::cerr << "Correct syntax: ./sed filename s1 s2" << std::endl;
        return (ERROR);
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream infile(filename.c_str());
    if (!infile) {
        std::cerr << "Error opening input file." << std::endl;
        return (ERROR);
    }

    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile) {
        std::cerr << "Error creating output file." << std::endl;
        return (ERROR);
    }

    std::string line;
    if (s1.empty()) {
        while (std::getline(infile, line)) outfile << line << std::endl;
    }

    else {
        while (std::getline(infile, line)) outfile << replaceString(line, s1, s2) << std::endl;
    }

    infile.close();
    outfile.close();

    return (GLAMOROUS);
}

std::string& replaceString(std::string& line, const std::string& s1, const std::string& s2) {
    size_t i = line.find(s1);

    while (i != std::string::npos) {
        line.erase(i, s1.length());
        line.insert(i, s2);
        i = line.find(s1, i + s2.length());
    }
    return (line);
}
