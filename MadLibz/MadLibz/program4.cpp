// Description: Menu-based program that will allow the user to play Mad Libs
// Author: 
// Date: Nov 5,2019

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

// functions Prototypes
int showMenuGetChoice();
string* createStringArray(int);
void getInfoFromUser(string*, string*, int);
void printStory(int, string*, int);

// Main Function
int main()
{
	while (true)
	{
		// displays menu and gets choice form function
		int choice = showMenuGetChoice();
		// ends game
		if (choice == 4)
			break;
		
		string num_of_questions; // number of questions
		fstream file; // to read file

		if (choice == 1)
			file.open("starWars.txt", ios::in); // opens file in read mode
		else if (choice == 2)
			file.open("dog.txt", ios::in); //opens file in read mode
		else
			file.open("pirate.txt", ios::in); // opens file in read mode

		getline(file, num_of_questions); // reads number of questions
		// creates questions array
		string *questions = createStringArray(stoi(num_of_questions));
		// creates answers array
		string *answers = createStringArray(stoi(num_of_questions));
		// reads questions
		for (int i = 0; i < stoi(num_of_questions); i++)
			getline(file, *(questions + i)); //reads questions and saves to question array 
		file.close(); // closes file

		// gets answers from user
		getInfoFromUser(questions, answers, stoi(num_of_questions));
		// prints story
		printStory(choice, answers, stoi(num_of_questions));

		// deletes allocated memory
		delete[] questions;
		delete[] answers;
	}
	return 0;
}

// Shows the menu, get the user’s choice, validate the user’s choice,
// Returns the users choice
int showMenuGetChoice()
{
	string choice; // for user's choice
	do 
	{	// menu
		cout << "\n\nLet's Play some MADLIBS!!\n\n";
		cout << "Choose a MAD LIBSm game:\n";
		cout << "1. The Power of theForce (Star Wars Mad Libs)\n";
		cout << "2. Dog Days (Dog Ate My Mad Libs)\n";
		cout << "3. Talk Like a Pirate (PiratesMad Libs)\n";
		cout << "4. END GAME\n";
		cout << "\nCHOOSE 1-4: ";
		cin >> choice;

		// returns choice accordingly
		if (choice == "1")
			return 1;
		else if (choice == "2")
			return 2;
		else if (choice == "3")
			return 3;
		else if (choice == "4")
			return 4;
		else
			cout << "You didn't entered correct choice. Try Again!\n"; // for invalid choice
	} while (choice != "4");
}

// Accepts an integer indicating the size of the array
// Dynamically allocates a new string array of this size 
// Returns a pointer to this array
string* createStringArray(int size)
{
	string *p = new string[size];
	return p;
}

// This function accepts three parameters
// The function supplies the user with each question or prompt (from the question array) 
// Allows the user to enter in an answer(put this in the answer array
void getInfoFromUser(string *questions, string *answers, int size)
{
	cout << "Please give a response for each request.\n\n";
	for (int i = 0; i < size; i++)
	{
		cout << *(questions + i) << ": "; // outputs question
		cin >> *(answers + i); // inputs answer
	}
	cout << "\n";
}

// Function accepts three parameters
// Open the appropriate file(for example starWarsText.txt) 
// Parses the file and print out answers from the answer array as necessary
void printStory(int choice, string*answers, int size)
{
	fstream f;
	// opens file according to choice in read mode
	if (choice == 1)
		f.open("starWarsText.txt", ios::in);
	else if (choice == 2)
		f.open("dogText.txt", ios::in);
	else
		f.open("pirateText.txt", ios::in);
	string line;
	for (int i = 0; i < size; i++)
	{
		getline (f,line); // reads line from file
		cout << line + *(answers + i); //prints line.
	}
	f.close();// closes file
}