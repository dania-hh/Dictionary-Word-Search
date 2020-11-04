#include "DSA1.h"
#include <cstdlib> // standard systems definitions
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int full_wild_binSearch(vector<string> dict,int Maxout, string userstr,string qmark_filled, bool wild, int i){ //binary search for both fullword and wild card
	string w;
	if(!wild){w=userstr; i=25;} //telling function: this is a fullword search. i is used in wildcard, in full, not used so defaulted
		else{w=qmark_filled;} //if not full, then wildcard search, where w is the word with the '?' replaced to search through dict for
	int low=0;
	int high=dict.size()-1;
	int mid=(low+high)/2;
	int count=0;
	bool found=false;
	while(high>=low){
		mid=(low+high)/2;

		if(w.compare(dict[mid])<0){ //user string exists after mid word
			high=mid-1;
			}

		else if(w.compare(dict[mid])>0){ //user string exists before mid word
			low=mid+1;
			}

		else if(w.compare(dict[mid])==0){ //user string=mid word
			found=true;
			break;}

		else if(!found && i==25 ){cout<<"Word not found"<<endl; return 0;}	//not found after having searched through all alphabet in wildcard case
																			//in full word, 'i' already defaulted to 25 to allow this statement to
																			//apply for both full and wild searche
	}
	
	count=dict.size()-mid; //count is size of dictionary- last index position: has checked all prev entries

	 if(found) //print for user
	 	{cout<<"-> "<<dict[mid]<<endl;
		cout<<"word found"<<endl;
		cout<<"The number of comparisons is: "<<abs(count)<<endl; 
	  	return 1;}


	 else 
	 	{return 0;}
		

	}

	//PREFIX BINARY SEARCH
	void prefix_binSearch(vector<string> dict,int Maxout, string userstr,string startseg){
		int complete_search=0;
		int count=0;
		bool found=false;
		vector<string> dict_edited; //creating new vector to copy dict
		vector<string> prefix_finds; //vector to store words found in dict_edited that started with prefix the user entered
		copy(dict.begin(),dict.end(),back_inserter(dict_edited)); //copy of dict created 
		int low=0;
		int mid;
		int print_outs=0;
		int high=dict_edited.size()-1;
		while(complete_search<dict.size()-1){ //looping until the whole dictionary has been checked
		complete_search++;

		while(high>=low){
			mid=(low+high)/2;

			if(dict_edited[mid].compare(0,startseg.size(),startseg)>0){ //user string exists after mid word
				high=mid-1;
			
			}
			else if(dict_edited[mid].compare(0,startseg.size(),startseg)<0){ //user string exists before mid word
				low=mid+1;
			
			}
			else if(dict_edited[mid].compare(0,startseg.size(),startseg)==0){ //user prefix=mid word prefix in dict
				found=true;
			

				bool exist = false;				//checking if found word already exists in list of prefix finds
				for(auto x:prefix_finds)
					{
						if(x==dict_edited[mid])
							{exist=true;}
					}

					if(exist==false)			//if it doesn't exist, add it to the list of prefix finds
						{prefix_finds.push_back(dict_edited[mid]);}
		
				dict_edited.erase(dict_edited.begin()+mid); //after finding it, delete it from dictionary copy to avoid coming across it again
				count=dict_edited.size()-mid; //update count
				break;
			
			}
		}}
		cout<<prefix_finds.size()<<" matches found."<<endl;
		cout<<"You asked for "<<Maxout<<" matches"<<endl;
		cout<<"Number of comparisons taken to reach first match: "<<abs(count)<<endl;	//absolute value of count taken take into account 
																						//right and left search from mid of the dictionary

		if(!prefix_finds.empty()) //only if list is not empty(i.e in case of finding words that started with prefix): print contents
			{
				for(auto x:prefix_finds)
				{cout<<"-> "<<x<<endl; 
					print_outs++; 		
					if(print_outs>=Maxout || print_outs>prefix_finds.size()){break;}} //when found words is printed up to max output OR
																					//printed for how many the search found even if less than maxout
			}


		 if(!found){cout<<"Word not found"<<endl;}}
	