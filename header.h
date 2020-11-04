#include <cstdlib> // standard systems definitions
#include<iostream>
#include <vector>
#include <string>
using namespace std;

int full_wild_binSearch(vector<string> dict,int Maxout, string userstr,string qmark_filled, bool wild, int i);
void prefix_binSearch(vector<string> dict,int Maxout, string userstr,string startseg);
void print(string myDict,int Maxout,int& printed,bool& found);
