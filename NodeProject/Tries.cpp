#include "Tries.h"

using namespace std;


/*   Hold off on this, sending an ifstream may be redundant
bool Tries::processDictionary(const ifstream& infile)
{
	return false;
}
*/


/**
	Main helper function for reading a file with a dictionary of words and store in current Tries
	For now, file is a .txt file, and words are seperated by newline or some blankspace delimitor

	TODO Later, implement a more structurted format for file (and maybe custom file extension) for extra features, like definitions and such
	Start with one word per line again, followed by deliminators for definition, then something else, etc
*/
bool Tries::processDictionary()
{
	string inputLine; //For reading in one line at a time. For now, it's just the word. Later, may implement other info on the word seperated by a deliminator, such as definitions and such. All contained on current line
	string word;
	//string definition

	while (getline(infile, inputLine)) //NOTE: this getline is part of std library, NOT ifstream.
	{
		//TODO Provide parsing by delimitor when more features of tries added
		//ie definition:  getLine(stringstream, definition)



		stringstream inputLineStream(inputLine); //Turns inputline into a stream object, which allows to do getLine again for parsing tokens
		
		//use getLine(inputLineStream, someVariable, ' ') each time a token is needed. Later, use different delimitor since one filed could be 'definition', which could be whole paragraphs with spaces
		getline(inputLineStream, word, ' ');
		//getline(inputLineStream, definition, ' ');




		insertWord(word);
		//insertWord(word, definition, ....);
		

	}

	//TODO For now just return True. Shouldn't be errors since inserting words only returns false if already a word. This function only returns false on ERRORS
	//In this case, should be formatting error or something
	return true;
}







/**
	Helper function for printing words. Will make use of Mutex printMutex to handle multi-threading when printing out
	@param outputStream A given ouput point where the given word is printed to, either a file (outfile) or the console
	@param targetWord The word to be printed to the outputStream. Word will be derived from parallel threads calling this function
*/



/*  Hold off...
void Tries::printWordOut(ostream outputStream, string targetWord)
{
	printMutex.lock();
	outputStream << targetWord;
	printMutex.unlock();
}


*/



Tries::Tries()
{
	root.reset(new TriesNode());
}

Tries::Tries(string filePath)
{
	root.reset(new TriesNode());
	bool isOpen;
	infile.open(filePath);
	isOpen = infile.is_open();
	if (!isOpen)
	{
		cout << "ERROR Cannot open file path, creating empty Tries";
		
	}
	else
	{
		processDictionary(); //TODO in future, implement return boolean which would idicate errors in parsing/format, which would require either creating an empty Tries, or quiting
	}

}

bool Tries::loadDictionary(string filePath)
{

	//TODO Check if a file is already open

	if (infile.is_open())
		infile.close();
		

	bool isOpen;
	infile.open(filePath);
	isOpen = infile.is_open();
	if (!isOpen)
	{
		cout << "ERROR Cannot open file path, creating empty Tries";
		return false;

	}
	else
	{
		processDictionary(); //TODO in future, implement return boolean which would idicate errors in parsing/format, which would require either creating an empty Tries, or quiting
	}


	return true;
}






/*
	Default save to file, using outFile

	Creates a PrintFunctor with buffer to outFile, the calls root node's printWord(printFunctor, currentWord = ""),
	which recursively calls functor to print currentWord + currentChar (if isWord), the creates a group of threads to recursively
	do same thing for each mapped nect letter.

*/

bool Tries::saveDictionary()
{
	//TODO figure out system for tracking file, current way may be incorrect since it may require constant open and closing, which removes path directory

	bool isOpen;
	isOpen = outfile.is_open();

	if (isOpen)
	{
		//move to beggining of file and overwrite (?)

		//TODO for now, return false, don't write out to already open file which should be closed
	}
	else
	{
		//TODO figure how to handle, for now just save to dummy file
		outfile.open("tempOutDict.txt");


		PrintFunctor* printOut = new PrintFunctor(outfile);

		root->printWord(*printOut);

		delete printOut;


	}
	outfile.close();

	return true;
}

bool Tries::saveDictionaryAs(string fileName, string filePath)
{
	return false;
}







bool Tries::insertWord(string newWord)
{
	//TODO later implementation, may want to switch to returning a pointer to a TriesNode where additional info can be added for that word, or make use of inserting extensions of word
	bool insertResult = root->insertWord(newWord);

	//Place any additional implementation here, such as updating a word count

	return insertResult;
}

bool Tries::deleteWord(string targetWord)
{
	return root->deleteWord(targetWord);
}

TriesNode* Tries::findWord(string targetWord)
{
	return root->findWord(targetWord);
}

bool Tries::isWord(string targetWord)
{
	TriesNode* isWordResult = root->findWord(targetWord);
	return (isWordResult != nullptr) ? true : false;
}
