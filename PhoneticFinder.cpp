#include <iostream>
#include <cstring> 
#include "PhoneticFinder.hpp"
using namespace std;
namespace phonetic {

	string fix(string w)
	{
		string str("");
		for (int i = 0; i < w.length(); i++)
		{
			char l = tolower(w.at(i));
		        if (l == 'i' || l == 'y')
			str += '1';
			else if (l == 'o' || l == 'u')
			str += '2';
			else if (l == 's' || l == 'z')
			str += '3';
			else if (l == 'd' || l == 't')
			str += '4';
			else if (l == 'g' || l == 'j')
			str += '5';
			else if (l == 'c' || l == 'k' || l == 'q')
			str += '6';
			else if (l == 'b' || l == 'f' || l == 'p')
			str += '7';
			else if (l == 'v' || l == 'w')
			str += '8';
			else
			str += l;
		}
		return str;
	}

	bool similiar(string word, string word2) {
		string s1 = fix(word);
		string s2 = fix(word2);
		int length1 = s1.length();
		int length2 = s2.length();
		if (length1!=length2)
			return false;
		if (s1.compare(s2)==0)
			return true;
		else
			return false;
	}

	string find(string temp, string word) {
		string text = temp + '\0';
		int i = 0, j = 0;
		if (word.compare("")==0|| word.compare(" ")==0)
			throw "uncorrect input";
		if (text.compare("")==0|| text.compare(" ")==0)
			throw "uncorrect input";

		while (i < text.length()) {
			if (text.at(i) == ' ' || i == text.length() - 1) 
			{
				char str[i- j + 1];
				memset(str, 0, i - j + 1);
				text.copy(str, i - j, j);
				if (similiar(str, word))
					return str;
				j = i + 1;
			}
			i++;

		}
		throw runtime_error("not find the word \"" + word + "\"");
	}



}
