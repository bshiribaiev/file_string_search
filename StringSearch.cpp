/*
	Name: StringSearch
	Copyright: 2023
	Author: Bekbol Shiribaiev
	Date: 27/10/23 14:36
	Description: This program asks a user for a file name and a string
	to search for and displays the line with a string on a screen
	and how many times it appeared in the file
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function prototypes
string getFileName();
void openFile(fstream &, string);
string getString(fstream &);
void displayStrings(fstream &, string);

// Main test driver
int main() {
	fstream userFile;
	string userFileName = getFileName();
	openFile(userFile, userFileName);
	string userString = getString(userFile);
	displayStrings(userFile, userString);
	userFile.close();
	return 0;
}

// Function to get a file name from the user
string getFileName() {
	string fileName;
	cout << "Enter a file name you want to open: ";
	getline(cin, fileName);
	return fileName;
}

// Function to get file name from a user and open it
void openFile(fstream &file, string fileName) {
	file.open(fileName, ios::in);
	cout << "Opening a file...\n" << endl;
	if(!file) {
		cout << "Error opening the file. " << endl;
		return;
	} else
		cout << "File successfully opened!" << endl;
}

// Function to get a specified string from the user
string getString(fstream &file) {
	string userString;
	if(file) {
		cout << "Enter a string to search for: " << endl;
		cin >> userString;
	}
	return userString;
}

// Function to display the lines with a string
void displayStrings(fstream &file, string userInput) {
	string line;
	int count = 0;
	if(file) {
		cout << "The lines in the file that contain your string: \n";
		while(getline(file, line)) {
			if(line.find(userInput) != string::npos) {
				cout << line << endl;
				count ++;
			}
		}
		cout << "The string appeared " << count << " times in the file.\n";
	}
}
