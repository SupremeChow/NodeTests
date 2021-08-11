/**
@date 7/30/2021

Tries.h


Header file for Tries data structure. Used for identifying words in a dictionary. This is the main class that will use TriesNode's to hold various letters and determine if a word.
Later implementation may save to file and load, etc. May make use of linkikng words that are same (ie car, c@r, caaaarrrrr, etc...)

This class is essentially a sort of overall wrapper of the TriesNode, which handles holding the entire data structure, and can hold info on the entire dictionary it represents.
For example, thgis class can track the ammount of words in the Tries, assign definitions, etc. 

*/


#pragma once

#include "TriesNode.h"
#include <string>
#include <sstream> //for stringstream needed for parsing and tokenizing dictionary input

#include <fstream> //Reading and writing to file
#include <iostream>

#include <memory> // for using smart pointer, something new

using namespace std;

class Tries
{
private:
	unique_ptr<TriesNode> root;

	ifstream infile;
	ofstream outfile;

	//TODO the infile reference may be redundant, since infile is already used. Hold off on this
	//bool processDictionary(const ifstream& infile); 
	bool processDictionary();

	//TODO Possibly hold a directory path to a file where dictionary is writen/read. Initially, set to curren local path with name like 'tempTries.dic', and will require new name when saving
	//If reading in a file, this path will update to that file path.
	//*Also, could possibly add bool hasChanged to signify the dictionary has updated, thus requiring to ask user to save changes

public:
	Tries();


	Tries(string filePath); //constructor that reads in a file to fill Tries structure


	/*
		//TODO 

		Tries(File inputDictionary); //Some implementation of reading in a file full of words

		bool writeToFile(path, name, ....); Some implementation of writing the tree out to file
	*/

	~Tries();


	//File readin/writeout

	bool loadDictionary(string filePath);
	bool saveDictionary(); //Saves to current filepath. If no filepath, prompts user for file name and path
	bool saveDictionaryAs(string fileName, string filePath);


	//TODO like in TriesNode, consider changing to returning a TriesNode so that further information can be updated, or additional features can be edited with that node
	bool insertWord(string newWord);
	bool deleteWord(string targetWord);
	TriesNode* findWord(string targetWord); //Returns TriesNode where the end of the word exists, incase that node also has additonal data that may be relevant
	bool isWord(string targetWord);
};

