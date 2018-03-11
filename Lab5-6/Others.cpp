#include "Others.h"

int stringToInt(string nr)
{
	int result = 0;

	for (unsigned int i = 0; i < nr.length(); i++)
		if (nr[i] >= 48 && nr[i] <= 57)
			result = result * 10 + (nr[i] - 48);
		else
			return -1;

	return result;
}

vector<string> tokenize(const string& str, char delimiter)
{
	vector <string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);

	return result;
}