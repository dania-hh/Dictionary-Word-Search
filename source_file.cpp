//Last Modified: Odmaa at 10/10/19 2:00pm

#include <cstdlib> // standard systems definitions
#include<string>
#include<string.h>
#include <fstream>
#include<iostream>
#include<vector>
#include "DSA1.h"
#include<algorithm>
using namespace std;

int main(int argc, char const *argv[]){

	//IOFILE HANDLING	
	int Maxout;
	int repeat=0;
	int qmark_index=0;
	string qmark_filled;
	string filename;
	ifstream inFile; 
	std::string word; 

	for(int i=0;i<argc;i++)
		{
			if (strcmp(argv[i], "-d") == 0) 
				{filename=argv[i+1];} //saving filename as arguement that follows "-d" string
				
			if (strcmp(argv[i],"-1") == 0)
				{Maxout=atoi(argv[i+1]);} //saving maximum output as arguement that follows "-l" string
				
		}

	vector<string>myDict;

	inFile.open(filename); //checking if filename, obtained from commandline, is open
	if(inFile.is_open()){ //Checking if file is open
		while(!inFile.eof()){ //Continuing until end of file 
			getline(inFile,word); //Storing each word in "word" variable
			myDict.push_back(word); //Adding word to myDictonary vector
			} 	
	}
	inFile.close(); //Closing file
	sort(myDict.begin(),myDict.end()); //Sorting the vector alphabetically //no need but we can keep

	int c=0;
	while(c==0){
		string userstr;
		cout<<endl<<"Enter a string: ";
		cin>>userstr; 
		cout<<endl;

		//ERROR CHECKING 
		bool valid_input=true;
		userstr.c_str(); //returning pointer from the begininning of userstr string to the array to be declared
		char array[userstr.size()]; //(this is array to be declared): creating array to store separate characters of userstr
		strcpy(array,userstr.c_str()); //copying each character of string into array

		for(int i=0;i<userstr.size();i++) 
			{
				if(int(array[i]<int('a')) || int(array[i]>int('z'))) //if ASCII code of charcter in array  less than ASCII 'a' or 
																	//greater than ASCII ''z...
				{valid_input=false;}								//valid input becomes false
			}

		if(userstr=="exit"){c=1;}//Breaks the while loop and terminates program

		//PREFIX SEARCH
		else if((userstr.find("*"))!=-1){
			int i=0;
			int count=0;
			int printed=0;
			int matches=0;
			bool found=false;
			string startseg=userstr.substr(0,userstr.find("*")); //saving portion of userstr before *
																				//startseg and backseg varibales are created to check '*' exists in the end
			string backseg=userstr.substr(userstr.find("*")+1,userstr.size());	//of the word 
			if(backseg!="" || startseg=="") //checking '*' is in the middle
				{cout<<"Wildcard search not conducted correctly."<<endl
					<<"Make sure '*' is at the end of the word"<<endl;}
			else{prefix_binSearch(myDict,Maxout, userstr,startseg); }
		}

		//WILDCARD BINARY SEARCH
		else if((userstr.find("?"))!=-1){ 
			string startseg=userstr.substr(0,userstr.find("?"));				//these two varibales are created to check '?' exists in the middle
			string backseg=userstr.substr(userstr.find("?")+1,userstr.size());	//of the word & to obtain index of '?' to replace alphabet into
			int i=0;
			bool found=false;
			int matches=0;
			int printed=0;
			int count=0;

			if(backseg=="" || startseg=="" || startseg.find("?")==0 || backseg.find("?")==0) //checking '?' is in the middle
				{cout<<"Wildcard search not conducted correctly."<<endl
					<<"Make sure '?' is in the middle of the word"<<endl;}
			else{ 			//confirmed, '?' is in the right position
				int repeat=0;
				bool wild=true;
				int qmark_find=0;
				string alpha[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"}; //alphabet letters to replace '?''
				qmark_index=startseg.size(); //saving index of question mark

				while(repeat<26){ //!!!!!!!!!!!!!!!!!while loop that checks for all 26 possibilities of the word as well as until a word is found
				for(int i=0;i<26;i++){
					qmark_filled=userstr.replace(qmark_index,1,alpha[i]); //replacing '?' with alphabet
					repeat++; //tracking how many alphabets have been replaced
					full_wild_binSearch(myDict,Maxout,userstr,qmark_filled,wild,i);
				}
					}}}

		//FULL WORD BINARY SEARCH
		else if((userstr.find("*"))==-1 && (userstr.find("?"))==-1 && valid_input==true){  //valid input checked previously for ASCII 'a'<ASCII userstr char<ASCII 'z'
			bool wild=false; //telling function this is not a wildcard search, this is fullword, as same function is used
			int qmark_find=0; //same function used for fullword & wild, so wild arguements defaulted before call
			int i;
			full_wild_binSearch(myDict,Maxout,userstr,qmark_filled="",wild,i=26);}

		else if(valid_input==false) 
			{cout<<"Wrong input format."<<endl<<"Make sure you are using lower case letters and no special characters apart from ? and *";}
		
		

	}}
		











