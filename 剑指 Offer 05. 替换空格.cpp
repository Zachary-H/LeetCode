#include <iostream>    //½£Ö¸ Offer 05. Ìæ»»¿Õ¸ñ(2020.10.4)
using namespace std;

class Solution {
public:
	string replaceSpace(string s) {
		string a;
		int i = 0;
		int j = 0;
		int len = s.length();

		for (; i < len; i++)
		{
			if (s[i] != ' '){
				a += s[i];

				j++;
			}

			else{
				a += "%20";
				j = j + 3;
			}
		}

		return a;
	}
};