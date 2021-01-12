#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str);
	string temp;

	while (getline(ss, temp, delimiter)) {
		internal.push_back(temp);
	}

	return internal;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string line;
	getline(cin, line);

	int res = 0;
	vector<string> line_vector = split(line, ' ');

	for (int i = 0; i < line_vector.size(); ++i) {
		//cout << line_vector[i];
		res++;
	}

	if (line[0] == ' ') {
		res--;
	}


	printf("%d", res);

	return 0;
}

